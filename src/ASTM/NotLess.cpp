#include "NodeId.h"
#include "NotLess.h"

NotLess::NotLess()
{
	//
}

NotLess::~NotLess()
{
	//
}

void
NotLess::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::NOT_LESS);
	BinaryOperator::identify(id);
}

void
NotLess::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "NotLess");
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
