#include "NodeId.h"
#include "Protected.h"

Protected::Protected()
{
	//
}

Protected::~Protected()
{
	//
}

void
Protected::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::PROTECTED);
	AccessKind::identify(id);
}

void
Protected::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Protected");
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
