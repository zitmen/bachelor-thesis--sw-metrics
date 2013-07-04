/*!
 * \file
 * Add.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_ADD_H_
#define _ASTM_ADD_H_

#include <vector>

#include "BinaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents addition operator.
 *
 * \section cpp C++
 * - operator: +
 * - example:
 * \code
x + y
\endcode
 */
class Add : public BinaryOperator
{
	public:
		Add();
		virtual ~Add();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_ADD_H_
