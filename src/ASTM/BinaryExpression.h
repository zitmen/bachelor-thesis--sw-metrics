/*!
 * \file
 * BinaryExpression.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_BINARY_EXPRESSION_H_
#define _ASTM_BINARY_EXPRESSION_H_

#include <vector>

#include "Expression.h"
#include "XmlDump.h"

class BinaryOperator;

/*!
 * \brief
 * Represents any of binary expressions (addition, subtraction, assignment, etc.).
 *
 * \section cpp C++
 * - example:
 * \code
a + b	// leftOperand = "a", op = "+", rightOperand = "b"
\endcode
 */
class BinaryExpression : public Expression
{
	public:
		BinaryExpression();
		virtual ~BinaryExpression();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		BinaryOperator *op;
		Expression *leftOperand;
		Expression *rightOperand;
};

#endif	// _ASTM_BINARY_EXPRESSION_H_
