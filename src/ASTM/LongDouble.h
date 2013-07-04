/*!
 * \file
 * LongDouble.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_LONG_DOUBLE_H_
#define _ASTM_LONG_DOUBLE_H_

#include <vector>

#include "PrimitiveType.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents long double type.
 *
 * C++ keywords sequence: long double
 */
class LongDouble : public PrimitiveType
{
	public:
		LongDouble();
		virtual ~LongDouble();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_LONG_DOUBLE_H_
