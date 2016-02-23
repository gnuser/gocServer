#ifndef __JSON_UTIL_H__
#define __JSON_UTIL_H__

#include <json/config.h>
#include <json/value.h>
#include <json/writer.h>
#include <json/reader.h>
#include <deque>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

inline string writeJson(map<string, string> data) 
{
	Json::Value root;
	map<string, string>::iterator it=data.begin();
	for(; it!=data.end(); ++it)
    {
		root[it->first] = it->second;
    }
	root.toStyledString();
	std::string out = root.toStyledString();
	return out;
}

inline string writeJson(map<string, Json::Value> data) 
{
	Json::Value root;
	map<string, Json::Value>::iterator it=data.begin();
	for(; it!=data.end(); ++it)
    {
		root[it->first] = it->second;
    }
	root.toStyledString();
	std::string out = root.toStyledString();
	return out;
}

inline map<string, string> readJson(string strValue) 
{
	Json::Reader reader;
	Json::Value value;
	map<string, string> result;
	if (reader.parse(strValue, value))
    {
		Json::Value::Members mem = value.getMemberNames();
		for (int i=0; i<mem.size(); i++)
        {
        	result[mem[i]] = value[mem[i]].asString();
        }
    }
    return result;
}

inline map<string, string> readJsonFile(string file)
{
//	std::ifstream t(file.c_str());
//	std::stringstream buffer;
//	buffer << t.rdbuf();

//	return readJson(buffer.str());

	Json::Value root;
	Json::Reader reader;
    std::ifstream test(file.c_str(), std::ifstream::binary);
    bool parsingSuccessful = reader.parse( test, root, false );
    if ( !parsingSuccessful )
    {
        // report to the user the failure and their locations in the document.
        std::cout  << reader.getFormattedErrorMessages()
               << endl;
    }

    return readJson(root.toStyledString());

}
#endif