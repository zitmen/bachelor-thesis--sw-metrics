#include "NodeId.h"
#include "Scope.h"
#include "DefinitionUnit.h"

#include <algorithm>

Scope::Scope()
{
	parentScope = NULL;
	childScope = NULL;
	definitionObject = NULL;
}

Scope::~Scope()
{
	//if(parentScope) delete parentScope;	// don't delete because object is already assigned to another node
	//
	if(childScope)
	{
		// don't delete because objects are already assigned to another nodes
		/*
		for(size_t i = 0, im = childScope->size(); i < im; ++i)
			if(childScope->at(i))
				delete childScope->at(i);
		*/
		//
		childScope->clear();
		delete childScope;
	}
	//
	if(definitionObject)
	{
		// don't delete because objects are already assigned to another nodes
		/*
		for(size_t i = 0, im = definitionObject->size(); i < im; ++i)
			if(definitionObject->at(i))
				delete definitionObject->at(i);
		*/
		//
		definitionObject->clear();
		delete definitionObject;
	}
}

void
Scope::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::SCOPE);
	GASTMSemanticObject::identify(id);
}

void
Scope::addChildScope(Scope *scope)
{
	if(!childScope)
	{
		childScope = new std::vector<Scope *>;
	}
	childScope->push_back(scope);
	scope->parentScope = this;
}

bool
Scope::removeChildScope(Scope *scope)
{
	if(!childScope)
	{
		return false;
	}
	std::vector<Scope *>::iterator it = std::find(childScope->begin(), childScope->end(), scope);
	if(it != childScope->end())
	{
		while(it != childScope->end())
		{
			childScope->erase(it);
			it = std::find(childScope->begin(), childScope->end(), scope);
		}
		return true;
	}
	return false;
}


void
Scope::addScopeMember(DefinitionUnit *d)
{
	if(!definitionObject)
	{
		definitionObject = new std::vector<DefinitionUnit *>;
	}
	definitionObject->push_back(d);
}

bool
Scope::removeScopeMember(DefinitionUnit *d)
{
	if(!definitionObject)
	{
		return false;
	}
	std::vector<DefinitionUnit *>::iterator it = std::find(definitionObject->begin(), definitionObject->end(), d);
	if(it != definitionObject->end())
	{
		while(it != definitionObject->end())
		{
			definitionObject->erase(it);
			it = std::find(definitionObject->begin(), definitionObject->end(), d);
		}
		return true;
	}
	return false;
}
