/*!
 * \file
 * AggregateType.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_AGGREGATE_TYPE_H_
#define _ASTM_AGGREGATE_TYPE_H_

#include <vector>

#include "DataType.h"
#include "AggregateScope.h"
#include "DefinitionUnit.h"

/*!
 * \brief
 * Types composed of heterogenous subtypes.
 *
 * \section cpp C++
 * - example:
 * \code
struct A
{
	int a;
	long b;
	char c;
};
\endcode
 * this->members = { "int a", "long b", "char c" }, this->opensScope = { "a", "b", "c" }
 */
class AggregateType : public DataType
{
	public:
		AggregateType();
		virtual ~AggregateType() = 0;
		
		virtual void identify(std::vector<int> &id) const;
		
		/*!
		 * \brief
		 * Set of members.
		 *
		 * \see DefinitionUnit
		 */
		std::vector<DefinitionUnit *> *members;
		
		/*!
		 * \brief
		 * Scope stores all aggregated declarations/definitions.
		 *
		 * \see AggregateScope
		 */
		AggregateScope *opensScope;
};

#endif	// _ASTM_AGGREGATE_TYPE_H_
