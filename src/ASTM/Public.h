/*!
 * \file
 * Public.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_PUBLIC_H_
#define _ASTM_PUBLIC_H_

#include <vector>

#include "AccessKind.h"
#include "XmlDump.h"

/*!
 * \brief
 * Specifies that the associated member or base class provides public access.
 *
 * \section cpp C++
 * - example:
 * \code
class A : public B
{
	public:
		void foo();
};
\endcode
 */
class Public : public AccessKind
{
	public:
		Public();
		virtual ~Public();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_PUBLIC_H_
