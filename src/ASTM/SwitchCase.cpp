#include "NodeId.h"
#include "SwitchCase.h"

SwitchCase::SwitchCase()
{
	//
}

SwitchCase::~SwitchCase()
{
	if(statement)
		delete statement;
}

void
SwitchCase::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::SWITCH_CASE);
	OtherSyntaxObject::identify(id);
}
