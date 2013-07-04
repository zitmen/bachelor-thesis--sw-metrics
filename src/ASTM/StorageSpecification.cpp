#include "NodeId.h"
#include "StorageSpecification.h"

StorageSpecification::StorageSpecification()
{
	//
}

StorageSpecification::~StorageSpecification()
{
	//
}

void
StorageSpecification::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::STORAGE_SPECIFICATION);
	OtherSyntaxObject::identify(id);
}
