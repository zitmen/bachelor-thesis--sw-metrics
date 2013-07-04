/*!
 * \file
 * AccessKind.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_ACCESS_KIND_H_
#define _ASTM_ACCESS_KIND_H_

#include <vector>

#include "OtherSyntaxObject.h"

/*!
 * \brief
 * Specifications of the kind of access provided by a member or base class.
 */
class AccessKind : public OtherSyntaxObject
{
	public:
		AccessKind();
		virtual ~AccessKind() = 0;
		
		virtual void identify(std::vector<int> &id) const;
};

#endif	// _ASTM_ACCESS_KIND_H_
