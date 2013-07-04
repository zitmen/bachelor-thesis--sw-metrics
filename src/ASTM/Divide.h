/*!
 * \file
 * Divide.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_DIVIDE_H_
#define _ASTM_DIVIDE_H_

#include <vector>

#include "BinaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents division operator.
 *
 * \section cpp C++
 * - operator: /
 * - example:
 * \code
x / 2
\endcode
 */
class Divide : public BinaryOperator
{
	public:
		Divide();
		virtual ~Divide();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_DIVIDE_H_
