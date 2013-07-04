#include "NodeId.h"
#include "Comment.h"

Comment::Comment()
{
	//
}

Comment::~Comment()
{
	//
}

void
Comment::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::COMMENT);
	PreprocessorElement::identify(id);
}

void
Comment::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "Comment");
	//addMember(elem, "locationInfo", locationInfo);
}
