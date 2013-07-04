#include "NodeId.h"
#include "FunctionMemberAttributes.h"
#include "VirtualSpecification.h"

FunctionMemberAttributes::FunctionMemberAttributes()
{
	isInline = false;
	isFriend = false;
	isThisConst = false;
	//
	virtualSpecifier = NULL;
}

FunctionMemberAttributes::~FunctionMemberAttributes()
{
	if(virtualSpecifier) delete virtualSpecifier;
}

void
FunctionMemberAttributes::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::FUNCTION_MEMBER_ATTRIBUTES);
	OtherSyntaxObject::identify(id);
}

void
FunctionMemberAttributes::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "FunctionMemberAttributes");
	addMember(elem, "isInline", isInline);
	addMember(elem, "isFriend", isFriend);
	addMember(elem, "isThisConst", isThisConst);
	addMember(elem, "virtualSpecifier", virtualSpecifier);
}
