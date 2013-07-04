#ifndef _SMES_MODULEBASE_H_
#define _SMES_MODULEBASE_H_

#include <string>

class CompilationUnit;

class ModuleBase
{
	protected:
		CompilationUnit *m_unit;
		
	public:
		ModuleBase(CompilationUnit *unit);
		virtual ~ModuleBase() = 0;
		
		virtual std::string dumpResultXml() = 0;
};

#endif	// _SMES_MODULEBASE_H_
