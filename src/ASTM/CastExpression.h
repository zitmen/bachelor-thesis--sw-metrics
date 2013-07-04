/*!
 * \file
 * CastExpression.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_CAST_EXPRESSION_H_
#define _ASTM_CAST_EXPRESSION_H_

#include <vector>

#include "Expression.h"
#include "XmlDump.h"

class TypeReference;

/*!
 * \brief
 * Expressions that are cast to a specified type.
 *
 * \section cpp C++
 * - example:
 * \code
(int)(3.5 * 7.44)	// castType = "int", expression = "3.5 * 7.44"
\endcode
 */
class CastExpression : public Expression
{
	public:
		CastExpression();
		virtual ~CastExpression();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		TypeReference *castType;
		Expression *expression;
};

#endif	// _ASTM_CAST_EXPRESSION_H_
