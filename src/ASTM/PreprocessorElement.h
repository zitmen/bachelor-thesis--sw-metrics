/*!
 * \file
 * PreprocessorElement.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_PREPROCESSOR_ELEMENT_H_
#define _ASTM_PREPROCESSOR_ELEMENT_H_

#include <vector>

#include "GASTMSyntaxObject.h"
#include "XmlDump.h"

/*!
 * \brief
 * Constructs involved in preprocessing.
 */
class PreprocessorElement : public GASTMSyntaxObject
{
	public:
		PreprocessorElement();
		virtual ~PreprocessorElement();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_PREPROCESSOR_ELEMENT_H_
