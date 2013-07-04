/*!
 * \file
 * BlockScope.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_BLOCK_SCOPE_H_
#define _ASTM_BLOCK_SCOPE_H_

#include <vector>

#include "Scope.h"
#include "XmlDump.h"

/*!
 * \brief
 * The scope introduced by a block statement.
 *
 * \see Scope::definitionObject
 */
class BlockScope : public Scope
{
	public:
		BlockScope();
		virtual ~BlockScope();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_BLOCK_SCOPE_H_
