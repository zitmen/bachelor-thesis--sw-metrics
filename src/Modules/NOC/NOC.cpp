#include "NOC.h"
#include "../ModuleApi.h"
using namespace NodeId;

#include <sstream>
#include <algorithm>

NumberOfClasses::NumberOfClasses(CompilationUnit *unit) : ModuleBase(unit)
{
	std::vector<AggregateTypeDefinition *> classes;
	ModuleApi::findClassesInFile(unit, classes);
	//
	m_nClasses = classes.size();
}

NumberOfClasses::~NumberOfClasses()
{
	//
}

std::string
NumberOfClasses::dumpResultXml()
{
	std::ostringstream os;
	os << "\t<module name=\"Number Of Classes\">\n";
	os << "\t\t<noc>" << m_nClasses << "</noc>\n";
	os << "\t</module>\n";
	return os.str();
}
