#include "NodeId.h"
#include "Project.h"
#include "GlobalScope.h"
#include "CompilationUnit.h"

Project::Project()
{
	outerScope = NULL;
}

Project::~Project()
{
	if(outerScope) delete outerScope;
	//
	for(size_t i = 0, im = files.size(); i < im; ++i)
		if(files[i])
			delete files[i];
	//
	files.clear();
}

void
Project::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::PROJECT);
	GASTMSemanticObject::identify(id);
}

void
Project::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Project");
	//addMember(elem, "outerScope", outerScope);
	addMember(elem, "files", (std::vector<GASTMObject *> *)&files);
}
