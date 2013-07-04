#ifndef _SMES_MODULE_API_H_
#define _SMES_MODULE_API_H_

#include "../ASTM/ASTM.h"
#include "../ASTM/Node.h"

class ModuleApi
{
	protected:
		static void findInDefinitions(int needle, std::vector<DefinitionUnit *> *haystack, std::vector<GASTMObject *> *out);
		
	public:
		static void statm2block(Statement *statm, BlockStatement *block);
		static void findFunctionsInFile(CompilationUnit *unit, std::vector<FunctionDefinition *> &functions);
		static void findClassesInFile(CompilationUnit *unit, std::vector<AggregateTypeDefinition *> &classes);
		static void findInScope(int needle, Scope *haystack, std::vector<DefinitionUnit *> *declsOrDefns, bool recursive = true);
		static void getDepthOfInharitanceTree(ClassType *c, int &depth);
		static void getFullName(DefinitionUnit *d, std::string &name, int level = 0);
		static bool typesEqual(TypeReference *t1, TypeReference *t2);
		static bool functionsEqual(FunctionDeclaration *fn1, FunctionDeclaration *fn2);
		static bool attributesEqual(VariableDeclaration *attr1, VariableDeclaration *attr2);
		static void getAllMembers(ClassType *c, std::vector<Declaration *> &methods, bool root = true);
};

#endif	// _SMES_MODULE_API_H_
