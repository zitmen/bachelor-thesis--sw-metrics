#include "NodeId.h"
#include "NameSpaceDefinition.h"
#include "NameSpaceScope.h"
#include "NameSpaceType.h"
#include "Name.h"

NameSpaceDefinition::NameSpaceDefinition()
{
	nameSpaceType = NULL;
	nameSpace = NULL;
	body = NULL;
	opensScope = NULL;
}

NameSpaceDefinition::~NameSpaceDefinition()
{
	if(nameSpaceType) delete nameSpaceType;
	if(nameSpace) delete nameSpace;
	if(body)
	{
		for(size_t i = 0, im = body->size(); i < im; ++i)
			if(body->at(i))
				delete body->at(i);
		//
		body->clear();
		delete body;
	}
	if(opensScope) delete opensScope;
}

void
NameSpaceDefinition::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::NAME_SPACE_DEFINITION);
	DefinitionUnit::identify(id);
}

void
NameSpaceDefinition::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "NameSpaceDefinition");
	addMember(elem, "nameSpaceType", nameSpaceType);
	addMember(elem, "nameSpace", nameSpace);
	addMember(elem, "body", (std::vector<GASTMObject *> *)body);
	addMember(elem, "opensScope", opensScope);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
