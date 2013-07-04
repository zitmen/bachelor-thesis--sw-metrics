/*!
 * \file
 * StringLiteral.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_STRING_LITERAL_H_
#define _ASTM_STRING_LITERAL_H_

#include <vector>

#include "Literal.h"
#include "XmlDump.h"

/*!
 * \brief
 * String literals.
 *
 * \section cpp C++
 * - example:
 * \code
"some string"	// this->value = "some string"
\endcode
 */
class StringLiteral : public Literal
{
	public:
		StringLiteral();
		virtual ~StringLiteral();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_STRING_LITERAL_H_
