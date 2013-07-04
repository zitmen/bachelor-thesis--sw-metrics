#include "NodeId.h"
#include "QualifiedOverPointer.h"
#include "IdentifierReference.h"

QualifiedOverPointer::QualifiedOverPointer()
{
	//
}

QualifiedOverPointer::~QualifiedOverPointer()
{
	//
}

void
QualifiedOverPointer::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::QUALIFIED_OVER_POINTER);
	QualifiedIdentifierReference::identify(id);
}

void
QualifiedOverPointer::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "QualifiedOverPointer");
	//addMember(elem, "expressionType", expressionType);
	addMember(elem, "name", name);
	addMember(elem, "member", member);
	addMember(elem, "qualifiers", qualifiers);
	//addMember(elem, "refersTo", refersTo);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
