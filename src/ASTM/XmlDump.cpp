#include "XmlDump.h"
#include "GASTMObject.h"

#include <sstream>

TiXmlElement *
addClass(TiXmlElement *parent, const std::string &name)
{
	TiXmlElement *elem = new TiXmlElement("class");
	elem->SetAttribute("name", name.c_str());
	parent->LinkEndChild(elem);
	return elem;
}

TiXmlElement *
addMember(TiXmlElement *parent, const std::string &name, int value)
{
	static std::ostringstream os;
	//
	TiXmlElement *member = new TiXmlElement("member");
	member->SetAttribute("name", name.c_str());
	//
	os.str("");
	os.clear();
	os << value;
	//
	TiXmlText *val = new TiXmlText(os.str().c_str());
	member->LinkEndChild(val);
	parent->LinkEndChild(member);
	return member;
}

TiXmlElement *
addMember(TiXmlElement *parent, const std::string &name, bool value)
{
	TiXmlElement *member = new TiXmlElement("member");
	member->SetAttribute("name", name.c_str());
	TiXmlText *val = new TiXmlText(value ? "true" : "false");
	member->LinkEndChild(val);
	parent->LinkEndChild(member);
	return member;
}

TiXmlElement *
addMember(TiXmlElement *parent, const std::string &name, const std::string &value)
{
	TiXmlElement *member = new TiXmlElement("member");
	member->SetAttribute("name", name.c_str());
	TiXmlText *val = new TiXmlText(value.c_str());
	member->LinkEndChild(val);
	parent->LinkEndChild(member);
	return member;
}

TiXmlElement *
addMember(TiXmlElement *parent, const std::string &name, const GASTMObject *value)
{
	TiXmlElement *member = new TiXmlElement("member");
	member->SetAttribute("name", name.c_str());
	if(value)
	{
		value->dumpXml(member);
	}
	else
	{
		TiXmlText *val = new TiXmlText("NULL");
		member->LinkEndChild(val);
	}
	parent->LinkEndChild(member);
	return member;
}

TiXmlElement *
addMember(TiXmlElement *parent, const std::string &name, const std::vector<GASTMObject *> *value)
{
	TiXmlElement *member = new TiXmlElement("member");
	member->SetAttribute("name", name.c_str());
	//
	if(value)
	{
		TiXmlElement *item;
		for(size_t i = 0, im = value->size(); i < im; i++)
		{
			item = new TiXmlElement("item");
			item->SetAttribute("index", i);
			if(value->at(i))
			{
				value->at(i)->dumpXml(item);
			}
			else
			{
				TiXmlText *val = new TiXmlText("NULL");
				item->LinkEndChild(val);
			}
			member->LinkEndChild(item);
		}
	}
	else
	{
		TiXmlText *val = new TiXmlText("NULL");
		member->LinkEndChild(val);
	}
	parent->LinkEndChild(member);
	return member;
}
