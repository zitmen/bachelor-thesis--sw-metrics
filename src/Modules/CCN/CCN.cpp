#include "CCN.h"
#include "../ModuleApi.h"
using namespace NodeId;

#include <sstream>
#include <algorithm>

void
CyclomaticComplexityNumber::countBlockComplexity(Statement *statm, int &ccn1, int &ccn2)
{
	if(statm == NULL) return;
	//
	BlockStatement block;
	block.subStatements = new std::vector<Statement *>;
	ModuleApi::statm2block(statm, &block);	// convert parameter to BlockStatement
	//
	for(size_t i = 0, im = block.subStatements->size(); i < im; ++i)
	{
		m_nodeId.setNode(block.subStatements->at(i));
		//
		if(m_nodeId == IF_STATEMENT)
		{
			ccn1 += 1; ccn2 += 1;
			countBlockComplexity(((IfStatement *)block.subStatements->at(i))->thenBody, ccn1, ccn2);
			countBlockComplexity(((IfStatement *)block.subStatements->at(i))->elseBody, ccn1, ccn2);
			countExpressionComplexity(((IfStatement *)block.subStatements->at(i))->condition, ccn1, ccn2);
		}
		else if(m_nodeId == SWITCH_STATEMENT)
		{
			countBlockComplexity(((SwitchStatement *)block.subStatements->at(i))->body, ccn1, ccn2);
			countExpressionComplexity(((IfStatement *)block.subStatements->at(i))->condition, ccn1, ccn2);
		}
		/* Search for cases inside of switch
		     - right form is guaranteed by compiler, so it's not necessary
		       to ensure that CASE_BLOCK is inside of SWITCH_STATEMENT.
		*/
		else if(m_nodeId == CASE_BLOCK)
		{
			ccn1 += 1; ccn2 += 1;
			countBlockComplexity(((CaseBlock *)block.subStatements->at(i))->statement, ccn1, ccn2);
			countExpressionComplexity(((CaseBlock *)block.subStatements->at(i))->expression, ccn1, ccn2);
		}
		else if(m_nodeId == DEFAULT_BLOCK)
		{
			//complexity += 0;	// keyword default is counted as original path
			countBlockComplexity(((CaseBlock *)block.subStatements->at(i))->statement, ccn1, ccn2);
		}
		else if(m_nodeId == LOOP_STATEMENT)
		{
			if(m_nodeId == FOR_STATEMENT)
			{
				countBlockComplexity(((ForStatement *)block.subStatements->at(i))->initBody, ccn1, ccn2);
			}
			ccn1 += 1; ccn2 += 1;
			countBlockComplexity(((LoopStatement *)block.subStatements->at(i))->body, ccn1, ccn2);
			countExpressionComplexity(((LoopStatement *)block.subStatements->at(i))->condition, ccn1, ccn2);
		}
		else if(m_nodeId == BLOCK_STATEMENT)
		{
			countBlockComplexity((BlockStatement *)block.subStatements->at(i), ccn1, ccn2);
		}
		else if(m_nodeId == EXPRESSION_STATEMENT)
		{
			countExpressionComplexity(((ExpressionStatement *)block.subStatements->at(i))->expression, ccn1, ccn2);
		}
		else if(m_nodeId == DECLARATION_OR_DEFINITION_STATEMENT)
		{
			std::vector<DefinitionUnit *> *tmp = ((DeclarationOrDefinitionStatement *)block.subStatements->at(i))->declOrDefn;
			if(tmp != NULL)
			{
				for(size_t defn = 0, defm = tmp->size(); defn < defm; ++defn)
				{
					m_nodeId.setNode(tmp->at(defn));
					if(m_nodeId == DATA_DEFINITION)
					{
						countExpressionComplexity(((DataDefinition *)tmp->at(defn))->initialValue, ccn1, ccn2);
					}
				}
			}
		}
		else if(m_nodeId == TRY_STATEMENT)
		{
			countBlockComplexity(((TryStatement *)block.subStatements->at(i))->guardedStatement, ccn1, ccn2);
			//
			for(size_t bn = 0, bm = ((TryStatement *)block.subStatements->at(i))->catchBlocks.size(); bn < bm; ++bn)
			{
				countBlockComplexity(((TryStatement *)block.subStatements->at(i))->catchBlocks.at(bn)->body, ccn1, ccn2);
			}
		}
	}
	//
	block.subStatements->clear();
}

void
CyclomaticComplexityNumber::countExpressionComplexity(Expression *expr, int &ccn1, int &ccn2)
{
	if(expr == NULL) return;
	//
	m_nodeId.setNode(expr);
	if(m_nodeId == CONDITIONAL_EXPRESSION)
	{
		ccn1 += 1; ccn2 += 1;
		countExpressionComplexity(((ConditionalExpression *)expr)->condition, ccn1, ccn2);
		countExpressionComplexity(((ConditionalExpression *)expr)->onTrueOperand, ccn1, ccn2);
		countExpressionComplexity(((ConditionalExpression *)expr)->onFalseOperand, ccn1, ccn2);
	}
	else if(m_nodeId == BINARY_EXPRESSION)
	{
		m_nodeId.setNode(((BinaryExpression *)expr)->op);
		if((m_nodeId == AND) || (m_nodeId == OR))
		{
			ccn2 += 1;	// CCN2 only! This is the difference between those two.
		}
		countExpressionComplexity(((BinaryExpression *)expr)->leftOperand, ccn1, ccn2);
		countExpressionComplexity(((BinaryExpression *)expr)->rightOperand, ccn1, ccn2);
	}
	else if(m_nodeId == UNARY_EXPRESSION)
	{
		countExpressionComplexity(((UnaryExpression *)expr)->operand, ccn1, ccn2);
	}
}

CyclomaticComplexityNumber::CyclomaticComplexityNumber(CompilationUnit *unit) : ModuleBase(unit)
{
	std::vector<FunctionDefinition *> functions;
	ModuleApi::findFunctionsInFile(unit, functions);
	int ccn1 = 1, ccn2 = 1;
	std::string fn_name;
	//
	for(size_t i = 0, im = functions.size(); i < im; ++i, ccn1 = ccn2 = 1, fn_name = "")
	{
		ModuleApi::getFullName(functions[i], fn_name);
		countBlockComplexity((BlockStatement *)functions[i]->body, ccn1, ccn2);
		//
		m_fnComplexity.push_back
		(
			std::make_pair
			(
				fn_name,
				std::make_pair(ccn1, ccn2)
			)
		);
	}
}

CyclomaticComplexityNumber::~CyclomaticComplexityNumber()
{
	//
}

std::string
CyclomaticComplexityNumber::dumpResultXml()
{
	std::ostringstream os;
	os << "\t<module name=\"Cyclomatic Complexity Number\">\n";
	for(size_t i = 0, im = m_fnComplexity.size(); i < im; ++i)
	{
		os << "\t\t<function>\n"
		   << "\t\t\t<name>" << m_fnComplexity[i].first  << "</name>\n"
		   << "\t\t\t<ccn1>" << m_fnComplexity[i].second.first << "</ccn1>\n"
		   << "\t\t\t<ccn2>" << m_fnComplexity[i].second.second << "</ccn2>\n"
		   << "\t\t</function>\n";
	}
	os << "\t</module>\n";
	return os.str();
}
