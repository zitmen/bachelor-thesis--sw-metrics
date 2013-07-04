/*!
 * \file
 * EmptyStatement.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_EMPTY_STATEMENT_H_
#define _ASTM_EMPTY_STATEMENT_H_

#include <vector>

#include "Statement.h"
#include "XmlDump.h"

/*!
 * \brief
 * Statement that does nothing.
 *
 * \section example
 * - C++
 * \code
;
\endcode
 */
class EmptyStatement : public Statement
{
	public:
		EmptyStatement();
		virtual ~EmptyStatement();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
};

#endif	// _ASTM_EMPTY_STATEMENT_H_
