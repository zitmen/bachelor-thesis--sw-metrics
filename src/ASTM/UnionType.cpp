#include "NodeId.h"
#include "UnionType.h"

UnionType::UnionType()
{
	//
}

UnionType::~UnionType()
{
	//
}

void
UnionType::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::UNION_TYPE);
	AggregateType::identify(id);
}

void
UnionType::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "UnionType");
	addMember(elem, "isConst", isConst);
	addMember(elem, "isVolatile", isVolatile);
	addMember(elem, "members", (std::vector<GASTMObject *> *)&members);
	//addMember(elem, "opensScope", opensScope);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
