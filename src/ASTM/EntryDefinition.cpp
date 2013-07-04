#include "NodeId.h"
#include "EntryDefinition.h"
#include "FormalParameterDefinition.h"

EntryDefinition::EntryDefinition()
{
	//
}

EntryDefinition::~EntryDefinition()
{
	for(size_t i = 0, im = formalParameters.size(); i < im; ++i)
		if(formalParameters[i])
			delete formalParameters[i];
	//
	formalParameters.clear();
}

void
EntryDefinition::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::ENTRY_DEFINITION);
	Definition::identify(id);
}

void
EntryDefinition::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "EntryDefinition");
	//addMember(elem, "locationInfo", locationInfo);
}
