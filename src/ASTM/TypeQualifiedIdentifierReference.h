/*!
 * \file
 * TypeQualifiedIdentifierReference.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_TYPE_QUALIFIED_IDENTIFIER_REFERENCE_H_
#define _ASTM_TYPE_QUALIFIED_IDENTIFIER_REFERENCE_H_

#include <vector>

#include "NameReference.h"
#include "XmlDump.h"

class IdentifierReference;
class TypeReference;

/*!
 * \brief
 * Represents .
 *
 * \section cpp C++
 * - example:
 * \code

\endcode
 */
class TypeQualifiedIdentifierReference : public NameReference
{
	public:
		TypeQualifiedIdentifierReference();
		virtual ~TypeQualifiedIdentifierReference();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		IdentifierReference *member;
		std::vector<TypeReference *> aggregateType;
};

#endif	// _ASTM_TYPE_QUALIFIED_IDENTIFIER_REFERENCE_H_
