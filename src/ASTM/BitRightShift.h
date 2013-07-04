/*!
 * \file
 * BitRightShift.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_BIT_RIGHT_SHIFT_H_
#define _ASTM_BIT_RIGHT_SHIFT_H_

#include <vector>

#include "BinaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents bit right shifting operator.
 *
 * \section cpp C++
 * - operator: >>
 * - example:
 * \code
x >> 2
\endcode
 */
class BitRightShift : public BinaryOperator
{
	public:
		BitRightShift();
		virtual ~BitRightShift();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_BIT_RIGHT_SHIFT_H_
