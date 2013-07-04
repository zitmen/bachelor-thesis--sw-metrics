#include "NodeId.h"
#include "Dimension.h"
#include "Expression.h"

Dimension::Dimension()
{
	lowBound = NULL;
	highBound = NULL;
}

Dimension::~Dimension()
{
	if(lowBound) delete lowBound;
	if(highBound) delete highBound;
}

void
Dimension::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::DIMENSION);
	OtherSyntaxObject::identify(id);
}

void
Dimension::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Dimension");
	//addMember(elem, "locationInfo", locationInfo);
}
