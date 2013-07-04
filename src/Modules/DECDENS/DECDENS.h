#ifndef _SMES_MODULE_DECDENS_H_
#define _SMES_MODULE_DECDENS_H_

#include "../../ASTM/Node.h"
#include "../../ASTM/ASTM.h"
#include "../ModuleBase.h"
#include "../LOC/LOC.h"
#include "../CCN/CCN.h"

class DecisionDensity : public ModuleBase
{
	private:
		Node m_nodeId;
		std::vector<std::pair<std::string, int> > m_fnDensity;	// first -> fnName, second -> density [%]
	
	public:
		DecisionDensity(const LinesOfCode &loc, const CyclomaticComplexityNumber &ccn);
		virtual ~DecisionDensity();
		
		virtual std::string dumpResultXml();
};

#endif	// _SMES_MODULE_DECDENS_H_
