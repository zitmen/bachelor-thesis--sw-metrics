#include "NodeId.h"
#include "MacroDefinition.h"

MacroDefinition::MacroDefinition()
{
	//
}

MacroDefinition::~MacroDefinition()
{
	//
}

void
MacroDefinition::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::MACRO_DEFINITION);
	PreprocessorElement::identify(id);
}

void
MacroDefinition::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "MacroDefinition");
	//addMember(elem, "locationInfo", locationInfo);
}
