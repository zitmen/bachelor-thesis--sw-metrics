/*!
 * \file
 * Float.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_FLOAT_H_
#define _ASTM_FLOAT_H_

#include <vector>

#include "PrimitiveType.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents float type.
 *
 * C++ keyword: float
 */
class Float : public PrimitiveType
{
	public:
		Float();
		virtual ~Float();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_FLOAT_H_
