/*!
 * \file
 * Scope.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_SCOPE_H_
#define _ASTM_SCOPE_H_

#include <vector>

#include "GASTMSemanticObject.h"

class DefinitionUnit;

/*!
 * \brief
 * Declaration context in which names declared must be unique.
 */
class Scope : public GASTMSemanticObject
{
	public:
		Scope();
		virtual ~Scope() = 0;
		
		virtual void identify(std::vector<int> &id) const;
		
		void addChildScope(Scope *scope);
		bool removeChildScope(Scope *scope);
		
		void addScopeMember(DefinitionUnit *d);
		bool removeScopeMember(DefinitionUnit *d);
		
		/*!
		 * \brief
		 * Link to parent scope. Together with childScope forms two way semantic association.
		 */
		Scope *parentScope;
		
		/*!
		 * \brief
		 * Links to childrens. Together with parentScope forms two way semantic association.
		 */
		std::vector<Scope *> *childScope;
		
		/*!
		 * \brief
		 * Objects in scope that should be unique. This is kind of symbol table for this block.
		 *
		 * \section cpp C++
		 * - example:
		 * \code
int b = 3;
double result;
{	// -> start of block
	int a = 5;
	double c = 1.5;
	result = (double)a * c + (double)b
}	// -> end of block
\endcode
		 *
		 * => definitionObject will contain variable declarations of "a" and "c"
		 */
		std::vector<DefinitionUnit *> *definitionObject;
};

#endif	// _ASTM_SCOPE_H_
