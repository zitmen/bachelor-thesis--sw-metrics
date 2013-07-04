#include "NodeId.h"
#include "LongDouble.h"

LongDouble::LongDouble()
{
	//
}

LongDouble::~LongDouble()
{
	//
}

void
LongDouble::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::LONG_DOUBLE);
	PrimitiveType::identify(id);
}

void
LongDouble::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "LongDouble");
	addMember(elem, "isConst", isConst);
	addMember(elem, "isSigned", isSigned);
	addMember(elem, "isVolatile", isVolatile);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
