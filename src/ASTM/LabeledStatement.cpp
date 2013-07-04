#include "NodeId.h"
#include "LabeledStatement.h"
#include "LabelDefinition.h"

LabeledStatement::LabeledStatement()
{
	label = NULL;
	statement = NULL;
}

LabeledStatement::~LabeledStatement()
{
	if(label) delete label;
	if(statement) delete statement;
}

void
LabeledStatement::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::LABELED_STATEMENT);
	Statement::identify(id);
}

void
LabeledStatement::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "LabeledStatement");
	//addMember(elem, "locationInfo", locationInfo);
}
