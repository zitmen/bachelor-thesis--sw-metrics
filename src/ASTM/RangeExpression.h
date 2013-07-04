/*!
 * \file
 * RangeExpression.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_RANGE_EXPRESSION_H_
#define _ASTM_RANGE_EXPRESSION_H_

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
class RangeExpression : public Expression
{
	public:
		RangeExpression();
		virtual ~RangeExpression();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		Expression *fromExpression;
		Expression *toExpression;
};

#endif	// _ASTM_RANGE_EXPRESSION_H_
