/*!
 * \file
 * Byte.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_BYTE_H_
#define _ASTM_BYTE_H_

#include <vector>

#include "PrimitiveType.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents byte type.
 *
 * C++ keyword: byte
 */
class Byte : public PrimitiveType
{
	public:
		Byte();
		virtual ~Byte();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_BYTE_H_
