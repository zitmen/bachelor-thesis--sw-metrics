/*!
 * \file
 * Deref.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_DEREF_H_
#define _ASTM_DEREF_H_

#include <vector>

#include "UnaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents dereferencing operator.
 *
 * \section cpp C++
 * - operator: *
 * - example:
 * \code
*x
\endcode
 */
class Deref : public UnaryOperator
{
	public:
		Deref();
		virtual ~Deref();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_DEREF_H_
