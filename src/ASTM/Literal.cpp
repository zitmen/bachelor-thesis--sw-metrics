#include "NodeId.h"
#include "Literal.h"

Literal::Literal()
{
	//
}

Literal::~Literal()
{
	//
}

void
Literal::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::LITERAL);
	Expression::identify(id);
}
