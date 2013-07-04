#ifndef _SMES_MODULE_TFC_H_
#define _SMES_MODULE_TFC_H_

#include <string>
#include <vector>

#include "../../ASTM/Node.h"
#include "../../ASTM/ASTM.h"
#include "../ModuleBase.h"

class TotalFunctionCalls : public ModuleBase
{
	private:
		Node m_nodeId;
		std::vector<std::pair<std::string, int> > m_fnCalls;	// first -> fnName, second -> calls
		
	protected:
		void countFunctionCallsInBlock(Statement *statm, int &tfc);
		void countFunctionCallsInExpression(Expression *expr, int &tfc);
		
	public:
		TotalFunctionCalls(CompilationUnit *unit);
		virtual ~TotalFunctionCalls();
		
		virtual std::string dumpResultXml();
};

#endif // _SMES_MODULE_TFC_H_
