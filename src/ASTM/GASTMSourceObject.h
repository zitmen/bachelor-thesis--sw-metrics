/*!
 * \file
 * GASTMSourceObject.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _GASTM_SOURCE_OBJECT_H_
#define _GASTM_SOURCE_OBJECT_H_

#include <vector>

#include "GASTMObject.h"

/*!
 * \brief
 * Objects related to specifying locations within source files.
 */
class GASTMSourceObject : public GASTMObject
{
	public:
		GASTMSourceObject();
		virtual ~GASTMSourceObject() = 0;
		
		virtual void identify(std::vector<int> &id) const;
};

#endif	// _GASTM_SOURCE_OBJECT_H_
