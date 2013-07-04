#include "NodeId.h"
#include "NotEqual.h"

NotEqual::NotEqual()
{
	//
}

NotEqual::~NotEqual()
{
	//
}

void
NotEqual::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::NOT_EQUAL);
	BinaryOperator::identify(id);
}

void
NotEqual::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "NotEqual");
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
