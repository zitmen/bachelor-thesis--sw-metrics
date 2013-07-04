#include "NodeId.h"
#include "DeclarationOrDefinitionStatement.h"

DeclarationOrDefinitionStatement::DeclarationOrDefinitionStatement()
{
	declOrDefn = NULL;
}

DeclarationOrDefinitionStatement::~DeclarationOrDefinitionStatement()
{
	if(declOrDefn)
	{
		for(size_t i = 0, im = declOrDefn->size(); i < im; ++i)
			if(declOrDefn->at(i))
				delete declOrDefn->at(i);
		//
		declOrDefn->clear();
		delete declOrDefn;
	}
}

void
DeclarationOrDefinitionStatement::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::DECLARATION_OR_DEFINITION_STATEMENT);
	Statement::identify(id);
}

void
DeclarationOrDefinitionStatement::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "DeclarationOrDefinitionStatement");
	addMember(elem, "declOrDefn", (std::vector<GASTMObject *> *)declOrDefn);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
