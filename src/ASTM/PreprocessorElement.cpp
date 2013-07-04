#include "NodeId.h"
#include "PreprocessorElement.h"

PreprocessorElement::PreprocessorElement()
{
	//
}

PreprocessorElement::~PreprocessorElement()
{
	//
}

void
PreprocessorElement::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::PREPROCESSOR_ELEMENT);
	GASTMSyntaxObject::identify(id);
}

void
PreprocessorElement::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "PreprocessorElement");
	addMember(elem, "locFirst", locFirst);
	addMember(elem, "locLast", locLast);
}
