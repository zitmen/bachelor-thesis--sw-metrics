#ifndef _SMES_MODULE_NPATH_H_
#define _SMES_MODULE_NPATH_H_

#include <string>
#include <vector>

#include "../../ASTM/Node.h"
#include "../../ASTM/ASTM.h"
#include "../ModuleBase.h"

class NPathComplexity : public ModuleBase
{
	private:
		Node m_nodeId;
		std::vector<std::pair<std::string, int> > m_fnComplexity;	// first -> fnName, second -> NPATH
		
	protected:
		int countBlockComplexity(Statement *statm);
		int countExpressionComplexity(Expression *expr);
		
	public:
		NPathComplexity(CompilationUnit *unit);
		virtual ~NPathComplexity();
		
		virtual std::string dumpResultXml();
};

#endif // _SMES_MODULE_NPATH_H_
