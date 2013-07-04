#include "NodeId.h"
#include "ForStatement.h"
#include "Expression.h"
#include "Statement.h"

ForStatement::ForStatement()
{
	initBody = NULL;
	iterationBody = NULL;
}

ForStatement::~ForStatement()
{
	if(initBody) delete initBody;
	if(iterationBody) delete iterationBody;
}

void
ForStatement::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::FOR_STATEMENT);
	LoopStatement::identify(id);
}

void
ForStatement::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "ForStatement");
	addMember(elem, "initBody", initBody);
	addMember(elem, "condition", condition);
	addMember(elem, "iterationBody", iterationBody);
	addMember(elem, "body", body);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
	addMember(elem, "opensScope", opensScope);
}
