#include "NodeId.h"
#include "FunctionDefinition.h"
#include "FunctionScope.h"
#include "Statement.h"
#include "TypeReference.h"
#include "FormalParameterDefinition.h"
#include "FunctionMemberAttributes.h"

FunctionDefinition::FunctionDefinition()
{
	functionMemberAttributes = NULL;
	opensScope = NULL;
	body = NULL;
	formalParameters = NULL;
}

FunctionDefinition::~FunctionDefinition()
{
	if(functionMemberAttributes) delete functionMemberAttributes;
	if(opensScope) delete opensScope;
	if(body) delete body;
	if(formalParameters)
	{
		for(size_t i = 0, im = formalParameters->size(); i < im; ++i)
			if(formalParameters->at(i))
				delete formalParameters->at(i);
		//
		formalParameters->clear();
		delete formalParameters;
	}
}

void
FunctionDefinition::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::FUNCTION_DEFINITION);
	Definition::identify(id);
}

void
FunctionDefinition::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "FunctionDefinition");
	addMember(elem, "isRegister", isRegister);
	addMember(elem, "linkageSpecifier", linkageSpecifier);
	addMember(elem, "storageSpecifiers", storageSpecifiers);
	addMember(elem, "accessKind", accessKind);
	addMember(elem, "functionMemberAttributes", functionMemberAttributes);
	addMember(elem, "declRef", declRef);
	addMember(elem, "type", type);
	addMember(elem, "identifierName", identifierName);
	addMember(elem, "formalParameters", (std::vector<GASTMObject *> *)formalParameters);
	addMember(elem, "body", body);
	addMember(elem, "opensScope", opensScope);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
