/*!
 * \file
 * Subtract.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_SUBTRACT_H_
#define _ASTM_SUBTRACT_H_

#include <vector>

#include "BinaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents subtraction operator.
 *
 * \section cpp C++
 * - operator: -
 * - example:
 * \code
x - y
\endcode
 */
class Subtract : public BinaryOperator
{
	public:
		Subtract();
		virtual ~Subtract();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_SUBTRACT_H_
