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

	static void WriteLine(char* str);
	static void WriteLine(LPWSTR str);

	static void WriteLineF(char* str, ...);
	static void WriteLineF(LPWSTR str, ...);

	static void Write(char* str);
	static void Write(LPWSTR str);

	static void NewLine();
};

