/*!
 * \file
 * PureVirtual.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_PURE_VIRTUAL_H_
#define _ASTM_PURE_VIRTUAL_H_

#include <vector>

#include "VirtualSpecification.h"
#include "XmlDump.h"

/*!
 * \brief
 * Specifies that the associated function member is pure virtual.
 *
 * \section cpp C++
 * - example:
 * \code
class A
{
	virtual void foo() = 0;
};
\endcode
 */
class PureVirtual : public VirtualSpecification
{
	public:
		PureVirtual();
		virtual ~PureVirtual();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_PURE_VIRTUAL_H_
