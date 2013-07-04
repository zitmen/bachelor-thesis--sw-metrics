#include "NodeId.h"
#include "PostDecrement.h"

PostDecrement::PostDecrement()
{
	//
}

PostDecrement::~PostDecrement()
{
	//
}

void
PostDecrement::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::POST_DECREMENT);
	UnaryOperator::identify(id);
}

void
PostDecrement::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "PostDecrement");
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
