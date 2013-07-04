#include "NodeId.h"
#include "AggregateExpression.h"

AggregateExpression::AggregateExpression()
{
	//
}

AggregateExpression::~AggregateExpression()
{
	for(size_t i = 0, im = expressions.size(); i < im; ++i)
		if(expressions[i])
			delete expressions[i];
	//
	expressions.clear();
}

void
AggregateExpression::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::AGGREGATE_EXPRESSION);
	Expression::identify(id);
}

void
AggregateExpression::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "AggregateExpression");
	//addMember(elem, "locationInfo", locationInfo);
}
