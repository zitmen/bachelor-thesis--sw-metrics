#include "NodeId.h"
#include "GlobalScope.h"

GlobalScope::GlobalScope()
{
	//
}

GlobalScope::~GlobalScope()
{
	//
}

void
GlobalScope::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::GLOBAL_SCOPE);
	Scope::identify(id);
}

void
GlobalScope::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "GlobalScope");
	//addMember(elem, "definitionObject", (std::vector<GASTMObject *> *)definitionObject);
	//addMember(elem, "childScope", (std::vector<GASTMObject *> *)childScope);
	//addMember(elem, "parentScope", parentScope);
}
