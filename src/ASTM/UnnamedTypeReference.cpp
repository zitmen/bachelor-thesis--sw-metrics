#include "NodeId.h"
#include "UnnamedTypeReference.h"

UnnamedTypeReference::UnnamedTypeReference()
{
	type = NULL;
}

UnnamedTypeReference::~UnnamedTypeReference()
{
	if(type) delete type;
}

void
UnnamedTypeReference::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::UNNAMED_TYPE_REFERENCE);
	TypeReference::identify(id);
}

void
UnnamedTypeReference::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "UnnamedTypeReference");
	addMember(elem, "isConst", isConst);
	addMember(elem, "isVolatile", isVolatile);
	addMember(elem, "type", type);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
