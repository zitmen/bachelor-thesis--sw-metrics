#include "NodeId.h"
#include "Byte.h"

Byte::Byte()
{
	//
}

Byte::~Byte()
{
	//
}

void
Byte::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::BYTE);
	PrimitiveType::identify(id);
}

void
Byte::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Byte");
	addMember(elem, "isConst", isConst);
	addMember(elem, "isSigned", isSigned);
	addMember(elem, "isVolatile", isVolatile);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
