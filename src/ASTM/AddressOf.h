/*!
 * \file
 * AddressOf.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_ADDRESS_OF_H_
#define _ASTM_ADDRESS_OF_H_

#include <vector>

#include "UnaryOperator.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents referencing operator.
 *
 * \section cpp C++
 * - operator: &
 * - example:
 * \code
&x
\endcode
 */
class AddressOf : public UnaryOperator
{
	public:
		AddressOf();
		virtual ~AddressOf();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_ADDRESS_OF_H_
