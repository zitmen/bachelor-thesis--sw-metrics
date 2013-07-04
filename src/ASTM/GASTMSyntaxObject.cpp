#include "NodeId.h"
#include "GASTMSyntaxObject.h"

GASTMSyntaxObject::GASTMSyntaxObject()
{
	locFirst = NULL;
	locLast = NULL;
}

GASTMSyntaxObject::~GASTMSyntaxObject()
{
	// if(locationInfo) delete locationInfo;	// don't delete it, because the whole locationInfo chain will be deleted from SourceFile class
}

void
GASTMSyntaxObject::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::GASTM_SYNTAX_OBJECT);
	GASTMObject::identify(id);
}
