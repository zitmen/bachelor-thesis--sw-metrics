#include "NodeId.h"
#include "BitFieldDefinition.h"
#include "Expression.h"

BitFieldDefinition::BitFieldDefinition()
{
	bitFieldSize = NULL;
}

BitFieldDefinition::~BitFieldDefinition()
{
	if(bitFieldSize) delete bitFieldSize;
}

void
BitFieldDefinition::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::BIT_FIELD_DEFINITION);
	DataDefinition::identify(id);
}

void
BitFieldDefinition::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "BitFieldDefinition");
	//addMember(elem, "locationInfo", locationInfo);
}
