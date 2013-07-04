/*!
 * \file
 * ByValueFormalParameterType.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_BY_VALUE_FORMAL_PARAMETER_TYPE_H_
#define _ASTM_BY_VALUE_FORMAL_PARAMETER_TYPE_H_

#include <vector>

#include "FormalParameterType.h"
#include "XmlDump.h"

/*!
 * \brief
 * Represents actual parameters passed by value.
 *
 * \section cpp C++
 * - example:
 * \code
void foo(Object o);	// "o" is passed by value
\endcode
 *
 * \see FormalParameterType
 */
class ByValueFormalParameterType : public FormalParameterType
{
	public:
		ByValueFormalParameterType();
		virtual ~ByValueFormalParameterType();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_BY_VALUE_FORMAL_PARAMETER_TYPE_H_
