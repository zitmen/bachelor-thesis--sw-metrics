#include "NodeId.h"
#include "ActualParameter.h"

ActualParameter::ActualParameter()
{
	value = NULL;
}

ActualParameter::~ActualParameter()
{
	if(value) delete value;
}

void
ActualParameter::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::ACTUAL_PARAMETER);
	OtherSyntaxObject::identify(id);
}

void
ActualParameter::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "ActualParameter");
	addMember(elem, "value", value);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
