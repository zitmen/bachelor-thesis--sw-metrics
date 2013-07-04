/*!
 * \file
 * Boolean.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_BOOLEAN_H_
#define _ASTM_BOOLEAN_H_

#include <vector>

#include "PrimitiveType.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents boolean type.
 *
 * C++ keyword: bool
 */
class Boolean : public PrimitiveType
{
	public:
		Boolean();
		virtual ~Boolean();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_BOOLEAN_H_
