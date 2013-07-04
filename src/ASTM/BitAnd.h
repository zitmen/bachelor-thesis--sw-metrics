/*!
 * \file
 * BitAnd.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_BIT_AND_H_
#define _ASTM_BIT_AND_H_

#include <vector>

#include "BinaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents bit AND operator.
 *
 * \section cpp C++
 * - operator: &
 * - example:
 * \code
x & 0x0F
\endcode
 */
class BitAnd : public BinaryOperator
{
	public:
		BitAnd();
		virtual ~BitAnd();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_BIT_AND_H_
