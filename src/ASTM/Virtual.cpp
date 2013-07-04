#include "NodeId.h"
#include "Virtual.h"

Virtual::Virtual()
{
	//
}

Virtual::~Virtual()
{
	//
}

void
Virtual::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::VIRTUAL);
	VirtualSpecification::identify(id);
}

void
Virtual::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Virtual");
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
