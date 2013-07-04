#include "LK.h"
#include "../ModuleApi.h"
using namespace NodeId;

#include <iomanip>
#include <sstream>
#include <algorithm>

LorenzKidd::LorenzKidd(CompilationUnit *unit) : ModuleBase(unit)
{
	std::vector<AggregateTypeDefinition *> classes;
	ModuleApi::findClassesInFile(unit, classes);
	//
	static Node nodeId;
	//
	int dit = 0;
	LKParams *lkp = new LKParams;
	std::string class_name;
	std::vector<Declaration *> items;
	for(size_t i = 0, im = classes.size(); i < im; ++i, dit = 0, class_name = "", lkp = new LKParams)
	{
		// Class Name
		ModuleApi::getFullName(classes[i], class_name);
		//
		// DIT
		ModuleApi::getDepthOfInharitanceTree((ClassType *)classes[i]->aggregateType, dit);
		//
		// All items in class (including inherited items). Item = method or attribute.
		ModuleApi::getAllMembers((ClassType *)classes[i]->aggregateType, items);
		//
		// Class Size
		for(size_t it = 0, itm = items.size(); it < itm; ++it)
		{
			nodeId.setNode(items[it]);
			if(nodeId == FUNCTION_DECLARATION)
			{
				lkp->cs.nm++;
				//
				nodeId.setNode(items[it]->accessKind);
				if(nodeId == PUBLIC)
				{
					lkp->cs.npm++;
				}
				//
				nodeId.setNode(items[it]->storageSpecifiers);
				if(nodeId == STATIC)
				{
					lkp->cs.ncm++;
				}
			}
			else if(nodeId == VARIABLE_DECLARATION)
			{
				lkp->cs.nv++;
				//
				nodeId.setNode(items[it]->accessKind);
				if(nodeId == PUBLIC)
				{
					lkp->cs.npv++;
				}
				//
				nodeId.setNode(items[it]->storageSpecifiers);
				if(nodeId == STATIC)
				{
					lkp->cs.ncv++;
				}
			}
		}
		items.clear();
		//
		// APM
		lkp->apm = (double)lkp->cs.nv / (double)lkp->cs.nm;
		//
		//
		// All inherited items. Item = method or attribute.
		ClassType *c = (ClassType *)classes[i]->aggregateType;
		if(c->derivesFrom)
		{
			for(size_t d = 0, dm = c->derivesFrom->size(); d < dm; ++d)
			{
				ModuleApi::getAllMembers((ClassType *)c->derivesFrom->at(d)->className->body, items, false);
			}
			//
			for(std::vector<Declaration *>::iterator it = items.begin(); it != items.end(); /*++it*/)
			{
				nodeId.setNode(*it);
				if(nodeId != FUNCTION_DECLARATION)
				{
					items.erase(it);	// default ++it
				}
				else
				{
					++it;
				}
			}
		}
		//
		// NMI
		lkp->nmi = items.size();
		//
		// NMA
		lkp->nma = lkp->cs.nm - lkp->nmi;
		//
		// NMO
		if(c->members)
		{
			FunctionDeclaration *fnDecl = NULL;
			for(size_t it = 0, itm = items.size(); it < itm; ++it)
			{
				for(size_t m = 0, mm = c->members->size(); m < mm; ++m, fnDecl = NULL)
				{
					nodeId.setNode(c->members->at(m));
					if(nodeId == FUNCTION_DECLARATION)
					{
						fnDecl = (FunctionDeclaration *)c->members->at(m);
					}
					else if(nodeId == FUNCTION_DEFINITION)
					{
						fnDecl = (FunctionDeclaration *)((FunctionDefinition *)c->members->at(m))->declRef;
					}
					//
					if(ModuleApi::functionsEqual(fnDecl, (FunctionDeclaration *)items[it]))
					{
						lkp->nmo++;
						break;
					}
				}
			}
		}
		//
		// SIX
		lkp->six = (double)lkp->nmo * (double)dit / (double)lkp->cs.nm;
		//
		// save
		m_LKClasses.push_back(std::make_pair(class_name, lkp));
	}
}

LorenzKidd::~LorenzKidd()
{
	for(size_t i = 0, im = m_LKClasses.size(); i < im; ++i)
		delete m_LKClasses[i].second;
}

std::string
LorenzKidd::dumpResultXml()
{
	std::ostringstream os;
	os << "\t<module name=\"Lorenz - Kidd\">\n";
	for(size_t i = 0, im = m_LKClasses.size(); i < im; ++i)
	{
		os << "\t\t<class>\n";
		os << "\t\t\t<name>" << m_LKClasses[i].first << "</name>\n";
		os << "\t\t\t<cs>\n";
		os << "\t\t\t\t<nm>"  << m_LKClasses[i].second->cs.nm  << "</nm>\n";
		os << "\t\t\t\t<npm>" << m_LKClasses[i].second->cs.npm << "</npm>\n";
		os << "\t\t\t\t<ncm>" << m_LKClasses[i].second->cs.ncm << "</ncm>\n";
		os << "\t\t\t\t<nv>"  << m_LKClasses[i].second->cs.nv  << "</nv>\n";
		os << "\t\t\t\t<npv>" << m_LKClasses[i].second->cs.npv << "</npv>\n";
		os << "\t\t\t\t<ncv>" << m_LKClasses[i].second->cs.ncv << "</ncv>\n";
		os << "\t\t\t</cs>\n";
		os << "\t\t\t<apm>" << std::fixed << std::setprecision(2)
							<< m_LKClasses[i].second->apm << "</apm>\n";
		os << "\t\t\t<nma>" << m_LKClasses[i].second->nma << "</nma>\n";
		os << "\t\t\t<nmi>" << m_LKClasses[i].second->nmi << "</nmi>\n";
		os << "\t\t\t<nmo>" << m_LKClasses[i].second->nmo << "</nmo>\n";
		os << "\t\t\t<six>" << std::fixed << std::setprecision(2)
							<< m_LKClasses[i].second->six << "</six>\n";
		os << "\t\t</class>\n";
	}
	os << "\t</module>\n";
	return os.str();
}
