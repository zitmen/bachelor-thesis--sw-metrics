#include "NodeId.h"
#include "TypeQualifiedIdentifierReference.h"
#include "IdentifierReference.h"
#include "TypeReference.h"

TypeQualifiedIdentifierReference::TypeQualifiedIdentifierReference()
{
	member = NULL;
}

TypeQualifiedIdentifierReference::~TypeQualifiedIdentifierReference()
{
	if(member) delete member;
	//
	for(size_t i = 0, im = aggregateType.size(); i < im; ++i)
		if(aggregateType[i])
			delete aggregateType[i];
	//
	aggregateType.clear();
}

void
TypeQualifiedIdentifierReference::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::TYPE_QUALIFIED_IDENTIFIER_REFERENCE);
	NameReference::identify(id);
}

void
TypeQualifiedIdentifierReference::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "TypeQualifiedIdentifierReference");
	addMember(elem, "name", name);
	//addMember(elem, "member", member);
	//addMember(elem, "refersTo", referesTo);
	//addMember(elem, "expressionType", expressionType);
	//addMember(elem, "aggregateType", aggregateType);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
