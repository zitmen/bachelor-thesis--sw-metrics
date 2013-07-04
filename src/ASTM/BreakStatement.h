/*!
 * \file
 * BreakStatement.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_BREAK_STATEMENT_H_
#define _ASTM_BREAK_STATEMENT_H_

#include <vector>

#include "Statement.h"
#include "XmlDump.h"

class LabelAccess;

/*!
 * \brief
 * Statements that exit a loop or a switch.
 *
 * \section example Example
 * - C++ has no labelled break statement, so target remains empty
 * \code
while(1)
{
	if(repeat)
		continue;
	else
		break;	// == this
}
// target = NULL;
//
// OR
//
switch(a)
{
	case 5:
		...
		break;	// == this
	...
}
// this->target = NULL;
\endcode
 *
 * - Java
 * \code
test:  for (int i = fromIndex; i + max1 <= max2; i++) {	// here is LabelDefinition = "test"
           if (charAt(i) == c0) {
               for (int k = 1; k<max1; k++) {
                   if (charAt(i+k) != str.charAt(k)) {
                       break test;	// this->target = "test"
                   }
               }     //  end of inner for loop
           }
       }             //  end of outer for loop
\endcode
 */
class BreakStatement : public Statement
{
	public:
		BreakStatement();
		virtual ~BreakStatement();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Target where break jumps.
		 *
		 * \see \ref example
		 * \see LabelAccess
		 */
		LabelAccess *target;
};

#endif	// _ASTM_BREAK_STATEMENT_H_
