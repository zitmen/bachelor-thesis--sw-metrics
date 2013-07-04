#ifndef _SMES_MODULE_LOC_H_
#define _SMES_MODULE_LOC_H_

#include <string>

#include "../../ASTM/ASTM.h"
#include "../ModuleBase.h"

class CompilationUnit;

struct SLOC
{
	int loc;
	int lloc;
	int cloc;
	
	SLOC() { loc = lloc = cloc = 0; }
};

class LinesOfCode : public ModuleBase
{
	friend class DecisionDensity;
	friend class CommentsDensity;
	
	private:
		int m_loc;
		int m_lloc;
		int m_cloc;
		std::vector<std::pair<std::string, SLOC *> > m_fnLines;	// first -> fnName, second -> SLOC
		
	protected:
		int countLines(SourceLocation *from, SourceLocation *to);
		int countLogicalLines(SourceLocation *from, SourceLocation *to);
		int countCommentLines(SourceLocation *from, SourceLocation *to);
	
	public:
		LinesOfCode(CompilationUnit *unit);
		virtual ~LinesOfCode();
		
		virtual std::string dumpResultXml();
};

#endif // _SMES_MODULE_LOC_H_
