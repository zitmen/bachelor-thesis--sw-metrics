/*!
 * \file
 * LabeledStatement.h
 * 
 * \author
 * Martin Ovesný (<a href="mailto:ovesnmar@fel.cvut.cz">ovesnmar@fel.cvut.cz</a>)
 */
#ifndef _ASTM_LABELED_STATEMENT_H_
#define _ASTM_LABELED_STATEMENT_H_

#include <vector>

#include "Statement.h"
#include "XmlDump.h"

class LabelDefinition;

/*!
 * \brief
 * Statements that are associated with a label definition.
 *
 * \section example Example
 * - Java
 * \code
       // this->statement = ( "for ...", that includes also inner IfStatements and another ForStatement )
test:  for (int i = fromIndex; i + max1 <= max2; i++) { // this->label = "test"
           if (charAt(i) == c0) {
               for (int k = 1; k<max1; k++) {
                   if (charAt(i+k) != str.charAt(k)) {
                       continue test;
                   }
               }     //  end of inner for loop
           }
       }             //  end of outer for loop
\endcode
 */
class LabeledStatement : public Statement
{
	public:
		LabeledStatement();
		virtual ~LabeledStatement();
		
		virtual void identify(std::vector<int> &id) const;
		virtual void dumpXml(TiXmlElement *parent) const;
		
		/*!
		 * \brief
		 * Label definition.
		 *
		 * \see \ref example
		 * \see LabelDefinition
		 */
		LabelDefinition *label;
		
		/*!
		 * \brief
		 * Statement associated with the label.
		 *
		 * \see \ref example
		 * \see Statement
		 */
		 Statement *statement;
};

#endif	// _ASTM_LABELED_STATEMENT_H_
