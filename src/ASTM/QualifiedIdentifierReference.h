/*!
 * \file
 * QualifiedIdentifierReference.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_QUALIFIED_IDENTIFIER_REFERENCE_H_
#define _ASTM_QUALIFIED_IDENTIFIER_REFERENCE_H_

#include <vector>

#include "NameReference.h"

class Expression;
class IdentifierReference;

/*!
 * \brief
 * Represents .
 *
 * \section cpp C++
 * - example:
 * \code

\endcode
 */
class QualifiedIdentifierReference : public NameReference
{
	public:
		QualifiedIdentifierReference();
		virtual ~QualifiedIdentifierReference() = 0;
		
		virtual void identify(std::vector<int> &id) const;
		
		Expression *qualifiers;
		IdentifierReference *member;
};

#endif	// _ASTM_QUALIFIED_IDENTIFIER_REFERENCE_H_
