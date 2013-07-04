#include "NodeId.h"
#include "LongInteger.h"

LongInteger::LongInteger()
{
	//
}

LongInteger::~LongInteger()
{
	//
}

void
LongInteger::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::LONG_INTEGER);
	PrimitiveType::identify(id);
}

void
LongInteger::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "LongInteger");
	addMember(elem, "isConst", isConst);
	addMember(elem, "isSigned", isSigned);
	addMember(elem, "isVolatile", isVolatile);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
