#include "NodeId.h"
#include "Multiply.h"

Multiply::Multiply()
{
	//
}

Multiply::~Multiply()
{
	//
}

void
Multiply::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::MULTIPLY);
	BinaryOperator::identify(id);
}

void
Multiply::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Multiply");
	//addMember(elem, "locationInfo", locationInfo);
}
