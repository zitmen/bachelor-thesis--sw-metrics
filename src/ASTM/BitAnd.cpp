#include "NodeId.h"
#include "BitAnd.h"

BitAnd::BitAnd()
{
	//
}

BitAnd::~BitAnd()
{
	//
}

void
BitAnd::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::BIT_AND);
	BinaryOperator::identify(id);
}

void
BitAnd::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "BitAnd");
	//addMember(elem, "locationInfo", locationInfo);
}
