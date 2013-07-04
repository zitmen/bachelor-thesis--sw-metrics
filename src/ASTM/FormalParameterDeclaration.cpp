#include "NodeId.h"
#include "FormalParameterDeclaration.h"

FormalParameterDeclaration::FormalParameterDeclaration()
{
	//
}

FormalParameterDeclaration::~FormalParameterDeclaration()
{
	//
}

void
FormalParameterDeclaration::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::FORMAL_PARAMETER_DECLARATION);
	Declaration::identify(id);
}

void
FormalParameterDeclaration::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "FormalParameterDeclaration");
	addMember(elem, "accessKind", accessKind);
	addMember(elem, "isRegister", isRegister);
	addMember(elem, "linkageSpecifier", linkageSpecifier);
	addMember(elem, "storageSpecifiers", storageSpecifiers);
	addMember(elem, "type", type);
	addMember(elem, "identifierName", identifierName);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
