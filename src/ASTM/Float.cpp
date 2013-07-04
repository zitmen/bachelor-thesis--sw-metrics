#include "NodeId.h"
#include "Float.h"

Float::Float()
{
	//
}

Float::~Float()
{
	//
}

void
Float::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::FLOAT);
	PrimitiveType::identify(id);
}

void
Float::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Float");
	addMember(elem, "isConst", isConst);
	addMember(elem, "isSigned", isSigned);
	addMember(elem, "isVolatile", isVolatile);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
