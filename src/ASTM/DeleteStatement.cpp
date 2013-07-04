#include "NodeId.h"
#include "DeleteStatement.h"
#include "Expression.h"

DeleteStatement::DeleteStatement()
{
	operand = NULL;
	deleteArray = false;
}

DeleteStatement::~DeleteStatement()
{
	if(operand) delete operand;
}

void
DeleteStatement::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::DELETE_STATEMENT);
	Statement::identify(id);
}

void
DeleteStatement::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "DeleteStatement");
	//addMember(elem, "locationInfo", locationInfo);
}
