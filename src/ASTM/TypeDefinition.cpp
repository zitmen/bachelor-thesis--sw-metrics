#include "NodeId.h"
#include "TypeDefinition.h"

TypeDefinition::TypeDefinition()
{
	name = NULL;
}

TypeDefinition::~TypeDefinition()
{
	if(name) delete name;
}

void
TypeDefinition::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::TYPE_DEFINITION);
	DefinitionUnit::identify(id);
}

void
TypeDefinition::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "TypeDefinition");
	addMember(elem, "name", name);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
