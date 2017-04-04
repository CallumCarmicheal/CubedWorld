#include "Console.h"
#include <conio.h>

/*
 * Create the console 
 */
void Console::Create() {
   int      hConHandle = 0;
   HANDLE   lStdHandle = 0;
   FILE     *fp        = 0;

   // Allocate a console
   AllocConsole();

   // redirect unbuffered STDOUT to the console
   lStdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   hConHandle = _open_osfhandle(PtrToUlong(lStdHandle), _O_TEXT);
   fp = _fdopen(hConHandle, "w");
   *stdout = *fp;
   setvbuf(stdout, NULL, _IONBF, 0);

   // redirect unbuffered STDIN to the console
   lStdHandle = GetStdHandle(STD_INPUT_HANDLE);
   hConHandle = _open_osfhandle(PtrToUlong(lStdHandle), _O_TEXT);
   fp = _fdopen(hConHandle, "r");
   *stdin = *fp;
   setvbuf(stdin, NULL, _IONBF, 0);

   // redirect unbuffered STDERR to the console
   lStdHandle = GetStdHandle(STD_ERROR_HANDLE);
   hConHandle = _open_osfhandle(PtrToUlong(lStdHandle), _O_TEXT);
   fp = _fdopen(hConHandle, "w");
   *stderr = *fp;
   setvbuf(stderr, NULL, _IONBF, 0);
}


/*
 * print to the console
 */
void Console::WriteLine(char* str) {
	printf(str);
	NewLine();
}

/*
 * print formatted to console
 */
void Console::WriteLineF(char* str, ...) {
	va_list argptr = NULL;
	va_start(argptr, str);
	vprintf(str, argptr);
	va_end(argptr);

    printf("\n");
}

/*
* print formatted to console
*/
void Console::WriteLineF(LPWSTR str, ...) {
	va_list argptr = NULL;
	va_start(argptr, str);
	vwprintf(str, argptr);
	va_end(argptr);

    printf("\n");
}

/*
 * print to the console
 */
void Console::WriteLine(LPWSTR str) {
	wprintf(str);
	NewLine();
}

/*
 * print to the console
 */
void Console::Write(char* str) {
	printf(str);
}

/*
 * print to the console
 */
void Console::Write(LPWSTR str) {
	wprintf(str);
}

/*
 * Print a new line
 */
void Console::NewLine() {
	printf("\n");
}

/*
 * Set consoles title
 */
void Console::SetTitle(LPCSTR str) {
   SetConsoleTitle(str);
}


void Console::Wait() {
   _getch();
}

void Console::Wait(char* str) {
   Console::Write(str);
   Console::Wait();
}

void Console::Wait(LPWSTR str) {
   Console::Write(str);
   Console::Wait();
}

void Console::WaitLine(char* str) {
   Console::WriteLine(str);
   Console::Wait();
}

void Console::WaitLine(LPWSTR str) {
   Console::WriteLine(str);
   Console::Wait();
}

void Console::WaitF(char* str, ...) {
   va_list argptr = NULL;
   va_start(argptr, str);
   vprintf(str, argptr);
   va_end(argptr);

   Console::Wait();
}

void Console::WaitF(LPWSTR str, ...) {
   va_list argptr = NULL;
   va_start(argptr, str);
   vwprintf(str, argptr);
   va_end(argptr);

   Console::Wait();
}

void Console::WaitLineF(char* str, ...) {
   va_list argptr = NULL;
   va_start(argptr, str);
   vprintf(str, argptr);
   va_end(argptr);

   printf("\n");
   Console::Wait();
}

void Console::WaitLineF(LPWSTR str, ...) {
   va_list argptr = NULL;
   va_start(argptr, str);
   vwprintf(str, argptr);
   va_end(argptr);

   printf("\n");
   Console::Wait();
}