#include "NodeId.h"
#include "Decrement.h"

Decrement::Decrement()
{
	//
}

Decrement::~Decrement()
{
	//
}

void
Decrement::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::DECREMENT);
	UnaryOperator::identify(id);
}

void
Decrement::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Decrement");
	//addMember(elem, "locationInfo", locationInfo);
}
