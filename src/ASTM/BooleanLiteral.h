/*!
 * \file
 * BooleanLiteral.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_BOOLEAN_LITERAL_H_
#define _ASTM_BOOLEAN_LITERAL_H_

#include <vector>

#include "Literal.h"
#include "XmlDump.h"

/*!
 * \brief
 * Boolean literals.
 *
 * \section cpp C++
 * - keywords: true, false
 */
class BooleanLiteral : public Literal
{
	public:
		BooleanLiteral();
		virtual ~BooleanLiteral();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_BOOLEAN_LITERAL_H_
