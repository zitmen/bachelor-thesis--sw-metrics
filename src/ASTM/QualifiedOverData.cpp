#include "NodeId.h"
#include "QualifiedOverData.h"
#include "IdentifierReference.h"

QualifiedOverData::QualifiedOverData()
{
	//
}

QualifiedOverData::~QualifiedOverData()
{
	//
}

void
QualifiedOverData::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::QUALIFIED_OVER_DATA);
	QualifiedIdentifierReference::identify(id);
}

void
QualifiedOverData::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "QualifiedOverData");
	//addMember(elem, "expressionType", expressionType);
	addMember(elem, "name", name);
	addMember(elem, "member", member);
	addMember(elem, "qualifiers", qualifiers);
	//addMember(elem, "refersTo", refersTo);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
