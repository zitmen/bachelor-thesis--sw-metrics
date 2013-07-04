#include "NameSpaceScope.h"
#include "NodeId.h"

NameSpaceScope::NameSpaceScope()
{
	//
}

NameSpaceScope::~NameSpaceScope()
{
	//
}

void
NameSpaceScope::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::NAME_SPACE_SCOPE);
	Scope::identify(id);
}

void
NameSpaceScope::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "NameSpaceScope");
	addMember(elem, "definitionObject", (std::vector<GASTMObject *> *)definitionObject);
	addMember(elem, "childScope", (std::vector<GASTMObject *> *)childScope);
	//addMember(elem, "parentScope", parentScope);
}
