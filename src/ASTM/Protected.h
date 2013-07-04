/*!
 * \file
 * Protected.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_PROTECTED_H_
#define _ASTM_PROTECTED_H_

#include <vector>

#include "AccessKind.h"
#include "XmlDump.h"

/*!
 * \brief
 * Specifies that the associated member or base class provides protected access.
 *
 * \section cpp C++
 * - example:
 * \code
class A : protected B
{
	protected:
		void foo();
};
\endcode
 */
class Protected : public AccessKind
{
	public:
		Protected();
		virtual ~Protected();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_PROTECTED_H_
