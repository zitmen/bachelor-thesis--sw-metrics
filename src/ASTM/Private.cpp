#include "NodeId.h"
#include "Private.h"

Private::Private()
{
	//
}

Private::~Private()
{
	//
}

void
Private::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::PRIVATE);
	AccessKind::identify(id);
}

void
Private::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Private");
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
