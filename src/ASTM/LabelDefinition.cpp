#include "NodeId.h"
#include "LabelDefinition.h"
#include "LabelType.h"
#include "Name.h"

LabelDefinition::LabelDefinition()
{
	labelType = NULL;
	labelName = NULL;
}

LabelDefinition::~LabelDefinition()
{
	if(labelType) delete labelType;
	if(labelName) delete labelName;
}

void
LabelDefinition::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::LABEL_DEFINITION);
	DefinitionUnit::identify(id);
}

void
LabelDefinition::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "LabelDefinition");
	//addMember(elem, "locationInfo", locationInfo);
}
