#include <windows.h>
#include <fcntl.h>
#include <stdio.h>
#include <io.h>
#include <string>

#pragma once
class Console
{
public:
	static void Create();

    static void SetTitle(LPCSTR str);

	static void WriteLine(char* str);
	static void WriteLine(LPWSTR str);

	static void WriteLineF(char* str, ...);
	static void WriteLineF(LPWSTR str, ...);

	static void Write(char* str);
	static void Write(LPWSTR str);

    static void Wait();
    static void Wait(char* str);
    static void Wait(LPWSTR str);

    static void WaitF(char* str, ...);
    static void WaitF(LPWSTR str, ...);

    static void WaitLine(char* str);
    static void WaitLine(LPWSTR str);

    static void WaitLineF(char* str, ...);
    static void WaitLineF(LPWSTR str, ...);
	static void NewLine();
};

