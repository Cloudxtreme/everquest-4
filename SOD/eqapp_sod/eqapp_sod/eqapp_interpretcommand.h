#pragma once

const std::vector<std::string> g_interpretCommandList
{
    "//help",
    "//unload",
    "//debug",
    "//test",
    "//hud",
    "//executecommanddebug, //ecd",
    "//executecommand",
    "//lootdebug, //ld",
    "//loot (item name)",
    "//autoloot, //al",
    "//autolootlist, //all",
    "//autolootreset",
    "//autolootadd (item name), //ala (item name)",
    "//autolootremove (item name), //alr (item name)",
    "//castray, //cr",
    "//meleerange, //mr",
    "//getspellname (spell id)",
    "//targetinfo, //ti",
    "//bank, //currency",
    "//banklist, //bl",
    "//banklist (item name), //bl (item name)",
    "//inventorylist, //il",
    "//inventorylist (item name), //il (item name)",
    "//spawnlist, //sl",
    "//spawnlist (spawn name), //sl (spawn name)",
    "//esp",
    "//espspawn, //esps",
    "//espgroundspawn, //espgs",
    "//espdoor, //espd",
    "//espskeleton, //espsk",
    "//espzoneactor, //espza",
    "//zoneactorsdebug, //zad",
    "//espcustom, //espc",
    "//espwaypoint, //espwp",
    "//setespspawndistance (distance), //setesps (distance), //setesp (distance)",
    "//setespgroundspawndistance (distance), //setespgs (distance)",
    "//setespdoordistance (distance), //setespd (distance)",
    "//setespskeletondistance (distance), //setespsk (distance)",
    "//setespzoneactordistance (distance), //setespza (distance)",
    "//setespcustomdistance (distance), //setespc (distance)",
    "//setespwaypointdistance (distance), //setespwp (distance)",
    "//getespcustomlocation, //getecl",
    "//speed",
    "//setspeed sow",
    "//setspeed run1",
    "//setspeed run2",
    "//setspeed run3",
    "//setspeed (speed), //ss (speed)",
    "//swimspeed",
    "//setswimspeed (speed), //sss (speed)",
    "//setrace (race id), //sr (race id)",
    "//locator, //loc",
    "//locatorline, //locline",
    "//getlocator, //getloc",
    "//setlocator (y) (x) (z), //setloc (y) (x) (z)",
    "//find",
    "//findline",
    "//getfind",
    "//setfind (spawn name)",
    "//linetotarget, //ltt",
    "//memorylist, //ml",
    "//memory (index), //mem (index)",
    "//alwaysattack, //aa",
    "//combathotbutton, //chb",
    "//getcombathotbutton, //getchb",
    "//setcombathotbutton (index), //setchb (index)",
    "//alwayshotbutton, //ahb",
    "//getalwayshotbutton, //getahb",
    "//setalwayshotbutton (index), //setahb (index)",
    "//ahbsitstandatmana",
    "//setahbsitatmana (mana)",
    "//setahbstandatmana (mana)",
    "//getahbsitstandatmana, //getahbsitatmana, //getahbstandatmana",
    "//setcollisionradius (radius), //setcr (radius)",
    "//drawdistance, //dd",
    "//getdrawdistance, //getdd",
    "//setdrawdistance (distance), //setdd  (distance)",
    "//setfieldofview (fov), //setfov (fov)",
    "//targetbeep, //tbeep",
    "//gettargetbeep, //gettbeep",
    "//settargetbeep (name) (delay), //settbeep (name) (delay), //stb (name) (delay)",
    "//spawnbeep, //sbeep",
    "//getspawnbeep, //getsbeep",
    "//setspawnbeep (name), //setsbeep (name), //ssb (name)",
    "//playeralert, //pa",
    "//getplayeralert, //getpa",
    "//setplayeralert (number), //setpa (number)",
    "//changeheight",
    "//setheight (height), //sh (height)",
    "//maplabels",
    "//addmaplabels, //addml",
    "//removemaplabels, //removeml",
    "//getmaplabels, //getml",
    "//filtermaplabels, //filterml",
    "//getfiltermaplabels, //getfilterml",
    "//setfiltermaplabels (spawn name), //setfilterml (spawn name)",
    "//getzoneinfo, //getzi",
    "//loadmemory, //loadmem",
    "//sounds",
    "//loadsounds",
    "//getsounds",
    "//namedspawns, //ns",
    "//loadnamedspawns, //loadns",
    "//loadespcustom, //loadespc",
    "//getnamedspawns, //getns",
    "//writecharacterfile, //writechar, //writecf",
    "//loadtextoverlaychattext, //loadtoct",
    "//gettextoverlaychattext, //gettoct",
    "//getonscreentext, //getost",
    "//loadnobeep, //loadnb",
    "//getnobeep, //getnb",
    "//loadshortzonenames, //loadzsn",
    "//getshortzonenames, //getzsn",
    "//hidecorpselooted, //hcl",
    "//openalldoors, //opendoors",
    "//closealldoors, //closedoors",
    "//census",
    "//freecamera, //freecam, //fc",
    "//setviewactor (spawn name), //setva (spawn name)",
    "//setviewactortarget, //setvat",
    "//resetviewactor, //resetva",
    "//maplocations, //maplocs",
    "//getmaplocation, //getmaploc",
    "//openzonemapfile, //openzmf",
    "//backstab",
    "//setbackstab (index), //setbs (index)",
    "//getbackstab, //getbs",
    "//waypointadd, //wpa",
    "//waypointremove (index), //wpr (index)",
    "//waypointconnect (index), //wpc (index)",
    "//waypointdisconnect (index), //wpd (index)",
    "//waypointlist, //wpl",
    "//waypointlistclear, //wplc",
    "//waypointlistload, //wpll",
    "//waypointlistsave, //wpls",
    "//waypointgetpathlist (from index) (to index), //wpgpl (from index) (to index)",
    "//zoneactorsnocollision, //zanc",
    "//loadzoneactorsnocollision, //loadzanc",
    "//executezoneactorsnocollision, //executezanc",
    "//restorezoneactorsnocollision, //restorezanc",
    "//getzoneactorsnocollision, //getzanc",
    "//chatfilter, //cf",
    "//chatfilterlist, //cfl",
    "//chatfilterreset",
    "//chatfilteradd (text), //cfa (text)",
    "//chatfilterremove (text), //cfr (text)",
};

void EQAPP_InterpretCommand(const char* command);

void EQAPP_InterpretCommand(const char* command)
{
    std::cout << "command: " << command << std::endl;

    // help
    if (strcmp(command, "//help") == 0)
    {
        std::cout << "Command List:" << std::endl;

        for (auto& slashCommand : g_interpretCommandList)
        {
            std::cout << slashCommand << std::endl;
        }

        return;
    }

    // unload
    if (strcmp(command, "//unload") == 0)
    {
        EQAPP_Unload();
        return;
    }

    // toggle debug
    if (strcmp(command, "//debug") == 0)
    {
        EQ_ToggleBool(g_debugIsEnabled);
        EQAPP_PrintBool("Debug", g_debugIsEnabled);
        return;
    }

    // start of in game check
    if (EQ_IsInGame() == false)
    {
        return;
    }

    // test
    if (strcmp(command, "//test") == 0)
    {
        std::cout << "test" << std::endl;

    /*
        uint32_t playerSpawn = EQ_GetPlayerSpawn();
        if (playerSpawn == NULL)
        {
            return;
        }

        float playerY = EQ_GetSpawnY(playerSpawn);
        float playerX = EQ_GetSpawnX(playerSpawn);
        float playerZ = EQ_GetSpawnZ(playerSpawn);

        uint32_t waypointIndex = EQAPP_WaypointList_GetIndexNearestToLocation(playerY, playerX, playerZ);

        std::cout << "nearest waypoint index: " << waypointIndex << std::endl;

        EQApp::Waypoint* waypoint = EQAPP_WaypointList_GetByIndex(waypointIndex);
        if (waypoint != NULL)
        {
            EQ_TurnPlayerTowardsLocation(waypoint->y, waypoint->x);
        }
    */

        size_t spawnIndex = 0;

        uint32_t spawn = EQ_GetFirstSpawn();
        while (spawn)
        {
            uint32_t randomSpellId       = EQAPP_GetRandomNumberLowHigh(1, 100);
            uint32_t randomSpellCastTime = EQAPP_GetRandomNumberLowHigh(5000, 30000);

            EQAPP_SpawnCastSpell_Add(spawn, randomSpellId, randomSpellCastTime);

            spawnIndex++;

            if (spawnIndex > 64)
            {
                break;
            }

            spawn = EQ_GetNextSpawn(spawn);
        }

        return;
    }

    // hud
    if (strcmp(command, "//hud") == 0)
    {
        EQ_ToggleBool(g_hudIsEnabled);
        EQAPP_PrintBool("HUD", g_hudIsEnabled);
        return;
    }

    // print execute command debug information
    if (strcmp(command, "//executecommanddebug") == 0 || strcmp(command, "//ecd") == 0)
    {
        EQAPP_ExecuteCommandDebugInformation_Print();
        return;
    }

    // execute command
    if (strncmp(command, "//executecommand ", 17) == 0)
    {
        char commandEx[128];

        uint32_t commandIndex = 0;

        int result = sscanf_s(command, "%s %d", commandEx, sizeof(commandEx), &commandIndex);
        if (result == 2)
        {
            if (commandIndex < 0 || commandIndex > EQ_EXECUTECMD_MAX)
            {
                std::cout << "No command at specified index: " << commandIndex << std::endl;
                return;
            }

            std::string commandName = EQ_GetExecuteCommandName(commandIndex);

            if (commandName.size() > 0)
            {
                EQ_ExecuteCommand(commandIndex, 0, 0);

                std::cout << "ExecuteCommand: " << commandName << " (" << commandIndex << ")" << std::endl;
            }
        }

        return;
    }

    // print loot debug information
    if (strcmp(command, "//lootdebug") == 0 || strcmp(command, "//ld") == 0)
    {
        EQAPP_LootDebugInformation_Print();
        return;
    }

    // loot item by name
    if (strncmp(command, "//loot ", 7) == 0)
    {
        char commandEx[128];

        char itemName[1024];

        int result = sscanf_s(command, "%s %s", commandEx, sizeof(commandEx), itemName, sizeof(itemName));
        if (result == 2)
        {
            EQ_String_ReplaceUnderscoresWithSpaces(itemName);

            bool lootResult = EQ_LootItemByName(itemName);

            std::cout << "Loot Item: " << itemName << " | Result: " << std::boolalpha << lootResult << std::noboolalpha << std::endl;
        }

        return;
    }

    // toggle auto loot
    if (strcmp(command, "//autoloot") == 0 || strcmp(command, "//al") == 0)
    {
        EQAPP_AutoLoot_Toggle();
        return;
    }

    // print auto loot list
    if (strcmp(command, "//autolootlist") == 0 || strcmp(command, "//all") == 0)
    {
        EQAPP_AutoLoot_Print();
        return;
    }

    // reset auto loot
    if (strcmp(command, "//autolootreset") == 0)
    {
        EQAPP_AutoLoot_Reset();
        return;
    }

    // add to auto loot list
    if (strncmp(command, "//autolootadd ", 14) == 0 || strncmp(command, "//ala ", 6) == 0)
    {
        char commandEx[128];

        char itemName[1024];

        int result = sscanf_s(command, "%s %s", commandEx, sizeof(commandEx), itemName, sizeof(itemName));
        if (result == 2)
        {
            EQ_String_ReplaceUnderscoresWithSpaces(itemName);

            EQAPP_AutoLoot_Add(itemName);

            g_autoLootIsEnabled = true;
        }

        return;
    }

    // remove from auto loot list
    if (strncmp(command, "//autolootremove ", 17) == 0 || strncmp(command, "//alr ", 6) == 0)
    {
        char commandEx[128];

        char itemName[1024];

        int result = sscanf_s(command, "%s %s", commandEx, sizeof(commandEx), itemName, sizeof(itemName));
        if (result == 2)
        {
            EQ_String_ReplaceUnderscoresWithSpaces(itemName);

            EQAPP_AutoLoot_Remove(itemName);
        }

        return;
    }

    // print cast ray to target
    if (strcmp(command, "//castray") == 0 || strcmp(command, "//cr") == 0)
    {
        EQAPP_CastRayToTarget_Print();
        return;
    }

    // print melee range to target
    if (strcmp(command, "//meleerange") == 0 || strcmp(command, "//mr") == 0)
    {
        EQAPP_MeleeRangeToTarget_Print();
        return;
    }

    // get spell name
    if (strncmp(command, "//getspellname ", 15) == 0)
    {
        char commandEx[128];

        uint32_t spellId = 0;

        int result = sscanf_s(command, "%s %d", commandEx, sizeof(commandEx), &spellId);
        if (result == 2)
        {
            std::string spellName = EQ_GetSpellNameById(spellId);

            std::cout << "Spell Name by ID: " << spellId << " == " << spellName << std::endl;
        }

        return;
    }

    // print target info
    if (strcmp(command, "//targetinfo") == 0 || strcmp(command, "//ti") == 0)
    {
        DWORD targetSpawn = EQ_GetTargetSpawn();
        EQAPP_SpawnInformation_Print(targetSpawn);
        return;
    }

    // print bank currency
    if (strcmp(command, "//bank") == 0 || strcmp(command, "//currency") == 0)
    {
        EQAPP_BankCurrency_Print();
        return;
    }

    // print bank list
    if (strcmp(command, "//banklist") == 0 || strcmp(command, "//bl") == 0)
    {
        EQAPP_BankList_Print(NULL);
        return;
    }

    // search bank list
    if (strncmp(command, "//banklist ", 11) == 0 || strncmp(command, "//bl ", 5) == 0)
    {
        char commandEx[128];

        char name[1024];

        int result = sscanf_s(command, "%s %s", commandEx, sizeof(commandEx), name, sizeof(name));
        if (result == 2)
        {
            EQ_String_ReplaceUnderscoresWithSpaces(name);

            EQAPP_BankList_Print(name);
        }

        return;
    }

    // print inventory list
    if (strcmp(command, "//inventorylist") == 0 || strcmp(command, "//il") == 0)
    {
        EQAPP_InventoryList_Print(NULL);
        return;
    }

    // search inventory list
    if (strncmp(command, "//inventorylist ", 16) == 0 || strncmp(command, "//il ", 5) == 0)
    {
        char commandEx[128];

        char name[1024];

        int result = sscanf_s(command, "%s %s", commandEx, sizeof(commandEx), name, sizeof(name));
        if (result == 2)
        {
            EQ_String_ReplaceUnderscoresWithSpaces(name);

            EQAPP_InventoryList_Print(name);
        }

        return;
    }

    // print spawn list
    if (strcmp(command, "//spawnlist") == 0 || strcmp(command, "//sl") == 0)
    {
        EQAPP_SpawnList_Print(NULL);
        return;
    }

    // search spawn list
    if (strncmp(command, "//spawnlist ", 12) == 0 || strncmp(command, "//sl ", 5) == 0)
    {
        char commandEx[128];

        char name[1024];

        int result = sscanf_s(command, "%s %s", commandEx, sizeof(commandEx), name, sizeof(name));
        if (result == 2)
        {
            EQ_String_ReplaceUnderscoresWithSpaces(name);

            EQAPP_SpawnList_Print(name);
        }

        return;
    }

    // toggle esp
    if (strcmp(command, "//esp") == 0)
    {
        EQ_ToggleBool(g_espIsEnabled);
        EQAPP_PrintBool("ESP", g_espIsEnabled);
        return;
    }

    // toggle esp spawn
    if (strcmp(command, "//espspawn") == 0 || strcmp(command, "//esps") == 0)
    {
        EQ_ToggleBool(g_espSpawnIsEnabled);
        EQAPP_PrintBool("ESP Spawn", g_espSpawnIsEnabled);
        return;
    }

    // toggle esp ground spawn
    if (strcmp(command, "//espgroundspawn") == 0 || strcmp(command, "//espgs") == 0)
    {
        EQ_ToggleBool(g_espGroundSpawnIsEnabled);
        EQAPP_PrintBool("ESP Ground Spawn", g_espGroundSpawnIsEnabled);
        return;
    }

    // toggle esp door
    if (strcmp(command, "//espdoor") == 0 || strcmp(command, "//espd") == 0)
    {
        EQ_ToggleBool(g_espDoorIsEnabled);
        EQAPP_PrintBool("ESP Door", g_espDoorIsEnabled);
        return;
    }

    // toggle esp skeleton
    if (strcmp(command, "//espskeleton") == 0 || strcmp(command, "//espsk") == 0)
    {
        EQ_ToggleBool(g_espSkeletonIsEnabled);
        EQAPP_PrintBool("ESP Skeleton", g_espSkeletonIsEnabled);
        return;
    }

    // toggle esp zone actor
    if (strcmp(command, "//espzoneactor") == 0 || strcmp(command, "//espza") == 0)
    {
        EQ_ToggleBool(g_espZoneActorIsEnabled);
        EQAPP_PrintBool("ESP Zone Actor", g_espZoneActorIsEnabled);
        return;
    }

    // debug zone actors
    if (strcmp(command, "//zoneactorsdebug") == 0 || strcmp(command, "//zad") == 0)
    {
        EQAPP_ZoneActors_Debug();
        return;
    }

    // toggle esp custom
    if (strcmp(command, "//espcustom") == 0 || strcmp(command, "//espc") == 0)
    {
        EQ_ToggleBool(g_espCustomIsEnabled);
        EQAPP_PrintBool("ESP Custom", g_espCustomIsEnabled);
        return;
    }

    // toggle esp waypoint
    if (strcmp(command, "//espwaypoint") == 0 || strcmp(command, "//espwp") == 0)
    {
        EQ_ToggleBool(g_espWaypointIsEnabled);
        EQAPP_PrintBool("ESP Waypoint", g_espWaypointIsEnabled);
        return;
    }

    // load esp custom
    if (strcmp(command, "//loadespcustom") == 0 || strcmp(command, "//loadespc") == 0)
    {
        EQAPP_ESP_Custom_Load();
        return;
    }

    // set esp spawn distance
    if (strncmp(command, "//setespspawndistance ", 22) == 0 || strncmp(command, "//setesps ", 10) == 0)
    {
        char commandEx[128];

        float distance = 0.0f;

        int result = sscanf_s(command, "%s %f", commandEx, sizeof(commandEx), &distance);
        if (result == 2)
        {
            g_espSpawnDistance = distance;

            std::cout << "ESP Spawn Distance: " << distance << std::endl;
        }

        return;
    }

    // set esp ground spawn distance
    if (strncmp(command, "//setespgroundspawndistance ", 28) == 0 || strncmp(command, "//setespgs ", 11) == 0)
    {
        char commandEx[128];

        float distance = 0.0f;

        int result = sscanf_s(command, "%s %f", commandEx, sizeof(commandEx), &distance);
        if (result == 2)
        {
            g_espGroundSpawnDistance = distance;

            std::cout << "ESP Ground Spawn Distance: " << distance << std::endl;
        }

        return;
    }

    // set esp door distance
    if (strncmp(command, "//setespdoordistance ", 21) == 0 || strncmp(command, "//setespd ", 10) == 0)
    {
        char commandEx[128];

        float distance = 0.0f;

        int result = sscanf_s(command, "%s %f", commandEx, sizeof(commandEx), &distance);
        if (result == 2)
        {
            g_espDoorDistance = distance;

            std::cout << "ESP Door Distance: " << distance << std::endl;
        }

        return;
    }

    // set esp skeleton distance
    if (strncmp(command, "//setespskeletondistance ", 25) == 0 || strncmp(command, "//setespsk ", 11) == 0)
    {
        char commandEx[128];

        float distance = 0.0f;

        int result = sscanf_s(command, "%s %f", commandEx, sizeof(commandEx), &distance);
        if (result == 2)
        {
            g_espSkeletonDistance = distance;

            std::cout << "ESP Skeleton Distance: " << distance << std::endl;
        }

        return;
    }

    // set esp zone actor distance
    if (strncmp(command, "//setespzoneactordistance ", 26) == 0 || strncmp(command, "//setespza ", 11) == 0)
    {
        char commandEx[128];

        float distance = 0.0f;

        int result = sscanf_s(command, "%s %f", commandEx, sizeof(commandEx), &distance);
        if (result == 2)
        {
            g_espZoneActorDistance = distance;

            std::cout << "ESP Zone Actor Distance: " << distance << std::endl;
        }

        return;
    }

    // set esp custom distance
    if (strncmp(command, "//setespcustomdistance ", 23) == 0 || strncmp(command, "//setespc ", 10) == 0)
    {
        char commandEx[128];

        float distance = 0.0f;

        int result = sscanf_s(command, "%s %f", commandEx, sizeof(commandEx), &distance);
        if (result == 2)
        {
            g_espCustomDistance = distance;

            std::cout << "ESP Custom Distance: " << distance << std::endl;
        }

        return;
    }

    // set esp waypoint distance
    if (strncmp(command, "//setespwaypointdistance ", 25) == 0 || strncmp(command, "//setespwp ", 11) == 0)
    {
        char commandEx[128];

        float distance = 0.0f;

        int result = sscanf_s(command, "%s %f", commandEx, sizeof(commandEx), &distance);
        if (result == 2)
        {
            g_espWaypointDistance = distance;

            std::cout << "ESP Waypoint Distance: " << distance << std::endl;
        }

        return;
    }

    // copy custom esp location to the clipboard
    if (strcmp(command, "//getespcustomlocation") == 0 || strcmp(command, "//getecl") == 0)
    {
        // try target first, then player
        DWORD spawnInfo = EQ_GetTargetSpawn();
        if (spawnInfo == NULL)
        {
            spawnInfo = EQ_GetPlayerSpawn();
            if (spawnInfo == NULL)
            {
                std::cout << "Player or Target not found!" << std::endl;
                return;
            }
        }

        EQ_CopySpawnEspCustomLocationToClipboard(spawnInfo);
        std::cout << "Copying custom ESP location to the clipboard..." << std::endl;
        return;
    }

    // toggle movement speed
    if (strcmp(command, "//speed") == 0)
    {
        EQ_ToggleBool(g_movementSpeedHackIsEnabled);
        EQAPP_PrintBool("Movement Speed Hack", g_movementSpeedHackIsEnabled);
        return;
    }

    // set movement speed sow
    if (strcmp(command, "//setspeed sow") == 0)
    {
        g_movementSpeedHackModifier = EQ_MOVEMENT_SPEED_MODIFIER_SPIRIT_OF_WOLF;
        std::cout << "Movement Speed Modifier: Spirit of Wolf" << std::endl;
        return;
    }

    // set movement speed run1
    if (strcmp(command, "//setspeed run1") == 0)
    {
        g_movementSpeedHackModifier = EQ_MOVEMENT_SPEED_MODIFIER_AA_RUN1;
        std::cout << "Movement Speed Modifier: AA Run 1" << std::endl;
        return;
    }

    // set speed run2
    if (strcmp(command, "//setspeed run2") == 0)
    {
        g_movementSpeedHackModifier = EQ_MOVEMENT_SPEED_MODIFIER_AA_RUN2;
        std::cout << "Movement Speed Modifier: AA Run 2" << std::endl;
        return;
    }

    // set speed run3
    if (strcmp(command, "//setspeed run3") == 0)
    {
        g_movementSpeedHackModifier = EQ_MOVEMENT_SPEED_MODIFIER_AA_RUN3;
        std::cout << "Movement Speed Modifier: AA Run 3" << std::endl;
        return;
    }

    // set speed
    if (strncmp(command, "//setspeed ", 11) == 0 || strncmp(command, "//ss ", 5) == 0)
    {
        char commandEx[128];

        float modifier = 0.0f;

        int result = sscanf_s(command, "%s %f", commandEx, sizeof(commandEx), &modifier);
        if (result == 2)
        {
            g_movementSpeedHackModifier = modifier;

            std::cout << "Movement Speed Modifier: " << g_movementSpeedHackModifier << std::endl;
        }

        return;
    }

    // toggle swim speed
    if (strcmp(command, "//swimspeed") == 0)
    {
        EQAPP_SwimSpeed_Toggle();
        return;
    }

    // set swim speed
    if (strncmp(command, "//setswimspeed ", 15) == 0 || strncmp(command, "//sss ", 6) == 0)
    {
        char commandEx[128];

        float modifier = 0.0f;

        int result = sscanf_s(command, "%s %f", commandEx, sizeof(commandEx), &modifier);
        if (result == 2)
        {
            g_swimSpeedHackModifier = modifier;

            std::cout << "Swim Speed Modifier: " << g_swimSpeedHackModifier << std::endl;
        }

        return;
    }

    // set race
    if (strncmp(command, "//setrace ", 10) == 0 || strncmp(command, "//sr ", 5) == 0)
    {
        char commandEx[128];

        uint32_t raceId = 0;

        int result = sscanf_s(command, "%s %d", commandEx, sizeof(commandEx), &raceId);
        if (result == 2)
        {
            DWORD playerSpawn = EQ_GetPlayerSpawn();
            if (playerSpawn == NULL)
            {
                std::cout << "player is NULL" << std::endl;
                return;
            }

            int spawnGender = EQ_ReadMemory<uint8_t>(playerSpawn + EQ_OFFSET_SPAWN_INFO_GENDER);

            EQ_SetSpawnForm(playerSpawn, raceId, spawnGender);
        }

        return;
    }

    // toggle locator
    if (strcmp(command, "//locator") == 0 || strcmp(command, "//loc") == 0)
    {
        EQ_ToggleBool(g_espLocatorIsEnabled);
        EQAPP_PrintBool("Locator", g_espLocatorIsEnabled);
        return;
    }

    // toggle locator line
    if (strcmp(command, "//locatorline") == 0 || strcmp(command, "//locline") == 0)
    {
        EQ_ToggleBool(g_espLocatorDrawLineIsEnabled);
        EQAPP_PrintBool("Locator Line", g_espLocatorDrawLineIsEnabled);
        return;
    }

    // get locator
    if (strcmp(command, "//getlocator") == 0 || strcmp(command, "//getloc") == 0)
    {
        EQAPP_ESP_Locator_Print();
        return;
    }

    // set locator
    if (strncmp(command, "//setlocator ", 13) == 0 || strncmp(command, "//setloc ", 9) == 0)
    {
        char commandEx[128];

        float y = 0.0f;
        float x = 0.0f;
        float z = 0.0f;

        int result = sscanf_s(command, "%s %f %f %f", commandEx, sizeof(commandEx), &y, &x, &z);
        if (result == 4)
        {
            g_espLocatorY = y;
            g_espLocatorX = x;
            g_espLocatorZ = z;

            EQAPP_ESP_Locator_Print();

            g_espLocatorIsEnabled = true;
        }

        return;
    }

    // toggle find
    if (strcmp(command, "//find") == 0)
    {
        EQ_ToggleBool(g_espFindIsEnabled);
        EQAPP_PrintBool("Find", g_espFindIsEnabled);
        return;
    }

    // toggle find line
    if (strcmp(command, "//findline") == 0)
    {
        EQ_ToggleBool(g_espFindDrawLineIsEnabled);
        EQAPP_PrintBool("Find Line", g_espFindDrawLineIsEnabled);
        return;
    }

    // get find
    if (strcmp(command, "//getfind") == 0)
    {
        EQAPP_ESP_Find_Print();
        return;
    }

    // set find
    if (strncmp(command, "//setfind ", 10) == 0)
    {
        char commandEx[128];

        char name[1024];

        int result = sscanf_s(command, "%s %s", commandEx, sizeof(commandEx), name, sizeof(name));
        if (result == 2)
        {
            EQ_String_ReplaceUnderscoresWithSpaces(name);

            g_espFindSpawnName = name;

            EQAPP_ESP_Find_Print();

            g_espFindIsEnabled = true;
        }

        return;
    }

    // toggle line to target
    if (strcmp(command, "//linetotarget") == 0 || strcmp(command, "//ltt") == 0)
    {
        EQ_ToggleBool(g_lineToTargetIsEnabled);
        EQAPP_PrintBool("Line to Target", g_lineToTargetIsEnabled);
        return;
    }

    // print memory list
    if (strcmp(command, "//memorylist") == 0 || strcmp(command, "//ml") == 0)
    {
        EQAPP_Memory_Print();
        return;
    }

    // toggle memory by index
    if (strncmp(command, "//memory ", 9) == 0 || strncmp(command, "//mem ", 6) == 0)
    {
        char commandEx[128];

        uint32_t index = 0;

        int result = sscanf_s(command, "%s %d", commandEx, sizeof(commandEx), &index);
        if (result == 2)
        {
            EQAPP_Memory_ToggleByIndex(index);
        }

        return;
    }

    // toggle always attack
    if (strcmp(command, "//alwaysattack") == 0 || strcmp(command, "//aa") == 0)
    {
        EQ_ToggleBool(g_alwaysAttackIsEnabled);
        EQAPP_PrintBool("Always Attack", g_alwaysAttackIsEnabled);
        return;
    }

    // toggle combat hotbutton
    if (strcmp(command, "//combathotbutton") == 0 || strcmp(command, "//chb") == 0)
    {
        EQ_ToggleBool(g_combatHotbuttonIsEnabled);
        EQAPP_PrintBool("Combat Hotbutton", g_combatHotbuttonIsEnabled);
        return;
    }

    // get combat hotbutton
    if (strcmp(command, "//getcombathotbutton") == 0 || strcmp(command, "//getchb") == 0)
    {
        EQAPP_CombatHotbutton_Print();
        return;
    }

    // set combat hotbutton
    if (strncmp(command, "//setcombathotbutton ", 21) == 0 || strncmp(command, "//setchb ", 9) == 0)
    {
        char commandEx[128];

        uint32_t buttonNumber        = 0;
        uint32_t timerDelayinSeconds = 1;

        int result = sscanf_s(command, "%s %d %d", commandEx, sizeof(commandEx), &buttonNumber, &timerDelayinSeconds);
        if (result == 3)
        {
            EQAPP_CombatHotbutton_Set(buttonNumber, timerDelayinSeconds);
            EQAPP_CombatHotbutton_Print();

            g_combatHotbuttonIsEnabled = true;
        }

        return;
    }

    // toggle always hotbutton
    if (strcmp(command, "//alwayshotbutton") == 0 || strcmp(command, "//ahb") == 0)
    {
        EQ_ToggleBool(g_alwaysHotbuttonIsEnabled);
        EQAPP_PrintBool("Always Hotbutton", g_alwaysHotbuttonIsEnabled);
        return;
    }

    // get always hotbutton
    if (strcmp(command, "//getalwayshotbutton") == 0 || strcmp(command, "//getahb") == 0)
    {
        EQAPP_AlwaysHotbutton_Print();
        return;
    }

    // set always hotbutton
    if (strncmp(command, "//setalwayshotbutton ", 21) == 0 || strncmp(command, "//setahb ", 9) == 0)
    {
        char commandEx[128];

        uint32_t buttonNumber        = 0;
        uint32_t timerDelayinSeconds = 1;

        int result = sscanf_s(command, "%s %d %d", commandEx, sizeof(commandEx), &buttonNumber, &timerDelayinSeconds);
        if (result == 3)
        {
            EQAPP_AlwaysHotbutton_Set(buttonNumber, timerDelayinSeconds);
            EQAPP_AlwaysHotbutton_Print();

            g_alwaysHotbuttonIsEnabled = true;
        }

        return;
    }

    // toggle always hotbutton sit stand at mana
    if (strcmp(command, "//ahbsitstandatmana") == 0)
    {
        EQAPP_AlwaysHotbutton_SitStandAtMana_Toggle();
        EQAPP_PrintBool("Always Hotbutton Sit Stand At Mana", g_alwaysHotbuttonSitStandAtManaIsEnabled);
        return;
    }

    // get always hotbutton sit stand at mana
    if (strcmp(command, "//getahbsitstandatmana") == 0 || strcmp(command, "//getahbsitatmana") == 0 || strcmp(command, "//getahbstandatmana") == 0)
    {
        EQAPP_AlwaysHotbutton_SitStandAtMana_Print();
        return;
    }

    // set always hotbutton sit at mana
    if (strncmp(command, "//setahbsitatmana ", 18) == 0)
    {
        char commandEx[128];

        uint32_t manaValue = 0;

        int result = sscanf_s(command, "%s %d", commandEx, sizeof(commandEx), &manaValue);
        if (result == 2)
        {
            g_alwaysHotbuttonSitAtManaValue = manaValue;
            EQAPP_AlwaysHotbutton_SitStandAtMana_Print();

            EQAPP_AlwaysHotbutton_SitStandAtMana_Set(true);
        }

        return;
    }

    // set always hotbutton stand at mana
    if (strncmp(command, "//setahbstandatmana ", 20) == 0)
    {
        char commandEx[128];

        uint32_t manaValue = 0;

        int result = sscanf_s(command, "%s %d", commandEx, sizeof(commandEx), &manaValue);
        if (result == 2)
        {
            g_alwaysHotbuttonStandAtManaValue = manaValue;
            EQAPP_AlwaysHotbutton_SitStandAtMana_Print();

            EQAPP_AlwaysHotbutton_SitStandAtMana_Set(true);
        }

        return;
    }

    // set collision radius
    if (strncmp(command, "//setcollisionradius ", 21) == 0 || strncmp(command, "//setcr ", 8) == 0)
    {
        char commandEx[128];

        float radius = 1.0f;

        int result = sscanf_s(command, "%s %f", commandEx, sizeof(commandEx), &radius);
        if (result == 2)
        {
            // try target first, then player
            DWORD spawnInfo = EQ_GetTargetSpawn();
            if (spawnInfo == NULL)
            {
                spawnInfo = EQ_GetPlayerSpawn();
                if (spawnInfo == NULL)
                {
                    std::cout << "Player or Target not found!" << std::endl;
                    return;
                }
            }

            if (radius < 0.1f)
            {
                std::cout << "Specified collision radius too low: " << radius << std::endl;
                return;
            }

            EQ_SetSpawnCollisionRadius(spawnInfo, radius);

            std::cout << "Set Player or Target Collision Radius: " << radius << std::endl;
        }

        return;
    }

    // toggle draw distance
    if (strcmp(command, "//drawdistance") == 0 || strcmp(command, "//dd") == 0)
    {
        EQ_ToggleBool(g_drawDistanceIsEnabled);
        EQAPP_PrintBool("Draw Distance", g_drawDistanceIsEnabled);
        return;
    }

    // get draw distance
    if (strcmp(command, "//getdrawdistance") == 0 || strcmp(command, "//getdd") == 0)
    {
        EQAPP_DrawDistance_Print();
        return;
    }

    // set draw distance
    if (strncmp(command, "//setdrawdistance ", 18) == 0 || strncmp(command, "//setdd ", 8) == 0)
    {
        char commandEx[128];

        float distance = EQ_DRAW_DISTANCE_DEFAULT;

        int result = sscanf_s(command, "%s %f", commandEx, sizeof(commandEx), &distance);
        if (result == 2)
        {
            if (distance < EQ_DRAW_DISTANCE_MINIMUM)
            {
                std::cout << "Specified draw distance too low: " << distance << std::endl;
                return;
            }

            g_drawDistance = distance;

            EQAPP_DrawDistance_Print();

            g_drawDistanceIsEnabled = true;
        }

        return;
    }

    // set field of view
    if (strncmp(command, "//setfieldofview ", 17) == 0 || strncmp(command, "//setfov ", 9) == 0)
    {
        char commandEx[128];

        float fov = EQ_FIELD_OF_VIEW_DEFAULT;

        int result = sscanf_s(command, "%s %f", commandEx, sizeof(commandEx), &fov);
        if (result == 2)
        {
            if (fov <= 0.0f)
            {
                std::cout << "Specified field of view too low: " << fov << std::endl;
                return;
            }

            EQ_SetFieldOfView(fov);

            std::cout << "Field of View: " << fov << std::endl;
        }

        return;
    }

    // toggle target beep
    if (strcmp(command, "//targetbeep") == 0 || strcmp(command, "//tbeep") == 0)
    {
        EQ_ToggleBool(g_targetBeepIsEnabled);
        EQAPP_PrintBool("Target Beep", g_targetBeepIsEnabled);
        return;
    }

    // print target beep
    if (strcmp(command, "//gettargetbeep") == 0 || strcmp(command, "//gettbeep") == 0)
    {
        EQAPP_TargetBeep_Print();
        return;
    }

    // set target beep
    if (strncmp(command, "//settargetbeep ", 16) == 0 || strncmp(command, "//settbeep ", 11) == 0 || strncmp(command, "//stb ", 6) == 0)
    {
        char commandEx[128];

        char name[1024];

        uint32_t timerDelayInSeconds = 1;

        int result = sscanf_s(command, "%s %s %d", commandEx, sizeof(commandEx), name, sizeof(name), &timerDelayInSeconds);
        if (result == 3)
        {
            EQ_String_ReplaceUnderscoresWithSpaces(name);

            EQAPP_TargetBeep_Set(name, timerDelayInSeconds);
            EQAPP_TargetBeep_Print();

            g_targetBeepIsEnabled = true;
        }

        return;
    }

    // toggle spawn beep
    if (strcmp(command, "//spawnbeep") == 0 || strcmp(command, "//sbeep") == 0)
    {
        EQ_ToggleBool(g_spawnBeepIsEnabled);
        EQAPP_PrintBool("Spawn Beep", g_spawnBeepIsEnabled);
        return;
    }

    // get spawn beep
    if (strcmp(command, "//getspawnbeep") == 0 || strcmp(command, "//getsbeep") == 0)
    {
        EQAPP_SpawnBeep_Print();
        return;
    }

    // set spawn beep
    if (strncmp(command, "//setspawnbeep ", 15) == 0 || strncmp(command, "//setsbeep ", 11) == 0 || strncmp(command, "//ssb ", 6) == 0)
    {
        char commandEx[128];

        char name[1024];

        int result = sscanf_s(command, "%s %s", commandEx, sizeof(commandEx), name, sizeof(name));
        if (result == 2)
        {
            EQ_String_ReplaceUnderscoresWithSpaces(name);

            EQAPP_SpawnBeep_Set(name);
            EQAPP_SpawnBeep_Print();

            g_spawnBeepIsEnabled = true;
        }

        return;
    }

    // toggle player alert
    if (strcmp(command, "//playeralert") == 0 || strcmp(command, "//pa") == 0)
    {
        EQ_ToggleBool(g_playerAlertIsEnabled);
        EQAPP_PrintBool("Player Alert", g_playerAlertIsEnabled);
        return;
    }

    // get player alert
    if (strcmp(command, "//getplayeralert") == 0 || strcmp(command, "//getpa") == 0)
    {
        EQAPP_PlayerAlert_Print();
        return;
    }

    // set player alert
    if (strncmp(command, "//setplayeralert ", 17) == 0 || strncmp(command, "//setpa ", 8) == 0)
    {
        char commandEx[128];

        uint32_t minimumNumPlayersInZone = 0;
        uint32_t timerDelayInSeconds = 1;

        int result = sscanf_s(command, "%s %d %d", commandEx, sizeof(commandEx), &minimumNumPlayersInZone, &timerDelayInSeconds);
        if (result == 3)
        {
            EQAPP_PlayerAlert_Set(minimumNumPlayersInZone, timerDelayInSeconds);
            EQAPP_PlayerAlert_Print();

            g_playerAlertIsEnabled = true;
        }

        return;
    }

    // toggle change height
    if (strcmp(command, "//changeheight") == 0)
    {
        EQ_ToggleBool(g_changeHeightIsEnabled);
        EQAPP_PrintBool("Change Height", g_changeHeightIsEnabled);
        return;
    }

    // set height
    if (strncmp(command, "//setheight ", 12) == 0 || strncmp(command, "//sh ", 5) == 0)
    {
        DWORD targetSpawn = EQ_GetTargetSpawn();
        if (targetSpawn == NULL)
        {
            std::cout << "Target not found!" << std::endl;
            return;
        }

        char commandEx[128];

        float height = g_changeHeightDefaultSize;

        int result = sscanf_s(command, "%s %f", commandEx, sizeof(commandEx), &height);
        if (result == 2)
        {
            EQ_SetSpawnHeight(targetSpawn, height);

            std::cout << "Set Target Height: " << height << std::endl;
        }

        return;
    }

    // toggle map labels
    if (strcmp(command, "//maplabels") == 0)
    {
        EQAPP_MapLabels_Toggle();
        return;
    }

    // add map labels
    if (strcmp(command, "//addmaplabels") == 0 || strcmp(command, "//addml") == 0)
    {
        EQAPP_MapLabels_Add();
        std::cout << "Adding map labels..." << std::endl;
        return;
    }

    // remove map labels
    if (strcmp(command, "//removemaplabels") == 0 || strcmp(command, "//removeml") == 0)
    {
        EQAPP_MapLabels_Remove();
        std::cout << "Removing map labels..." << std::endl;
        return;
    }

    // print map labels
    if (strcmp(command, "//getmaplabels") == 0 || strcmp(command, "//getml") == 0)
    {
        EQAPP_MapLabels_Print();
        return;
    }

    // toggle filter map labels
    if (strcmp(command, "//filtermaplabels") == 0 || strcmp(command, "//filterml") == 0)
    {
        EQ_ToggleBool(g_mapLabelsFilterIsEnabled);
        EQAPP_PrintBool("Map Labels Filter", g_mapLabelsFilterIsEnabled);
        return;
    }

    // get filter map labels
    if (strcmp(command, "//getfiltermaplabels") == 0 || strcmp(command, "//getfilterml") == 0)
    {
        EQAPP_MapLabels_Filter_Print();
        return;
    }

    // set filter map labels
    if (strncmp(command, "//setfiltermaplabels ", 21) == 0 || strncmp(command, "//setfilterml ", 14) == 0)
    {
        char commandEx[128];

        char name[1024];

        int result = sscanf_s(command, "%s %s", commandEx, sizeof(commandEx), name, sizeof(name));
        if (result == 2)
        {
            EQ_String_ReplaceUnderscoresWithSpaces(name);

            g_mapLabelsFilterName = name;

            EQAPP_MapLabels_Filter_Print();

            g_mapLabelsFilterIsEnabled = true;
        }

        return;
    }

    // get zone info
    if (strcmp(command, "//getzoneinfo") == 0 || strcmp(command, "//getzi") == 0)
    {
        EQAPP_ZoneInformation_Print();
        return;
    }

    // load memory
    if (strcmp(command, "//loadmemory") == 0 || strcmp(command, "//loadmem") == 0)
    {
        EQAPP_Memory_Unload();
        EQAPP_Memory_Load();
        return;
    }

    // toggle sounds
    if (strcmp(command, "//sounds") == 0)
    {
        EQ_ToggleBool(g_soundsIsEnabled);
        EQAPP_PrintBool("Sounds", g_soundsIsEnabled);
        return;
    }

    // load sounds
    if (strcmp(command, "//loadsounds") == 0)
    {
        EQAPP_Sounds_Load();
        return;
    }

    // get sounds
    if (strcmp(command, "//getsounds") == 0)
    {
        EQAPP_Sounds_Print();
        return;
    }

    // toggle named spawns
    if (strcmp(command, "//namedspawns") == 0 || strcmp(command, "//ns") == 0)
    {
        EQ_ToggleBool(g_namedSpawnsIsEnabled);
        EQAPP_PrintBool("Named Spawns" , g_namedSpawnsIsEnabled);
        return;
    }

    // load named spawns
    if (strcmp(command, "//loadnamedspawns") == 0 || strcmp(command, "//loadns") == 0)
    {
        EQAPP_NamedSpawns_Load();
        return;
    }

    // get named spawns list
    if (strcmp(command, "//getnamedspawns") == 0 || strcmp(command, "//getns") == 0)
    {
        EQAPP_NamedSpawns_Print();
        return;
    }

    // write character file
    if (strcmp(command, "//writecharacterfile") == 0 || strcmp(command, "//writechar") == 0 || strcmp(command, "//writecf") == 0)
    {
        EQAPP_CharacterFile_Write();
        return;
    }

    // load text overlay chat text
    if (strcmp(command, "//loadtextoverlaychattext") == 0 || strcmp(command, "//loadtoct") == 0)
    {
        EQAPP_TextOverlayChatText_Load();
        return;
    }

    // get text overlay chat text
    if (strcmp(command, "//gettextoverlaychattext") == 0 || strcmp(command, "//gettoct") == 0)
    {
        EQAPP_TextOverlayChatText_Print();
        return;
    }

    // get on screen text
    if (strcmp(command, "//getonscreentext") == 0 || strcmp(command, "//getost") == 0)
    {
        EQAPP_OnScreenText_Print();
        return;
    }

    // load no beep
    if (strcmp(command, "//loadnobeep") == 0 || strcmp(command, "//loadnb") == 0)
    {
        EQAPP_NoBeep_Load();
        return;
    }

    // get no beep
    if (strcmp(command, "//getnobeep") == 0 || strcmp(command, "//getnb") == 0)
    {
        EQAPP_NoBeep_Print();
        return;
    }

    // load zone short names
    if (strcmp(command, "//loadzoneshortnames") == 0 || strcmp(command, "//loadzsn") == 0)
    {
        EQAPP_ZoneShortNames_Load();
        return;
    }

    // load zone short names
    if (strcmp(command, "//getloadzoneshortnames") == 0 || strcmp(command, "//getzsn") == 0)
    {
        EQAPP_ZoneShortNames_Print();
        return;
    }

    // toggle hide corpse looted
    if (strcmp(command, "//hidecorpselooted") == 0 || strcmp(command, "//hcl") == 0)
    {
        EQ_ToggleBool(g_hideCorpseLootedIsEnabled);
        EQAPP_PrintBool("Hide Corpse Looted", g_hideCorpseLootedIsEnabled);
        return;
    }

    // open all doors
    if (strcmp(command, "//openalldoors") == 0 || strcmp(command, "//opendoors") == 0)
    {
        EQAPP_Doors_OpenAll(true);

        return;
    }

    // close all doors
    if (strcmp(command, "//closealldoors") == 0 || strcmp(command, "//closedoors") == 0)
    {
        EQAPP_Doors_OpenAll(false);

        return;
    }

    // census
    if (strcmp(command, "//census") == 0)
    {
        EQAPP_Census_Toggle();
        return;
    }

    // toggle free camera
    if (strcmp(command, "//freecamera") == 0 || strcmp(command, "//freecam") == 0 || strcmp(command, "//fc") == 0)
    {
        EQAPP_FreeCamera_Toggle();
        return;
    }

    // set view actor by name
    if (strncmp(command, "//setviewactor ", 15) == 0 || strncmp(command, "//setva ", 8) == 0)
    {
        char commandEx[128];

        char name[1024];

        int result = sscanf_s(command, "%s %s", commandEx, sizeof(commandEx), name, sizeof(name));
        if (result == 2)
        {
            EQ_CDisplay->SetViewActorByName(name);
            std::cout << "Set View Actor: " << name << std::endl;
        }

        return;
    }

    // set view actor to target
    if (strcmp(command, "//setviewactortarget") == 0 || strcmp(command, "//setvat") == 0)
    {
        DWORD targetSpawn = EQ_GetTargetSpawn();
        if (targetSpawn == NULL)
        {
            std::cout << "Target not found!" << std::endl;
            return;
        }

        EQ_SetViewActorBySpawn(targetSpawn);
        std::cout << "Set View Actor to Target." << std::endl;
        return;
    }

    // reset view actor
    if (strcmp(command, "//resetviewactor") == 0 || strcmp(command, "//resetva") == 0)
    {
        EQ_ResetViewActor();
        std::cout << "Reset View Actor." << std::endl;
        return;
    }

    // map locations
    if (strcmp(command, "//maplocations") == 0 || strcmp(command, "//maplocs") == 0)
    {
        EQAPP_MapLocations_WriteToFile();
        return;
    }

    // get map location
    if (strcmp(command, "//getmaplocation") == 0 || strcmp(command, "//getmaploc") == 0)
    {
        // try target first, then player
        DWORD spawnInfo = EQ_GetTargetSpawn();
        if (spawnInfo == NULL)
        {
            spawnInfo = EQ_GetPlayerSpawn();
            if (spawnInfo == NULL)
            {
                std::cout << "Player or Target not found!" << std::endl;
                return;
            }
        }

        EQ_CopySpawnMapLocationToClipboard(spawnInfo);
        std::cout << "Copying player or target map location to the clipboard..." << std::endl;
        return;
    }

    // open zone map file
    if (strcmp(command, "//openzonemapfile") == 0 || strcmp(command, "//openzmf") == 0)
    {
        EQAPP_OpenZoneMapFile();
        return;
    }

    // toggle backstab
    if (strcmp(command, "//backstab") == 0)
    {
        EQ_ToggleBool(g_backstabIsEnabled);
        EQAPP_PrintBool("Backstab", g_backstabIsEnabled);
        return;
    }

    // set backstab
    if (strncmp(command, "//setbackstab ", 14) == 0 || strncmp(command, "//setbs ", 8) == 0)
    {
        char commandEx[128];

        uint32_t buttonNumber = 0;

        int result = sscanf_s(command, "%s %d", commandEx, sizeof(commandEx), &buttonNumber);
        if (result == 2)
        {
            EQAPP_Backstab_Set(buttonNumber);
            EQAPP_Backstab_Print();

            g_backstabIsEnabled = true;
        }

        return;
    }

    // get backstab
    if (strcmp(command, "//getbackstab") == 0 || strcmp(command, "//getbs") == 0)
    {
        EQAPP_Backstab_Print();
        return;
    }

    // waypoint add
    if (strcmp(command, "//waypointadd") == 0 || strcmp(command, "//wpa") == 0)
    {
        EQAPP_WaypointList_Add();
        return;
    }

    // waypoint remove
    if (strncmp(command, "//waypointremove ", 17) == 0 || strncmp(command, "//wpr ", 6) == 0)
    {
        char commandEx[128];

        uint32_t index;

        int result = sscanf_s(command, "%s %d", commandEx, sizeof(commandEx), &index);
        if (result == 2)
        {
            EQAPP_WaypointList_Remove(index);
        }

        return;
    }

    // waypoint connect
    if (strncmp(command, "//waypointconnect ", 18) == 0 || strncmp(command, "//wpc ", 6) == 0)
    {
        char commandEx[128];

        uint32_t fromIndex;
        uint32_t toIndex;

        int result = sscanf_s(command, "%s %d %d", commandEx, sizeof(commandEx), &fromIndex, &toIndex);
        if (result == 3)
        {
            EQAPP_WaypointList_Connect(fromIndex, toIndex);
        }

        return;
    }

    // waypoint disconnect
    if (strncmp(command, "//waypointdisconnect ", 21) == 0 || strncmp(command, "//wpd ", 6) == 0)
    {
        char commandEx[128];

        uint32_t fromIndex;
        uint32_t toIndex;

        int result = sscanf_s(command, "%s %d %d", commandEx, sizeof(commandEx), &fromIndex, &toIndex);
        if (result == 3)
        {
            EQAPP_WaypointList_Disconnect(fromIndex, toIndex);
        }

        return;
    }

    // waypoint list print
    if (strcmp(command, "//waypointlist") == 0 || strcmp(command, "//wpl") == 0)
    {
        EQAPP_WaypointList_Print();
        return;
    }

    // waypoint list clear
    if (strcmp(command, "//waypointlistclear") == 0 || strcmp(command, "//wplc") == 0)
    {
        EQAPP_WaypointList_Clear();
        return;
    }

    // waypoint list load
    if (strcmp(command, "//waypointlistload") == 0 || strcmp(command, "//wpll") == 0)
    {
        EQAPP_WaypointList_Load();
        return;
    }

    // waypoint list save
    if (strcmp(command, "//waypointlistsave") == 0 || strcmp(command, "//wpls") == 0)
    {
        EQAPP_WaypointList_Save();
        return;
    }

    // waypoint list get path
    if (strncmp(command, "//waypointgetpathlist ", 22) == 0 || strncmp(command, "//wpgpl ", 8) == 0)
    {
        char commandEx[128];

        uint32_t fromIndex;
        uint32_t toIndex;

        int result = sscanf_s(command, "%s %d %d", commandEx, sizeof(commandEx), &fromIndex, &toIndex);

        if (result == 3)
        {
            EQApp::WaypointPathList pathList = EQAPP_Waypoint_CreatePathList(fromIndex, toIndex);

            EQAPP_Waypoint_PrintPathList(fromIndex, pathList);
        }

        return;
    }

    // toggle zone actors no collision
    if (strcmp(command, "//zoneactorsnocollision") == 0 || strcmp(command, "//zanc") == 0)
    {
        EQ_ToggleBool(g_zoneActorsNoCollisionIsEnabled);
        EQAPP_PrintBool("Zone Actors No Collision", g_zoneActorsNoCollisionIsEnabled);
        return;
    }

    // load zone actors no collision
    if (strcmp(command, "//loadzoneactorsnocollision") == 0 || strcmp(command, "//loadzanc") == 0)
    {
        EQAPP_ZoneActors_NoCollision_Load();
        return;
    }

    // execute zone actors no collision
    if (strcmp(command, "//executezoneactorsnocollision") == 0 || strcmp(command, "//executezanc") == 0)
    {
        EQAPP_ZoneActors_NoCollision_Execute();
        return;
    }

    // restore zone actors no collision
    if (strcmp(command, "//restorezoneactorsnocollision") == 0 || strcmp(command, "//restorezanc") == 0)
    {
        EQAPP_ZoneActors_NoCollision_Restore();
        return;
    }

     // get zone actors no collision
    if (strcmp(command, "//getzoneactorsnocollision") == 0 || strcmp(command, "//getzanc") == 0)
    {
        EQAPP_ZoneActors_NoCollision_Print();
        return;
    }

    // toggle chat filter
    if (strcmp(command, "//chatfilter") == 0 || strcmp(command, "//cf") == 0)
    {
        EQ_ToggleBool(g_chatFilterIsEnabled);
        EQAPP_PrintBool("Chat Filter", g_chatFilterIsEnabled);
        return;
    }

    // print chat filter list
    if (strcmp(command, "//chatfilterlist") == 0 || strcmp(command, "//cfl") == 0)
    {
        EQAPP_ChatFilter_Print();
        return;
    }

    // reset chat filter
    if (strcmp(command, "//chatfilterreset") == 0)
    {
        EQAPP_ChatFilter_Reset();
        return;
    }

    // add to chat filter list
    if (strncmp(command, "//chatfilteradd ", 16) == 0 || strncmp(command, "//cfa ", 6) == 0)
    {
        char commandEx[128];

        char chatText[1024];

        int result = sscanf_s(command, "%s %s", commandEx, sizeof(commandEx), chatText, sizeof(chatText));
        if (result == 2)
        {
            EQ_String_ReplaceUnderscoresWithSpaces(chatText);

            EQAPP_ChatFilter_Add(chatText);

            g_chatFilterIsEnabled = true;
        }

        return;
    }

    // remove from chat filter list
    if (strncmp(command, "//chatfilterremove ", 19) == 0 || strncmp(command, "//cfr ", 6) == 0)
    {
        char commandEx[128];

        char chatText[1024];

        int result = sscanf_s(command, "%s %s", commandEx, sizeof(commandEx), chatText, sizeof(chatText));
        if (result == 2)
        {
            EQ_String_ReplaceUnderscoresWithSpaces(chatText);

            EQAPP_ChatFilter_Remove(chatText);
        }

        return;
    }
}

