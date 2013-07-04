#include "NodeId.h"
#include "Auto.h"

Auto::Auto()
{
	//
}

Auto::~Auto()
{
	//
}

void
Auto::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::AUTO);
	StorageSpecification::identify(id);
}

void
Auto::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Auto");
	//addMember(elem, "locationInfo", locationInfo);
}
