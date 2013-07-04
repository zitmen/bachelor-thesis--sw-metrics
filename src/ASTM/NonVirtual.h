/*!
 * \file
 * NonVirtual.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_NON_VIRTUAL_H_
#define _ASTM_NON_VIRTUAL_H_

#include <vector>

#include "VirtualSpecification.h"
#include "XmlDump.h"

/*!
 * \brief
 * Specifies that the associated function member is not virtual.
 *
 * \section cpp C++
 * - example:
 * \code
class A
{
	void foo();
};
\endcode
 */
class NonVirtual : public VirtualSpecification
{
	public:
		NonVirtual();
		virtual ~NonVirtual();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_NON_VIRTUAL_H_
