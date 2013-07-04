#include "NodeId.h"
#include "AggregateTypeDefinition.h"
#include "AggregateType.h"

AggregateTypeDefinition::AggregateTypeDefinition()
{
	aggregateType = NULL;
}

AggregateTypeDefinition::~AggregateTypeDefinition()
{
	if(aggregateType) delete aggregateType;
}

void
AggregateTypeDefinition::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::AGGREGATE_TYPE_DEFINITION);
	TypeDefinition::identify(id);
}

void
AggregateTypeDefinition::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "AggregateTypeDefinition");
	addMember(elem, "name", name);
	addMember(elem, "aggregateType", aggregateType);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
