/*!
 * \file
 * GASTMSemanticObject.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _GASTM_SEMANTIC_OBJECT_H_
#define _GASTM_SEMANTIC_OBJECT_H_

#include <vector>

#include "GASTMObject.h"

/*!
 * \brief
 * Objects related to semantic artifacts of the modeled/analyzed system.
 */
class GASTMSemanticObject : public GASTMObject
{
	public:
		GASTMSemanticObject();
		virtual ~GASTMSemanticObject() = 0;
		
		virtual void identify(std::vector<int> &id) const;
};

#endif	// _GASTM_SEMANTIC_OBJECT_H_
