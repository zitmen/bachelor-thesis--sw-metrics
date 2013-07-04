/*!
 * \file
 * VariableDeclaration.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_VARIABLE_DECLARATION_H_
#define _ASTM_VARIABLE_DECLARATION_H_

#include <vector>

#include "Declaration.h"
#include "XmlDump.h"

/*!
 * \brief
 * Variable declarations.
 *
 * \section cpp C++
 * - example:
 * \code
mutable int x;	// this->mutable = true
\endcode
 *
 * \see Declaration
 */
class VariableDeclaration : public Declaration
{
	public:
		VariableDeclaration();
		virtual ~VariableDeclaration();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Specifies if the variable is mutable or not.
		 */
		bool isMutable;
};

#endif	// _ASTM_VARIABLE_DECLARATION_H_
