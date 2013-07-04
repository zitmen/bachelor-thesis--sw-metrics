#include "NodeId.h"
#include "EnumLiteralDefinition.h"
#include "Expression.h"

EnumLiteralDefinition::EnumLiteralDefinition()
{
	value = NULL;
}

EnumLiteralDefinition::~EnumLiteralDefinition()
{
	if(value) delete value;
}

void
EnumLiteralDefinition::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::ENUM_LITERAL_DEFINITION);
	Definition::identify(id);
}

void
EnumLiteralDefinition::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "EnumLiteralDefinition");
	//addMember(elem, "locationInfo", locationInfo);
}
