#include "NodeId.h"
#include "PostIncrement.h"

PostIncrement::PostIncrement()
{
	//
}

PostIncrement::~PostIncrement()
{
	//
}

void
PostIncrement::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::POST_INCREMENT);
	UnaryOperator::identify(id);
}

void
PostIncrement::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "PostIncrement");
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
