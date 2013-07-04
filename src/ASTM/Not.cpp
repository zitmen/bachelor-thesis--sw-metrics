#include "NodeId.h"
#include "Not.h"

Not::Not()
{
	//
}

Not::~Not()
{
	//
}

void
Not::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::NOT);
	UnaryOperator::identify(id);
}

void
Not::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Not");
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
