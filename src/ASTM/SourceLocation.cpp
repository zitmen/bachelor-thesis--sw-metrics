#include "NodeId.h"
#include "SourceLocation.h"

SourceLocation::SourceLocation(std::string tok, int startLn, int startCol, int endLn, int endCol)
{
	prev         = NULL;
	next         = NULL;
	//
	token        = tok;
	startLine    = startLn;
	startColumn  = startCol;
	endLine      = endLn;
	endColumn    = endCol;
}

SourceLocation::~SourceLocation()
{
	// prev shouldn't be deleted, because the chain of elements is deleted in forward direction
	delete next;
}

SourceLocation *
SourceLocation::insertBefore(SourceLocation *loc)
{
	prev = loc;
	prev->next = this;
	return prev;
}

SourceLocation *
SourceLocation::insertAfter(SourceLocation *loc)
{
	next = loc;
	next->prev = this;
	return next;
}

bool
SourceLocation::operator<(const SourceLocation &loc) const
{
	if(startLine < loc.startLine)
		return true;
	else if(startLine > loc.startLine)
		return false;
	else
		return (startColumn < loc.startColumn);
}

bool
SourceLocation::operator>(const SourceLocation &loc) const
{
	if(endLine > loc.endLine)
		return true;
	else if(endLine < loc.endLine)
		return false;
	else
		return (endColumn > loc.endColumn);
}

void
SourceLocation::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::SOURCE_LOCATION);
	GASTMSourceObject::identify(id);
}

void
SourceLocation::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "SourceLocation");
	addMember(elem, "token", token);
	addMember(elem, "startLine", startLine);
	addMember(elem, "startColumn", startColumn);
	addMember(elem, "endLine", endLine);
	addMember(elem, "endColumn", endColumn);
}
