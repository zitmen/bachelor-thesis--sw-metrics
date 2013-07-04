/*!
 * \file
 * ByReferenceFormalParameterType.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_BY_REFERENCE_FORMAL_PARAMETER_TYPE_H_
#define _ASTM_BY_REFERENCE_FORMAL_PARAMETER_TYPE_H_

#include <vector>

#include "FormalParameterType.h"
#include "XmlDump.h"

/*!
 * \brief
 * Specifies that a formal parameter is passed by reference.
 *
 * \section cpp C++
 * - example:
 * \code
void foo(Object &o);	// "o" is passed by reference
\endcode
 *
 * \see FormalParameterType
 */
class ByReferenceFormalParameterType : public FormalParameterType
{
	public:
		ByReferenceFormalParameterType();
		virtual ~ByReferenceFormalParameterType();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_BY_REFERENCE_FORMAL_PARAMETER_TYPE_H_
