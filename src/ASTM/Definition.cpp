#include "NodeId.h"
#include "Definition.h"

Definition::Definition()
{
	declRef = NULL;
}

Definition::~Definition()
{
	//if(declRef) delete declRef;
}

void
Definition::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::DEFINITION);
	DeclarationOrDefinition::identify(id);
}
