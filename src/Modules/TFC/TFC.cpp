#include "TFC.h"
#include "../ModuleApi.h"
using namespace NodeId;

#include <sstream>
#include <algorithm>

void
TotalFunctionCalls::countFunctionCallsInBlock(Statement *statm, int &tfc)
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
			countFunctionCallsInBlock(((IfStatement *)block.subStatements->at(i))->thenBody, tfc);
			countFunctionCallsInBlock(((IfStatement *)block.subStatements->at(i))->elseBody, tfc);
			countFunctionCallsInExpression(((IfStatement *)block.subStatements->at(i))->condition, tfc);
		}
		else if(m_nodeId == SWITCH_STATEMENT)
		{
			countFunctionCallsInBlock(((SwitchStatement *)block.subStatements->at(i))->body, tfc);
			countFunctionCallsInExpression(((IfStatement *)block.subStatements->at(i))->condition, tfc);
		}
		else if(m_nodeId == CASE_BLOCK)
		{
			countFunctionCallsInBlock(((CaseBlock *)block.subStatements->at(i))->statement, tfc);
			countFunctionCallsInExpression(((CaseBlock *)block.subStatements->at(i))->expression, tfc);
		}
		else if(m_nodeId == DEFAULT_BLOCK)
		{
			countFunctionCallsInBlock(((CaseBlock *)block.subStatements->at(i))->statement, tfc);
		}
		else if(m_nodeId == LOOP_STATEMENT)
		{
			if(m_nodeId == FOR_STATEMENT)
			{
				countFunctionCallsInBlock(((ForStatement *)block.subStatements->at(i))->initBody, tfc);
			}
			countFunctionCallsInBlock(((LoopStatement *)block.subStatements->at(i))->body, tfc);
			countFunctionCallsInExpression(((LoopStatement *)block.subStatements->at(i))->condition, tfc);
		}
		else if(m_nodeId == BLOCK_STATEMENT)
		{
			countFunctionCallsInBlock((BlockStatement *)block.subStatements->at(i), tfc);
		}
		else if(m_nodeId == EXPRESSION_STATEMENT)
		{
			countFunctionCallsInExpression(((ExpressionStatement *)block.subStatements->at(i))->expression, tfc);
		}
		else if(m_nodeId == RETURN_STATEMENT)
		{
			countFunctionCallsInExpression(((ReturnStatement *)block.subStatements->at(i))->returnValue, tfc);
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
						countFunctionCallsInExpression(((DataDefinition *)tmp->at(defn))->initialValue, tfc);
					}
				}
			}
		}
		else if(m_nodeId == TRY_STATEMENT)
		{
			countFunctionCallsInBlock(((TryStatement *)block.subStatements->at(i))->guardedStatement, tfc);
			//
			for(size_t bn = 0, bm = ((TryStatement *)block.subStatements->at(i))->catchBlocks.size(); bn < bm; ++bn)
			{
				countFunctionCallsInBlock(((TryStatement *)block.subStatements->at(i))->catchBlocks.at(bn)->body, tfc);
			}
		}
	}
	//
	block.subStatements->clear();
}

void
TotalFunctionCalls::countFunctionCallsInExpression(Expression *expr, int &tfc)
{
	if(expr == NULL) return;
	//
	m_nodeId.setNode(expr);
	if(m_nodeId == CONDITIONAL_EXPRESSION)
	{
		countFunctionCallsInExpression(((ConditionalExpression *)expr)->condition, tfc);
		countFunctionCallsInExpression(((ConditionalExpression *)expr)->onTrueOperand, tfc);
		countFunctionCallsInExpression(((ConditionalExpression *)expr)->onFalseOperand, tfc);
	}
	else if(m_nodeId == BINARY_EXPRESSION)
	{
		countFunctionCallsInExpression(((BinaryExpression *)expr)->leftOperand, tfc);
		countFunctionCallsInExpression(((BinaryExpression *)expr)->rightOperand, tfc);
	}
	else if(m_nodeId == UNARY_EXPRESSION)
	{
		countFunctionCallsInExpression(((UnaryExpression *)expr)->operand, tfc);
	}
	else if(m_nodeId == FUNCTION_CALL_EXPRESSION)
	{
		tfc += 1;
		//
		if(((FunctionCallExpression *)expr)->actualParams)
		{
			for(size_t i = 0, im = ((FunctionCallExpression *)expr)->actualParams->size(); i < im; ++i)
			{
				countFunctionCallsInExpression(((FunctionCallExpression *)expr)->actualParams->at(i)->value, tfc);
			}
		}
	}
}

TotalFunctionCalls::TotalFunctionCalls(CompilationUnit *unit) : ModuleBase(unit)
{
	std::vector<FunctionDefinition *> functions;
	ModuleApi::findFunctionsInFile(unit, functions);
	int tfc = 0;
	std::string fn_name;
	//
	for(size_t i = 0, im = functions.size(); i < im; ++i, tfc = 0, fn_name = "")
	{
		ModuleApi::getFullName(functions[i], fn_name);
		countFunctionCallsInBlock(functions[i]->body, tfc);
		//
		m_fnCalls.push_back
		(
			std::make_pair
			(
				fn_name,
				tfc
			)
		);
	}
}

TotalFunctionCalls::~TotalFunctionCalls()
{
	//
}

std::string
TotalFunctionCalls::dumpResultXml()
{
	std::ostringstream os;
	os << "\t<module name=\"Total Function Calls\">\n";
	for(size_t i = 0, im = m_fnCalls.size(); i < im; ++i)
	{
		os << "\t\t<function>\n"
		   << "\t\t\t<name>" << m_fnCalls[i].first  << "</name>\n"
		   << "\t\t\t<tfc>" << m_fnCalls[i].second << "</tfc>\n"
		   << "\t\t</function>\n";
	}
	os << "\t</module>\n";
	return os.str();
}
