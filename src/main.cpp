#include <iostream>
#include <random>
#define NOMINMAX
#include <Windows.h>

int cps;
int timeOut;

int main()
{
    printf("Enter CPS you lazy mf: ");
    std::cin >> cps;

    timeOut = 1000 / cps;

    for (;;) {
        if (GetAsyncKeyState(VK_F1))
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, NULL, NULL);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, NULL, NULL);
            Sleep(timeOut);
        }
    }
}
