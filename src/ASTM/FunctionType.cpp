#include "NodeId.h"
#include "FunctionType.h"
#include "FormalParameterType.h"
#include "TypeReference.h"

FunctionType::FunctionType()
{
	returnType = NULL;
}

FunctionType::~FunctionType()
{
	for(size_t i = 0, im = parameterTypes.size(); i < im; ++i)
		if(parameterTypes[i])
			delete parameterTypes[i];
	//
	parameterTypes.clear();
	//
	if(returnType) delete returnType;
}

void
FunctionType::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::FUNCTION_TYPE);
	Type::identify(id);
}

void
FunctionType::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "FunctionType");
	//addMember(elem, "locationInfo", locationInfo);
}
