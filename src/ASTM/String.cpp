#include "NodeId.h"
#include "String.h"

String::String()
{
	//
}

String::~String()
{
	//
}

void
String::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::STRING);
	PrimitiveType::identify(id);
}

void
String::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "String");
	addMember(elem, "isConst", isConst);
	addMember(elem, "isSigned", isSigned);
	addMember(elem, "isVolatile", isVolatile);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
