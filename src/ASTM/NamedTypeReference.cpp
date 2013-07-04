#include "NodeId.h"
#include "NamedTypeReference.h"
#include "Name.h"
#include "TypeDefinition.h"

NamedTypeReference::NamedTypeReference()
{
	name = NULL;
	aType = NULL;
}

NamedTypeReference::~NamedTypeReference()
{
	if(name) delete name;
	//if(aType) delete aType;	// this is reference, so it's deleted somewhere else
}

void
NamedTypeReference::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::NAMED_TYPE_REFERENCE);
	TypeReference::identify(id);
}

void
NamedTypeReference::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "NamedTypeReference");
	addMember(elem, "aType", aType);
	//addMember(elem, "locationInfo", locationInfo);
}
