/*!
 * \file
 * Modulus.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_MODULUS_H_
#define _ASTM_MODULUS_H_

#include <vector>

#include "BinaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents modulo operator.
 *
 * \section cpp C++
 * - operator: %
 * - example:
 * \code
x % 10
\endcode
 */
class Modulus : public BinaryOperator
{
	public:
		Modulus();
		virtual ~Modulus();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_MODULUS_H_
