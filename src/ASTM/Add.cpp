#include "NodeId.h"
#include "Add.h"

Add::Add()
{
	//
}

Add::~Add()
{
	//
}

void
Add::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::ADD);
	BinaryOperator::identify(id);
}

void
Add::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Add");
	//addMember(elem, "locationInfo", locationInfo);
}
