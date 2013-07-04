#include "COMMDENS.h"
#include "../ModuleApi.h"
using namespace NodeId;

#include <iomanip>
#include <sstream>

CommentsDensity::CommentsDensity(const LinesOfCode &sloc) : ModuleBase(sloc.m_unit)
{
	double loc, cloc;
	for(size_t i = 0, im = sloc.m_fnLines.size(); i < im; ++i)
	{
		loc = sloc.m_fnLines[i].second->loc;
		cloc = sloc.m_fnLines[i].second->cloc;
		//
		m_fnDensity.push_back
		(
			std::make_pair
			(
				sloc.m_fnLines[i].first,
				cloc / loc * 100.0	// (int) [%]
			)
		);
	}
}

CommentsDensity::~CommentsDensity()
{
	//
}

std::string
CommentsDensity::dumpResultXml()
{
	std::ostringstream os;
	os << "\t<module name=\"Comments Density\">\n";
	for(size_t i = 0, im = m_fnDensity.size(); i < im; ++i)
	{
		os << "\t\t<function>\n"
		   << "\t\t\t<name>" << m_fnDensity[i].first  << "</name>\n"
		   << "\t\t\t<commdens>" << m_fnDensity[i].second << "%</commdens>\n"
		   << "\t\t</function>\n";
	}
	os << "\t</module>\n";
	return os.str();
}
