#include "NodeId.h"
#include "ArrayAccess.h"

ArrayAccess::ArrayAccess()
{
	arrayName = NULL;
}

ArrayAccess::~ArrayAccess()
{
	if(arrayName) delete arrayName;
	//
	for(size_t i = 0, im = subScripts.size(); i < im; ++i)
		if(subScripts[i])
			delete subScripts[i];
	//
	subScripts.clear();
}

void
ArrayAccess::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::ARRAY_ACCESS);
	Expression::identify(id);
}

void
ArrayAccess::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "ArrayAccess");
	//addMember(elem, "locationInfo", locationInfo);
}
