#include "NodeId.h"
#include "Type.h"

Type::Type()
{
	isVolatile = false;
	isConst = false;
}

Type::~Type()
{
	//
}

void
Type::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::TYPE);
	GASTMSyntaxObject::identify(id);
}

void
Type::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Type");
	addMember(elem, "isConst", isConst);
	addMember(elem, "isVolatile", isVolatile);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
