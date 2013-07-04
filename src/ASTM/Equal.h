/*!
 * \file
 * Equal.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_EQUAL_H_
#define _ASTM_EQUAL_H_

#include <vector>

#include "BinaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents operator for equal to comparison.
 *
 * \section cpp C++
 * - operator: ==
 * - example:
 * \code
x == 5
\endcode
 */
class Equal : public BinaryOperator
{
	public:
		Equal();
		virtual ~Equal();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_EQUAL_H_
