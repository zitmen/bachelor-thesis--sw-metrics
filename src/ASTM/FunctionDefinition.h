/*!
 * \file
 * FunctionDefinition.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_FUNCTION_DEFINITION_H_
#define _ASTM_FUNCTION_DEFINITION_H_

#include <vector>

#include "Definition.h"
#include "XmlDump.h"

class FunctionMemberAttributes;
class FormalParameterDefinition;
class TypeReference;
class FunctionScope;
class Statement;

/*!
 * \brief
 * Subprogram definitions.
 *
 * \section cpp C++
 * - example:
 * \code
int foo(int bar1, char bar2)	// this->functionMemberAttributes = NULL (because function is not member of any class), this->formalParameters = { "int bar1", "char bar2" }
{	// -> start of this->body
	int x = 3;
	return x + bar1 * bar2;
}	// -> end of this->body
\endcode
 *
 * this->opensScope = { "int bar1", "char bar2", "int x" }
 *
 * \see Definition
 */
class FunctionDefinition : public Definition
{
	public:
		FunctionDefinition();
		virtual ~FunctionDefinition();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Specifies if member function is virtual, friend, const or inline.
		 *
		 * \see FunctionMemberAttributes
		 */
		FunctionMemberAttributes *functionMemberAttributes;
		
		/*!
		 * \brief
		 * List of function parameters.
		 * FormalParameters are type of FormalParameterDEFINITION, because in C++ or Java,
		 * could be written "void foo(int a = 0) { ... }" to set default parameter value.
		 *
		 * \see FormalParameterDefinition
		 */
		std::vector<FormalParameterDefinition *> *formalParameters;
		
		/*!
		 * \brief
		 * Function scope = list of declared variables inside the function (including formal parameters).
		 *
		 * \see FunctionScope
		 */
		FunctionScope *opensScope;
		
		
		/*!
		 * \brief
		 * Body of function.
		 *
		 * \see Statement
		 */
		Statement *body;
};

#endif	// _ASTM_FUNCTION_DEFINITION_H_
