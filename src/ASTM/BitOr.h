/*!
 * \file
 * BitOr.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_BIT_OR_H_
#define _ASTM_BIT_OR_H_

#include <vector>

#include "BinaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents bit OR operator.
 *
 * \section cpp C++
 * - operator: |
 * - example:
 * \code
x | 0x0F
\endcode
 */
class BitOr : public BinaryOperator
{
	public:
		BitOr();
		virtual ~BitOr();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_BIT_OR_H_
