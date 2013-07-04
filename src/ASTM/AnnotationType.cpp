#include "NodeId.h"
#include "AnnotationType.h"

AnnotationType::AnnotationType()
{
	//
}

AnnotationType::~AnnotationType()
{
	//
}

void
AnnotationType::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::ANNOTATION_TYPE);
	AggregateType::identify(id);
}

void
AnnotationType::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "AnnotationType");
	//addMember(elem, "locationInfo", locationInfo);
}
