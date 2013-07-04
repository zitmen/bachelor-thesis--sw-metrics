/*!
 * \file
 * DeclarationOrDefinitionStatement.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_DECLARATION_OR_DEFINITION_STATEMENT_H_
#define _ASTM_DECLARATION_OR_DEFINITION_STATEMENT_H_

#include <vector>

#include "DefinitionUnit.h"
#include "Statement.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents .
 *
 * \section cpp C++
 * - example:
 * \code

\endcode
 */
class DeclarationOrDefinitionStatement : public Statement
{
	public:
		DeclarationOrDefinitionStatement();
		virtual ~DeclarationOrDefinitionStatement();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		std::vector<DefinitionUnit *> *declOrDefn;
};

#endif	// _ASTM_DECLARATION_OR_DEFINITION_STATEMENT_H_
