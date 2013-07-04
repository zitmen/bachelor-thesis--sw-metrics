/*!
 * \file
 * DataDefinition.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_DATA_DEFINITION_H_
#define _ASTM_DATA_DEFINITION_H_

#include <vector>

#include "Definition.h"
#include "Expression.h"

/*!
 * \brief
 * Definitions involving data.
 *
 * \section cpp C++
 * - example:
 * \code
int x = 5;	// this->isMutable = false, this->initialValue = "5"
\endcode
 *
 * \see Definition
 */
class DataDefinition : public Definition
{
	public:
		DataDefinition();
		virtual ~DataDefinition() = 0;
		
		virtual void identify(std::vector<int> &id) const;
		
		/*!
		 * \brief
		 * Specifies if data is or is not mutable.
		 */
		bool isMutable;
		
		/*!
		 * \brief
		 * Assigns initial value to data.
		 */
		Expression *initialValue;
};

#endif	// _ASTM_DATA_DEFINITION_H_
