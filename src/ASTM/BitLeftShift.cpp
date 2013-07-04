#include "NodeId.h"
#include "BitLeftShift.h"

BitLeftShift::BitLeftShift()
{
	//
}

BitLeftShift::~BitLeftShift()
{
	//
}

void
BitLeftShift::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::BIT_LEFT_SHIFT);
	BinaryOperator::identify(id);
}

void
BitLeftShift::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "BitLeftShift");
	//addMember(elem, "locationInfo", locationInfo);
}
