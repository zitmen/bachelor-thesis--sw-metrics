#include "NodeId.h"
#include "ReferenceType.h"

ReferenceType::ReferenceType()
{
	//
}

ReferenceType::~ReferenceType()
{
	//
}

void
ReferenceType::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::REFERENCE_TYPE);
	ConstructedType::identify(id);
}

void
ReferenceType::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "ReferenceType");
	addMember(elem, "isConst", isConst);
	addMember(elem, "isVolatile", isVolatile);
	//addMember(elem, "baseType", baseType);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
