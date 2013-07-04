#include "NodeId.h"
#include "BinaryExpression.h"
#include "BinaryOperator.h"

BinaryExpression::BinaryExpression()
{
	op = NULL;
	leftOperand = NULL;
	rightOperand = NULL;
}

BinaryExpression::~BinaryExpression()
{
	if(op) delete op;
	if(leftOperand) delete leftOperand;
	if(rightOperand) delete rightOperand;
}

void
BinaryExpression::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::BINARY_EXPRESSION);
	Expression::identify(id);
}

void
BinaryExpression::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "BinaryExpression");
	addMember(elem, "leftOperand", leftOperand);
	addMember(elem, "op", op);
	addMember(elem, "rightOperand", rightOperand);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
