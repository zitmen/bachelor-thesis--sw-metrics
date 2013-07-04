#include "NodeId.h"
#include "LongLong.h"

LongLong::LongLong()
{
	//
}

LongLong::~LongLong()
{
	//
}

void
LongLong::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::LONG_LONG);
	PrimitiveType::identify(id);
}

void
LongLong::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "LongLong");
	addMember(elem, "isConst", isConst);
	addMember(elem, "isSigned", isSigned);
	addMember(elem, "isVolatile", isVolatile);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
