/*!
 * \file
 * NameSpaceDefinition.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_NAME_SPACE_DEFINITION_H_
#define _ASTM_NAME_SPACE_DEFINITION_H_

#include <vector>

#include "DefinitionUnit.h"
#include "XmlDump.h"

class Name;
class NameSpaceScope;
class NameSpaceType;

/*!
 * \brief
 * Definitions of namespaces.
 *
 * \section cpp C++
 * - example:
 * \code
namespace Directions	// this->nameSpace = "Directions", nameSpaceType = new NameSpaceType()
{	// -> start of this->body
	enum
	{
		LEFT,
		RIGHT,
		UP,
		DOWN
	}
}	// -> end of this->body
\endcode
 */
class NameSpaceDefinition : public DefinitionUnit
{
	public:
		NameSpaceDefinition();
		virtual ~NameSpaceDefinition();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Type of namespace (only semantical meaning - determines that this is a namespace).
		 *
		 * \see NameSpaceType
		 */
		NameSpaceType *nameSpaceType;
		
		/*!
		 * \brief
		 * Namespace name.
		 *
		 * \see Name
		 */
		Name *nameSpace;
		
		/*!
		 * \brief
		 * Content of namespace.
		 *
		 * \see DefinitionUnit
		 */
		std::vector<DefinitionUnit *> *body;
		
		/*!
		 * \brief
		 * List of variables declared inside of the namespace.
		 *
		 * \see \ref example
		 * \see NameSpaceScope
		 */
		NameSpaceScope *opensScope;
};

#endif	// _ASTM_NAME_SPACE_DEFINITION_H_
