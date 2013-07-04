#include "NodeId.h"
#include "UnaryExpression.h"
#include "UnaryOperator.h"

UnaryExpression::UnaryExpression()
{
	op = NULL;
	operand = NULL;
}

UnaryExpression::~UnaryExpression()
{
	if(op) delete op;
	if(operand) delete operand;
}

void
UnaryExpression::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::UNARY_EXPRESSION);
	Expression::identify(id);
}

void
UnaryExpression::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "UnaryExpression");
	//addMember(elem, "expressionType", expressionType);
	addMember(elem, "op", op);
	addMember(elem, "operand", operand);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
