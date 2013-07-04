/*!
 * \file
 * AggregateExpression.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_AGGREGATE_EXPRESSION_H_
#define _ASTM_AGGREGATE_EXPRESSION_H_

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
class AggregateExpression : public Expression
{
	public:
		AggregateExpression();
		virtual ~AggregateExpression();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		std::vector<Expression *> expressions;
};

#endif	// _ASTM_AGGREGATE_EXPRESSION_H_
