#pragma once

namespace EQApp
{
    typedef struct _Memory
    {
        uint32_t Index;
        std::string Name;
        std::string Filename;
        std::string Description;
        bool Enabled;
    } Memory, *Memory_ptr;
}

bool g_memoryIsEnabled = true;
std::vector<EQApp::Memory> g_memoryList;
uint32_t g_memoryFilesMax = 255;
uint32_t g_memoryAddressesMax = 8;

void EQAPP_Memory_Load();
void EQAPP_Memory_Unload();
void EQAPP_Memory_Set(EQApp::Memory* pMemory, bool bEnable);
void EQAPP_Memory_ToggleByIndex(uint32_t index);
void EQAPP_Memory_Print();

void EQAPP_Memory_Load()
{
    std::cout << "Loading Memory..." << std::endl;

    g_memoryList.clear();

    std::stringstream filePathIni;
    filePathIni << g_applicationName << "/memory.ini";

    std::string filePathIniStr = filePathIni.str();

    const char* filePathIniCStr = filePathIniStr.c_str();

    g_memoryIsEnabled = EQAPP_INI_ReadBool(filePathIniCStr, "Memory", "bEnabled", 1);

    if (g_memoryIsEnabled == false)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "memory is disabled");
        return;
    }

    for (size_t i = 0; i < g_memoryFilesMax; i++)
    {
        std::stringstream ssFilename;
        ssFilename << "sFilename" << i;

        std::string filename = EQAPP_INI_ReadString(filePathIniCStr, "Memory", ssFilename.str().c_str(), "");
        if (filename.size() == 0)
        {
            EQAPP_PrintErrorMessage(__FUNCTION__, "");
            break;
        }

        std::stringstream filePath;
        filePath << g_applicationName << "/memory/" << filename;

        std::stringstream ssEnabled;
        ssEnabled << "bEnabled" << i;

        EQApp::Memory memory;
        memory.Enabled = EQAPP_INI_ReadBool(filePathIniCStr, "Memory", ssEnabled.str().c_str(), 0);

        std::cout << __FUNCTION__ << ": " << filename << " Enabled: " << std::boolalpha << memory.Enabled << std::noboolalpha << std::endl;

        memory.Index          = i;
        memory.Filename       = filePath.str();
        memory.Name           = EQAPP_INI_ReadString(filePath.str().c_str(), "Memory", "Name", "");
        memory.Description    = EQAPP_INI_ReadString(filePath.str().c_str(), "Memory", "Description", "");
        
        g_memoryList.push_back(memory);
    }

    for (auto& memory : g_memoryList)
    {
        if (memory.Enabled == true)
        {
            EQAPP_Memory_Set(&memory, true);

            std::cout << __FUNCTION__ << ": " << memory.Filename << " has been enabled" << std::endl;
        }
    }
}

void EQAPP_Memory_Unload()
{
    std::cout << "Unloading Memory..." << std::endl;

    for (auto& memory : g_memoryList)
    {
        EQAPP_Memory_Set(&memory, false);
    }
}

void EQAPP_Memory_Set(EQApp::Memory* pMemory, bool bEnable)
{
    if (pMemory == NULL)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "memory is NULL");
        return;
    }

    pMemory->Enabled = bEnable;

    for (size_t i = 0; i < g_memoryAddressesMax; i++)
    {
        std::stringstream ssFilename;
        ssFilename << pMemory->Filename.c_str() << ".ini";

        std::stringstream ssAddress;
        ssAddress << "Address" << i;

        std::string sAddress = EQAPP_INI_ReadString(ssFilename.str().c_str(), "Memory", ssAddress.str().c_str(), "");

        if (sAddress.size() == 0)
        {
            ////EQAPP_PrintErrorMessage(__FUNCTION__, "address size is ZERO");
            continue;
        }

        if (sAddress.find("+") == std::string::npos)
        {
            ////EQAPP_PrintErrorMessage(__FUNCTION__, "address '+' operator NOT found");
            continue;
        }

        std::transform(sAddress.begin(), sAddress.end(), sAddress.begin(), ::tolower);

        std::stringstream ssEnable;
        ssEnable << "Enable" << i;

        std::stringstream ssDisable;
        ssDisable << "Disable" << i;

        std::string sEnable  = EQAPP_INI_ReadString(ssFilename.str().c_str(), "Memory", ssEnable.str().c_str(), "");
        std::string sDisable = EQAPP_INI_ReadString(ssFilename.str().c_str(), "Memory", ssDisable.str().c_str(), "");

        DWORD baseAddress = 0;

        // find eqgame.exe or EQGraphicsDLL__.dll and get base address
        if (sAddress.find(EQ_STRING_PROCESS_NAME) != std::string::npos)
        {
            baseAddress = EQ_ADDRESS_BASE;
        }
        else if (sAddress.find(EQ_STRING_GRAPHICS_DLL_NAME) != std::string::npos || sAddress.find(EQ_STRING_GRAPHICS_DLL_NAME_LOWERCASE) != std::string::npos)
        {
            baseAddress = EQ_ReadMemory<DWORD>(EQ_ADDRESS_GRAPHICS_DLL_POINTER_BASE);
        }

        std::istringstream addressSplit(sAddress);
        std::vector<std::string> addressTokens;
        for (std::string addressToken; std::getline(addressSplit, addressToken, '+'); addressTokens.push_back(addressToken));

        DWORD offset = std::stoul(addressTokens.back(), NULL, 16);

        DWORD address = baseAddress + offset;

        std::string sBytes;
        if (bEnable == true)
        {
            sBytes = sEnable;
        }
        else
        {
            sBytes = sDisable;
        }

        if (sBytes.size() == 0)
        {
            EQAPP_PrintErrorMessage(__FUNCTION__, "bytes size is ZERO");
            break;
        }

        std::istringstream bytesSplit(sBytes);
        std::vector<std::string> bytesTokens;
        for (std::string bytesToken; std::getline(bytesSplit, bytesToken, ' '); bytesTokens.push_back(bytesToken));

        unsigned char value[256];
        size_t valueSize = 0;

        for (auto& token : bytesTokens)
        {
            value[valueSize] = (unsigned char)(std::stoul(token, NULL, 16));
            valueSize++;
        }

        DWORD oldProtection;
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, valueSize, PAGE_EXECUTE_READWRITE, &oldProtection);

        WriteProcessMemory(GetCurrentProcess(), (LPVOID)address, value, valueSize, 0);

        DWORD tempProtection;
        VirtualProtectEx(GetCurrentProcess(), (LPVOID)address, valueSize, oldProtection, &tempProtection);
    }
}

void EQAPP_Memory_ToggleByIndex(uint32_t index)
{
    if (index > (g_memoryList.size() - 1))
    {
        std::stringstream ss;
        ss << "no memory found at specified index: " << index;

        EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());
        return;
    }

    EQApp::Memory* pMemory = &g_memoryList.at(index);
    EQ_ToggleBool(pMemory->Enabled);
    EQAPP_Memory_Set(pMemory, pMemory->Enabled);
    EQAPP_PrintBool(pMemory->Name.c_str(), pMemory->Enabled);
}

void EQAPP_Memory_Print()
{
    std::cout << "Memory List:" << std::endl;
    std::cout << "Index : Enabled : Name (Description)" << std::endl;

    for (auto& memory : g_memoryList)
    {
        std::cout << "#" << memory.Index << " : " << memory.Enabled << " : " << memory.Name << " (" << memory.Description << ")" << std::endl;
    }
}