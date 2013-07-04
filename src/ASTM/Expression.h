/*!
 * \file
 * Expression.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_EXPRESSION_H_
#define _ASTM_EXPRESSION_H_

#include <vector>

#include "GASTMSyntaxObject.h"
#include "TypeReference.h"

/*!
 * \brief
 * All expressions.
 *
 * \section example Example
 * - C++
 * \code
int a = 5, b = 2;	// For "a = (int)": this->expressionType = "int"; For "b = (int)": this->expressionType (int)
float c = a + b;	// For "a + b": this->expressionType = "int"; For "c = (int)": this->expressionType (float)
\endcode
 */
class Expression : public GASTMSyntaxObject
{
	public:
		Expression();
		virtual ~Expression() = 0;
		
		virtual void identify(std::vector<int> &id) const;
		
		/*!
		 * \brief
		 * Type of expression.
		 *
		 * \see \ref example
		 * \see TypeReference
		 */
		TypeReference *expressionType;
};

#endif	// _ASTM_EXPRESSION_H_
