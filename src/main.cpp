#include <iostream>
#include <random>
#define NOMINMAX
#include <Windows.h>


int main()
{
    for (;;) {
        if (GetAsyncKeyState(VK_F1))
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, NULL, NULL);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, NULL, NULL);
            printf("click");
            Sleep(33);
        }
    }
}
