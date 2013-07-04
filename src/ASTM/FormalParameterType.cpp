#include "NodeId.h"
#include "FormalParameterType.h"
#include "TypeReference.h"

FormalParameterType::FormalParameterType()
{
	type = NULL;
}

FormalParameterType::~FormalParameterType()
{
	if(type) delete type;
}

void
FormalParameterType::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::FORMAL_PARAMETER_TYPE);
	DataType::identify(id);
}
