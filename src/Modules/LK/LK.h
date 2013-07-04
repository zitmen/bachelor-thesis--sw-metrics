#ifndef _SMES_MODULE_LK_H_
#define _SMES_MODULE_LK_H_

#include <string>
#include <vector>

#include "../../ASTM/Node.h"
#include "../../ASTM/ASTM.h"
#include "../ModuleBase.h"

struct LKParams
{
	struct ClassSize
	{
		// Methods
		int nm;		// NM - Number of Methods
		int npm;	// NPM - Number of Public Methods
		int ncm;	// NCM - Number of Class Methods
		// Variables
		int nv;		// NV - Number of Variables
		int npv;	// NPV - Number of Public Variables
		int ncv;	// NCV - Number of Class Variables
		//
		ClassSize() { nm = npm = ncm = nv = npv = ncv = 0; }
		//
	} cs;		// CS - Class Size
	double apm;	// APM - Average Parameters per Method: APM = NV / NM
	int nma;	// NMA - Number of Methods Added
	int nmi;	// NMI - Number of Methods Inherited
	int nmo;	// NMO - Number of Methods Overridden
	double six;	// SIX - Specialization IndeX: SIX = (NMO * DIT) / NM
	//
	LKParams() { apm = nma = nmi = nmo = six = 0; }
	//
};

class LorenzKidd : public ModuleBase
{
	private:
		Node m_nodeId;
		std::vector<std::pair<std::string, LKParams *> > m_LKClasses;	// first -> class name, second -> LK metric's parameters
		
	public:
		LorenzKidd(CompilationUnit *unit);
		virtual ~LorenzKidd();
		
		virtual std::string dumpResultXml();
};

#endif // _SMES_MODULE_LK_H_
