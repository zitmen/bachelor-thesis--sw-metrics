#include "NodeId.h"
#include "NamedType.h"

NamedType::NamedType()
{
	body = NULL;
}

NamedType::~NamedType()
{
	//
}

void
NamedType::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::NAMED_TYPE);
	DataType::identify(id);
}

void
NamedType::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "NamedType");
	addMember(elem, "body", body);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
