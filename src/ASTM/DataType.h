/*!
 * \file
 * DataType.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_DATA_TYPE_H_
#define _ASTM_DATA_TYPE_H_

#include <vector>

#include "Type.h"

/*!
 * \brief
 * Types involving data.
 */
class DataType : public Type
{
	public:
		DataType();
		virtual ~DataType() = 0;
		
		virtual void identify(std::vector<int> &id) const;
};

#endif	// _ASTM_DATA_TYPE_H_
