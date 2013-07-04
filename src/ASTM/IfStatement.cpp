#include "NodeId.h"
#include "IfStatement.h"
#include "Expression.h"
#include "BlockScope.h"

IfStatement::IfStatement()
{
	condition = NULL;
	thenBody = NULL;
	elseBody = NULL;
	opensScope = NULL;
}

IfStatement::~IfStatement()
{
	if(condition) delete condition;
	if(thenBody) delete thenBody;
	if(elseBody) delete elseBody;
	if(opensScope) delete opensScope;
}

void
IfStatement::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::IF_STATEMENT);
	Statement::identify(id);
}

void
IfStatement::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "IfStatement");
	addMember(elem, "condition", condition);
	addMember(elem, "thenBody", thenBody);
	addMember(elem, "elseBody", elseBody);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
	addMember(elem, "opensScope", opensScope);
}
