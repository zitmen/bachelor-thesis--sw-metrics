/*!
 * \file
 * RangeType.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_RANGE_TYPE_H_
#define _ASTM_RANGE_TYPE_H_

#include <vector>

#include "ConstructedType.h"
#include "XmlDump.h"

class Expression;

/*!
 * \brief
 * Types whose values are ranges.
 *
 * \section python Python
 * - example:
 * \code
x = range(5, 10);	# this->lowBound = "5", this->highBound = "10"
\endcode
 */
class RangeType : public ConstructedType
{
	public:
		RangeType();
		virtual ~RangeType();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Low bound of range.
		 */
		Expression *lowBound;
		
		/*!
		 * \brief
		 * High bound of range.
		 */
		Expression *highBound;
};

#endif	// _ASTM_RANGE_TYPE_H_
