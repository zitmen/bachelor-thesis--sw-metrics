/*!
 * \file
 * FunctionDeclaration.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_FUNCTION_DECLARATION_H_
#define _ASTM_FUNCTION_DECLARATION_H_

#include <vector>

#include "Declaration.h"
#include "XmlDump.h"

class FunctionMemberAttributes;
class FormalParameterDefinition;

/*!
 * \brief
 * Function declarations.
 *
 * \section cpp C++
 * - example:
 * \code
int foo(int bar1, char);	// this->functionMemberAttributes = NULL (because function is not member of any class),
							// this->formalParameters = { "int bar1", "char" } (C++ function delaration must specify parameters types, not names)
\endcode
 *
 * \see Declaration
 */
class FunctionDeclaration : public Declaration
{
	public:
		FunctionDeclaration();
		virtual ~FunctionDeclaration();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * List of function parameters.
		 * FormalParameters are type of FormalParameterDEFINITION, because in C++,
		 * could be written "void foo(int a = 0);" to set default value.
		 *
		 * \see FormalParameterDefinition
		 */
		std::vector<FormalParameterDefinition *> *formalParameters;
		
		/*!
		 * \brief
		 * Specifies if member function is virtual, friend, const or inline.
		 *
		 * \see FunctionMemberAttributes
		 */
		FunctionMemberAttributes *functionMemberAttributes;
};

#endif	// _ASTM_FUNCTION_DECLARATION_H_
