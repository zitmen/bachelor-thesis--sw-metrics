#include "NodeId.h"
#include "Void.h"

Void::Void()
{
	//
}

Void::~Void()
{
	//
}

void
Void::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::VOID);
	PrimitiveType::identify(id);
}

void
Void::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Void");
	addMember(elem, "isConst", isConst);
	addMember(elem, "isSigned", isSigned);
	addMember(elem, "isVolatile", isVolatile);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
