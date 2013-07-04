#include "NodeId.h"
#include "CastExpression.h"
#include "TypeReference.h"

CastExpression::CastExpression()
{
	castType = NULL;
	expression = NULL;
}

CastExpression::~CastExpression()
{
	if(castType) delete castType;
	if(expression) delete expression;
}

void
CastExpression::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::CAST_EXPRESSION);
	Expression::identify(id);
}

void
CastExpression::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "CastExpression");
	//addMember(elem, "locationInfo", locationInfo);
}
