#include "NodeId.h"
#include "BinaryOperator.h"

BinaryOperator::BinaryOperator()
{
	//
}

BinaryOperator::~BinaryOperator()
{
	//
}

void
BinaryOperator::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::BINARY_OPERATOR);
	OtherSyntaxObject::identify(id);
}
