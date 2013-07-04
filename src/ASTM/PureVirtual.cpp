#include "NodeId.h"
#include "PureVirtual.h"

PureVirtual::PureVirtual()
{
	//
}

PureVirtual::~PureVirtual()
{
	//
}

void
PureVirtual::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::PURE_VIRTUAL);
	VirtualSpecification::identify(id);
}

void
PureVirtual::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "PureVirtual");
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
