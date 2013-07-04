#include "NodeId.h"
#include "IntegerLiteral.h"

IntegerLiteral::IntegerLiteral()
{
	//
}

IntegerLiteral::~IntegerLiteral()
{
	//
}

void
IntegerLiteral::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::INTEGER_LITERAL);
	Literal::identify(id);
}

void
IntegerLiteral::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "IntegerLiteral");
	addMember(elem, "value", value);
	//addMember(elem, "expressionType", expressionType);
	//addMember(elem, "locationInfo", locationInfo);
}
