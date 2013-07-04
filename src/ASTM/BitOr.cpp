#include "NodeId.h"
#include "BitOr.h"

BitOr::BitOr()
{
	//
}

BitOr::~BitOr()
{
	//
}

void
BitOr::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::BIT_OR);
	BinaryOperator::identify(id);
}

void
BitOr::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "BitOr");
	//addMember(elem, "locationInfo", locationInfo);
}
