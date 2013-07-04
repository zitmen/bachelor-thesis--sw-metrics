/*!
 * \file
 * EntryDefinition.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_ENTRY_DEFINITION_H_
#define _ASTM_ENTRY_DEFINITION_H_

#include <vector>

#include "Definition.h"
#include "XmlDump.h"

class FormalParameterDefinition;

/*!
 * \brief
 * Represents .
 *
 * \section cpp C++
 * - example:
 * \code

\endcode
 */
class EntryDefinition : public Definition
{
	public:
		EntryDefinition();
		virtual ~EntryDefinition();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		std::vector<FormalParameterDefinition *> formalParameters;
};

#endif	// _ASTM_ENTRY_DEFINITION_H_
