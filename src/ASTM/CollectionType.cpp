#include "NodeId.h"
#include "CollectionType.h"

CollectionType::CollectionType()
{
	//
}

CollectionType::~CollectionType()
{
	//
}

void
CollectionType::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::COLLECTION_TYPE);
	ConstructedType::identify(id);
}

void
CollectionType::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "CollectionType");
	//addMember(elem, "locationInfo", locationInfo);
}
