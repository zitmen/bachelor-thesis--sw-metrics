#include "NodeId.h"
#include "BooleanLiteral.h"

BooleanLiteral::BooleanLiteral()
{
	//
}

BooleanLiteral::~BooleanLiteral()
{
	//
}

void
BooleanLiteral::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::BOOLEAN_LITERAL);
	Literal::identify(id);
}

void
BooleanLiteral::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "BooleanLiteral");
	addMember(elem, "value", value);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
