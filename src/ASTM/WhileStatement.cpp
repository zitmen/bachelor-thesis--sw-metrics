#include "NodeId.h"
#include "WhileStatement.h"

WhileStatement::WhileStatement()
{
	//
}

WhileStatement::~WhileStatement()
{
	//
}

void
WhileStatement::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::WHILE_STATEMENT);
	LoopStatement::identify(id);
}

void
WhileStatement::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "WhileStatement");
	addMember(elem, "condition", (GASTMObject *)condition);
	addMember(elem, "body", body);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
	addMember(elem, "opensScope", opensScope);
}
