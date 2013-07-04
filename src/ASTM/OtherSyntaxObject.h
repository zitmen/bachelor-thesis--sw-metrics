/*!
 * \file
 * OtherSyntaxObject.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_OTHER_SYNTAX_OBJECT_H_
#define _ASTM_OTHER_SYNTAX_OBJECT_H_

#include <vector>

#include "GASTMSyntaxObject.h"

/*!
 * \brief
 * Various syntactic entities not otherwise categorized (operators, access kinds, etc.).
 */
class OtherSyntaxObject : public GASTMSyntaxObject
{
	public:
		OtherSyntaxObject();
		virtual ~OtherSyntaxObject() = 0;
		
		virtual void identify(std::vector<int> &id) const;
};

#endif	// _ASTM_OTHER_SYNTAX_OBJECT_H_
