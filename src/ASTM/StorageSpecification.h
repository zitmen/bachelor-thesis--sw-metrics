/*!
 * \file
 * StorageSpecification.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_STORAGE_SPECIFICATION_H_
#define _ASTM_STORAGE_SPECIFICATION_H_

#include <vector>

#include "OtherSyntaxObject.h"

/*!
 * \brief
 * A property of data that depicts how it is allocated.
 */
class StorageSpecification : public OtherSyntaxObject
{
	public:
		StorageSpecification();
		virtual ~StorageSpecification() = 0;
		
		virtual void identify(std::vector<int> &id) const;
};

#endif	// _ASTM_STORAGE_SPECIFICATION_H_
