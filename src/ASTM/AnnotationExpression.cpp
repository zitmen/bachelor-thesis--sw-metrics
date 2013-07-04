#include "NodeId.h"
#include "AnnotationExpression.h"
#include "TypeReference.h"

AnnotationExpression::AnnotationExpression()
{
	annotationType = NULL;
}

AnnotationExpression::~AnnotationExpression()
{
	if(annotationType) delete annotationType;
	//
	for(size_t i = 0, im = memberValues.size(); i < im; ++i)
		if(memberValues[i])
			delete memberValues[i];
	//
	memberValues.clear();
}

void
AnnotationExpression::identify(std::vector<int> &id) const
{
	id.push_back(NodeId::ANNOTATION_EXPRESSION);
	Expression::identify(id);
}

void
AnnotationExpression::dumpXml(TiXmlElement *parent) const
{
	TiXmlElement *elem = addClass(parent, "AnnotationExpression");
	//addMember(elem, "locationInfo", locationInfo);
}
