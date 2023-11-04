#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <thread>
#include "memory.h"
#include "structures.h"
#include "Display.h"

void mainFunc(HMODULE hModule) {

    //create a console
    AllocConsole();
    FILE* f = nullptr;
    freopen_s(&f, "CONOUT$", "w", stdout);
    Display hackMenu;

    uintptr_t baseAdd = (uintptr_t)GetModuleHandle(NULL);

    playerObj* localPlayerPtr = *(playerObj**)(baseAdd + 0x10F4F4);

    typedef playerObj* (*tgetCrosshairEnt)();
    
    typedef char* (*tPrintChat)(const char* Format, ...);

    tPrintChat printChat = (tPrintChat)(baseAdd + 0x6B060);

    tgetCrosshairEnt getCrosshairEnt = (tgetCrosshairEnt)(0x400000 + 0x607C0);

    int loopCounter = 0;

    printChat("\f%d%s:\f%d%s", 1, "HackClient", 3,  " Loaded...");

    //main loop
    while (!GetKeyState(VK_END))
    {
        if (loopCounter == 40)
        {
            loopCounter = 0;
            hackMenu.update();
        }
        else { loopCounter++; }

        //triggerbot
        if (GetKeyState(VK_F1))
        {
            hackMenu.bTriggerBot = '*';
            playerObj* crosshairEntPtr = getCrosshairEnt();
            if (crosshairEntPtr != nullptr)
            {
                if (crosshairEntPtr->teamNum != localPlayerPtr->teamNum) {
                    localPlayerPtr->bShooting = true;
                }
            }
			else
			{
				localPlayerPtr->bShooting = false;
			}
        }
        else
        {
            hackMenu.bTriggerBot = ' ';
        }

        //no recoil
        if (GetKeyState(VK_F2))
        {
            hackMenu.bNoRecoil = '*';
            mem::patchBytes((void*)"\xC2\x08\x00", (void*)(baseAdd + 0x62020), 3);
        }
        else
        {
            hackMenu.bNoRecoil = ' ';
            mem::patchBytes((void*)"\x55\x8B\xEC", (void*)(baseAdd + 0x62020), 3);
        }

    }



    printChat("\f%d%s:\f%d%s", 1, "HackClient", 3,  " Exited...");


    //close file, free console & free library/eject DLL
    fclose(f);
    FreeConsole();
    FreeLibrary(hModule);
}


BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        std::thread mainThread(mainFunc, hModule);
        mainThread.detach();
    }
    }
    return TRUE;
}

