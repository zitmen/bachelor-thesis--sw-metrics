#include "NodeId.h"
#include "Expression.h"

Expression::Expression()
{
	expressionType = NULL;
}

Expression::~Expression()
{
	if(expressionType) delete expressionType;
}

void
Expression::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::EXPRESSION);
	GASTMSyntaxObject::identify(id);
}
