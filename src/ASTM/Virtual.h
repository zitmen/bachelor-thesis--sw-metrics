/*!
 * \file
 * Virtual.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_VIRTUAL_H_
#define _ASTM_VIRTUAL_H_

#include <vector>

#include "VirtualSpecification.h"
#include "XmlDump.h"

/*!
 * \brief
 * Specifies that the associated function member is virtual.
 *
 * \section cpp C++
 * - example:
 * \code
class A
{
	virtual void foo();
};
\endcode
 */
class Virtual : public VirtualSpecification
{
	public:
		Virtual();
		virtual ~Virtual();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_VIRTUAL_H_
