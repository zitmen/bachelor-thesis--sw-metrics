/*!
 * \file
 * CharLiteral.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_CHAR_LITERAL_H_
#define _ASTM_CHAR_LITERAL_H_

#include <vector>

#include "Literal.h"
#include "XmlDump.h"

/*!
 * \brief
 * Character literals.
 *
 * \section cpp C++
 * - examples:
 * \code
'c'		// this->value = "c"
'\t'	// this->value = "\t"
L'á'	// this->value = "á"
\endcode
 */
class CharLiteral : public Literal
{
	public:
		CharLiteral();
		virtual ~CharLiteral();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_CHAR_LITERAL_H_
