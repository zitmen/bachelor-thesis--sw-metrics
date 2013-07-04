#include "NodeId.h"
#include "EnumType.h"
#include "EnumLiteralDefinition.h"

EnumType::EnumType()
{
	//
}

EnumType::~EnumType()
{
	for(size_t i = 0, im = enumLiterals.size(); i < im; ++i)
		if(enumLiterals[i])
			delete enumLiterals[i];
	//
	enumLiterals.clear();
}

void
EnumType::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::ENUM_TYPE);
	DataType::identify(id);
}

void
EnumType::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "EnumType");
	//addMember(elem, "locationInfo", locationInfo);
}
