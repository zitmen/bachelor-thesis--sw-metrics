/*!
 * \file
 * RealLiteral.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_REAL_LITERAL_H_
#define _ASTM_REAL_LITERAL_H_

#include <vector>

#include "Literal.h"
#include "XmlDump.h"

/*!
 * \brief
 * Floating-point literals.
 *
 * \section cpp C++
 * - example:
 * \code
.17e+4	// this->value = ".17e+4"
\endcode
 */
class RealLiteral : public Literal
{
	public:
		RealLiteral();
		virtual ~RealLiteral();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_REAL_LITERAL_H_
