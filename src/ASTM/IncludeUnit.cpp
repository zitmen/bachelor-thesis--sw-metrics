#include "NodeId.h"
#include "IncludeUnit.h"
#include "SourceFile.h"

IncludeUnit::IncludeUnit()
{
	file = NULL;
}

IncludeUnit::~IncludeUnit()
{
	if(file) delete file;
}

void
IncludeUnit::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::INCLUDE_UNIT);
	PreprocessorElement::identify(id);
}

void
IncludeUnit::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "IncludeUnit");
	//addMember(elem, "locationInfo", locationInfo);
}
