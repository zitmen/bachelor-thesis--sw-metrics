#include "NodeId.h"
#include "Exponent.h"

Exponent::Exponent()
{
	//
}

Exponent::~Exponent()
{
	//
}

void
Exponent::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::EXPONENT);
	BinaryOperator::identify(id);
}

void
Exponent::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Exponent");
	//addMember(elem, "locationInfo", locationInfo);
}
