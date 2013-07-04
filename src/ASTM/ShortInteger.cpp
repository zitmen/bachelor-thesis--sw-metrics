#include "NodeId.h"
#include "ShortInteger.h"

ShortInteger::ShortInteger()
{
	//
}

ShortInteger::~ShortInteger()
{
	//
}

void
ShortInteger::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::SHORT_INTEGER);
	PrimitiveType::identify(id);
}

void
ShortInteger::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "ShortInteger");
	addMember(elem, "isConst", isConst);
	addMember(elem, "isSigned", isSigned);
	addMember(elem, "isVolatile", isVolatile);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
