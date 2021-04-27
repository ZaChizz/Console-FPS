//
// Created by Admin on 27.04.2021.
//

#include <iostream>
#include <windows.h>

MSG Msg;

void clrscr()
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { 0, 0 };
    DWORD count;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hStdOut, &csbi);

    FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

    SetConsoleCursorPosition(hStdOut, coord);
}


int main(int argc, char* argv[])
{
    int i = 10;
    SetTimer(NULL, 1, 1000, NULL);

    while (GetMessage(&Msg, NULL, 0, 0) && i)
    {
        if (Msg.message == WM_TIMER) {
            clrscr();
            std::cout << "------" << i << "------" <<std::endl;
            i--;
        }
    }
    return 0;
}
