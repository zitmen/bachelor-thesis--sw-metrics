/*!
 * \file
 * IdentifierReference.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_IDENTIFIER_REFERENCE_H_
#define _ASTM_IDENTIFIER_REFERENCE_H_

#include <vector>

#include "NameReference.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents .
 *
 * \section cpp C++
 * - example:
 * \code

\endcode
 */
class IdentifierReference : public NameReference
{
	public:
		IdentifierReference();
		virtual ~IdentifierReference();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_IDENTIFIER_REFERENCE_H_
