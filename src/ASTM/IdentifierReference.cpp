#include "NodeId.h"
#include "IdentifierReference.h"

IdentifierReference::IdentifierReference()
{
	//
}

IdentifierReference::~IdentifierReference()
{
	//
}

void
IdentifierReference::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::IDENTIFIER_REFERENCE);
	NameReference::identify(id);
}

void
IdentifierReference::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "IdentifierReference");
	addMember(elem, "name", name);
	//addMember(elem, "refersTo", refersTo);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
