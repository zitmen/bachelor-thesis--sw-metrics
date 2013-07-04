#include "NodeId.h"
#include "OperatorAssign.h"

OperatorAssign::OperatorAssign()
{
	op = NULL;
}

OperatorAssign::~OperatorAssign()
{
	if(op) delete op;
}

void
OperatorAssign::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::OPERATOR_ASSIGN);
	BinaryOperator::identify(id);
}

void
OperatorAssign::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "OperatorAssign");
	addMember(elem, "op", op);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
