/*!
 * \file
 * EnumLiteralDefinition.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_ENUM_LITERAL_DEFINITION_H_
#define _ASTM_ENUM_LITERAL_DEFINITION_H_

#include <vector>

#include "Definition.h"
#include "XmlDump.h"

class Expression;

/*!
 * \brief
 * Definitions of enumerals (members of enumerated types).
 *
 * \section cpp C++
 * - example:
 * \code
enum Enumeration
{
	FOO,		// this->value = NULL, identifierName = "FOO", definitionType = NULL
	BAR = 10	// this->value = "10", identifierName = "BAR", definitionType = NULL
};
\endcode
 *
 * \see Definition
 */
class EnumLiteralDefinition : public Definition
{
	public:
		EnumLiteralDefinition();
		virtual ~EnumLiteralDefinition();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Value assigned to literal or NULL if there is no value assigned.
		 *
		 * \see Expression
		 */
		Expression *value;
};

#endif	// _ASTM_ENUM_LITERAL_DEFINITION_H_
