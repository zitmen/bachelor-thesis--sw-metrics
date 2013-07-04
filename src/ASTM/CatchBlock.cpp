#include "NodeId.h"
#include "CatchBlock.h"
#include "DataDefinition.h"
#include "Statement.h"
#include "Type.h"

CatchBlock::CatchBlock()
{
	body = NULL;
}

CatchBlock::~CatchBlock()
{
	if(body) delete body;
	//
	for(size_t i = 0, im = exceptions.size(); i < im; ++i)
		if(exceptions[i])
			delete exceptions[i];
	//
	exceptions.clear();
}

void
CatchBlock::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::CATCH_BLOCK);
	OtherSyntaxObject::identify(id);
}

void
CatchBlock::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "CatchBlock");
	//addMember(elem, "locationInfo", locationInfo);
}
