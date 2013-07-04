/*!
 * \file
 * Exponent.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_EXPONENT_H_
#define _ASTM_EXPONENT_H_

#include <vector>

#include "BinaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents exponentiation operator.
 *
 * \section Python
 * - operator: **
 * - example:
 * \code
3 ** 2	# = 9
\endcode
 */
class Exponent : public BinaryOperator
{
	public:
		Exponent();
		virtual ~Exponent();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_EXPONENT_H_
