/*!
 * \file
 * IncludeUnit.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_INCLUDE_UNIT_H_
#define _ASTM_INCLUDE_UNIT_H_

#include <vector>

#include "PreprocessorElement.h"
#include "XmlDump.h"

class SourceFile;

/*!
 * \brief
 * Inclusion of a file during preprocessing.
 */
class IncludeUnit : public PreprocessorElement
{
	public:
		IncludeUnit();
		virtual ~IncludeUnit();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * File that is included during preprocessing.
		 */
		SourceFile *file;
};

#endif	// _ASTM_INCLUDE_UNIT_H_
