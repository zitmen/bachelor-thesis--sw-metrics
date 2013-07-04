/*!
 * \file
 * FunctionCallExpression.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_FUNCTION_CALL_EXPRESSION_H_
#define _ASTM_FUNCTION_CALL_EXPRESSION_H_

#include <vector>

#include "Expression.h"
#include "XmlDump.h"

class ActualParameter;

/*!
 * \brief
 * Represents .
 *
 * \section cpp C++
 * - example:
 * \code

\endcode
 */
class FunctionCallExpression : public Expression
{
	public:
		FunctionCallExpression();
		virtual ~FunctionCallExpression();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		Expression *calledFunction;
		std::vector<ActualParameter *> *actualParams;
};

#endif	// _ASTM_FUNCTION_CALL_EXPRESSION_H_
