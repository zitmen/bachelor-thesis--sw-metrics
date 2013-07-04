#include "NodeId.h"
#include "UnaryPlus.h"

UnaryPlus::UnaryPlus()
{
	//
}

UnaryPlus::~UnaryPlus()
{
	//
}

void
UnaryPlus::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::UNARY_PLUS);
	UnaryOperator::identify(id);
}

void
UnaryPlus::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "UnaryPlus");
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
