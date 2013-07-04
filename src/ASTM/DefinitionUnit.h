/*!
 * \file
 * DefinitionUnit.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_DEFINITION_UNIT_H_
#define _ASTM_DEFINITION_UNIT_H_

#include <vector>

#include "GASTMSyntaxObject.h"

/*!
 * \brief
 * Constructs that define entities.
 */
class DefinitionUnit : public GASTMSyntaxObject
{
	public:
		DefinitionUnit();
		virtual ~DefinitionUnit() = 0;
		
		virtual void identify(std::vector<int> &id) const;
};

#endif	// _ASTM_DEFINITION_UNIT_H_
