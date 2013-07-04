/*!
 * \file
 * NamedTypeReference.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_NAMED_TYPE_REFERENCE_H_
#define _ASTM_NAMED_TYPE_REFERENCE_H_

#include <vector>

#include "TypeReference.h"
#include "XmlDump.h"

class TypeDefinition;
class Name;

/*!
 * \brief
 * References to types via the name of the referenced type.
 *
 * \section cpp C++
 * - example:
 * \code
class A { ... };	// this->name = "A", this->aType = "class A { ... }"
\endcode
 */
class NamedTypeReference : public TypeReference
{
	public:
		NamedTypeReference();
		virtual ~NamedTypeReference();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Name of the type that is referenced.
		 *
		 * \see Name
		 */
		Name *name;
		
		/*!
		 * \brief
		 * Type that is referenced.
		 *
		 * \see TypeDefinition
		 */
		TypeDefinition *aType;
};

#endif	// _ASTM_NAMED_TYPE_REFERENCE_H_
