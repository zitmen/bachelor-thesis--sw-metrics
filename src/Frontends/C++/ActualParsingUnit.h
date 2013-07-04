#ifndef _ACTUAL_PARSING_UNIT_H
#define _ACTUAL_PARSING_UNIT_H

#include <vector>

class CompilationUnit;
class GASTMSyntaxObject;

class ActualParsingUnit
{
	private:
		static CompilationUnit *m_unit;
	
	public:
		static inline void setUnit(CompilationUnit *unit) { m_unit = unit; }
		static inline CompilationUnit * getUnit() { return m_unit; }
		//
		static std::vector<std::pair<GASTMSyntaxObject *, GASTMSyntaxObject *> > colisions;
};

#endif	// _ACTUAL_PARSING_UNIT_H
