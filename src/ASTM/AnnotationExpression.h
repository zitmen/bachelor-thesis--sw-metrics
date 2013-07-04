/*!
 * \file
 * AnnotationExpression.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_ANNOTATION_EXPRESSION_H_
#define _ASTM_ANNOTATION_EXPRESSION_H_

#include <vector>

#include "Expression.h"
#include "XmlDump.h"

class TypeReference;

/*!
 * \brief
 * Represents .
 *
 * \section cpp C++
 * - example:
 * \code

\endcode
 */
class AnnotationExpression : public Expression
{
	public:
		AnnotationExpression();
		virtual ~AnnotationExpression();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		TypeReference *annotationType;
		std::vector<Expression *> memberValues;
};

#endif	// _ASTM_ANNOTATION_EXPRESSION_H_
