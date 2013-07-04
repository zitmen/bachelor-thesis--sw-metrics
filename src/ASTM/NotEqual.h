/*!
 * \file
 * NotEqual.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_NOT_EQUAL_H_
#define _ASTM_NOT_EQUAL_H_

#include <vector>

#include "BinaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents operator for not equal comparison.
 *
 * \section cpp C++
 * - operator: !=
 * - example:
 * \code
x != 5
\endcode
 */
class NotEqual : public BinaryOperator
{
	public:
		NotEqual();
		virtual ~NotEqual();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_NOT_EQUAL_H_
