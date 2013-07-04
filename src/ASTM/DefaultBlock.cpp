#include "NodeId.h"
#include "DefaultBlock.h"

DefaultBlock::DefaultBlock()
{
	//
}

DefaultBlock::~DefaultBlock()
{
	//
}

void
DefaultBlock::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::DEFAULT_BLOCK);
	SwitchCase::identify(id);
}

void
DefaultBlock::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "DefaultBlock");
	addMember(elem, "statement", statement);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
