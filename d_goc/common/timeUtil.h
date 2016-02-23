// timeUtil.h
//
// last-edit-by: <cjing> 
//
// Description:
//
// Created: 2015/04/24 12:11:48//
//
//////////////////////////////////////////////////////////////////////

#ifndef __TIMEUTIL_H__
#define __TIMEUTIL_H__

#include <time.h>
#include <sstream>
#include "stringUtil.h"

using namespace std;

inline bool isTimeout(int hour, int minute, int second)
{
	time_t timep;
	struct tm *p;
	time(&timep); /*获得time_t结构的时间，UTC时间*/
	p = localtime(&timep); /*转换为struct tm结构的当地时间*/
	//	printf("%d/%d/%d ", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
	//	printf("%s %d:%d:%d/n", wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec);
	if (p->tm_hour < hour) 
	{
		return false;
	}

	if (p->tm_hour == hour && p->tm_min < minute)
	{
		return false;
	}

	if (p->tm_hour == hour && p->tm_min == minute && p->tm_sec <= second)
	{
		return false;
	}

	cout << "isTimeout:" << p->tm_hour << ":" << p->tm_min << ":" << p->tm_sec << endl;		

	return true;
}

inline string getCurrentTime()
{
	stringstream ss;

	time_t timep;
	struct tm *p;
	time(&timep); /*获得time_t结构的时间，UTC时间*/
	p = localtime(&timep); /*转换为struct tm结构的当地时间*/

	string result = "";
	if (p->tm_hour < 10)
	{
		ss << "0" << p->tm_hour;
	}
	else
	{
		ss << p->tm_hour;
	}
	ss << ":";
	if(p->tm_min < 10)
	{
		ss << "0" << p->tm_min;
	}
	else
	{
		ss << p->tm_min;
	}
	ss << ":";
	if(p->tm_sec < 10)
	{
		ss << "0" << p->tm_sec;
	}
	else
	{
		ss << p->tm_sec;
	}	
	result = ss.str();
	return result;
}


inline bool isTimeLater(string src, string dst)
{
	return dst > src;
}

/// src， dst都是时:分:秒格式
inline int diffSeconds(string src, string dst)
{
	vector<string> srcTime = split(src, ':');
	vector<string> dstTime = split(dst, ':');

	int srcHour = convert<int>(srcTime[0]);
	int srcMin = convert<int>(srcTime[1]);
	int srcSec = convert<int>(srcTime[2]);	

	int dstHour = convert<int>(dstTime[0]);
	int dstMin = convert<int>(dstTime[1]);
	int dstSec = convert<int>(dstTime[2]);		

	return (dstHour - srcHour) * 60 * 60 + (dstMin - srcMin) * 60 + (dstSec - srcSec);
}

///
// 获取当前年月日
///
inline string currentDay()
{
	time_t tt;
	time(&tt);
	struct tm *p;
	p=localtime(&tt);
	string day = convert<string>(p->tm_year+1900);
	day += "-" + convert<string>(p->tm_mon+1);
	day += "-" + convert<string>(p->tm_mday);
	return day;
}

#endif // TIMEUTIL_H__
//////////////////////////////////////////////////////////////////////
// $Log:$
//
