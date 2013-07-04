#include "NodeId.h"
#include "Boolean.h"

Boolean::Boolean()
{
	//
}

Boolean::~Boolean()
{
	//
}

void
Boolean::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::BOOLEAN);
	PrimitiveType::identify(id);
}

void
Boolean::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Boolean");
	addMember(elem, "isConst", isConst);
	addMember(elem, "isSigned", isSigned);
	addMember(elem, "isVolatile", isVolatile);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
