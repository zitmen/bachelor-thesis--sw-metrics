#ifndef _SMES_MODULE_NOC_H_
#define _SMES_MODULE_NOC_H_

#include <string>
#include <vector>

#include "../../ASTM/Node.h"
#include "../../ASTM/ASTM.h"
#include "../ModuleBase.h"

class NumberOfClasses : public ModuleBase
{
	private:
		Node m_nodeId;
		int m_nClasses;
		
	public:
		NumberOfClasses(CompilationUnit *unit);
		virtual ~NumberOfClasses();
		
		virtual std::string dumpResultXml();
};

#endif // _SMES_MODULE_NOC_H_
