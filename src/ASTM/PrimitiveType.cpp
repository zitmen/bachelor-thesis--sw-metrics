#include "NodeId.h"
#include "PrimitiveType.h"

PrimitiveType::PrimitiveType()
{
	isSigned = true;
}

PrimitiveType::~PrimitiveType()
{
	//
}

void
PrimitiveType::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::PRIMITIVE_TYPE);
	DataType::identify(id);
}
