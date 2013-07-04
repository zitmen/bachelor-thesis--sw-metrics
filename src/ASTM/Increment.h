/*!
 * \file
 * Increment.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_INCREMENT_H_
#define _ASTM_INCREMENT_H_

#include <vector>

#include "UnaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents incrementation operator.
 *
 * \section cpp C++
 * - operator: ++
 * - example:
 * \code
++x
\endcode
 */
class Increment : public UnaryOperator
{
	public:
		Increment();
		virtual ~Increment();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_INCREMENT_H_
