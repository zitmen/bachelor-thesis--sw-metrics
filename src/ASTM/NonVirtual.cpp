#include "NodeId.h"
#include "NonVirtual.h"

NonVirtual::NonVirtual()
{
	//
}

NonVirtual::~NonVirtual()
{
	//
}

void
NonVirtual::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::NON_VIRTUAL);
	VirtualSpecification::identify(id);
}

void
NonVirtual::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "NonVirtual");
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
