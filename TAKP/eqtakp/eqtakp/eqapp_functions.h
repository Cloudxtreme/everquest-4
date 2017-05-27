#pragma once

#include "eqapp.h"

template <class T>
void EQAPP_Log(const char* text, T number);

void EQAPP_String_ReplaceAll(std::string& subject, const std::string& search, const std::string& replace);

void EQAPP_EnableDebugPrivileges();
DWORD EQAPP_GetModuleBaseAddress(const wchar_t* moduleName);
bool EQAPP_IsForegroundWindowCurrentProcessId();

void EQAPP_PrintBool(const char* text, bool& b);
void EQAPP_PrintErrorMessage(const char* functionName, std::string text);
void EQAPP_PrintDebugMessage(const char* functionName, std::string text);

void EQAPP_PlaySound(const char* filename);
void EQAPP_Beep();
void EQAPP_BeepEx(UINT beepType);
void EQAPP_DeleteFileContents(const char* filename);
void EQAPP_ReadFileToList(const char* filename, std::vector<std::string>& list);

uint32_t EQAPP_GetRandomNumber(uint32_t low, uint32_t high);

template <class T>
void EQAPP_Log(const char* text, T number)
{
    std::stringstream filePath;
    filePath << g_applicationName << "/log.txt";

    std::fstream file;
    file.open(filePath.str().c_str(), std::ios::out | std::ios::app);
    file << "[" << __TIME__ << "] " << text << " (" << number << ")" << " Hex(" << std::hex << number << std::dec << ")" << std::endl;
    file.close();
}

void EQAPP_String_ReplaceAll(std::string& subject, const std::string& search, const std::string& replace)
{
    std::size_t position = 0;
    while ((position = subject.find(search, position)) != std::string::npos)
    {
         subject.replace(position, search.length(), replace);
         position += replace.length();
    }
}

void EQAPP_EnableDebugPrivileges()
{
    HANDLE token;

    if (OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &token))
    {
        TOKEN_PRIVILEGES tp;
        TOKEN_PRIVILEGES tpPrevious;

        DWORD cbPrevious = sizeof(TOKEN_PRIVILEGES);

        LUID luid;

        if (LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luid))
        {
            tp.PrivilegeCount           = 1;
            tp.Privileges[0].Luid       = luid;
            tp.Privileges[0].Attributes = 0;

            AdjustTokenPrivileges(token, FALSE, &tp, sizeof(TOKEN_PRIVILEGES), &tpPrevious, &cbPrevious);

            tpPrevious.PrivilegeCount            = 1;
            tpPrevious.Privileges[0].Luid        = luid;
            tpPrevious.Privileges[0].Attributes |= (SE_PRIVILEGE_ENABLED);

            AdjustTokenPrivileges(token, FALSE, &tpPrevious, cbPrevious, NULL, NULL);
        }
    }

    CloseHandle(token);
}

DWORD EQAPP_GetModuleBaseAddress(const wchar_t* moduleName)
{
    DWORD moduleBaseAddress = 0;
    DWORD processId = GetCurrentProcessId();
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, processId);

    if (snapshot != INVALID_HANDLE_VALUE)
    {
        MODULEENTRY32 ModuleEntry32 = {0};
        ModuleEntry32.dwSize = sizeof(MODULEENTRY32);

        if (Module32First(snapshot, &ModuleEntry32))
        {
            do
            {
                if (wcscmp(ModuleEntry32.szModule, moduleName) == 0)
                {
                    moduleBaseAddress = (DWORD)ModuleEntry32.modBaseAddr;
                    break;
                }
            } while (Module32Next(snapshot, &ModuleEntry32));
        }

        CloseHandle(snapshot);
    }

    return moduleBaseAddress;
}

bool EQAPP_IsForegroundWindowCurrentProcessId()
{
    HWND foregroundHwnd = GetForegroundWindow();

    DWORD foregroundProcessId;
    GetWindowThreadProcessId(foregroundHwnd, &foregroundProcessId);

    return (foregroundProcessId == GetCurrentProcessId());
}

void EQAPP_PrintBool(const char* text, bool& b)
{
    std::cout << text << ": " << (b ? "On" : "Off") << std::endl;
}

void EQAPP_PrintErrorMessage(const char* functionName, std::string text)
{
    std::cout << "[ERROR] " << functionName << ": " << text << std::endl;
}

void EQAPP_PrintDebugMessage(const char* functionName, std::string text)
{
    std::cout << "[DEBUG] " << functionName << ": " << text << std::endl;
}

void EQAPP_PlaySound(const char* filename)
{
    PlaySoundA(filename, 0, SND_FILENAME | SND_NODEFAULT | SND_ASYNC);
}

void EQAPP_Beep()
{
    MessageBeep(0);
}

void EQAPP_BeepEx(UINT beepType)
{
    MessageBeep(beepType);
}

void EQAPP_DeleteFileContents(const char* filename)
{
    std::fstream file;
    file.open(filename, std::fstream::out | std::fstream::trunc);
    file.close();
}

void EQAPP_ReadFileToList(const char* filename, std::vector<std::string>& list)
{
    std::stringstream filePath;
    filePath << g_applicationName << "/" << filename;

    std::string filePathStr = filePath.str();

    std::fstream file;
    file.open(filePathStr.c_str(), std::fstream::in);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePathStr;

        EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        if (line.size() == 0)
        {
            continue;
        }

        if (line.at(0) == '#')
        {
            continue;
        }

        std::cout << filename << ": " << line << std::endl;

        list.push_back(line);
    }

    file.close();
}

uint32_t EQAPP_GetRandomNumberLowHigh(uint32_t low, uint32_t high)
{
    std::uniform_int_distribution<uint32_t> uid;
    std::uniform_int_distribution<uint32_t>::param_type uidpt(low, high);

    return uid(g_randomEngine, uidpt);
}

