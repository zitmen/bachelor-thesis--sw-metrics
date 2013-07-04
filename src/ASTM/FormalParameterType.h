/*!
 * \file
 * FormalParameterType.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_FORMAL_PARAMETER_TYPE_H_
#define _ASTM_FORMAL_PARAMETER_TYPE_H_

#include <vector>

#include "DataType.h"

class TypeReference;

/*!
 * \brief
 * Specifies the by-value/reference nature of formal parameters.
 *
 * \section cpp C++
 * - example:
 * \code
// function declarations
void foo(Object o);		// this = new ByValueFormalParameterType(), this->type = "int"
void foo(Object &o);	// this = new ByReferenceFormalParameterType(), this->type = "int"
\endcode
 */
class FormalParameterType : public DataType
{
	public:
		FormalParameterType();
		virtual ~FormalParameterType() = 0;
		
		virtual void identify(std::vector<int> &id) const;
		
		/*!
		 * \brief
		 * Specifies type of parameter that is passed into a function.
		 *
		 * \see TypeReference
		 */
		TypeReference *type;
};

#endif	// _ASTM_FORMAL_PARAMETER_TYPE_H_
