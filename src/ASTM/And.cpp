#include "NodeId.h"
#include "And.h"

And::And()
{
	//
}

And::~And()
{
	//
}

void
And::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::AND);
	BinaryOperator::identify(id);
}

void
And::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "And");
	//addMember(elem, "locationInfo", locationInfo);
}
