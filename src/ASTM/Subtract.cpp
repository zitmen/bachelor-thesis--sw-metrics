#include "NodeId.h"
#include "Subtract.h"

Subtract::Subtract()
{
	//
}

Subtract::~Subtract()
{
	//
}

void
Subtract::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::SUBTRACT);
	BinaryOperator::identify(id);
}

void
Subtract::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Subtract");
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
