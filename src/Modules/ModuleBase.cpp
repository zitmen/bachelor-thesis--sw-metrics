#include "ModuleBase.h"

#include "../ASTM/ASTM.h"

ModuleBase::ModuleBase(CompilationUnit *unit)
{
	m_unit = unit;
}

ModuleBase::~ModuleBase()
{
	//
}
		
std::string
ModuleBase::dumpResultXml()
{
	return "";
}
