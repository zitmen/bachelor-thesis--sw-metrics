#include "NodeId.h"
#include "BitRightShift.h"

BitRightShift::BitRightShift()
{
	//
}

BitRightShift::~BitRightShift()
{
	//
}

void
BitRightShift::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::BIT_RIGHT_SHIFT);
	BinaryOperator::identify(id);
}

void
BitRightShift::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "BitRightShift");
	//addMember(elem, "locationInfo", locationInfo);
}
