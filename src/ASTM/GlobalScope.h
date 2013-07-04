/*!
 * \file
 * GlobalScope.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_GLOBAL_SCOPE_H_
#define _ASTM_GLOBAL_SCOPE_H_

#include <vector>

#include "Scope.h"
#include "XmlDump.h"

/*!
 * \brief
 * The outermost scope, surrounding all compilation units of a project.
 *
 * \see Scope::definitionObject
 */
class GlobalScope : public Scope
{
	public:
		GlobalScope();
		virtual ~GlobalScope();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_GLOBAL_SCOPE_H_
