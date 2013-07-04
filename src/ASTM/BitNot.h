/*!
 * \file
 * BitNot.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_BIT_NOT_H_
#define _ASTM_BIT_NOT_H_

#include <vector>

#include "UnaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents bit nogotiation operator.
 *
 * \section cpp C++
 * - operator: ~
 * - example:
 * \code
~x
\endcode
 */
class BitNot : public UnaryOperator
{
	public:
		BitNot();
		virtual ~BitNot();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_BIT_NOT_H_
