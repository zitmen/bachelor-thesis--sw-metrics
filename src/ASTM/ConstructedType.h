/*!
 * \file
 * ConstructedType.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_CONSTRUCTED_TYPE_H_
#define _ASTM_CONSTRUCTED_TYPE_H_

#include <vector>

#include "DataType.h"

class TypeReference;

/*!
 * \brief
 * Types constructed from a specified base type.
 *
 * \section cpp C++
 * - example:
 * \code
int *a;	// this = new PointerType(), this->baseType = "int"
\endcode
 */
class ConstructedType : public DataType
{
	public:
		ConstructedType();
		virtual ~ConstructedType() = 0;
		
		virtual void identify(std::vector<int> &id) const;
		
		/*!
		 * \brief
		 * Base type.
		 *
		 * \see TypeReference
		 */
		TypeReference *baseType;
};

#endif	// _ASTM_CONSTRUCTED_TYPE_H_
