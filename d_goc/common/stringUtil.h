// stringUtil.h
//
// last-edit-by: <cjing> 
//
// Description:
//
// Created: 2015/04/24 11:12:04//
//
//////////////////////////////////////////////////////////////////////

#ifndef __STRINGUTIL_H__
#define __STRINGUTIL_H__

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

inline vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str); // Turn the string into a stream.
	string tok;
  
	while(getline(ss, tok, delimiter)) {
		internal.push_back(tok);
	}
  
	return internal;
}

inline string doubleToStr(double d)
{
	string str;
	stringstream ss;
	ss << d;
	ss >> str;
	return str;
}

/**
*@brief 将T类型转换为string
*@param val
*@return string
*/
template<class T> string convertToString(const T& val)
{
    ostringstream s;
 
    //T -> string
    if (!(s << val))
    {
        std::cout << "can't convert form T type to string type !" << std::endl;
    }
 
    return s.str();
}
 
/**
*@brief 将string转换为T类型
*@param val
*@return string
*/
template<class T> T convertFromString(const string& str)
{
    istringstream s(str);
 
    T buf;
    //string -> T
    if (!(s >> buf))
    {
        std::cout << "can't convert from string type to T type !" << std::endl;
    }
 
    return buf;
}

template<class out_type,class in_value>
out_type convert(const in_value & t)
{
	stringstream stream;
	stream<<t;//向流中传值
	out_type result;//这里存储转换结果
	stream>>result;//向result中写入值
	return result;
}

inline string& trim(string& str)
{
  string::size_type pos = str.find_last_not_of(' ');
  if(pos != string::npos) {
    str.erase(pos + 1);
    pos = str.find_first_not_of(' ');
    if(pos != string::npos) str.erase(0, pos);
  }
  else str.erase(str.begin(), str.end());
  return str;
}

#endif // STRINGUTIL_H__
//////////////////////////////////////////////////////////////////////
// $Log:$
//
