#include "NodeId.h"
#include "NameReference.h"

NameReference::NameReference()
{
	name = NULL;
	refersTo = NULL;
}

NameReference::~NameReference()
{
	if(name) delete name;
}

void
NameReference::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::NAME_REFERENCE);
	Expression::identify(id);
}
