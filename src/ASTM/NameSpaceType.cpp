#include "NodeId.h"
#include "NameSpaceType.h"

NameSpaceType::NameSpaceType()
{
	//
}

NameSpaceType::~NameSpaceType()
{
	//
}

void
NameSpaceType::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::NAME_SPACE_TYPE);
	Type::identify(id);
}

void
NameSpaceType::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "NameSpaceType");
	addMember(elem, "isConst", isConst);
	addMember(elem, "isVolatile", isVolatile);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
