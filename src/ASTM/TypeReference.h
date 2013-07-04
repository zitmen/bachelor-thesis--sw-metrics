/*!
 * \file
 * TypeReference.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_TYPE_REFERENCE_H_
#define _ASTM_TYPE_REFERENCE_H_

#include <vector>

#include "Type.h"

/*!
 * \brief
 * References to types.
 */
class TypeReference : public Type
{
	public:
		TypeReference();
		virtual ~TypeReference() = 0;
		
		virtual void identify(std::vector<int> &id) const;
};

#endif	// _ASTM_TYPE_REFERENCE_H_
