#include "NodeId.h"
#include "SourceFile.h"
#include "SourceLocation.h"

SourceFile::SourceFile()
{
	firstToken = NULL;
	lastToken = NULL;
}

SourceFile::~SourceFile()
{
	if(firstToken) delete firstToken;
	//if(lastToken) delete lastToken;	// don't delete it because deletion of the first one deletes the whole chain including the last token
}

void
SourceFile::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::SOURCE_FILE);
	GASTMSourceObject::identify(id);
}

void
SourceFile::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "SourceFile");
	addMember(elem, "pathName", pathName);
}
