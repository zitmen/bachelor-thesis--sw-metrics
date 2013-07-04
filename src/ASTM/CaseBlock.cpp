#include "NodeId.h"
#include "CaseBlock.h"
#include "Expression.h"

CaseBlock::CaseBlock()
{
	expression = NULL;
}

CaseBlock::~CaseBlock()
{
	if(expression)
		delete expression;
}

void
CaseBlock::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::CASE_BLOCK);
	SwitchCase::identify(id);
}

void
CaseBlock::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "CaseBlock");
	addMember(elem, "expression", expression);
	addMember(elem, "statement", statement);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
