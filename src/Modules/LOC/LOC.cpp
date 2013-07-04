#include "LOC.h"
#include "../ModuleApi.h"

#include <sstream>

int
LinesOfCode::countLines(SourceLocation *from, SourceLocation *to)
{
	int loc = 1;
	if(to && from)
	{
		loc += to->endLine - from->startLine;
	}
	return loc;
}

int
LinesOfCode::countLogicalLines(SourceLocation *from, SourceLocation *to)
{
	static Node helper;
	//
	int lloc = 1;	// starting line
	SourceLocation *token = from;
	while((token != to) && (token != NULL))
	{
		if(token->parent)
		{
			helper.setNode(token->parent);
			if(helper == NodeId::COMMENT)
			{	// is this comment the only token on the current line?
				if(token->prev && token->next)
				{
					if(token->prev->startLine != token->prev->endLine)	// first thing on the line
					{
						if(token->next->startLine != token->next->endLine)	// last thing on the line
						{
							token = token->next->next;
							continue;
						}
					}
				}
			}
		}
		//
		if((token->endLine - token->startLine) > 0)
		{
			lloc++;
		}
		//
		token = token->next;
	}
	return lloc;
}

int
LinesOfCode::countCommentLines(SourceLocation *from, SourceLocation *to)
{
	static Node helper;
	//
	int cloc = 0;
	SourceLocation *token = from;
	while(token != NULL)
	{
		if(token->parent)
		{
			helper.setNode(token->parent);
			if(helper == NodeId::COMMENT)
			{
				cloc += token->endLine - token->startLine + 1;
			}
		}
		//
		if(token == to) break;
		//
		token = token->next;
	}
	return cloc;
}

LinesOfCode::LinesOfCode(CompilationUnit *unit) : ModuleBase(unit)
{
	std::vector<FunctionDefinition *> functions;
	ModuleApi::findFunctionsInFile(unit, functions);
	SLOC *sloc = NULL;
	std::string fn_name;
	//
	for(size_t i = 0, im = functions.size(); i < im; ++i, fn_name = "")
	{
		sloc = new SLOC;
		ModuleApi::getFullName(functions[i], fn_name);
		sloc->loc = countLines(functions[i]->locFirst, functions[i]->locLast);
		sloc->lloc = countLogicalLines(functions[i]->locFirst, functions[i]->locLast);
		sloc->cloc = countCommentLines(functions[i]->locFirst, functions[i]->locLast);
		//
		m_fnLines.push_back
		(
			std::make_pair
			(
				fn_name,
				sloc
			)
		);
	}
	//
	m_loc = countLines(unit->srcFile->firstToken, unit->srcFile->lastToken);
	m_lloc = countLogicalLines(unit->srcFile->firstToken, unit->srcFile->lastToken);
	m_cloc = countCommentLines(unit->srcFile->firstToken, unit->srcFile->lastToken);
}

LinesOfCode::~LinesOfCode()
{
	for(size_t i = 0, im = m_fnLines.size(); i < im; ++i)
		if(m_fnLines[i].second)
			delete m_fnLines[i].second;
}

std::string
LinesOfCode::dumpResultXml()
{
	std::ostringstream os;
	os << "\t<module name=\"Lines Of Code\">\n"
	   << "\t\t<loc>" << m_loc << "</loc>\n"
	   << "\t\t<lloc>" << m_lloc << "</lloc>\n"
	   << "\t\t<cloc>" << m_cloc << "</cloc>\n";
	//
	for(size_t i = 0, im = m_fnLines.size(); i < im; ++i)
	{
		os << "\t\t<function>\n"
		   << "\t\t\t<name>" << m_fnLines[i].first  << "</name>\n"
		   << "\t\t\t<loc>" << m_fnLines[i].second->loc << "</loc>\n"
		   << "\t\t\t<lloc>" << m_fnLines[i].second->lloc << "</lloc>\n"
		   << "\t\t\t<cloc>" << m_fnLines[i].second->cloc << "</cloc>\n"
		   << "\t\t</function>\n";
	}
	os << "\t</module>\n";
	return os.str();
}
