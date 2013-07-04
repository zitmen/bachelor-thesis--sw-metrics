#include "NodeId.h"
#include "ExpressionStatement.h"
#include "Expression.h"

ExpressionStatement::ExpressionStatement()
{
	expression = NULL;
}

ExpressionStatement::~ExpressionStatement()
{
	if(expression) delete expression;
}

void
ExpressionStatement::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::EXPRESSION_STATEMENT);
	Statement::identify(id);
}

void
ExpressionStatement::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "ExpressionStatement");
	addMember(elem, "expression", expression);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
