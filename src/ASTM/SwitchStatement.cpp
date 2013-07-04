#include "NodeId.h"
#include "SwitchStatement.h"
#include "Expression.h"
#include "BlockScope.h"

SwitchStatement::SwitchStatement()
{
	switchExpression = NULL;
	body = NULL;
	opensScope = NULL;
}

SwitchStatement::~SwitchStatement()
{
	if(switchExpression) delete switchExpression;
	if(body) delete body;
	if(opensScope) delete opensScope;
}


void
SwitchStatement::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::SWITCH_STATEMENT);
	Statement::identify(id);
}

void
SwitchStatement::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "SwitchStatement");
	addMember(elem, "switchExpression", switchExpression);
	addMember(elem, "body", body);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
	addMember(elem, "opensScope", opensScope);
}
