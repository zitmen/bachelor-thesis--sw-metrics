#include "NodeId.h"
#include "VariableDefinition.h"

VariableDefinition::VariableDefinition()
{
	//
}

VariableDefinition::~VariableDefinition()
{
	//
}

void
VariableDefinition::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::VARIABLE_DEFINITION);
	DataDefinition::identify(id);
}

void
VariableDefinition::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "VariableDefinition");
	addMember(elem, "isMutable", isMutable);
	addMember(elem, "isRegister", isRegister);
	addMember(elem, "linkageSpecifier", linkageSpecifier);
	addMember(elem, "storageSpecifiers", storageSpecifiers);
	addMember(elem, "accessKind", accessKind);
	//addMember(elem, "declRef", declRef);
	addMember(elem, "type", type);
	addMember(elem, "identifierName", identifierName);
	addMember(elem, "initialValue", initialValue);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
