/*!
 * \file
 * UnaryExpression.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_UNARY_EXPRESSION_H_
#define _ASTM_UNARY_EXPRESSION_H_

#include <vector>

#include "Expression.h"
#include "XmlDump.h"

class UnaryOperator;

/*!
 * \brief
 * Represents .
 *
 * \section cpp C++
 * - example:
 * \code

\endcode
 */
class UnaryExpression : public Expression
{
	public:
		UnaryExpression();
		virtual ~UnaryExpression();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		UnaryOperator *op;
		Expression *operand;
};

#endif	// _ASTM_UNARY_EXPRESSION_H_
