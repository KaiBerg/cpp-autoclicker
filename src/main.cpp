#include <iostream>
#include <random>
#define NOMINMAX
#include <Windows.h>
#include <string>
#include <Nuklear/nuklear.h>

int cps;
int cps1;
int cps2;
int timeOut;
int cpsCounter = 0;
bool ToggleClicker = FALSE;
std::mt19937 mTwister;

int select() {
    printf("Enter CPS range you lazy mf: ");

    std::cin >> cps1;
    std::cin >> cps2;
    //idc about errors, dont be dumb using this program fr
    return NULL;
}

int randCPSgen() {
    std::uniform_int_distribution<> range{ cps1, cps2 };
    cps = range(mTwister);
    timeOut = 1000 / cps;
    return NULL;
}

int main()
{
    select();
    randCPSgen();
    for (;;) {
        //use whatever button you want to toggle to program
        if (GetKeyState('P') & 0x8000) {
            ToggleClicker = !ToggleClicker;
            if (ToggleClicker)
                printf("Active");
            else
                printf("Disabled");
            Sleep(128);
        }

        if (GetKeyState('Q') && ToggleClicker)
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, NULL, NULL);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, NULL, NULL);
            Sleep(timeOut);
            cpsCounter++;
            if (cpsCounter >= cps) {
                randCPSgen();
                cpsCounter = 0;
            }
        }
    }
}
