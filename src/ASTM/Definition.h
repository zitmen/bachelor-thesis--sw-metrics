/*!
 * \file
 * Definition.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_DEFINITION_H_
#define _ASTM_DEFINITION_H_

#include <vector>

#include "DeclarationOrDefinition.h"
#include "Declaration.h"

/*!
 * \brief
 * Constructs that declare entities as they also define them.
 *
 * \section cpp C++
 * - example:
 * \code
 1| int foo();
 2| 
  | ...
10| 
11| int foo()	// this->declRef = declaration on line 1, this->identifierName = "foo", this->type = "int"
12| {
  | 	...
21| }
\endcode
 */
class Definition : public DeclarationOrDefinition
{
	public:
		Definition();
		virtual ~Definition() = 0;
		
		virtual void identify(std::vector<int> &id) const;
		
		/*!
		 * \brief
		 * Reference to declaration of defined entity.
		 * If there is no preceding declaration, then declRef can
		 * be set to NULL or it can be created explicitly.
		 *
		 * \see Declaration
		 */
		Declaration *declRef;
};

#endif	// _ASTM_DEFINITION_H_
