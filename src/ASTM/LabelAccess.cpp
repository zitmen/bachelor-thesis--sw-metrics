#include "NodeId.h"
#include "LabelAccess.h"
#include "Name.h"
#include "LabelDefinition.h"

LabelAccess::LabelAccess()
{
	aName = NULL;
	aDefinition = NULL;
}

LabelAccess::~LabelAccess()
{
	if(aName) delete aName;
	if(aDefinition) delete aDefinition;
}

void
LabelAccess::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::LABEL_ACCESS);
	Expression::identify(id);
}

void
LabelAccess::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "LabelAccess");
	//addMember(elem, "locationInfo", locationInfo);
}
