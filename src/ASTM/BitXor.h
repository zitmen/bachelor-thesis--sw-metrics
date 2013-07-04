/*!
 * \file
 * BitXor.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_BIT_XOR_H_
#define _ASTM_BIT_XOR_H_

#include <vector>

#include "BinaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents bit XOR operator.
 *
 * \section cpp C++
 * - operator: ^
 * - example:
 * \code
x ^ 0x0F
\endcode
 */
class BitXor : public BinaryOperator
{
	public:
		BitXor();
		virtual ~BitXor();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_BIT_XOR_H_
