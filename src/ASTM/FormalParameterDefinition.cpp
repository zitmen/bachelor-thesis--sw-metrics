#include "NodeId.h"
#include "FormalParameterDefinition.h"

FormalParameterDefinition::FormalParameterDefinition()
{
	//
}

FormalParameterDefinition::~FormalParameterDefinition()
{
	//
}


void
FormalParameterDefinition::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::FORMAL_PARAMETER_DEFINITION);
	DataDefinition::identify(id);
}

void
FormalParameterDefinition::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "FormalParameterDefinition");
	addMember(elem, "accessKind", accessKind);
	addMember(elem, "isMutable", isMutable);
	addMember(elem, "isRegister", isRegister);
	addMember(elem, "linkageSpecifier", linkageSpecifier);
	addMember(elem, "storageSpecifiers", storageSpecifiers);
	addMember(elem, "type", type);
	addMember(elem, "identifierName", identifierName);
	addMember(elem, "initialValue", initialValue);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
