#include "NodeId.h"
#include "MacroCall.h"
#include "MacroDefinition.h"

MacroCall::MacroCall()
{
	refersTo = NULL;
}

MacroCall::~MacroCall()
{
	if(refersTo) delete refersTo;
}

void
MacroCall::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::MACRO_CALL);
	PreprocessorElement::identify(id);
}

void
MacroCall::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "MacroCall");
	//addMember(elem, "locationInfo", locationInfo);
}
