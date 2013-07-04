/*!
 * \file
 * IntegerLiteral.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_INTEGER_LITERAL_H_
#define _ASTM_INTEGER_LITERAL_H_

#include <vector>

#include "Literal.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents integer number literal.
 *
 * \section cpp C++
 * - example:
 * \code
156L
\endcode
 */
class IntegerLiteral : public Literal
{
	public:
		IntegerLiteral();
		virtual ~IntegerLiteral();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_INTEGER_LITERAL_H_
