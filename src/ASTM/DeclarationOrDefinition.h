/*!
 * \file
 * DeclarationOrDefinition.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_DECLARATION_OR_DEFINITION_H_
#define _ASTM_DECLARATION_OR_DEFINITION_H_

#include <string>
#include <vector>

#include "DefinitionUnit.h"
#include "StorageSpecification.h"
#include "AccessKind.h"
#include "TypeReference.h"
#include "Name.h"

/*!
 * \brief
 * Declarations and definitions.
 *
 * \section cpp C++
 * - example:
 * \code
class A
{
	register int counter;	// isRegister = true, storageSpecifier = NoDef, accessKind = Private, linkageSpecifier = "", identifierName = "counter"
};

__stdcall int foo();	// isRegister = false, storageSpecifier = NoDef, accessKind = NULL, linkageSpecifier = "__stdcall", identifierName = "foo"
\endcode
 */
class DeclarationOrDefinition : public DefinitionUnit
{
	public:
		DeclarationOrDefinition();
		virtual ~DeclarationOrDefinition() = 0;
		
		virtual void identify(std::vector<int> &id) const;
		
		/*!
		 * \brief
		 * Stores information about if this object is register or not.
		 */
		bool isRegister;
		
		/*!
		 * \brief
		 * Stores information for linker.
		 */
		std::string linkageSpecifier;
		
		/*!
		 * \brief
		 * Stores information about access to element represented by this object.
		 *
		 * \see AccessKind
		 */
		AccessKind *accessKind;
		
		/*!
		 * \brief
		 * Stores information about storage specification of element represented by this object.
		 *
		 * \see StorageSpecification
		 */
		StorageSpecification *storageSpecifiers;
		
		/*!
		 * \brief
		 * Type of declared or defined entity or return type of a function.
		 *
		 * \see TypeReference
		 */
		TypeReference *type;
		
		/*!
		 * \brief
		 * Name of declared or defined identifier.
		 *
		 * \see Name
		 */
		Name *identifierName;
};

#endif	// _ASTM_DECLARATION_OR_DEFINITION_H_
