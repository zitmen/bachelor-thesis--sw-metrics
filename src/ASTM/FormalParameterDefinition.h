/*!
 * \file
 * FormalParameterDefinition.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_FORMAL_PARAMETER_DEFINITION_H_
#define _ASTM_FORMAL_PARAMETER_DEFINITION_H_

#include <vector>

#include "DataDefinition.h"
#include "XmlDump.h"

/*!
 * \brief
 * Formal parameter definitions, appearing in function definitions and declarations.
 *
 * \see DataDefinition
 */
class FormalParameterDefinition : public DataDefinition
{
	public:
		FormalParameterDefinition();
		virtual ~FormalParameterDefinition();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_FORMAL_PARAMETER_DEFINITION_H_
