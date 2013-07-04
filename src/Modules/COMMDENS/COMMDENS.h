#ifndef _SMES_MODULE_COMMDENS_H_
#define _SMES_MODULE_COMMDENS_H_

#include "../../ASTM/Node.h"
#include "../../ASTM/ASTM.h"
#include "../ModuleBase.h"
#include "../LOC/LOC.h"

class CommentsDensity : public ModuleBase
{
	private:
		Node m_nodeId;
		std::vector<std::pair<std::string, int> > m_fnDensity;	// first -> fnName, second -> density [%]
	
	public:
		CommentsDensity(const LinesOfCode &loc);
		virtual ~CommentsDensity();
		
		virtual std::string dumpResultXml();
};

#endif	// _SMES_MODULE_COMMDENS_H_
