#include "NodeId.h"
#include "UnaryOperator.h"

UnaryOperator::UnaryOperator()
{
	//
}

UnaryOperator::~UnaryOperator()
{
	//
}

void
UnaryOperator::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::UNARY_OPERATOR);
	OtherSyntaxObject::identify(id);
}
