/*!
 * \file
 * AggregateScope.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_AGGREGATE_SCOPE_H_
#define _ASTM_AGGREGATE_SCOPE_H_

#include <vector>

#include "Scope.h"
#include "XmlDump.h"

/*!
 * \brief
 * The scope introduced by a aggregate type.
 *
 * \see Scope::definitionObject
 */
class AggregateScope : public Scope
{
	public:
		AggregateScope();
		virtual ~AggregateScope();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_AGGREGATE_SCOPE_H_
