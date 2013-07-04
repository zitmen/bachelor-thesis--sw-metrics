#include "NodeId.h"
#include "DoWhileStatement.h"

DoWhileStatement::DoWhileStatement()
{
	//
}

DoWhileStatement::~DoWhileStatement()
{
	//
}

void
DoWhileStatement::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::DO_WHILE_STATEMENT);
	LoopStatement::identify(id);
}

void
DoWhileStatement::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "DoWhileStatement");
	addMember(elem, "body", body);
	addMember(elem, "condition", (GASTMObject *)condition);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
	addMember(elem, "opensScope", opensScope);
}
