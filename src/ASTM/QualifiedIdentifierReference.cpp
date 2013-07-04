#include "NodeId.h"
#include "QualifiedIdentifierReference.h"
#include "IdentifierReference.h"

QualifiedIdentifierReference::QualifiedIdentifierReference()
{
	qualifiers = NULL;
	member = NULL;
}

QualifiedIdentifierReference::~QualifiedIdentifierReference()
{
	if(qualifiers) delete qualifiers;
	if(member) delete member;
}

void
QualifiedIdentifierReference::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::QUALIFIED_IDENTIFIER_REFERENCE);
	NameReference::identify(id);
}
