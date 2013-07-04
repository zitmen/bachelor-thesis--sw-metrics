#include "NodeId.h"
#include "Name.h"

Name::Name()
{
	nameString = "";
}

Name::Name(const std::string &name)
{
	nameString = name;
}

Name::~Name()
{
	//
}

void
Name::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::NAME);
	OtherSyntaxObject::identify(id);
}

void
Name::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Name");
	addMember(elem, "nameString", nameString);
	//addMember(elem, "locationInfo", locationInfo);
}
