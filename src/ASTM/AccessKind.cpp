#include "NodeId.h"
#include "AccessKind.h"

AccessKind::AccessKind()
{
	//
}

AccessKind::~AccessKind()
{
	//
}

void
AccessKind::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::ACCESS_KIND);
	OtherSyntaxObject::identify(id);
}
