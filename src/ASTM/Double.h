/*!
 * \file
 * Double.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_DOUBLE_H_
#define _ASTM_DOUBLE_H_

#include <vector>

#include "PrimitiveType.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents double type.
 *
 * C++ keyword: double
 */
class Double : public PrimitiveType
{
	public:
		Double();
		virtual ~Double();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_DOUBLE_H_
