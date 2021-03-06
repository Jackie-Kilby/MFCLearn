// TimeClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "atltime.h"
#include <iostream>
using namespace std;

int main()
{
    //std::cout << "Hello World!\n"; 
	CString strTime;
	CTime curTime = CTime::GetCurrentTime();

	int iYear = curTime.GetYear();
	int iMonth = curTime.GetMonth();
	int iDay = curTime.GetDay();
	int iHour = curTime.GetHour();
	int iMin = curTime.GetMinute();
	int iSec = curTime.GetSecond();

	cout << "当前时间：" << endl;
	cout << iYear << "年" << iMonth << "月" << iDay << "日" << iHour << "时" << iMin << "分" << iSec << "秒" << endl;

	CTime ctStartTime = CTime(2018, 10, 8, 17, 13, 20);
	cout << "起始时间:" << endl;
	cout << ctStartTime.GetYear() << "年" << ctStartTime.GetMonth() << "月" << ctStartTime.GetDay() << "日" << ctStartTime.GetHour() << "时" << ctStartTime.GetMinute() << "分" << ctStartTime.GetSecond() << "秒" << endl;

	CTimeSpan ctsTimeSpan;
	ctsTimeSpan = curTime - ctStartTime;
	cout << "两时间相差：" << endl;
	cout << ctsTimeSpan.GetDays() << "天" << ctsTimeSpan.GetHours() << "小时" << ctsTimeSpan.GetMinutes() << "分" << ctsTimeSpan.GetSeconds() << "秒" << endl;
	cout << "总小时数：" << ctsTimeSpan.GetTotalHours() << "小时" << endl;
	cout << "总分钟数：" << ctsTimeSpan.GetTotalMinutes() << "分钟" << endl;
	cout << "总秒数：" << ctsTimeSpan.GetTotalSeconds() << "秒" << endl;

	strTime = curTime.Format(_T("%Y-%m-%d %H:%M:%S"));
	wcout << (LPCTSTR)strTime << endl;


	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
