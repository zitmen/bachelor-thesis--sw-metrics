#include "NodeId.h"
#include "AggregateType.h"
#include "DefinitionUnit.h"

AggregateType::AggregateType()
{
	opensScope = NULL;
	members = NULL;
}

AggregateType::~AggregateType()
{
	if(opensScope) delete opensScope;
	if(members)
	{
		for(size_t i = 0, im = members->size(); i < im; ++i)
			if(members->at(i))
				delete members->at(i);
		//
		members->clear();
		delete members;
	}
}

void
AggregateType::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::AGGREGATE_TYPE);
	DataType::identify(id);
}
