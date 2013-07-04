/*!
 * \file
 * Void.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_VOID_H_
#define _ASTM_VOID_H_

#include <vector>

#include "PrimitiveType.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents void type.
 *
 * C++ keyword: void
 */
class Void : public PrimitiveType
{
	public:
		Void();
		virtual ~Void();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_VOID_H_
