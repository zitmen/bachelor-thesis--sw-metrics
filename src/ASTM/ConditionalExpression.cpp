#include "NodeId.h"
#include "ConditionalExpression.h"

ConditionalExpression::ConditionalExpression()
{
	condition = NULL;
	onTrueOperand = NULL;
	onFalseOperand = NULL;
}

ConditionalExpression::~ConditionalExpression()
{
	if(condition) delete condition;
	if(onTrueOperand) delete onTrueOperand;
	if(onFalseOperand) delete onFalseOperand;
}

void
ConditionalExpression::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::CONDITIONAL_EXPRESSION);
	Expression::identify(id);
}

void
ConditionalExpression::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "ConditionalExpression");
	addMember(elem, "condition", condition);
	addMember(elem, "onTrueOperand", onTrueOperand);
	addMember(elem, "onFalseOperand", onFalseOperand);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
