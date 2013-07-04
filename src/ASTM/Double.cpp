#include "NodeId.h"
#include "Double.h"

Double::Double()
{
	//
}

Double::~Double()
{
	//
}

void
Double::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::DOUBLE);
	PrimitiveType::identify(id);
}

void
Double::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Double");
	addMember(elem, "isConst", isConst);
	addMember(elem, "isSigned", isSigned);
	addMember(elem, "isVolatile", isVolatile);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
