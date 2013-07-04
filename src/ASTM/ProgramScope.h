/*!
 * \file
 * ProgramScope.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_PROGRAM_SCOPE_H_
#define _ASTM_PROGRAM_SCOPE_H_

#include <vector>

#include "Scope.h"
#include "XmlDump.h"

/*!
 * \brief
 * The scope introduced by a compilation unit.
 *
 * \see Scope::definitionObject
 */
class ProgramScope : public Scope
{
	public:
		ProgramScope();
		virtual ~ProgramScope();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_PROGRAM_SCOPE_H_
