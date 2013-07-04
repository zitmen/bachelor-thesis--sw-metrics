/*!
 * \file
 * ConditionalExpression.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_CONDITIONAL_EXPRESSION_H_
#define _ASTM_CONDITIONAL_EXPRESSION_H_

#include <vector>

#include "Expression.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents .
 *
 * \section cpp C++
 * - example:
 * \code

\endcode
 */
class ConditionalExpression : public Expression
{
	public:
		ConditionalExpression();
		virtual ~ConditionalExpression();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		Expression *condition;
		Expression *onTrueOperand;
		Expression *onFalseOperand;
};

#endif	// _ASTM_CONDITIONAL_EXPRESSION_H_
