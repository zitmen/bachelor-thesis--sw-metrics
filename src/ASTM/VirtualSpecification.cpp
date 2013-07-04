#include "NodeId.h"
#include "VirtualSpecification.h"

VirtualSpecification::VirtualSpecification()
{
	//
}

VirtualSpecification::~VirtualSpecification()
{
	//
}

void
VirtualSpecification::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::VIRTUAL_SPECIFICATION);
	OtherSyntaxObject::identify(id);
}
