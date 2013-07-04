/*!
 * \file
 * ArrayType.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_ARRAY_TYPE_H_
#define _ASTM_ARRAY_TYPE_H_

#include <vector>

#include "ConstructedType.h"
#include "XmlDump.h"

class Dimension;

/*!
 * \brief
 * Array types.
 *
 * \section cpp C++
 * - example:
 * \code
int arr[5][3];	// this->ranks = { "5", "3" }
\endcode
 *
 * \see ConstructedType
 */
class ArrayType : public ConstructedType
{
	public:
		ArrayType();
		virtual ~ArrayType();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Array dimensions.
		 *
		 * \see Dimension
		 */
		std::vector<Dimension *> ranks;
};

#endif	// _ASTM_ARRAY_TYPE_H_
