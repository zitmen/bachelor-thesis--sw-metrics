#include "NodeId.h"
#include "DataDefinition.h"

DataDefinition::DataDefinition()
{
	isMutable = false;
	//
	initialValue = NULL;
}

DataDefinition::~DataDefinition()
{
	if(initialValue) delete initialValue;
}

void
DataDefinition::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::DATA_DEFINITION);
	Definition::identify(id);
}
