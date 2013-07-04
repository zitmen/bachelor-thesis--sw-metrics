/*!
 * \file
 * CollectionType.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_COLLECTION_TYPE_H_
#define _ASTM_COLLECTION_TYPE_H_

#include <vector>

#include "ConstructedType.h"
#include "XmlDump.h"

/*!
 * \brief
 * Types characterized as collections (lists, sets, bags, ...).
 *
 * \see ConstructedType
 */
class CollectionType : public ConstructedType
{
	public:
		CollectionType();
		virtual ~CollectionType();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_COLLECTION_TYPE_H_
