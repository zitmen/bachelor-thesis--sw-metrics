#include "NodeId.h"
#include "ByReferenceFormalParameterType.h"

ByReferenceFormalParameterType::ByReferenceFormalParameterType()
{
	//
}

ByReferenceFormalParameterType::~ByReferenceFormalParameterType()
{
	//
}

void
ByReferenceFormalParameterType::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::BY_REFERENCE_FORMAL_PARAMETER_TYPE);
	FormalParameterType::identify(id);
}

void
ByReferenceFormalParameterType::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "ByReferenceFormalParameterType");
	//addMember(elem, "locationInfo", locationInfo);
}
