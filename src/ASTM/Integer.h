/*!
 * \file
 * Integer.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_INTEGER_H_
#define _ASTM_INTEGER_H_

#include <vector>

#include "PrimitiveType.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents integer type.
 *
 * C++ keyword: int
 */
class Integer : public PrimitiveType
{
	public:
		Integer();
		virtual ~Integer();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_INTEGER_H_
