/*!
 * \file
 * StructureType.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_STRUCTURE_TYPE_H_
#define _ASTM_STRUCTURE_TYPE_H_

#include <vector>

#include "AggregateType.h"
#include "XmlDump.h"

/*!
 * \brief
 * Single structure types (no inheritance or function members).
 *
 * \see AggregateType
 */
class StructureType : public AggregateType
{
	public:
		StructureType();
		virtual ~StructureType();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_STRUCTURE_TYPE_H_
