#include "NodeId.h"
#include "CompilationUnit.h"
#include "ProgramScope.h"
#include "DefinitionUnit.h"
#include "SourceFile.h"

CompilationUnit::CompilationUnit()
{
	opensScope = NULL;
	srcFile = NULL;
	fragments = NULL;
}

CompilationUnit::~CompilationUnit()
{
	if(opensScope) delete opensScope;
	if(srcFile) delete srcFile;
	if(fragments)
	{
		for(size_t i = 0, im = fragments->size(); i < im; ++i)
			if(fragments->at(i))
				delete fragments->at(i);
		//
		fragments->clear();
		delete fragments;
	}
}

void
CompilationUnit::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::COMPILATION_UNIT);
	OtherSyntaxObject::identify(id);
}

void
CompilationUnit::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "CompilationUnit");
	addMember(elem, "language", language);
	addMember(elem, "srcFile", srcFile);
	addMember(elem, "opensScope", opensScope);
	addMember(elem, "fragments", (std::vector<GASTMObject *> *)fragments);
}
