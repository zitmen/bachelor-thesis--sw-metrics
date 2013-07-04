#include "NodeId.h"
#include "AddressOf.h"

AddressOf::AddressOf()
{
	//
}

AddressOf::~AddressOf()
{
	//
}

void
AddressOf::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::ADDRESS_OF);
	UnaryOperator::identify(id);
}

void
AddressOf::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "AddressOf");
	//addMember(elem, "locationInfo", locationInfo);
}
