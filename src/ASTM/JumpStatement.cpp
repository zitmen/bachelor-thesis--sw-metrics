#include "NodeId.h"
#include "JumpStatement.h"
#include "Expression.h"

JumpStatement::JumpStatement()
{
	target = NULL;
}

JumpStatement::~JumpStatement()
{
	if(target) delete target;
}

void
JumpStatement::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::JUMP_STATEMENT);
	Statement::identify(id);
}

void
JumpStatement::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "JumpStatement");
	//addMember(elem, "locationInfo", locationInfo);
}
