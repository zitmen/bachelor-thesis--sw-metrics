/*!
 * \file
 * NameSpaceType.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_NAME_SPACE_TYPE_H_
#define _ASTM_NAME_SPACE_TYPE_H_

#include <vector>

#include "Type.h"
#include "XmlDump.h"

/*!
 * \brief
 * The type of a namespace - used for depicting that the type of an element is a namespace.
 */
class NameSpaceType : public Type
{
	public:
		NameSpaceType();
		virtual ~NameSpaceType();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_NAME_SPACE_TYPE_H_
