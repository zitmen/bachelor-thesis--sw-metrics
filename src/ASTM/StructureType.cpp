#include "NodeId.h"
#include "StructureType.h"

StructureType::StructureType()
{
	//
}

StructureType::~StructureType()
{
	//
}

void
StructureType::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::STRUCTURE_TYPE);
	AggregateType::identify(id);
}

void
StructureType::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "StructureType");
	addMember(elem, "isConst", isConst);
	addMember(elem, "isVolatile", isVolatile);
	addMember(elem, "members", (std::vector<GASTMObject *> *)members);
	addMember(elem, "opensScope", opensScope);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
