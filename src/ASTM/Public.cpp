#include "NodeId.h"
#include "Public.h"

Public::Public()
{
	//
}

Public::~Public()
{
	//
}

void
Public::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::PUBLIC);
	AccessKind::identify(id);
}

void
Public::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Public");
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
