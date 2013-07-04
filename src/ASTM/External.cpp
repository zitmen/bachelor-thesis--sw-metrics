#include "NodeId.h"
#include "External.h"

External::External()
{
	//
}

External::~External()
{
	//
}

void
External::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::EXTERNAL);
	StorageSpecification::identify(id);
}

void
External::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "External");
	//addMember(elem, "locationInfo", locationInfo);
}
