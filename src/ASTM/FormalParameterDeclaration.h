/*!
 * \file
 * FormalParameterDeclaration.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_FORMAL_PARAMETER_DECLARATION_H_
#define _ASTM_FORMAL_PARAMETER_DECLARATION_H_

#include <vector>

#include "Declaration.h"
#include "XmlDump.h"

/*!
 * \brief
 * Formal parameter declarations, appearing in function declarations.
 * Formal parameter declaration don't have to contain identifier name
 * or even a data type (f.e. in C++ function can be declared like this: "void foo(char *, int, ...)")
 *
 * \see Declaration
 * \see FunctionDeclaration
 */
class FormalParameterDeclaration : public Declaration
{
	public:
		FormalParameterDeclaration();
		virtual ~FormalParameterDeclaration();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_FORMAL_PARAMETER_DECLARATION_H_
