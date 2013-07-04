#include "NodeId.h"
#include "TypeReference.h"

TypeReference::TypeReference()
{
	//
}

TypeReference::~TypeReference()
{
	//
}

void
TypeReference::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::TYPE_REFERENCE);
	Type::identify(id);
}
