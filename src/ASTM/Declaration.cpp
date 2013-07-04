#include "NodeId.h"
#include "Declaration.h"
#include "Definition.h"

Declaration::Declaration()
{
	defRef = NULL;
}

Declaration::~Declaration()
{
	//if(defRef) delete defRef;
}

void
Declaration::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::DECLARATION);
	DeclarationOrDefinition::identify(id);
}
