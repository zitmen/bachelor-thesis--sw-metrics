/*!
 * \file
 * String.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_STRING_H_
#define _ASTM_STRING_H_

#include <vector>

#include "PrimitiveType.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents string type.
 *
 * C++ keyword: String
 */
class String : public PrimitiveType
{
	public:
		String();
		virtual ~String();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_STRING_H_
