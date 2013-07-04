#include "NodeId.h"
#include "BreakStatement.h"
#include "LabelAccess.h"

BreakStatement::BreakStatement()
{
	target = NULL;
}

BreakStatement::~BreakStatement()
{
	if(target) delete target;
}

void
BreakStatement::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::BREAK_STATEMENT);
	Statement::identify(id);
}

void
BreakStatement::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "BreakStatement");
	addMember(elem, "target", target);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
