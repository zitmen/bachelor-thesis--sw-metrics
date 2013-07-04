#include "NodeId.h"
#include "RealLiteral.h"

RealLiteral::RealLiteral()
{
	//
}

RealLiteral::~RealLiteral()
{
	//
}

void
RealLiteral::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::REAL_LITERAL);
	Literal::identify(id);
}

void
RealLiteral::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "RealLiteral");
	addMember(elem, "expressionType", expressionType);
	addMember(elem, "value", value);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
