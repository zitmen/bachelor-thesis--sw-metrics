#include "NodeId.h"
#include "RangeExpression.h"

RangeExpression::RangeExpression()
{
	fromExpression = toExpression = NULL;
}

RangeExpression::~RangeExpression()
{
	if(fromExpression) delete fromExpression;
	if(toExpression) delete toExpression;
}

void
RangeExpression::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::RANGE_EXPRESSION);
	Expression::identify(id);
}

void
RangeExpression::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "RangeExpression");
	//addMember(elem, "expressionType", expressionType);
	addMember(elem, "fromExpression", fromExpression);
	addMember(elem, "toExpression", toExpression);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
