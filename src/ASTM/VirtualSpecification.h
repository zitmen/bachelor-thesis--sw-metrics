/*!
 * \file
 * VirtualSpecification.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_VIRTUAL_SPECIFICATION_H_
#define _ASTM_VIRTUAL_SPECIFICATION_H_

#include <vector>

#include "OtherSyntaxObject.h"

/*!
 * \brief
 * Specifications of the virtual characteristics of a function member.
 */
class VirtualSpecification : public OtherSyntaxObject
{
	public:
		VirtualSpecification();
		virtual ~VirtualSpecification() = 0;
		
		virtual void identify(std::vector<int> &id) const;
};

#endif	// _ASTM_VIRTUAL_SPECIFICATION_H_
