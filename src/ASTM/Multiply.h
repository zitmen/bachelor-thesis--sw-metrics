/*!
 * \file
 * Multiply.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_MULTIPLY_H_
#define _ASTM_MULTIPLY_H_

#include <vector>

#include "BinaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents miltiplication operator.
 *
 * \section cpp C++
 * - operator: *
 * - example:
 * \code
x * y
\endcode
 */
class Multiply : public BinaryOperator
{
	public:
		Multiply();
		virtual ~Multiply();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_MULTIPLY_H_
