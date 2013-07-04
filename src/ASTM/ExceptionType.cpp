#include "NodeId.h"
#include "ExceptionType.h"

ExceptionType::ExceptionType()
{
	//
}

ExceptionType::~ExceptionType()
{
	//
}

void
ExceptionType::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::EXCEPTION_TYPE);
	DataType::identify(id);
}

void
ExceptionType::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "ExceptionType");
	//addMember(elem, "locationInfo", locationInfo);
}
