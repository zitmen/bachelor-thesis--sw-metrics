#include "NodeId.h"
#include "LoopStatement.h"
#include "Expression.h"
#include "BlockScope.h"

LoopStatement::LoopStatement()
{
	condition = NULL;
	body = NULL;
	opensScope = NULL;
}

LoopStatement::~LoopStatement()
{
	if(condition) delete condition;
	if(body) delete body;
	if(opensScope) delete opensScope;
}

void
LoopStatement::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::LOOP_STATEMENT);
	Statement::identify(id);
}

void
LoopStatement::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "LoopStatement");
	//addMember(elem, "locationInfo", locationInfo);
}
