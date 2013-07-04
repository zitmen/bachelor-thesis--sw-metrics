#include "NodeId.h"
#include "Equal.h"

Equal::Equal()
{
	//
}

Equal::~Equal()
{
	//
}

void
Equal::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::EQUAL);
	BinaryOperator::identify(id);
}

void
Equal::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Equal");
	//addMember(elem, "locationInfo", locationInfo);
}
