/*!
 * \file
 * LongInteger.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_LONG_INTEGER_H_
#define _ASTM_LONG_INTEGER_H_

#include <vector>

#include "PrimitiveType.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents long integer type.
 *
 * C++ keywords sequence: long int
 */
class LongInteger : public PrimitiveType
{
	public:
		LongInteger();
		virtual ~LongInteger();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_LONG_INTEGER_H_
