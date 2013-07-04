#include "NodeId.h"
#include "DeclarationOrDefinition.h"

DeclarationOrDefinition::DeclarationOrDefinition()
{
	isRegister = false;
	identifierName = NULL;
	//
	accessKind = NULL;
	storageSpecifiers = NULL;
	type = NULL;
}

DeclarationOrDefinition::~DeclarationOrDefinition()
{
	//if(accessKind) delete accessKind;	// this is shared between all class objects
	if(identifierName) delete identifierName;
	if(storageSpecifiers) delete storageSpecifiers;
	if(type) delete type;
}

void
DeclarationOrDefinition::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::DECLARATION_OR_DEFINITION);
	DefinitionUnit::identify(id);
}
