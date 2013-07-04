#include "ActualParsingUnit.h"

CompilationUnit * ActualParsingUnit::m_unit = NULL;
std::vector<std::pair<GASTMSyntaxObject *, GASTMSyntaxObject *> > ActualParsingUnit::colisions;