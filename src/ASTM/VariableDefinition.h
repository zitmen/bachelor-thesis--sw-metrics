/*!
 * \file
 * VariableDefinition.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_VARIABLE_DEFINITION_H_
#define _ASTM_VARIABLE_DEFINITION_H_

#include <vector>

#include "DataDefinition.h"
#include "XmlDump.h"

/*!
 * \brief
 * Variable definitions.
 *
 * \see DataDefinition
 */
class VariableDefinition : public DataDefinition
{
	public:
		VariableDefinition();
		virtual ~VariableDefinition();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_VARIABLE_DEFINITION_H_
