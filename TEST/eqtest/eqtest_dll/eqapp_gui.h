#pragma once

#ifdef EQ_FEATURE_GUI

#include "imgui_impl_win32.h"

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

extern void EQAPP_InterpretCommand_PrintList();

#include "eqapp_gui_mainwindow.h"
#include "eqapp_gui_mapwindow.h"
#include "eqapp_gui_waypointeditorwindow.h"

bool g_GUIIsEnabled = true;

bool g_GUIIsLoaded = false;

bool g_GUIDarkThemeIsEnabled = true;

bool g_GUIDemoWindowIsEnabled = false;

ImFont* g_GUIFont = NULL;

void EQAPP_GUI_Toggle();
void EQAPP_GUI_On();
void EQAPP_GUI_Off();
bool EQAPP_GUI_Load();
void EQAPP_GUI_Unload();
bool EQAPP_GUI_IsMouseOver();
signed int EQAPP_GUI_HandleEvent_WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
bool EQAPP_GUI_HandleEvent_ProcessMouseEvent();
bool EQAPP_GUI_HandleEvent_ProcessKeyboardEvent();
bool EQAPP_GUI_HandleEvent_CXWndManager__DrawCursor();
bool EQAPP_GUI_HandleEvent_CEverQuest__HandleMouseWheel(signed int delta);
void EQAPP_GUI_HandleEvent_CRender__ResetDevice_Before();
void EQAPP_GUI_HandleEvent_CRender__ResetDevice_After();
void EQAPP_GUI_HandleEvent_CRender__UpdateDisplay();

void EQAPP_GUI_Toggle()
{
    EQ_ToggleBool(g_GUIIsEnabled);
    EQAPP_PrintBool("GUI", g_GUIIsEnabled);
}

void EQAPP_GUI_On()
{
    if (g_GUIIsEnabled == false)
    {
        EQAPP_GUI_Toggle();
    }
}

void EQAPP_GUI_Off()
{
    if (g_GUIIsEnabled == true)
    {
        EQAPP_GUI_Toggle();
    }
}

bool EQAPP_GUI_Load()
{
    HWND window = EQ_GetWindow();
    if (window == NULL)
    {
        return false;
    }

    auto render = EQ_GetRender();
    if (render == NULL)
    {
        return false;
    }

    IMGUI_CHECKVERSION();

    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ////io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;    // enable keyboard controls
    io.ConfigWindowsMoveFromTitleBarOnly = true;

    g_GUIFont = io.Fonts->AddFontDefault();
    if (g_GUIFont == NULL)
    {
        return false;
    }

    if (ImGui_ImplWin32_Init(window) == false)
    {
        return false;
    }

    auto devicePointer = EQ_ReadMemory<LPDIRECT3DDEVICE9>(render + EQ_OFFSET_CRender_Direct3DDevicePointer);
    if (devicePointer == NULL)
    {
        return false;
    }

    if (ImGui_ImplDX9_Init(devicePointer) == false)
    {
        return false;
    }

    ImGuiStyle& style = ImGui::GetStyle();
    style.FrameBorderSize = 1.0f;

    ImGui::StyleColorsDark();
    g_GUIDarkThemeIsEnabled = true;

    //// EQAPP_GUI_MapWindow_LoadTextures();

    return true;
}

void EQAPP_GUI_Unload()
{
    g_GUIIsLoaded = false;

    ImGui_ImplDX9_Shutdown();
    ImGui_ImplWin32_Shutdown();

    ImGui::DestroyContext();
}

bool EQAPP_GUI_IsMouseOver()
{
    if (g_GUIIsEnabled == false)
    {
        return false;
    }

    if (g_GUIIsLoaded == false)
    {
        return false;
    }

    if (EQ_IsWindowInBackground() == true || EQ_IsMouseLookEnabled() == true)
    {
        return false;
    }

    if (ImGui::IsWindowHovered(ImGuiHoveredFlags_AnyWindow) == false)
    {
        return false;
    }

    return true;
}

signed int EQAPP_GUI_HandleEvent_WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (g_GUIIsLoaded == false)
    {
        return 0;
    }

    ImGuiIO& io = ImGui::GetIO();

    if (EQ_IsWindowInBackground() == true || EQ_IsMouseLookEnabled() == true)
    {
        // have to do this to fix a bug when switching windows
        // game would think it was still in the foreground
        io.WantCaptureMouse = false;
        io.WantCaptureKeyboard = false;

        return 0;
    }

    if (io.WantCaptureMouse == true || (io.WantCaptureKeyboard == true && EQ_IsPlayerMoving() == false))
    {
        if (ImGui_ImplWin32_WndProcHandler(hwnd, uMsg, wParam, lParam))
        {
            return 1;
        }

        return -1;
    }

    return 0;
}

bool EQAPP_GUI_HandleEvent_ProcessMouseEvent()
{
    if (g_GUIIsLoaded == false)
    {
        return false;
    }

    if (EQ_IsWindowInBackground() == true || EQ_IsMouseLookEnabled() == true)
    {
        return false;
    }

    ImGuiIO& io = ImGui::GetIO();
    if (io.WantCaptureMouse == true)
    {
        EQ_FUNCTION_FlushDxMouse();

        //EQ::MouseState_ptr mouseState = (EQ::MouseState_ptr)EQ_ADDRESS_DirectInputMouseCopy;
        //mouseState->InWindow = 0;

        return true;
    }
    else
    {
        memset(io.MouseDown, 0, sizeof(io.MouseDown));
        io.MouseWheel = 0.0f;

        //EQ::MouseState_ptr mouseState = (EQ::MouseState_ptr)EQ_ADDRESS_DirectInputMouseCopy;
        //mouseState->InWindow = 1;
    }

    return false;
}

bool EQAPP_GUI_HandleEvent_ProcessKeyboardEvent()
{
    if (g_GUIIsLoaded == false)
    {
        return false;
    }

    if (EQ_IsWindowInBackground() == true || EQ_IsMouseLookEnabled() == true || EQ_IsPlayerMoving() == true)
    {
        return false;
    }

    ImGuiIO& io = ImGui::GetIO();
    if (io.WantCaptureKeyboard == true)
    {
        EQ_FUNCTION_FlushDxKeyboard();

        return true;
    }

    return false;
}

bool EQAPP_GUI_HandleEvent_CXWndManager__DrawCursor()
{
    if (g_GUIIsLoaded == false)
    {
        return false;
    }

    if (EQ_IsWindowInBackground() == true || EQ_IsMouseLookEnabled() == true)
    {
        return false;
    }

    ImGuiIO& io = ImGui::GetIO();
    if (io.WantCaptureMouse == true)
    {
        return true;
    }

    return false;
}

bool EQAPP_GUI_HandleEvent_CEverQuest__HandleMouseWheel(signed int delta)
{
    if (g_GUIIsLoaded == false)
    {
        return false;
    }

    if (EQ_IsWindowInBackground() == true || EQ_IsMouseLookEnabled() == true)
    {
        return false;
    }

    ImGuiIO& io = ImGui::GetIO();
    if (io.WantCaptureMouse == true)
    {
        return true;
    }

    if (ImGui::IsWindowHovered(ImGuiHoveredFlags_AnyWindow) == true)
    {
        return true;
    }

    return false;
}

void EQAPP_GUI_HandleEvent_CRender__ResetDevice_Before()
{
    if (g_GUIIsLoaded == false)
    {
        return;
    }

    ImGui_ImplDX9_InvalidateDeviceObjects();
}

void EQAPP_GUI_HandleEvent_CRender__ResetDevice_After()
{
    if (g_GUIIsLoaded == false)
    {
        return;
    }

    ImGui_ImplDX9_CreateDeviceObjects();
}

void EQAPP_GUI_HandleEvent_CRender__UpdateDisplay()
{
    if (g_GUIIsLoaded == false)
    {
        return;
    }

    if (EQ_IsWindowInBackground() == true)
    {
        return;
    }

    ImGui_ImplDX9_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();

    if (g_GUIDemoWindowIsEnabled == true)
    {
        ImGui::ShowDemoWindow(&g_GUIDemoWindowIsEnabled);
    }

    EQAPP_GUI_MainWindow();

    if (g_GUIMapWindowIsEnabled == true)
    {
        EQAPP_GUI_MapWindow();
    }

    if (g_GUIWaypointEditorWindowIsEnabled == true)
    {
        EQAPP_GUI_WaypointEditorWindow();
    }

    ImGui::EndFrame();

    ImGui::Render();
    ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}

#endif // EQ_FEATURE_GUI
