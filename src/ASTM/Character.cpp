#include "NodeId.h"
#include "Character.h"

Character::Character()
{
	//
}

Character::~Character()
{
	//
}

void
Character::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::CHARACTER);
	PrimitiveType::identify(id);
}

void
Character::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Character");
	addMember(elem, "isConst", isConst);
	addMember(elem, "isSigned", isSigned);
	addMember(elem, "isVolatile", isVolatile);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
