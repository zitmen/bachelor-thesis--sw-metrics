#include "NodeId.h"
#include "VariableDeclaration.h"

VariableDeclaration::VariableDeclaration()
{
	isMutable = false;
}

VariableDeclaration::~VariableDeclaration()
{
	//
}

void
VariableDeclaration::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::VARIABLE_DECLARATION);
	Declaration::identify(id);
}

void
VariableDeclaration::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "VariableDeclaration");
	addMember(elem, "isMutable", isMutable);
	addMember(elem, "isRegister", isRegister);
	addMember(elem, "linkageSpecifier", linkageSpecifier);
	addMember(elem, "storageSpecifiers", storageSpecifiers);
	addMember(elem, "accessKind", accessKind);
	//addMember(elem, "defRef", defRef);
	addMember(elem, "type", type);
	addMember(elem, "identifierName", identifierName);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
