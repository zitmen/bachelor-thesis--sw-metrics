/*!
 * \file
 * SourceLocation.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_SOURCE_LOCATION_H_
#define _ASTM_SOURCE_LOCATION_H_

#include <vector>
#include <string>

#include "GASTMSourceObject.h"
#include "XmlDump.h"

class GASTMSyntaxObject;

/*!
 * \brief
 * Represents a token and it's location in a source code.
 * Instances of this class are chained tokens from input files.
 * By the following call, you should get the original source file, if the source is parsed correctly:
 * \code
ASTM astm;
//
// ...parsing...
//
SourceLocation *token = astm.tokenFirst;
while(token)
{
	cout << token->token;
	token = token->next;
}
\endcode
 *
 * \see ASTM
 */
class SourceLocation : public GASTMSourceObject
{
	public:
		SourceLocation(std::string tok, int startLn = 0, int startCol = 0, int endLn = 0, int endCol = 0);
		virtual ~SourceLocation();
		
		bool operator<(const SourceLocation &loc) const;
		bool operator>(const SourceLocation &loc) const;
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Inserts some other token right before this one.
		 *
		 * \param loc
		 * Pointer to an object, that caller wants to insert before this one.
		 *
		 * \return
		 * Returns inserted token (loc param).
		 */
		SourceLocation * insertBefore(SourceLocation *loc);
		
		/*!
		 * \brief
		 * Inserts some other token right after this one.
		 *
		 * \param loc
		 * Pointer to an object, that caller wants to insert after this one.
		 *
		 * \return
		 * Returns inserted token (loc param).
		 */
		SourceLocation * insertAfter(SourceLocation *loc);
		
		/*!
		 * \brief
		 * Token.
		 */
		std::string token;
		
		/*!
		 * \brief
		 * Starting position (column) of the token in source file.
		 */
		int startColumn;
		
		/*!
		 * \brief
		 * Ending position (column) of the token in source file.
		 */
		int endColumn;
		
		/*!
		 * \brief
		 * Starting position (line) of the token in source file.
		 */
		int startLine;
		
		/*!
		 * \brief
		 * Ending position (line) of the token in source file.
		 */
		int endLine;
		
		/*!
		 * \brief
		 * Previous token read from source file.
		 */
		SourceLocation *prev;
		
		/*!
		 * \brief
		 * Following token read from source file.
		 */
		SourceLocation *next;
};

#endif	// _ASTM_SOURCE_LOCATION_H_
