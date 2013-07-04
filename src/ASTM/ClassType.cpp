#include "NodeId.h"
#include "ClassType.h"
#include "DerivesFrom.h"

ClassType::ClassType()
{
	derivesFrom = NULL;
}

ClassType::~ClassType()
{
	if(derivesFrom)
	{
		for(size_t i = 0, im = derivesFrom->size(); i < im; ++i)
			if(derivesFrom->at(i))
				delete derivesFrom->at(i);
		//
		derivesFrom->clear();
		delete derivesFrom;
	}
}

void
ClassType::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::CLASS_TYPE);
	AggregateType::identify(id);
}

void
ClassType::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "ClassType");
	addMember(elem, "isConst", isConst);
	addMember(elem, "isVolatile", isVolatile);
	addMember(elem, "derivesFrom", (std::vector<GASTMObject *> *)derivesFrom);
	addMember(elem, "members", (std::vector<GASTMObject *> *)members);
	addMember(elem, "opensScope", opensScope);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
