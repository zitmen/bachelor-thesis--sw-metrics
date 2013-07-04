#include "NodeId.h"
#include "GASTMSourceObject.h"

GASTMSourceObject::GASTMSourceObject()
{
	//
}

GASTMSourceObject::~GASTMSourceObject()
{
	//
}

void
GASTMSourceObject::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::GASTM_SOURCE_OBJECT);
	GASTMObject::identify(id);
}
