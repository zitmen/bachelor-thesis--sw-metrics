/*!
 * \file
 * NewExpression.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_NEW_EXPRESSION_H_
#define _ASTM_NEW_EXPRESSION_H_

#include <vector>

#include "Expression.h"
#include "XmlDump.h"

class ActualParameter;
class TypeReference;

/*!
 * \brief
 * Represents memory allocation expression via new operator.
 *
 * \section cpp C++
 * - example:
 * Calling the operator
 * \code
new(2,f) T[5]
\endcode
 * expands to
 * \code
new[](sizeof(T)*5+y,2,f)
\endcode
 * so it's saved as
 * newType = "T"
 * actualParams[0] = "5"
 * actualParams[1] = "2"
 * actualParams[2] = "f"
 */
class NewExpression : public Expression
{
	public:
		NewExpression();
		virtual ~NewExpression();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		TypeReference *newType;
		std::vector<ActualParameter *> actualParams;
};

#endif	// _ASTM_NEW_EXPRESSION_H_
