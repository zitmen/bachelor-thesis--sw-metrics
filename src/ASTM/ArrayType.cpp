#include "NodeId.h"
#include "ArrayType.h"
#include "Dimension.h"

ArrayType::ArrayType()
{
	//
}

ArrayType::~ArrayType()
{
	for(size_t i = 0, im = ranks.size(); i < im; ++i)
		if(ranks[i])
			delete ranks[i];
	//
	ranks.clear();
}

void
ArrayType::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::ARRAY_TYPE);
	ConstructedType::identify(id);
}

void
ArrayType::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "ArrayType");
	//addMember(elem, "locationInfo", locationInfo);
}
