#include "NodeId.h"
#include "NotGreater.h"

NotGreater::NotGreater()
{
	//
}

NotGreater::~NotGreater()
{
	//
}

void
NotGreater::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::NOT_GREATER);
	BinaryOperator::identify(id);
}

void
NotGreater::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "NotGreater");
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
