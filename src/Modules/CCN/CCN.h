#ifndef _SMES_MODULE_CCN_H_
#define _SMES_MODULE_CCN_H_

#include <string>
#include <vector>

#include "../../ASTM/Node.h"
#include "../../ASTM/ASTM.h"
#include "../ModuleBase.h"

class CyclomaticComplexityNumber : public ModuleBase
{
	friend class DecisionDensity;
	
	private:
		Node m_nodeId;
		std::vector<std::pair<std::string, std::pair<int, int> > > m_fnComplexity;	// first -> fnName, second -> ( first -> CCN1, second -> CCN2 )
		
	protected:
		void countBlockComplexity(Statement *statm, int &ccn1, int &ccn2);
		void countExpressionComplexity(Expression *expr, int &ccn1, int &ccn2);
		
	public:
		CyclomaticComplexityNumber(CompilationUnit *unit);
		virtual ~CyclomaticComplexityNumber();
		
		virtual std::string dumpResultXml();
};

#endif // _SMES_MODULE_CCN_H_
