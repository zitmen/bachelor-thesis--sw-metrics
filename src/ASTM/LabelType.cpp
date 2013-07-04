#include "NodeId.h"
#include "LabelType.h"

LabelType::LabelType()
{
	//
}

LabelType::~LabelType()
{
	//
}

void
LabelType::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::LABEL_TYPE);
	Type::identify(id);
}

void
LabelType::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "LabelType");
	//addMember(elem, "locationInfo", locationInfo);
}
