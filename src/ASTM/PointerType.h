/*!
 * \file
 * PointerType.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_POINTER_TYPE_H_
#define _ASTM_POINTER_TYPE_H_

#include <vector>

#include "ConstructedType.h"
#include "PointerType.h"

/*!
 * \brief
 * Types whose values are pointers.
 *
 * \see ConstructedType
 */
class PointerType : public ConstructedType
{
	public:
		PointerType();
		virtual ~PointerType();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_POINTER_TYPE_H_
