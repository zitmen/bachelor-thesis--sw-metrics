#include "NodeId.h"
#include "Assign.h"

Assign::Assign()
{
	//
}

Assign::~Assign()
{
	//
}

void
Assign::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::ASSIGN);
	BinaryOperator::identify(id);
}

void
Assign::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Assign");
	//addMember(elem, "locationInfo", locationInfo);
}
