/*!
 * \file
 * WideCharacter.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_WIDE_CHARACTER_H_
#define _ASTM_WIDE_CHARACTER_H_

#include <vector>

#include "PrimitiveType.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents wide character type.
 *
 * C++ keyword: wchar_t
 */
class WideCharacter : public PrimitiveType
{
	public:
		WideCharacter();
		virtual ~WideCharacter();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_WIDE_CHARACTER_H_
