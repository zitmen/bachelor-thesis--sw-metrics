#include "NodeId.h"
#include "OtherSyntaxObject.h"

OtherSyntaxObject::OtherSyntaxObject()
{
	//
}

OtherSyntaxObject::~OtherSyntaxObject()
{
	//
}

void
OtherSyntaxObject::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::OTHER_SYNTAX_OBJECT);
	GASTMSyntaxObject::identify(id);
}
