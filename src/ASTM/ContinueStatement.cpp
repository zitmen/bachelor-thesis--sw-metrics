#include "NodeId.h"
#include "ContinueStatement.h"
#include "LabelAccess.h"

ContinueStatement::ContinueStatement()
{
	target = NULL;
}

ContinueStatement::~ContinueStatement()
{
	if(target) delete target;
}

void
ContinueStatement::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::CONTINUE_STATEMENT);
	Statement::identify(id);
}

void
ContinueStatement::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "ContinueStatement");
	addMember(elem, "target", target);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
