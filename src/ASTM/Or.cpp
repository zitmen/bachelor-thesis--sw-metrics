#include "NodeId.h"
#include "Or.h"

Or::Or()
{
	//
}

Or::~Or()
{
	//
}

void
Or::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::OR);
	BinaryOperator::identify(id);
}

void
Or::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "LocationInfo");
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
