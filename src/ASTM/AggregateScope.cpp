#include "NodeId.h"
#include "AggregateScope.h"

AggregateScope::AggregateScope()
{
	//
}

AggregateScope::~AggregateScope()
{
	//
}

void
AggregateScope::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::AGGREGATE_SCOPE);
	Scope::identify(id);
}

void
AggregateScope::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "AggregateScope");
	//addMember(elem, "parentScope", parentScope);
	addMember(elem, "childScope", (std::vector<GASTMObject *> *)childScope);
	addMember(elem, "definitionObject", (std::vector<GASTMObject *> *)definitionObject);
}
