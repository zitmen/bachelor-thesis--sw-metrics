#include "NodeId.h"
#include "Deref.h"

Deref::Deref()
{
	//
}

Deref::~Deref()
{
	//
}

void
Deref::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::DEREF);
	UnaryOperator::identify(id);
}

void
Deref::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Deref");
	//addMember(elem, "locationInfo", locationInfo);
}
