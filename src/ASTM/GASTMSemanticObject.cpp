#include "NodeId.h"
#include "GASTMSemanticObject.h"

GASTMSemanticObject::GASTMSemanticObject()
{
	//
}

GASTMSemanticObject::~GASTMSemanticObject()
{
	//
}

void
GASTMSemanticObject::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::GASTM_SEMANTIC_OBJECT);
	GASTMObject::identify(id);
}
