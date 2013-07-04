#include "NodeId.h"
#include "EmptyStatement.h"

EmptyStatement::EmptyStatement()
{
	//
}

EmptyStatement::~EmptyStatement()
{
	//
}

void
EmptyStatement::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::EMPTY_STATEMENT);
	Statement::identify(id);
}

void
EmptyStatement::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "EmptyStatement");
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
