#include "NodeId.h"
#include "GASTMObject.h"

GASTMObject::GASTMObject()
{
	parent = NULL;
}

GASTMObject::~GASTMObject()
{
	//
}

void
GASTMObject::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::GASTM_OBJECT);
}
