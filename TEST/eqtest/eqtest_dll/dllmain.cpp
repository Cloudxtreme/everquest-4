#undef EQ_FEATURE_BAZAAR
#undef EQ_FEATURE_GUI
#undef EQ_FEATURE_CREATE_AND_DELETE_ACTORS
#define EQ_FEATURE_CollisionCallbackForActors
#undef EQ_FEATURE_DoSpellEffect
#undef EQ_FEATURE_EQPlayer__FollowPlayerAI
#define EQ_FEATURE_EQPlayer__UpdateItemSlot
#undef EQ_FEATURE_EQSwitch__ChangeState
#undef EQ_FEATURE_CEverQuest__StartCasting

#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <locale>
#include <map>
#include <memory>
#include <numeric>
#include <random>
#include <regex>
#include <set>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

#include <filesystem>
namespace std__filesystem = std::experimental::filesystem::v1; // not available yet

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cmath>
#include <ctime>

#define _WINSOCKAPI_ // prevent windows.h from including winsock.h, we use winsock2.h instead

#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
#include <tlhelp32.h>
#include <fcntl.h>
#include <io.h>

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>
#pragma comment(lib, "ws2_32.lib")

#include <psapi.h>
#pragma comment(lib, "psapi.lib")

// DirectX 9
#include <d3d9.h>
#pragma comment(lib, "d3d9.lib")
#include <d3dx9.h>
#pragma comment(lib, "d3dx9.lib")

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

// imgui
// https://github.com/ocornut/imgui
#include "imgui.h"
#include "misc/cpp/imgui_stdlib.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"

// Microsoft Detours 1.5
#include "detours.h"
#pragma comment(lib, "detours.lib")

// LuaJIT
#include "lua.hpp"
#pragma comment(lib, "lua51.lib")
#pragma comment(lib, "luajit.lib")

// sol lua wrapper
// https://github.com/ThePhD/sol2
#include <sol.hpp>

// libfmt
// https://github.com/fmtlib/fmt
#define FMT_HEADER_ONLY
#include "fmt/format.h"

// boost
#include <boost/optional.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

// MacroQuest2
#include "mq2.h"

// EverQuest
#include "eq.h"
#include "eq_functions.h"

// EQApp
#include "eqapp.h"
#include "eqapp_functions.h"

#include "eqapp_addresses.h"
#include "eqapp_actorcollision.h"
#include "eqapp_alwaysattack.h"
#include "eqapp_alwayshotbutton.h"
#include "eqapp_autogroup.h"
#include "eqapp_autologin.h"
#include "eqapp_autotrade.h"
#include "eqapp_bazaarbot.h"
#include "eqapp_bazaarfilter.h"
#include "eqapp_boxchat.h"
#include "eqapp_changeheight.h"
#include "eqapp_combathotbutton.h"
#include "eqapp_console.h"
#include "eqapp_detours.h"
#include "eqapp_esp.h"
#include "eqapp_followai.h"
#include "eqapp_findpath.h"
#include "eqapp_freecamera.h"
#include "eqapp_fps.h"
#include "eqapp_hud.h"
#include "eqapp_interpretcommand.h"
#include "eqapp_lua.h"
#include "eqapp_namecolor.h"
#include "eqapp_namedspawns.h"
#include "eqapp_nodraw.h"
#include "eqapp_sleep.h"
#include "eqapp_spawncastspell.h"
#include "eqapp_speed.h"
#include "eqapp_windowtitle.h"
#include "eqapp_waypoint.h"

#include "eqapp_gui.h"

#include "eqapp_loadoptions.h"

void EQAPP_Load()
{
#ifdef EQ_FEATURE_GUI
    g_GUIIsLoaded = EQAPP_GUI_Load();
#endif // EQ_FEATURE_GUI

#ifdef EQ_FEATURE_CollisionCallbackForActors
    EQAPP_ActorCollision_Load();
#endif // EQ_FEATURE_CollisionCallbackForActors
    EQAPP_AutoLogin_Load();
    EQAPP_WaypointList_Load();
    EQAPP_NamedSpawns_Load();

    if (g_WindowTitleIsEnabled == true)
    {
        EQAPP_WindowTitle_Execute();
    }

    if (g_BoxChatIsEnabled == true && g_BoxChatAutoConnectIsEnabled == true)
    {
        if (EQAPP_BoxChat_IsServerRunning() == true)
        {
            std::string playerSpawnName = EQ_GetPlayerSpawnName();
            if (playerSpawnName.size() != 0)
            {
                EQAPP_BoxChat_Connect(playerSpawnName);
            }
        }
    }

    auto render = EQ_GetRender();
    if (render != NULL)
    {
        std::cout << "CRender: 0x" << std::hex << render << std::dec << std::endl;

        auto devicePointer = EQ_ReadMemory<LPDIRECT3DDEVICE9>(render + EQ_OFFSET_CRender_Direct3DDevicePointer);
        if (devicePointer != NULL)
        {
            std::cout << "CRender Device Pointer: 0x" << std::hex << devicePointer << std::dec << std::endl;
        }
    }

    std::cout << "EQ_SIZE_CXWnd: 0x" << std::hex << EQ_SIZE_CXWnd << std::dec << std::endl;

    std::cout << "EQ_SIZE_CSidlWnd: 0x" << std::hex << EQ_SIZE_CSidlWnd << std::dec << std::endl;

    std::cout << "EQ_OFFSET_CMapViewWnd_LINES: 0x" << std::hex << EQ_OFFSET_CMapViewWnd_LINES << std::dec << std::endl;
    std::cout << "EQ_OFFSET_CMapViewWnd_LABELS: 0x" << std::hex << EQ_OFFSET_CMapViewWnd_LABELS << std::dec << std::endl;

    if (g_LuaIsEnabled == true)
    {
        EQAPP_Lua_EventScriptList_ExecuteFunction("OnLoad");
    }

    std::string timeText = EQAPP_Timer_GetTimeAsString();

    std::cout << "Loaded!    " << timeText;

    g_EQAppIsLoaded = 1;
}

void EQAPP_Unload()
{
    g_NoDrawIsEnabled = false;

    if (g_LuaIsEnabled == true)
    {
        EQAPP_Lua_EventScriptList_ExecuteFunction("OnUnload");
    }

    EQAPP_FreeCamera_Off();
    EQAPP_Speed_Off();

    g_WindowTitleIsEnabled = false;
    EQAPP_WindowTitle_Reset();

    std::string timeText = EQAPP_Timer_GetTimeAsString();

    std::cout << "Unloaded!    " << timeText;

    g_EQAppShouldUnload = 1;
}

DWORD WINAPI EQAPP_ThreadLoop(LPVOID param)
{
    while (g_EQAppShouldUnload == 0)
    {
        Sleep(100);
    }

    // wait for the console to unload
    while (g_ConsoleIsLoaded == 1)
    {
        Sleep(100);
    }

#ifdef EQ_FEATURE_GUI
    EQAPP_GUI_Unload();
#endif // EQ_FEATURE_GUI

    EQAPP_BoxChat_Unload();
    EQAPP_Detours_Unload();

    TerminateThread(EQAPP_ThreadLoad, 0);
    TerminateThread(EQAPP_ThreadConsole, 0);

    FreeLibraryAndExitThread(g_EQAppModule, 0);
    return 0;
}

DWORD WINAPI EQAPP_ThreadLoad(LPVOID param)
{
    EQAPP_EnableDebugPrivileges();

    EQAPP_InitializeAddresses();
    EQAPP_InitializeAddressPointers();

    g_EQAppHandleThreadConsole = CreateThread(NULL, 0, &EQAPP_ThreadConsole, NULL, 0, NULL);

    // wait for the console to load
    while (g_ConsoleIsLoaded == 0);

    g_EQAppHandleThreadLoop = CreateThread(NULL, 0, &EQAPP_ThreadLoop, NULL, 0, NULL);

    EQAPP_LoadOptions();
    EQAPP_Lua_Load();
    EQAPP_Detours_Load();
    EQAPP_AutoLogin_Load();

    EQ_SetNetStatus(true);

    EQAPP_SetWindowTitle("EverQuest*");

    return 0;
}

DWORD WINAPI EQAPP_ThreadConsole(LPVOID param)
{
    EQAPP_Console_Load();

    while (g_EQAppShouldUnload == 0)
    {
        Sleep(100);
    }

    EQAPP_Console_Unload();

    return 0;
}

BOOL __stdcall DllMain(HMODULE module, DWORD reason, LPVOID reserved)
{
    g_EQAppModule = module;

    if (reason == DLL_PROCESS_ATTACH)
    {
        DisableThreadLibraryCalls(module);
        g_EQAppHandleThreadLoad = CreateThread(NULL, 0, &EQAPP_ThreadLoad, NULL, 0, NULL);
    }
    else if (reason == DLL_PROCESS_DETACH)
    {
        //
    }

    return TRUE;
}
