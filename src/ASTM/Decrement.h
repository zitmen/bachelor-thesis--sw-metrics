/*!
 * \file
 * Decrement.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_DECREMENT_H_
#define _ASTM_DECREMENT_H_

#include <vector>

#include "UnaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents decrementation operator.
 *
 * \section cpp C++
 * - operator: --
 * - example:
 * \code
--x
\endcode
 */
class Decrement : public UnaryOperator
{
	public:
		Decrement();
		virtual ~Decrement();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_DECREMENT_H_
