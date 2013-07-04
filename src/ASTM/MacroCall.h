/*!
 * \file
 * MacroCall.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_MACRO_CALL_H_
#define _ASTM_MACRO_CALL_H_

#include <vector>

#include "PreprocessorElement.h"
#include "XmlDump.h"

class MacroDefinition;

/*!
 * \brief
 * Invocation of a preprocessing macro.
 */
class MacroCall : public PreprocessorElement
{
	public:
		MacroCall();
		virtual ~MacroCall();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Definition of called macro.
		 */
		MacroDefinition *refersTo;
};

#endif	// _ASTM_MACRO_CALL_H_
