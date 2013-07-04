#include "NodeId.h"
#include "UnaryMinus.h"

UnaryMinus::UnaryMinus()
{
	//
}

UnaryMinus::~UnaryMinus()
{
	//
}

void
UnaryMinus::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::UNARY_MINUS);
	UnaryOperator::identify(id);
}

void
UnaryMinus::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "UnaryMinus");
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
