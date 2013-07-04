#ifndef _XML_DUMP_H_
#define _XML_DUMP_H_

#include <string>
#include <vector>

#include "../TinyXML/tinyxml.h"

class GASTMObject;

TiXmlElement * addClass(TiXmlElement *parent, const std::string &name);
TiXmlElement * addMember(TiXmlElement *parent, const std::string &name, int value);
TiXmlElement * addMember(TiXmlElement *parent, const std::string &name, bool value);
TiXmlElement * addMember(TiXmlElement *parent, const std::string &name, const std::string &value);
TiXmlElement * addMember(TiXmlElement *parent, const std::string &name, const GASTMObject *value);
TiXmlElement * addMember(TiXmlElement *parent, const std::string &name, const std::vector<GASTMObject *> *value);

#endif	// _XML_DUMP_H_
