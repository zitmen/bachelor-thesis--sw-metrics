#include "NodeId.h"
#include "Statement.h"

Statement::Statement()
{
	//
}

Statement::~Statement()
{
	//
}

void
Statement::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::STATEMENT);
	GASTMSyntaxObject::identify(id);
}
