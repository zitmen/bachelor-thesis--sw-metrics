/*!
 * \file
 * Not.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_NOT_H_
#define _ASTM_NOT_H_

#include <vector>

#include "UnaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents logical negotiation operator.
 *
 * \section cpp C++
 * - operator: !
 * - example:
 * \code
!x
\endcode
 */
class Not : public UnaryOperator
{
	public:
		Not();
		virtual ~Not();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_NOT_H_
