#include "NodeId.h"
#include "Increment.h"

Increment::Increment()
{
	//
}

Increment::~Increment()
{
	//
}

void
Increment::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::INCREMENT);
	UnaryOperator::identify(id);
}

void
Increment::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Increment");
	//addMember(elem, "locationInfo", locationInfo);
}
