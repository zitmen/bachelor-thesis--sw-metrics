/*!
 * \file
 * LongLong.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_LONG_LONG_H_
#define _ASTM_LONG_LONG_H_

#include <vector>

#include "PrimitiveType.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents long long type.
 *
 * C++ keywords sequence: long long
 */
class LongLong : public PrimitiveType
{
	public:
		LongLong();
		virtual ~LongLong();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_LONG_LONG_H_
