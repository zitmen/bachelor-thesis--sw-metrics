#include "NodeId.h"
#include "Less.h"

Less::Less()
{
	//
}

Less::~Less()
{
	//
}

void
Less::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::LESS);
	BinaryOperator::identify(id);
}

void
Less::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Less");
	//addMember(elem, "locationInfo", locationInfo);
}
