#include "NPATH.h"
#include "../ModuleApi.h"
using namespace NodeId;

#include <sstream>
#include <algorithm>

int
NPathComplexity::countBlockComplexity(Statement *statm)
{
	int npath = 1, np = 0;
	if(statm == NULL) return 1;
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
			np  = countBlockComplexity(((IfStatement *)block.subStatements->at(i))->thenBody);
			np += countBlockComplexity(((IfStatement *)block.subStatements->at(i))->elseBody);
			np += countExpressionComplexity(((IfStatement *)block.subStatements->at(i))->condition);
			npath *= np;
		}
		else if(m_nodeId == SWITCH_STATEMENT)
		{
			np  = countBlockComplexity(((SwitchStatement *)block.subStatements->at(i))->body);
			np += countExpressionComplexity(((IfStatement *)block.subStatements->at(i))->condition);
			npath *= np;
		}
		/* Search for cases inside of switch
		     - right form is guaranteed by compiler, so it's not necessary
		       to ensure that CASE_BLOCK is inside of SWITCH_STATEMENT.
		*/
		else if(m_nodeId == CASE_BLOCK)
		{
			np += countBlockComplexity(((CaseBlock *)block.subStatements->at(i))->statement);
			np += countExpressionComplexity(((CaseBlock *)block.subStatements->at(i))->expression);
			npath = np;
		}
		else if(m_nodeId == DEFAULT_BLOCK)
		{
			np += countBlockComplexity(((CaseBlock *)block.subStatements->at(i))->statement);
			npath = np;
		}
		else if(m_nodeId == LOOP_STATEMENT)
		{
			np = 1;
			if(m_nodeId == FOR_STATEMENT)
			{
				np += countBlockComplexity(((ForStatement *)block.subStatements->at(i))->initBody);
			}
			np += countBlockComplexity(((LoopStatement *)block.subStatements->at(i))->body);
			np += countExpressionComplexity(((LoopStatement *)block.subStatements->at(i))->condition);
			npath *= np;
		}
		else if(m_nodeId == BLOCK_STATEMENT)
		{
			np = countBlockComplexity((BlockStatement *)block.subStatements->at(i));
			npath *= np;
		}
		else if(m_nodeId == EXPRESSION_STATEMENT)
		{
			np = countExpressionComplexity(((ExpressionStatement *)block.subStatements->at(i))->expression);
			if(np != 0) npath *= np;
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
						np = countExpressionComplexity(((DataDefinition *)tmp->at(defn))->initialValue);
						if(np != 0) npath *= np;
					}
				}
			}
		}
		else if(m_nodeId == TRY_STATEMENT)
		{
			np = countBlockComplexity(((TryStatement *)block.subStatements->at(i))->guardedStatement);
			npath *= np;
			//
			for(size_t bn = 0, bm = ((TryStatement *)block.subStatements->at(i))->catchBlocks.size(); bn < bm; ++bn)
			{
				np = countBlockComplexity(((TryStatement *)block.subStatements->at(i))->catchBlocks.at(bn)->body);
				npath *= np;
			}
		}
	}
	//
	block.subStatements->clear();
	return npath;
}

int
NPathComplexity::countExpressionComplexity(Expression *expr)
{
	int np = 0;
	if(expr == NULL) return 0;
	//
	m_nodeId.setNode(expr);
	if(m_nodeId == CONDITIONAL_EXPRESSION)
	{
		np  = 2;
		np += countExpressionComplexity(((ConditionalExpression *)expr)->condition);
		np += countExpressionComplexity(((ConditionalExpression *)expr)->onTrueOperand);
		np += countExpressionComplexity(((ConditionalExpression *)expr)->onFalseOperand);
	}
	else if(m_nodeId == BINARY_EXPRESSION)
	{
		m_nodeId.setNode(((BinaryExpression *)expr)->op);
		if((m_nodeId == AND) || (m_nodeId == OR))
		{
			np = 1;
		}
		np += countExpressionComplexity(((BinaryExpression *)expr)->leftOperand);
		np += countExpressionComplexity(((BinaryExpression *)expr)->rightOperand);
	}
	else if(m_nodeId == UNARY_EXPRESSION)
	{
		np += countExpressionComplexity(((UnaryExpression *)expr)->operand);
	}
	//
	return np;
}

NPathComplexity::NPathComplexity(CompilationUnit *unit) : ModuleBase(unit)
{
	std::vector<FunctionDefinition *> functions;
	ModuleApi::findFunctionsInFile(unit, functions);
	std::string fn_name;
	//
	for(size_t i = 0, im = functions.size(); i < im; ++i, fn_name = "")
	{
		ModuleApi::getFullName(functions[i], fn_name);
		//
		m_fnComplexity.push_back
		(
			std::make_pair
			(
				fn_name,
				countBlockComplexity((BlockStatement *)functions[i]->body)
			)
		);
	}
}

NPathComplexity::~NPathComplexity()
{
	//
}

std::string
NPathComplexity::dumpResultXml()
{
	std::ostringstream os;
	os << "\t<module name=\"NPath Complexity\">\n";
	for(size_t i = 0, im = m_fnComplexity.size(); i < im; ++i)
	{
		os << "\t\t<function>\n"
		   << "\t\t\t<name>" << m_fnComplexity[i].first  << "</name>\n"
		   << "\t\t\t<npath>" << m_fnComplexity[i].second << "</npath>\n"
		   << "\t\t</function>\n";
	}
	os << "\t</module>\n";
	return os.str();
}
