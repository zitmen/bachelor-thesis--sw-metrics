/*!
 * \file
 * Type.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_TYPE_H_
#define _ASTM_TYPE_H_

#include <vector>

#include "GASTMSyntaxObject.h"

/*!
 * \brief
 * All types.
 */
class Type : public GASTMSyntaxObject
{
	public:
		Type();
		virtual ~Type();// = 0;	// this class is not pure virtual, because it's used as helper class for carrying const and volatile flags during the parsing
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Specifies if type is or is not volatile.
		 *
		 * - C++ keyword: volatile
		 */
		bool isVolatile;
		
		/*!
		 * \brief
		 * Specifies if type is or is not constant.
		 *
		 * - C++ keyword: const
		 */
		bool isConst;
};

#endif	// _ASTM_TYPE_H_
