#include "NodeId.h"
#include "Static.h"

Static::Static()
{
	//
}

Static::~Static()
{
	//
}

void
Static::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::STATIC);
	StorageSpecification::identify(id);
}

void
Static::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Static");
	//addMember(elem, "locationInfo", locationInfo);
}
