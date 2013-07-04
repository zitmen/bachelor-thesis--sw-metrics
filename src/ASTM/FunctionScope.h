/*!
 * \file
 * FunctionScope.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_FUNCTION_SCOPE_H_
#define _ASTM_FUNCTION_SCOPE_H_

#include <vector>

#include "Scope.h"
#include "XmlDump.h"

/*!
 * \brief
 * The scope introduced by a function definition.
 *
 * \see Scope::definitionObject
 */
class FunctionScope : public Scope
{
	public:
		FunctionScope();
		virtual ~FunctionScope();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_FUNCTION_SCOPE_H_
