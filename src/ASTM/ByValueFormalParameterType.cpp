#include "NodeId.h"
#include "ByValueFormalParameterType.h"

ByValueFormalParameterType::ByValueFormalParameterType()
{
	//
}

ByValueFormalParameterType::~ByValueFormalParameterType()
{
	//
}

void
ByValueFormalParameterType::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::BY_VALUE_FORMAL_PARAMETER_TYPE);
	FormalParameterType::identify(id);
}

void
ByValueFormalParameterType::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "ByValueFormalParameterType");
	//addMember(elem, "locationInfo", locationInfo);
}
