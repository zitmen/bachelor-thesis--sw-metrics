#include "DECDENS.h"
#include "../ModuleApi.h"
using namespace NodeId;

#include <iomanip>
#include <sstream>

DecisionDensity::DecisionDensity(const LinesOfCode &loc, const CyclomaticComplexityNumber &ccn) : ModuleBase(loc.m_unit)
{
	double lloc, ccn1;
	for(size_t i = 0, im = loc.m_fnLines.size(); i < im; ++i)
	{
		lloc = loc.m_fnLines[i].second->lloc;
		ccn1 = ccn.m_fnComplexity[i].second.first;
		//
		m_fnDensity.push_back
		(
			std::make_pair
			(
				loc.m_fnLines[i].first,
				ccn1 / lloc * 100.0	// (int) [%]
			)
		);
	}
}

DecisionDensity::~DecisionDensity()
{
	//
}

std::string
DecisionDensity::dumpResultXml()
{
	std::ostringstream os;
	os << "\t<module name=\"Decision Density\">\n";
	for(size_t i = 0, im = m_fnDensity.size(); i < im; ++i)
	{
		os << "\t\t<function>\n"
		   << "\t\t\t<name>" << m_fnDensity[i].first  << "</name>\n"
		   << "\t\t\t<decdens>" << m_fnDensity[i].second << "%</decdens>\n"
		   << "\t\t</function>\n";
	}
	os << "\t</module>\n";
	return os.str();
}
