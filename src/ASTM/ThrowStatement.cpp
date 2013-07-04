#include "NodeId.h"
#include "ThrowStatement.h"
#include "Expression.h"

ThrowStatement::ThrowStatement()
{
	exception = NULL;
}

ThrowStatement::~ThrowStatement()
{
	if(exception) delete exception;
}

void
ThrowStatement::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::THROW_STATEMENT);
	Statement::identify(id);
}

void
ThrowStatement::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "ThrowStatement");
	//addMember(elem, "exception", exception);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
