/*!
 * \file
 * ReferenceType.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_REFERENCE_TYPE_H_
#define _ASTM_REFERENCE_TYPE_H_

#include <vector>

#include "ConstructedType.h"
#include "XmlDump.h"

/*!
 * \brief
 * Types whose values are references.
 *
 * \see ConstructedType
 */
class ReferenceType : public ConstructedType
{
	public:
		ReferenceType();
		virtual ~ReferenceType();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_REFERENCE_TYPE_H_
