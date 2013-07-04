#include "NodeId.h"
#include "ConstructedType.h"
#include "TypeReference.h"

ConstructedType::ConstructedType()
{
	baseType = NULL;
}

ConstructedType::~ConstructedType()
{
	if(baseType) delete baseType;
}

void
ConstructedType::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::CONSTRUCTED_TYPE);
	DataType::identify(id);
}
