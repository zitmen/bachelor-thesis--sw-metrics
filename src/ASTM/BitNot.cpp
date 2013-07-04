#include "NodeId.h"
#include "BitNot.h"

BitNot::BitNot()
{
	//
}

BitNot::~BitNot()
{
	//
}

void
BitNot::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::BIT_NOT);
	UnaryOperator::identify(id);
}

void
BitNot::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "BitNot");
	//addMember(elem, "locationInfo", locationInfo);
}
