/*!
 * \file
 * Private.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_PRIVATE_H_
#define _ASTM_PRIVATE_H_

#include <vector>

#include "AccessKind.h"
#include "XmlDump.h"

/*!
 * \brief
 * Specifies that the associated member or base class provides private access.
 *
 * \section cpp C++
 * - example:
 * \code
class A : private B
{
	void foo();	// also private (default C++ class behaviour)
	
	private:
		void bar();
};
\endcode
 */
class Private : public AccessKind
{
	public:
		Private();
		virtual ~Private();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_PRIVATE_H_
