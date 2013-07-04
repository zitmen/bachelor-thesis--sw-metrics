/*!
 * \file
 * Declaration.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_DECLARATION_H_
#define _ASTM_DECLARATION_H_

#include <vector>

#include "DeclarationOrDefinition.h"

class Definition;
class TypeReference;

/*!
 * \brief
 * Constructs that delare entities without defining them.
 *
 * \section cpp C++
 * - example:
 * \code
 1| int foo();	// defRef = definition begining on line 11, identifierName = "foo", type = "int"
 2| 
  | ...
10| 
11| int foo()
12| {
  | 	...
21| }
\endcode
 *
 * \see DeclarationOrDefinition
 */
class Declaration : public DeclarationOrDefinition
{
	public:
		Declaration();
		virtual ~Declaration() = 0;
		
		virtual void identify(std::vector<int> &id) const;
		
		/*!
		 * \brief
		 * Reference to definition of declared entity.
		 *
		 * \see Definition
		 */
		Definition *defRef;
};

#endif	// _ASTM_DECLARATION_H_
