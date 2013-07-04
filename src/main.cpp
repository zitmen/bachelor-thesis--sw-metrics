#ifdef WIN32
	#include <vld.h>
#endif

#include "config.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Frontends/C++/CppParser.h"

#include "Modules/LOC/LOC.h"
#include "Modules/COMMDENS/COMMDENS.h"
#include "Modules/CCN/CCN.h"
#include "Modules/DECDENS/DECDENS.h"
#include "Modules/NPATH/NPATH.h"
#include "Modules/TFC/TFC.h"
#include "Modules/NOC/NOC.h"
#include "Modules/LK/LK.h"

void printHelp();
void printWarning();
bool processCmdLineArgs(int n, char *params[], string &in, string &out);

int main(int argc, char *argv[])
{
	string inPath, outPath;	// in - source code, out - xml report
	if(!processCmdLineArgs(argc, argv, inPath, outPath))
		return 0;
	//
	cout << "Parsing...";
	CppParser cpp;
	Project *project = cpp.parseFile(inPath);
	if(cpp.errorOccured())
	{
		cout << "Error!" << endl;
		return 1;
	}
	cout << "Ok." << endl;
	//
#if YYDEBUG == 1
	//
	// TinyXML test
	TiXmlDocument doc;
	TiXmlDeclaration *decl = new TiXmlDeclaration("1.0", "utf-8", "yes");
	doc.LinkEndChild(decl);
	//
	//TiXmlStylesheetReference *style = new TiXmlStylesheetReference("text/xsl", "test.xsl");
	//doc.LinkEndChild(style);
	//
	TiXmlElement *root = new TiXmlElement("ASTM");
	project->dumpXml(root);
	doc.LinkEndChild(root);
	//
	doc.SaveFile("astm_dump.xml");
	//
#endif	// YYDEBUG == 1
	//
	cout << "Analysing...";
	//
	LinesOfCode loc(project->files[0]);
	CommentsDensity commdens(loc);
	CyclomaticComplexityNumber ccn(project->files[0]);
	DecisionDensity decdens(loc, ccn);
	NPathComplexity npath(project->files[0]);
	TotalFunctionCalls tfc(project->files[0]);
	NumberOfClasses noc(project->files[0]);
	LorenzKidd lk(project->files[0]);
	//
	string resultsFile = (outPath.size() > 0) ? outPath : "report.xml";
	ofstream fout;
	fout.open(resultsFile.c_str());
	if(!fout.is_open())
	{
		cout << "Error writing the results!" << endl;
		return 2;
	}
	fout << "<?xml version=\"1.0\" encoding=\"iso-8859-1\"?>\n"
		 << "<?xml-stylesheet href=\"sw_metrics.xsl\" type=\"text/xml\"?>\n"
		 << "<sw_stats>\n"
		 << "\t<file>" << inPath << "</file>\n"
		 << loc.dumpResultXml()
		 << commdens.dumpResultXml()
		 << ccn.dumpResultXml()
		 << decdens.dumpResultXml()
		 << npath.dumpResultXml()
		 << tfc.dumpResultXml()
		 << noc.dumpResultXml()
		 << lk.dumpResultXml()
		 << "</sw_stats>\n";
	//
	fout.close();
	cout << "Ok." << endl;
	cout << "Results written into '" << resultsFile << "'." << endl;
	//
	//delete project;
	return 0;
}

void printHelp()
{
	cout << "Software Metrics Evaluation System - help\n"
		 << "-----------------------------------------\n"
		 << "Syntax: ./sw_metrics [options] source_file\n"
		 << "\n"
		 << "Options:\n"
		 << "'-h' or '--help' show this help\n"
		 << "'-o output_file' saves analysis report into 'output_file'. Default location is 'report.xml' in the current directory.\n"
		 << "\n"
		 << "'source_file' is a path to the source file you want to analyse\n"
		 << endl;
}

void printWarning()
{
	cout << "Wrong syntax!\n"
		 << "To get help try one of\n"
		 << "  ./sw_metrics -h\n"
		 << "  ./sw_metrics --help"
		 << endl;
}

bool processCmdLineArgs(int n, char *params[], string &in, string &out)
{
	if(n == 2)
	{
		if(strcmp(params[1], "-h") == 0)
		{
			printHelp();
			return false;
		}
		else if(strcmp(params[1], "--help") == 0)
		{
			printHelp();
			return false;
		}
		else
		{
			if(params[1][0] != '-')
			{
				in = params[1];
				return true;
			}
		}
	}
	else if(n == 4)
	{
		if(strcmp(params[1], "-o") == 0)
		{
			in = params[3];
			out = params[2];
			return true;
		}
	}
	//
	printWarning();
	return false;
}
