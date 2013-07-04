#include "NodeId.h"
#include "FunctionCallExpression.h"
#include "ActualParameter.h"

FunctionCallExpression::FunctionCallExpression()
{
	calledFunction = NULL;
	actualParams = NULL;
}

FunctionCallExpression::~FunctionCallExpression()
{
	if(calledFunction) delete calledFunction;
	//
	if(actualParams)
	{
		for(size_t i = 0, im = actualParams->size(); i < im; ++i)
			if(actualParams->at(i))
				delete actualParams->at(i);
		//
		actualParams->clear();
	}
}

void
FunctionCallExpression::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::FUNCTION_CALL_EXPRESSION);
	Expression::identify(id);
}

void
FunctionCallExpression::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "FunctionCallExpression");
	addMember(elem, "calledFunction", calledFunction);
	addMember(elem, "actualParams", (std::vector<GASTMObject *> *)actualParams);
	addMember(elem, "locationInfo", locFirst);
	addMember(elem, "locationInfo", locLast);
}
