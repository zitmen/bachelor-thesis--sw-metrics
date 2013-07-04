#include "NodeId.h"
#include "Modulus.h"

Modulus::Modulus()
{
	//
}

Modulus::~Modulus()
{
	//
}

void
Modulus::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::MODULUS);
	BinaryOperator::identify(id);
}

void
Modulus::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Modulus");
	//addMember(elem, "locationInfo", locationInfo);
}
