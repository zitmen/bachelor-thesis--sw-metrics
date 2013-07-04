#include "NodeId.h"
#include "TryStatement.h"
#include "CatchBlock.h"

TryStatement::TryStatement()
{
	finalStatement = guardedStatement = NULL;
}

TryStatement::~TryStatement()
{
	if(finalStatement) delete finalStatement;
	if(guardedStatement) delete guardedStatement;
	//
	for(size_t i = 0, im = catchBlocks.size(); i < im; ++i)
		if(catchBlocks[i])
			delete catchBlocks[i];
	//
	catchBlocks.clear();
}

void
TryStatement::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::TRY_STATEMENT);
	Statement::identify(id);
}

void
TryStatement::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "TryStatement");
	addMember(elem, "guardedStatement", guardedStatement);
	addMember(elem, "catchBlocks", (std::vector<GASTMObject *> *)&catchBlocks);
	addMember(elem, "finalStatement", finalStatement);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
