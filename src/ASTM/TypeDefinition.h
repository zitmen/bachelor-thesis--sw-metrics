/*!
 * \file
 * TypeDefinition.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_TYPE_DEFINITION_H_
#define _ASTM_TYPE_DEFINITION_H_

#include <vector>

#include "DefinitionUnit.h"
#include "Name.h"
#include "XmlDump.h"

/*!
 * \brief
 * Definitions of types.
 *
 * \section cpp C++
 * - example:
 * \code
typedef BYTE unsigned char;	// this->name = "BYTE"
\endcode
 *
 * \see DefinitionUnit
 */
class TypeDefinition : public DefinitionUnit
{
	public:
		TypeDefinition();
		virtual ~TypeDefinition();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;

		/*!
		 * \brief
		 * Name of defined data type.
		 *
		 * \see Name
		 */
		Name *name;
};

#endif	// _ASTM_TYPE_DEFINITION_H_
