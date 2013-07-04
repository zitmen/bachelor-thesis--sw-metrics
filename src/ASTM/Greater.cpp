#include "NodeId.h"
#include "Greater.h"

Greater::Greater()
{
	//
}

Greater::~Greater()
{
	//
}

void
Greater::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::GREATER);
	BinaryOperator::identify(id);
}

void
Greater::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Greater");
	//addMember(elem, "locationInfo", locationInfo);
}
