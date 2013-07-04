/*!
 * \file
 * MacroDefinition.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_MACRO_DEFINITION_H_
#define _ASTM_MACRO_DEFINITION_H_

#include <string>
#include <vector>

#include "PreprocessorElement.h"
#include "XmlDump.h"

/*!
 * \brief
 * Definition of preprocessor macro.
 *
 * \section cpp C++
 * -example:
 * \code
// this->name = "ADD", this->body = "(a, b) ((a) + (b))"
#define ADD(a, b) ((a) + (b))
\endcode
 */
class MacroDefinition : public PreprocessorElement
{
	public:
		MacroDefinition();
		virtual ~MacroDefinition();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Name of preprocessor macro.
		 */
		std::string name;
		
		/*!
		 * \brief
		 * Body of preprocessor macro.
		 */
		std::string body;
};

#endif	// _ASTM_MACRO_DEFINITION_H_
