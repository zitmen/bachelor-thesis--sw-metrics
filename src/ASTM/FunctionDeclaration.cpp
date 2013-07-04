#include "NodeId.h"
#include "FunctionDeclaration.h"
#include "FunctionMemberAttributes.h"
#include "FormalParameterDefinition.h"

FunctionDeclaration::FunctionDeclaration()
{
	functionMemberAttributes = NULL;
	formalParameters = NULL;
}

FunctionDeclaration::~FunctionDeclaration()
{
	if(functionMemberAttributes) delete functionMemberAttributes;
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
FunctionDeclaration::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::FUNCTION_DECLARATION);
	Declaration::identify(id);
}

void
FunctionDeclaration::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "FunctionDeclaration");
	addMember(elem, "isRegister", isRegister);
	addMember(elem, "linkageSpecifier", linkageSpecifier);
	addMember(elem, "storageSpecifiers", storageSpecifiers);
	addMember(elem, "accessKind", accessKind);
	addMember(elem, "functionMemberAttributes", functionMemberAttributes);
	//addMember(elem, "defRef", defRef);
	addMember(elem, "type", type);
	addMember(elem, "identifierName", identifierName);
	addMember(elem, "formalParameters", (std::vector<GASTMObject *> *)formalParameters);
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
