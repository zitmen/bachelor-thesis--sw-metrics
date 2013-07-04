#include "NodeId.h"
#include "RangeType.h"
#include "Expression.h"

RangeType::RangeType()
{
	//
}

RangeType::~RangeType()
{
	//
}

void
RangeType::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::RANGE_TYPE);
	ConstructedType::identify(id);
}

void
RangeType::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "RangeType");
	addMember(elem, "isConst", isConst);
	addMember(elem, "isVolatile", isVolatile);
	//addMember(elem, "baseType", baseType);
	addMember(elem, "lowBound", lowBound);
	addMember(elem, "highBound", highBound);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
