/*!
 * \file
 * NamedTypeDefinition.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_NAMED_TYPE_DEFINITION_H_
#define _ASTM_NAMED_TYPE_DEFINITION_H_

#include <vector>

#include "TypeDefinition.h"
#include "XmlDump.h"

class NamedType;

/*!
 * \brief
 * Definitions of types to be refered by specified name.
 *
 * \section cpp C++
 * - example:
 * \code
typedef BYTE unsigned char;	// this->definitionType = "unsigned char" (typedef body), this->name = "BYTE" (typedef name)
\endcode
 *
 * \see TypeDefinition
 */
class NamedTypeDefinition : public TypeDefinition
{
	public:
		NamedTypeDefinition();
		virtual ~NamedTypeDefinition();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Type that is defined as NamedType.
		 *
		 * \see NamedType
		 */
		NamedType *definitionType;
};

#endif	// _ASTM_NAMED_TYPE_DEFINITION_H_
