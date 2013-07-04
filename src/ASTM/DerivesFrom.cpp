#include "NodeId.h"
#include "DerivesFrom.h"
#include "AccessKind.h"
#include "NamedType.h"

DerivesFrom::DerivesFrom()
{
	isVirtual = false;
	//
	accessKind = NULL;
	className = NULL;
}

DerivesFrom::~DerivesFrom()
{
	if(accessKind) delete accessKind;
	if(className) delete className;
}

void
DerivesFrom::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::DERIVES_FROM);
	OtherSyntaxObject::identify(id);
}

void
DerivesFrom::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "DerivesFrom");
	addMember(elem, "isVirtual", isVirtual);
	addMember(elem, "accessKind", accessKind);
	addMember(elem, "className", className);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
