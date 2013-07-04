#include "NodeId.h"
#include "BitXor.h"

BitXor::BitXor()
{
	//
}

BitXor::~BitXor()
{
	//
}

void
BitXor::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::BIT_XOR);
	BinaryOperator::identify(id);
}

void
BitXor::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "BitXor");
	//addMember(elem, "locationInfo", locationInfo);
}
