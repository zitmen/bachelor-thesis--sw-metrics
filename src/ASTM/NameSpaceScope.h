/*!
 * \file
 * NameSpaceScope.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_NAME_SPACE_SCOPE_H_
#define _ASTM_NAME_SPACE_SCOPE_H_

#include <vector>

#include "Scope.h"
#include "XmlDump.h"

/*!
 * \brief
 * The scope introduced by a namespace header.
 *
 * \see Scope::definitionObject
 */
class NameSpaceScope : public Scope
{
	public:
		NameSpaceScope();
		virtual ~NameSpaceScope();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_NAME_SPACE_SCOPE_H_
