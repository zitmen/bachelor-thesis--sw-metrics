#include "NodeId.h"
#include "ReturnStatement.h"
#include "Expression.h"

ReturnStatement::ReturnStatement()
{
	returnValue = NULL;
}

ReturnStatement::~ReturnStatement()
{
	if(returnValue) delete returnValue;
}

void
ReturnStatement::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::RETURN_STATEMENT);
	Statement::identify(id);
}

void
ReturnStatement::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "ReturnStatement");
	addMember(elem, "returnValue", returnValue);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
