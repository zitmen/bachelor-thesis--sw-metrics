#include "NodeId.h"
#include "WideCharacter.h"

WideCharacter::WideCharacter()
{
	//
}

WideCharacter::~WideCharacter()
{
	//
}

void
WideCharacter::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::WIDE_CHARACTER);
	PrimitiveType::identify(id);
}

void
WideCharacter::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "WideCharacter");
	addMember(elem, "isConst", isConst);
	addMember(elem, "isSigned", isSigned);
	addMember(elem, "isVolatile", isVolatile);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
