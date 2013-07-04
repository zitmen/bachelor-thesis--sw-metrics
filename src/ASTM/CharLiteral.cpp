#include "NodeId.h"
#include "CharLiteral.h"

CharLiteral::CharLiteral()
{
	//
}

CharLiteral::~CharLiteral()
{
	//
}

void
CharLiteral::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::CHAR_LITERAL);
	Literal::identify(id);
}

void
CharLiteral::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "CharLiteral");
	addMember(elem, "value", value);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
