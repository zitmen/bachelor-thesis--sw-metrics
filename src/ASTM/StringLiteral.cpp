#include "NodeId.h"
#include "StringLiteral.h"

StringLiteral::StringLiteral()
{
	//
}

StringLiteral::~StringLiteral()
{
	//
}

void
StringLiteral::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::STRING_LITERAL);
	Literal::identify(id);
}

void
StringLiteral::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "StringLiteral");
	//addMember(elem, "expressionType", expressionType);
	addMember(elem, "value", value);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
