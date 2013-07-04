/*!
 * \file
 * NameReference.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_NAME_REFERENCE_H_
#define _ASTM_NAME_REFERENCE_H_

#include <vector>

#include "DefinitionUnit.h"
#include "Expression.h"
#include "Name.h"

class DefinitionUnit;

/*!
 * \brief
 * Represents .
 *
 * \section cpp C++
 * - example:
 * \code

\endcode
 */
class NameReference : public Expression
{
	public:
		NameReference();
		virtual ~NameReference() = 0;
		
		virtual void identify(std::vector<int> &id) const;
		
		Name *name;
		DefinitionUnit *refersTo;
};

#endif	// _ASTM_NAME_REFERENCE_H_
