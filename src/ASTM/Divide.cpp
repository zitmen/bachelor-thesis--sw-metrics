#include "NodeId.h"
#include "Divide.h"

Divide::Divide()
{
	//
}

Divide::~Divide()
{
	//
}

void
Divide::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::DIVIDE);
	BinaryOperator::identify(id);
}

void
Divide::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Divide");
	//addMember(elem, "locationInfo", locationInfo);
}
