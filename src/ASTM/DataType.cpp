#include "NodeId.h"
#include "DataType.h"

DataType::DataType()
{
	//
}

DataType::~DataType()
{
	//
}

void
DataType::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::DATA_TYPE);
	Type::identify(id);
}
