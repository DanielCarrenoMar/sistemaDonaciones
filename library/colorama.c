#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int isWindows10orGreater() {
    OSVERSIONINFOEX info;
    ZeroMemory(&info, sizeof(OSVERSIONINFOEX));
    info.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    info.dwMajorVersion = 10;

    DWORDLONG mask = 0;
    VER_SET_CONDITION(mask, VER_MAJORVERSION, VER_GREATER_EQUAL);

    return VerifyVersionInfo(&info, VER_MAJORVERSION, mask);
}

void just_fix_windows_console() {
    if (!isWindows10orGreater()) {
        printf("Colorma no funcion para versiones inferiores Windows 10\n");
        exit(1);
    }

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) {
        return;
    }

    DWORD consoleMode;
    if (!GetConsoleMode(hConsole, &consoleMode)) {
        return;
    }

    consoleMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hConsole, consoleMode)) {
        return;
    }
}