/*!
 * \file
 * UnionType.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_UNION_TYPE_H_
#define _ASTM_UNION_TYPE_H_

#include <vector>

#include "AggregateType.h"
#include "XmlDump.h"

/*!
 * \brief
 * Union types (like structures but each data member occupies the same location).
 *
 * \see AggregateType
 */
class UnionType : public AggregateType
{
	public:
		UnionType();
		virtual ~UnionType();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_UNION_TYPE_H_
