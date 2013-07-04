#include "NodeId.h"
#include "FunctionScope.h"

FunctionScope::FunctionScope()
{
	//
}

FunctionScope::~FunctionScope()
{
	//
}

void
FunctionScope::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::FUNCTION_SCOPE);
	Scope::identify(id);
}

void
FunctionScope::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "FunctionScope");
	addMember(elem, "definitionObject", (std::vector<GASTMObject *> *)definitionObject);
	addMember(elem, "childScope", (std::vector<GASTMObject *> *)childScope);
	//addMember(elem, "parentScope", parentScope);
}
