/*!
 * \file
 * Dimension.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_DIMENSION_H_
#define _ASTM_DIMENSION_H_

#include <vector>

#include "OtherSyntaxObject.h"
#include "XmlDump.h"

class Expression;

/*!
 * \brief
 * Range of subscript values for one dimension of an array type.
 *
 * \section cpp C++
 * - example:
 * \code
int p[4];	// highBound = "4", lowBound remains unset as default because low bound is 0 (default value)
\endcode
 *
 * \section pascal Pascal
 * - example:
 * \code
var p: array[1..4] of integer;	{ lowBound = "1", highBound = "4" }
\endcode
 */
class Dimension : public OtherSyntaxObject
{
	public:
		Dimension();
		virtual ~Dimension();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Low bound of array.
		 */
		Expression *lowBound;
		
		/*!
		 * \brief
		 * Hight bound of array.
		 */
		Expression *highBound;
};

#endif	// _ASTM_DIMENSION_H_
