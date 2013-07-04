/*!
 * \file
 * LabelType.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_LABEL_TYPE_H_
#define _ASTM_LABEL_TYPE_H_

#include <vector>

#include "Type.h"
#include "XmlDump.h"

/*!
 * \brief
 * The type of a label - used for depicting that the type of an element is a label.
 */
class LabelType : public Type
{
	public:
		LabelType();
		virtual ~LabelType();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_LABEL_TYPE_H_
