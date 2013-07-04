#include "NodeId.h"
#include "ProgramScope.h"

ProgramScope::ProgramScope()
{
	//
}

ProgramScope::~ProgramScope()
{
	//
}

void
ProgramScope::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::PROGRAM_SCOPE);
	Scope::identify(id);
}

void
ProgramScope::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "ProgramScope");
	//addMember(elem, "definitionObject", (std::vector<GASTMObject *> *)definitionObject);
	//addMember(elem, "childScope", (std::vector<GASTMObject *> *)childScope);
	//addMember(elem, "parentScope", parentScope);
}
