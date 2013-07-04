#include "NodeId.h"
#include "NewExpression.h"
#include "TypeReference.h"
#include "ActualParameter.h"

NewExpression::NewExpression()
{
	newType = NULL;
}

NewExpression::~NewExpression()
{
	if(newType) delete newType;
	//
	for(size_t i = 0, im = actualParams.size(); i < im; ++i)
		if(actualParams[i])
			delete actualParams[i];
	//
	actualParams.clear();
}

void
NewExpression::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::NEW_EXPRESSION);
	Expression::identify(id);
}

void
NewExpression::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "NewExpression");
	//addMember(elem, "locationInfo", locationInfo);
}
