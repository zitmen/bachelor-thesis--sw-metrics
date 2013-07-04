#include "NodeId.h"
#include "NamedTypeDefinition.h"
#include "NamedType.h"

NamedTypeDefinition::NamedTypeDefinition()
{
	definitionType = NULL;
}

NamedTypeDefinition::~NamedTypeDefinition()
{
	if(definitionType) delete definitionType;
}

void
NamedTypeDefinition::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::NAMED_TYPE_DEFINITION);
	TypeDefinition::identify(id);
}

void
NamedTypeDefinition::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "NamedTypeDefinition");
	//addMember(elem, "locationInfo", locationInfo);
}
