#include "NodeId.h"
#include "BlockStatement.h"
#include "BlockScope.h"

BlockStatement::BlockStatement()
{
	opensScope = NULL;
	subStatements = NULL;
}

BlockStatement::~BlockStatement()
{
	if(opensScope) delete opensScope;
	if(subStatements)
	{
		for(size_t i = 0, im = subStatements->size(); i < im; ++i)
			if(subStatements->at(i))
				delete subStatements->at(i);
		//
		subStatements->clear();
		delete subStatements;
	}
}

void
BlockStatement::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::BLOCK_STATEMENT);
	Statement::identify(id);
}

void
BlockStatement::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "BlockStatement");
	addMember(elem, "subStatements", (std::vector<GASTMObject *> *)subStatements);
	addMember(elem, "opensScope", opensScope);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
