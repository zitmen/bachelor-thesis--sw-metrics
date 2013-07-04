#include "NodeId.h"
#include "Integer.h"

Integer::Integer()
{
	//
}

Integer::~Integer()
{
	//
}

void
Integer::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::INTEGER);
	PrimitiveType::identify(id);
}

void
Integer::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Integer");
	addMember(elem, "isConst", isConst);
	addMember(elem, "isSigned", isSigned);
	addMember(elem, "isVolatile", isVolatile);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
