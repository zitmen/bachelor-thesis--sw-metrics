/*!
 * \file
 * PrimitiveType.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_PRIMITIVE_TYPE_H_
#define _ASTM_PRIMITIVE_TYPE_H_

#include <vector>

#include "DataType.h"

/*!
 * \brief
 * Primitive types; not further decomposable.
 *
 * \section cpp C++
 * - example:
 * \code
int a;			// this->signed = "true"
unsigned int b;	// this->signed = "false"
\endcode
 */
class PrimitiveType : public DataType
{
	public:
		PrimitiveType();
		virtual ~PrimitiveType() = 0;
		
		virtual void identify(std::vector<int> &id) const;
		
		/*!
		 * \brief
		 * Specifies if type is signed or unsigned.
		 */
		bool isSigned;
};

#endif	// _ASTM_PRIMITIVE_TYPE_H_
