/*!
 * \file
 * Less.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_LESS_H_
#define _ASTM_LESS_H_

#include <vector>

#include "BinaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents operator for less than comparison.
 *
 * \section cpp C++
 * - operator: <
 * - example:
 * \code
x < 5
\endcode
 */
class Less : public BinaryOperator
{
	public:
		Less();
		virtual ~Less();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_LESS_H_
