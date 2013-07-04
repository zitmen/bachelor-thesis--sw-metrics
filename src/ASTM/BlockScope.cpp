#include "NodeId.h"
#include "BlockScope.h"

BlockScope::BlockScope()
{
	//
}

BlockScope::~BlockScope()
{
	//
}

void
BlockScope::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::BLOCK_SCOPE);
	Scope::identify(id);
}

void
BlockScope::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "BlockScope");
	addMember(elem, "definitionObject", (std::vector<GASTMObject *> *)definitionObject);
	addMember(elem, "childScope", (std::vector<GASTMObject *> *)childScope);
	//addMember(elem, "parentScope", parentScope);
}
