#include "NodeId.h"
#include "DefinitionUnit.h"

DefinitionUnit::DefinitionUnit()
{
	//
}

DefinitionUnit::~DefinitionUnit()
{
	//
}

void
DefinitionUnit::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::DEFINITION_UNIT);
	GASTMSyntaxObject::identify(id);
}
