/*!
 * \file
 * ActualParameter.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_ACTUAL_PARAMETER_H_
#define _ASTM_ACTUAL_PARAMETER_H_

#include <vector>

#include "OtherSyntaxObject.h"
#include "Expression.h"

/*!
 * \brief
 * Represents actual parameters involving expression.
 *
 * \section cpp C++
 * - example:
 * \code
// declaration & definition
void foo(int a, int *b, int *c = NULL) { ... }

// function call
foo(4, &x);	// 1st and 2nd arguments are ActualParameterExpression, 3rd argument is MissingActualParameter
\endcode
 */
class ActualParameter : public OtherSyntaxObject
{
	public:
		ActualParameter();
		virtual ~ActualParameter();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		Expression *value;
};

#endif	// _ASTM_ACTUAL_PARAMETER_H_
