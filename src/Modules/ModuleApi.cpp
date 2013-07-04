#include "ModuleApi.h"

void
ModuleApi::findInDefinitions(int needle, std::vector<DefinitionUnit *> *haystack, std::vector<GASTMObject *> *out)
{
	if(!haystack) return;
	if(!out) return;
	//
	static Node nodeId;
	//
	for(size_t i = 0, im = haystack->size(); i < im; ++i)
	{
		nodeId.setNode(haystack->at(i));
		//
		if(nodeId == needle)
		{
			out->push_back((Definition *)haystack->at(i));
		}
		//
		if(nodeId == NodeId::FUNCTION_DEFINITION)
		{
			//findInDefinitions(needle, ((FunctionDefinition *)haystack->at(i))->body, out);
		}
		else if(nodeId == NodeId::NAME_SPACE_DEFINITION)
		{
			findInDefinitions(needle, ((NameSpaceDefinition *)haystack->at(i))->body, out);
		}
		else if(nodeId == NodeId::AGGREGATE_TYPE_DEFINITION)
		{
			AggregateType *type = ((AggregateTypeDefinition *)haystack->at(i))->aggregateType;
			nodeId.setNode(type);
			if(nodeId == needle)
				out->push_back((AggregateTypeDefinition *)haystack->at(i));
			//
			findInDefinitions(needle, type->members, out);
		}
	}
}

void
ModuleApi::findInScope(int needle, Scope *haystack, std::vector<DefinitionUnit *> *declsOrDefns, bool recursive)
{
	if(!haystack) return;
	if(!declsOrDefns) return;
	//
	static Node nodeId;
	//
	for(size_t i = 0, im = haystack->definitionObject->size(); i < im; ++i)
	{
		nodeId.setNode(haystack->definitionObject->at(i));
		//
		if(nodeId == needle)
		{
			declsOrDefns->push_back(haystack->definitionObject->at(i));
		}
	}
	//
	if(recursive)
	{
		for(size_t i = 0, im = haystack->childScope->size(); i < im; ++i)
		{
			findInScope(needle, haystack->childScope->at(i), declsOrDefns, recursive);
		}
	}
}

void
ModuleApi::statm2block(Statement *statm, BlockStatement *block)
{
	static Node nodeId;
	//
	block->subStatements->clear();
	if(statm == NULL) return;
	//
	nodeId.setNode(statm);
	if(nodeId == NodeId::BLOCK_STATEMENT)
	{
		if(((BlockStatement *)statm)->subStatements)
			block->subStatements->operator=(*(((BlockStatement *)statm)->subStatements));
	}
	else
		block->subStatements->push_back(statm);
}

void
ModuleApi::findFunctionsInFile(CompilationUnit *unit, std::vector<FunctionDefinition *> &functions)
{
	if(!unit) return;
	if(!unit->fragments) return;
	//
	findInDefinitions(NodeId::FUNCTION_DEFINITION, unit->fragments, (std::vector<GASTMObject *> *)&functions);
}

void
ModuleApi::findClassesInFile(CompilationUnit *unit, std::vector<AggregateTypeDefinition *> &classes)
{
	if(!unit) return;
	if(!unit->fragments) return;
	//
	findInDefinitions(NodeId::CLASS_TYPE, unit->fragments, (std::vector<GASTMObject *> *)&classes);
}

void
ModuleApi::getDepthOfInharitanceTree(ClassType *c, int &depth)
{
	static Node nodeId;
	//
	if(!c) return;
	nodeId.setNode(c);
	if(nodeId != NodeId::CLASS_TYPE) return;
	//
	depth += 1;
	//
	if(!c->derivesFrom) return;
	for(size_t i = 0, im = c->derivesFrom->size(); i < im; ++i)
	{
		getDepthOfInharitanceTree((ClassType *)c->derivesFrom->at(0)->className->body, depth);
	}
}

void
ModuleApi::getFullName(DefinitionUnit *d, std::string &name, int level)
{
	using namespace NodeId;
	Node nodeId;
	//
	if(!d) return;
	nodeId.setNode(d);
	if(nodeId != DEFINITION_UNIT) return;
	//
	if(d->parent)
		getFullName((DefinitionUnit *)d->parent, name, level + 1);
	//
	if(nodeId == NAME_SPACE_DEFINITION)
	{
		if(((NameSpaceDefinition *)d)->nameSpace)
			name += ((NameSpaceDefinition *)d)->nameSpace->nameString + ((level > 0) ? "::" : "");
	}
	else if(nodeId == AGGREGATE_TYPE_DEFINITION)
	{
		if(((AggregateTypeDefinition *)d)->name)
			name += ((AggregateTypeDefinition *)d)->name->nameString + ((level > 0) ? "::" : "");
	}
	else if(nodeId == TYPE_DEFINITION)
	{
		if(((TypeDefinition *)d)->name)
			name += ((TypeDefinition *)d)->name->nameString;
	}
	else if(nodeId == DECLARATION_OR_DEFINITION)
	{
		if(((DeclarationOrDefinition *)d)->identifierName)
			name += ((DeclarationOrDefinition *)d)->identifierName->nameString;
	}
}

bool
ModuleApi::typesEqual(TypeReference *t1, TypeReference *t2)
{
	static Node hlp1, hlp2;
	//
	// input
	if(!t1 || !t2) return false;
	hlp1.setNode(t1);
	hlp2.setNode(t2);
	if(hlp1 != hlp2)
		return false;
	//
	// reference type
	if(hlp1 == NodeId::UNNAMED_TYPE_REFERENCE)
	{
		Type *type1 = ((UnnamedTypeReference *)t1)->type;
		Type *type2 = ((UnnamedTypeReference *)t2)->type;
		if(!type1 || !type2)
			return false;
		//
		hlp1.setNode(type1);
		hlp2.setNode(type2);
		//
		// primitive data types
		if(hlp1 == NodeId::PRIMITIVE_TYPE)
		{
			if(hlp1 != hlp2)	// f.e. INTEGER, CHAR, ...
				return false;
		}
		else
		{
			// TODO: other types
			return false;
		}
	}
	else if(hlp1 == NodeId::NAMED_TYPE_REFERENCE)
	{
		// type name
		if(!((NamedTypeReference *)t1)->aType->name || !((NamedTypeReference *)t2)->name)
			return false;
		//
		if(((NamedTypeReference *)t1)->aType->name->nameString != ((NamedTypeReference *)t2)->aType->name->nameString)
			return false;
		//
		// data type
		TypeDefinition *type1 = ((NamedTypeReference *)t1)->aType;
		TypeDefinition *type2 = ((NamedTypeReference *)t2)->aType;
		if(!type1 || !type2)
			return false;
		//
		//hlp1.setNode(type1);
		//hlp2.setNode(type2);
		//if(hlp1 != hlp2)	// TypeDefinition <-- AggregateTypeDefinition or NamedTypeDefinition
		//	return false;
		//
		if(type1 != type2)	// pointers should refer to the same definition
			return false;
	}
	else
		return false;
	//
	return true;
}

bool
ModuleApi::attributesEqual(VariableDeclaration *attr1, VariableDeclaration *attr2)
{
	static Node hlp1, hlp2;
	//
	// input
	if(!attr1 || !attr2) return false;
	hlp1.setNode(attr1);
	hlp2.setNode(attr2);
	if(hlp1 != NodeId::VARIABLE_DECLARATION) return false;
	if(hlp2 != NodeId::VARIABLE_DECLARATION) return false;
	//
	// pointers to the same attribute?
	if(attr1 == attr2) return true;
	//
	// attribute name
	if(!attr1->identifierName || !attr2->identifierName) return false;
	if(attr1->identifierName->nameString != attr2->identifierName->nameString)
		return false;
	//
	return true;
}

bool
ModuleApi::functionsEqual(FunctionDeclaration *fn1, FunctionDeclaration *fn2)
{
	static Node hlp1, hlp2;
	//
	// input
	if(!fn1 || !fn2) return false;
	hlp1.setNode(fn1);
	hlp2.setNode(fn2);
	if(hlp1 != NodeId::FUNCTION_DECLARATION) return false;
	if(hlp2 != NodeId::FUNCTION_DECLARATION) return false;
	//
	// pointers to the same function?
	if(fn1 == fn2) return true;
	//
	// function name
	if(!fn1->identifierName || !fn2->identifierName) return false;
	if(fn1->identifierName->nameString != fn2->identifierName->nameString)
		return false;
	//
	// return type - in C++ doesn't matter on the return type
	//if(!typesEqual(fn1->type, fn2->type))
	//	return false;
	//
	// parameters?
	if(fn1->formalParameters)
	{
		if(!fn2->formalParameters)
			return false;
		//
		// parameters count
		if(fn1->formalParameters->size() != fn2->formalParameters->size())
			return false;
		//
		// parameters types
		for(size_t i = 0, im = fn1->formalParameters->size(); i < im; ++i)
		{
			if(!typesEqual(fn1->formalParameters->at(i)->type, fn2->formalParameters->at(i)->type))
				return false;
		}
	}
	else if(fn2->formalParameters)
		return false;
	//
	return true;
}

void
ModuleApi::getAllMembers(ClassType *c, std::vector<Declaration *> &members, bool root)
{
	static Node nodeId;
	if(!c) return;
	nodeId.setNode(c);
	if(nodeId != NodeId::CLASS_TYPE) return;
	//
	if(c->derivesFrom)
	{
		for(size_t i = 0, im = c->derivesFrom->size(); i < im; ++i)
		{
			if(c->derivesFrom->at(i)->accessKind)
			{
				nodeId.setNode(c->derivesFrom->at(i)->accessKind);
				if(nodeId != NodeId::PRIVATE)
				{
					getAllMembers((ClassType *)c->derivesFrom->at(i)->className->body, members, false);
				}
			}
		}
	}
	//
	if(!c->members) return;
	bool add_member = true;
	for(size_t i = 0, im = c->members->size(); i < im; ++i, add_member = true)
	{
		nodeId.setNode(c->members->at(i));
		if((nodeId == NodeId::FUNCTION_DEFINITION) || (nodeId == NodeId::FUNCTION_DECLARATION) || (nodeId == NodeId::VARIABLE_DECLARATION))
		{
			if(((DeclarationOrDefinition *)c->members->at(i))->accessKind)
			{
				nodeId.setNode(((DeclarationOrDefinition *)c->members->at(i))->accessKind);
				if(!root)
				{
					if(nodeId == NodeId::PRIVATE)
					{
						add_member = false;
					}
				}
				//
				if(add_member)
				{
					nodeId.setNode(c->members->at(i));
					if(nodeId == NodeId::VARIABLE_DECLARATION)
					{
						// remove overridden attributes
						for(std::vector<Declaration *>::iterator it = members.begin(); it != members.end(); /*++it*/)
						{
							if(attributesEqual((VariableDeclaration *)*it, (VariableDeclaration *)c->members->at(i)))
								members.erase(it);	// does ++it as default
							else
								++it;
						}
						//
						// add new attribute
						members.push_back((VariableDeclaration *)c->members->at(i));
					}
					else
					{
						FunctionDeclaration *tmpDecl;
						if(nodeId == NodeId::FUNCTION_DEFINITION)
							tmpDecl = (FunctionDeclaration *)((FunctionDefinition *)c->members->at(i))->declRef;
						else
							tmpDecl = (FunctionDeclaration *)c->members->at(i);
						//
						// remove overridden methods
						for(std::vector<Declaration *>::iterator it = members.begin(); it != members.end(); /*++it*/)
						{
							if(functionsEqual((FunctionDeclaration *)*it, tmpDecl))
								members.erase(it);	// does ++it as default
							else
								++it;
						}
						//
						// add new method
						members.push_back(tmpDecl);
					}
				}
			}
		}
	}
}
