#pragma once

#include "eqapp_imgui.h"

struct EQAPPIMGUIOptionsWindow
{
    EQAPPIMGUIOptionsWindow()
    {
        //
    }

    ~EQAPPIMGUIOptionsWindow()
    {
        //
    }

    void Draw(const char* title, bool* p_open)
    {
        ImGui::Begin(title, p_open);

        ImGui::PushID("ID Debug");
        ImGui::Checkbox("Debug", &g_debugIsEnabled);
        ImGui::SameLine(200);
        ImGui::Text("Show debugging information for this application");
        ImGui::PopID();

        ImGui::PushID("ID Test");
        if (ImGui::Button("Test"))
        {
            EQAPP_InterpretCommand("//test");
        }
        ImGui::SameLine(200);
        ImGui::Text("Perform the //test command");
        ImGui::PopID();

        if (ImGui::CollapsingHeader("HUD"))
        {
            ImGui::PushID("ID HUD");

            ImGui::Checkbox("Enabled", &g_hudIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Show important information in-game");
            ImGui::Separator();
            ImGui::InputInt("X", (int*)&g_hudX, 1, 10);
            ImGui::InputInt("Y", (int*)&g_hudY, 1, 10);
            ImGui::InputFloat("Width", &g_hudWidth, 1.0f, 10.0f, 0);
            ImGui::InputFloat("Height", &g_hudHeight, 1.0f, 10.0f, 0);

            ImGui::PopID();
        }

        if (ImGui::CollapsingHeader("Speed"))
        {
            ImGui::PushID("ID Movement Speed Hack");

            ImGui::Checkbox("Movement Speed", &g_movementSpeedHackIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Lets you run faster");
            ImGui::InputFloat("Modifier", &g_movementSpeedHackModifier, 0.0f, 0.0f, 4);

            if (ImGui::Button("Spirit of Wolf")) g_movementSpeedHackModifier = EQ_MOVEMENT_SPEED_MODIFIER_SPIRIT_OF_WOLF; ImGui::SameLine();
            if (ImGui::Button("AA Run Speed 1")) g_movementSpeedHackModifier = EQ_MOVEMENT_SPEED_MODIFIER_AA_RUN1; ImGui::SameLine();
            if (ImGui::Button("AA Run Speed 2")) g_movementSpeedHackModifier = EQ_MOVEMENT_SPEED_MODIFIER_AA_RUN2; ImGui::SameLine();
            if (ImGui::Button("AA Run Speed 3")) g_movementSpeedHackModifier = EQ_MOVEMENT_SPEED_MODIFIER_AA_RUN3;

            ImGui::PopID();

            ImGui::Separator();

            ImGui::PushID("ID Swim Speed Hack");

            ImGui::Checkbox("Swim Speed", &g_swimSpeedHackIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Lets you swim faster");
            ImGui::InputFloat("Modifier", &g_swimSpeedHackModifier, 0.0f, 0.0f, 0);

            if (ImGui::Button(" 0 ")) g_swimSpeedHackModifier = 0.0f; ImGui::SameLine();
            if (ImGui::Button(" 2 ")) g_swimSpeedHackModifier = 2.0f; ImGui::SameLine();
            if (ImGui::Button(" 4 ")) g_swimSpeedHackModifier = 4.0f; ImGui::SameLine();
            if (ImGui::Button(" 6 ")) g_swimSpeedHackModifier = 6.0f; ImGui::SameLine();
            if (ImGui::Button(" 8 ")) g_swimSpeedHackModifier = 8.0f; ImGui::SameLine();
            if (ImGui::Button(" 10 ")) g_swimSpeedHackModifier = 10.0f;

            ImGui::PopID();
        }

        if (ImGui::CollapsingHeader("ESP"))
        {
            ImGui::PushID("ID ESP");

            ImGui::Checkbox("Enabled", &g_espIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Show spawns and other objects through walls");

            ImGui::Separator();

            ImGui::Text("Type");
            ImGui::SameLine(200);
            ImGui::Text("Distance");

            ImGui::Checkbox("Spawns", &g_espSpawnIsEnabled);
            ImGui::SameLine(200);
            ImGui::InputFloat("##ESP Spawn Distance", &g_espSpawnDistance, 1.0f, 100.0f, 0);

            ImGui::Checkbox("Ground Spawns", &g_espGroundSpawnIsEnabled);
            ImGui::SameLine(200);
            ImGui::InputFloat("##ESP Ground Spawn Distance", &g_espGroundSpawnDistance, 1.0f, 100.0f, 0);

            ImGui::Checkbox("Doors", &g_espDoorIsEnabled);
            ImGui::SameLine(200);
            ImGui::InputFloat("##ESP Door Distance", &g_espDoorDistance, 1.0f, 100.0f, 0);

            ImGui::Checkbox("Spawn Skeletons", &g_espSkeletonIsEnabled);
            ImGui::SameLine(200);
            ImGui::InputFloat("##ESP Skeleton Distance", &g_espSkeletonDistance, 1.0f, 100.0f, 0);

            ImGui::Checkbox("Waypoints", &g_espWaypointIsEnabled);
            ImGui::SameLine(200);
            ImGui::InputFloat("##ESP Waypoint Distance", &g_espWaypointDistance, 1.0f, 100.0f, 0);

            ImGui::Checkbox("Zone Actors", &g_espZoneActorIsEnabled);
            ImGui::SameLine(200);
            ImGui::InputFloat("##ESP Zone Actor Distance", &g_espZoneActorDistance, 1.0f, 100.0f, 0);

            ImGui::Checkbox("Custom", &g_espCustomIsEnabled);
            ImGui::SameLine(200);
            ImGui::InputFloat("##ESP Custom Distance", &g_espCustomDistance, 1.0f, 100.0f, 0);

            ImGui::PopID();

            ImGui::Separator();

            ImGui::PushID("ID ESP Spawn Cast Spell");

            ImGui::Checkbox("Spawn Cast Spell", &g_spawnCastSpellEspIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Show what spells players and NPCs are casting");

            ImGui::PopID();

            ImGui::Separator();

            ImGui::PushID("ID ESP Skeleton");

            ImGui::Text("Spawn Skeletons");
            ImGui::SameLine(200);
            ImGui::Text("See a wireframe outline of spawns through walls");
            ImGui::Checkbox("Hide by Line of Sight", &g_espSkeletonHideByLineOfSightIsEnabled);
            ImGui::Checkbox("Draw Lines", &g_espSkeletonDrawLinesIsEnabled);
            ImGui::Checkbox("Draw Addresses", &g_espSkeletonDrawAddressesIsEnabled);

            ImGui::PopID();

            ImGui::Separator();

            ImGui::PushID("ID ESP Locator");

            ImGui::Checkbox("Locator", &g_espLocatorIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Show an indicator in-game of a '/loc' location n");
            ImGui::Checkbox("Draw Line", &g_espLocatorDrawLineIsEnabled);
            ImGui::InputFloat("Y", &g_espLocatorY, 1.0f, 10.0f, 0);
            ImGui::InputFloat("X", &g_espLocatorX, 1.0f, 10.0f, 0);
            ImGui::InputFloat("Z", &g_espLocatorZ, 1.0f, 10.0f, 0);

            ImGui::PopID();

            ImGui::Separator();

            ImGui::PushID("ID ESP Find");

            ImGui::Checkbox("Find", &g_espFindIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Show an indicator in-game of where a spawn is located");
            ImGui::Checkbox("Draw Line", &g_espFindDrawLineIsEnabled);
            ImGui::Checkbox("Ignore NPC Corpse", &g_espFindIgnoreNpcCorpseIsEnabled);

            ImGui::Text("Spawn Name:");
            ImGui::SameLine(200);

            static char g_espFindInputText[EQ_SIZE_SPAWN_INFO_NAME];
            if (ImGui::InputText("##ESP Find Input Text", g_espFindInputText, IM_ARRAYSIZE(g_espFindInputText)))
            {
                g_espFindSpawnName = g_espFindInputText;
            }

            if (g_espFindSpawnName.size() != 0)
            {
                ImGui::Text(g_espFindSpawnName.c_str());
            }

            ImGui::PopID();
        }

        if (ImGui::CollapsingHeader("Hotbuttons"))
        {
            ImGui::PushID("ID Always Hotbutton");

            ImGui::Checkbox("Always Hotbutton", &g_alwaysHotbuttonIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Press a hotbutton constantly at the specified interval");

            ImGui::Text("Number:"); ImGui::SameLine(200);
            if (ImGui::Button(" 1 ")) g_alwaysHotbuttonNumber = 1; ImGui::SameLine();
            if (ImGui::Button(" 2 ")) g_alwaysHotbuttonNumber = 2; ImGui::SameLine();
            if (ImGui::Button(" 3 ")) g_alwaysHotbuttonNumber = 3; ImGui::SameLine();
            if (ImGui::Button(" 4 ")) g_alwaysHotbuttonNumber = 4; ImGui::SameLine();
            if (ImGui::Button(" 5 ")) g_alwaysHotbuttonNumber = 5; ImGui::SameLine();
            if (ImGui::Button(" 6 ")) g_alwaysHotbuttonNumber = 6; ImGui::SameLine();
            if (ImGui::Button(" 7 ")) g_alwaysHotbuttonNumber = 7; ImGui::SameLine();
            if (ImGui::Button(" 8 ")) g_alwaysHotbuttonNumber = 8; ImGui::SameLine();
            if (ImGui::Button(" 9 ")) g_alwaysHotbuttonNumber = 9; ImGui::SameLine();
            if (ImGui::Button(" 10 ")) g_alwaysHotbuttonNumber = 10;

            ImGui::Text("Delay:"); ImGui::SameLine(200);
            if (ImGui::Button(" 1s ")) EQAPP_AlwaysHotbutton_Set(g_alwaysHotbuttonNumber, 1); ImGui::SameLine();
            if (ImGui::Button(" 2s ")) EQAPP_AlwaysHotbutton_Set(g_alwaysHotbuttonNumber, 2); ImGui::SameLine();
            if (ImGui::Button(" 3s ")) EQAPP_AlwaysHotbutton_Set(g_alwaysHotbuttonNumber, 3); ImGui::SameLine();
            if (ImGui::Button(" 4s ")) EQAPP_AlwaysHotbutton_Set(g_alwaysHotbuttonNumber, 4); ImGui::SameLine();
            if (ImGui::Button(" 5s ")) EQAPP_AlwaysHotbutton_Set(g_alwaysHotbuttonNumber, 5); ImGui::SameLine();
            if (ImGui::Button(" 6s ")) EQAPP_AlwaysHotbutton_Set(g_alwaysHotbuttonNumber, 6); ImGui::SameLine();
            if (ImGui::Button(" 7s ")) EQAPP_AlwaysHotbutton_Set(g_alwaysHotbuttonNumber, 7); ImGui::SameLine();
            if (ImGui::Button(" 8s ")) EQAPP_AlwaysHotbutton_Set(g_alwaysHotbuttonNumber, 8); ImGui::SameLine();
            if (ImGui::Button(" 9s ")) EQAPP_AlwaysHotbutton_Set(g_alwaysHotbuttonNumber, 9); ImGui::SameLine();
            if (ImGui::Button(" 10s ")) EQAPP_AlwaysHotbutton_Set(g_alwaysHotbuttonNumber, 10);

            std::stringstream ssAlwaysHotbutton;
            ssAlwaysHotbutton << "#" << g_alwaysHotbuttonNumber << " (" << g_alwaysHotbuttonTimerDelayInSeconds << " second(s))";

            ImGui::Text(ssAlwaysHotbutton.str().c_str());

            ImGui::Separator();

            ImGui::Checkbox("AHB Sit Stand At Mana", &g_alwaysHotbuttonSitStandAtManaIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Sit or stand when your mana is less than or greater than the specified values");

            ImGui::InputInt("Sit At Mana", (int*)&g_alwaysHotbuttonSitAtManaValue, 1, 100);
            ImGui::InputInt("Stand At Mana", (int*)&g_alwaysHotbuttonStandAtManaValue, 1, 100);

            ImGui::PopID();

            ImGui::Separator();

            ImGui::PushID("ID Combat Hotbutton");

            ImGui::Checkbox("Combat Hotbutton", &g_combatHotbuttonIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Press a hotbutton while in combat at the specified interval");

            ImGui::Text("Number:"); ImGui::SameLine(200);
            if (ImGui::Button(" 1 ")) g_combatHotbuttonNumber = 1; ImGui::SameLine();
            if (ImGui::Button(" 2 ")) g_combatHotbuttonNumber = 2; ImGui::SameLine();
            if (ImGui::Button(" 3 ")) g_combatHotbuttonNumber = 3; ImGui::SameLine();
            if (ImGui::Button(" 4 ")) g_combatHotbuttonNumber = 4; ImGui::SameLine();
            if (ImGui::Button(" 5 ")) g_combatHotbuttonNumber = 5; ImGui::SameLine();
            if (ImGui::Button(" 6 ")) g_combatHotbuttonNumber = 6; ImGui::SameLine();
            if (ImGui::Button(" 7 ")) g_combatHotbuttonNumber = 7; ImGui::SameLine();
            if (ImGui::Button(" 8 ")) g_combatHotbuttonNumber = 8; ImGui::SameLine();
            if (ImGui::Button(" 9 ")) g_combatHotbuttonNumber = 9; ImGui::SameLine();
            if (ImGui::Button(" 10 ")) g_combatHotbuttonNumber = 10;

            ImGui::Text("Delay:"); ImGui::SameLine(200);
            if (ImGui::Button(" 1s ")) EQAPP_CombatHotbutton_Set(g_combatHotbuttonNumber, 1); ImGui::SameLine();
            if (ImGui::Button(" 2s ")) EQAPP_CombatHotbutton_Set(g_combatHotbuttonNumber, 2); ImGui::SameLine();
            if (ImGui::Button(" 3s ")) EQAPP_CombatHotbutton_Set(g_combatHotbuttonNumber, 3); ImGui::SameLine();
            if (ImGui::Button(" 4s ")) EQAPP_CombatHotbutton_Set(g_combatHotbuttonNumber, 4); ImGui::SameLine();
            if (ImGui::Button(" 5s ")) EQAPP_CombatHotbutton_Set(g_combatHotbuttonNumber, 5); ImGui::SameLine();
            if (ImGui::Button(" 6s ")) EQAPP_CombatHotbutton_Set(g_combatHotbuttonNumber, 6); ImGui::SameLine();
            if (ImGui::Button(" 7s ")) EQAPP_CombatHotbutton_Set(g_combatHotbuttonNumber, 7); ImGui::SameLine();
            if (ImGui::Button(" 8s ")) EQAPP_CombatHotbutton_Set(g_combatHotbuttonNumber, 8); ImGui::SameLine();
            if (ImGui::Button(" 9s ")) EQAPP_CombatHotbutton_Set(g_combatHotbuttonNumber, 9); ImGui::SameLine();
            if (ImGui::Button(" 10s ")) EQAPP_CombatHotbutton_Set(g_combatHotbuttonNumber, 10);

            std::stringstream ssCombatHotbutton;
            ssCombatHotbutton << "#" << g_combatHotbuttonNumber << " (" << g_combatHotbuttonTimerDelayInSeconds << " second(s))";

            ImGui::Text(ssCombatHotbutton.str().c_str());

            ImGui::PopID();

            ImGui::Separator();

            ImGui::PushID("ID Backstab Hotbutton");

            ImGui::Checkbox("Backstab Hotbutton", &g_backstabIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Hotbutton for backstab when there is an opening");

            ImGui::Text("Number:"); ImGui::SameLine(200);
            if (ImGui::Button(" 1 ")) g_backstabHotbuttonNumber = 1; ImGui::SameLine();
            if (ImGui::Button(" 2 ")) g_backstabHotbuttonNumber = 2; ImGui::SameLine();
            if (ImGui::Button(" 3 ")) g_backstabHotbuttonNumber = 3; ImGui::SameLine();
            if (ImGui::Button(" 4 ")) g_backstabHotbuttonNumber = 4; ImGui::SameLine();
            if (ImGui::Button(" 5 ")) g_backstabHotbuttonNumber = 5; ImGui::SameLine();
            if (ImGui::Button(" 6 ")) g_backstabHotbuttonNumber = 6; ImGui::SameLine();
            if (ImGui::Button(" 7 ")) g_backstabHotbuttonNumber = 7; ImGui::SameLine();
            if (ImGui::Button(" 8 ")) g_backstabHotbuttonNumber = 8; ImGui::SameLine();
            if (ImGui::Button(" 9 ")) g_backstabHotbuttonNumber = 9; ImGui::SameLine();
            if (ImGui::Button(" 10 ")) g_backstabHotbuttonNumber = 10;

            std::stringstream ssBackstabHotbutton;
            ssBackstabHotbutton << "#" << g_backstabHotbuttonNumber;

            ImGui::Text(ssBackstabHotbutton.str().c_str());

            ImGui::PopID();

            ImGui::Separator();
        }

        if (ImGui::CollapsingHeader("Memory"))
        {
            ImGui::PushID("ID Memory");

            ImGui::Checkbox("Enabled", &g_memoryIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Cheats or hacks that modify the game memory");

            ImGui::Separator();

            if (ImGui::Button("Reload"))
            {
                EQAPP_Memory_Unload();
                EQAPP_Memory_Load();
            }

            ImGui::PopID();

            size_t index = 0;
            static EQApp::Memory* memoryEx;

            for (auto& memory : g_memoryList)
            {
                memoryEx = &memory;

                std::stringstream ssPushId;
                ssPushId << "ID Memory List Index " << index;

                ImGui::PushID(ssPushId.str().c_str());

                if (ImGui::Checkbox(memoryEx->name.c_str(), &memoryEx->isEnabled))
                {
                    EQAPP_Memory_Set(memoryEx, memoryEx->isEnabled);
                }
                ImGui::SameLine(400);
                ImGui::Text(memoryEx->description.c_str());

                ImGui::PopID();

                index++;
            }
        }

        if (ImGui::CollapsingHeader("Auto Loot"))
        {
            ImGui::PushID("ID Auto Loot");

            ImGui::Checkbox("Enabled", &g_autoLootIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Automatically loot items by name at the specified interval");

            ImGui::Separator();

            ImGui::Text("Delay:");
            ImGui::SameLine(200);
            std::stringstream ssDelay;
            ssDelay << g_autoLootTimerDelay << "ms";
            ImGui::Text(ssDelay.str().c_str());
            if (ImGui::Button(" 1ms ")) g_autoLootTimerDelay = 1; ImGui::SameLine();
            if (ImGui::Button(" 10ms ")) g_autoLootTimerDelay = 10; ImGui::SameLine();
            if (ImGui::Button(" 100ms ")) g_autoLootTimerDelay = 100; ImGui::SameLine();
            if (ImGui::Button(" 500ms ")) g_autoLootTimerDelay = 500; ImGui::SameLine();
            if (ImGui::Button(" 1s ")) g_autoLootTimerDelay = 1000;

            ImGui::Separator();

            ImGui::Text("Item Name:");

            ImGui::SameLine(200);

            ImGui::PushItemWidth(400);
            static char g_autoLootInputText[1024];
            ImGui::InputText("##Auto Loot Input Text", g_autoLootInputText, IM_ARRAYSIZE(g_autoLootInputText));
            ImGui::PopItemWidth();

            ImGui::SameLine();

            if (ImGui::Button("Add"))
            {
                EQAPP_AutoLoot_Add(g_autoLootInputText);
            }

            if (ImGui::Button("Clear List"))
            {
                g_autoLootList.clear();
            }
            ImGui::SameLine();
            ImGui::Text("(click text to remove)");

            ImGui::PopID();

            size_t itemIndex = 0;
            static std::string itemNameEx;

            float autoLootItemListHeight = 1.0f;

            if (g_autoLootList.size() > 0)
            {
                if (g_autoLootList.size() < 10)
                {
                    autoLootItemListHeight = 200.0f;
                }
                else
                {
                    autoLootItemListHeight = 400.0f;
                }
            }

            ImGui::BeginChild("ID Auto Loot Item List", ImVec2(600.0f, autoLootItemListHeight), true);

            for (auto& itemName : g_autoLootList)
            {
                itemNameEx = itemName;

                std::stringstream ssPushId;
                ssPushId << "ID Auto Loot List Index " << itemIndex;

                ImGui::PushID(ssPushId.str().c_str());

                if (ImGui::Button(itemNameEx.c_str()))
                {
                    EQAPP_AutoLoot_Remove(itemNameEx.c_str());
                }

                ImGui::PopID();

                if (itemIndex % 2 == 0)
                {
                    ImGui::SameLine(300);
                }

                itemIndex++;
            }

            ImGui::EndChild();
        }

        if (ImGui::CollapsingHeader("Named Spawns"))
        {
            ImGui::PushID("ID Named Spawns");

            ImGui::Checkbox("Enabled", &g_namedSpawnsIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Show a list in-game of specific spawns that are currently up");

            ImGui::Separator();

            ImGui::InputInt("X", (int*)&g_namedSpawnsX, 1, 100);
            ImGui::InputInt("Y", (int*)&g_namedSpawnsY, 1, 100);

            ImGui::Separator();

            if (ImGui::Button("Reload"))
            {
                EQAPP_NamedSpawns_Load();
            }

            for (auto& namedSpawn : g_namedSpawnsList)
            {
                ImGui::Text(namedSpawn.c_str());
            }

            ImGui::PopID();
        }

        if (ImGui::CollapsingHeader("On Screen Text"))
        {
            ImGui::PushID("ID On Screen Text");

            ImGui::Checkbox("Enabled", &g_onScreenTextIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Show a list in-game of specific events like NPCs casting spells");

            ImGui::Separator();

            ImGui::InputInt("X", (int*)&g_onScreenTextX, 1, 100);
            ImGui::InputInt("Y", (int*)&g_onScreenTextY, 1, 100);

            ImGui::PopID();
        }

        if (ImGui::CollapsingHeader("Text Overlay Chat Text"))
        {
            ImGui::PushID("ID Text Overlay Chat Text");

            ImGui::Checkbox("Enabled", &g_textOverlayOnChatTextIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Show text in middle of screen when specified chat text events occur");

            ImGui::Separator();

            if (ImGui::Button("Reload"))
            {
                EQAPP_TextOverlayChatText_Load();
            }

            for (auto& textOverlayChatText : g_textOverlayChatTextList)
            {
                ImGui::Text(textOverlayChatText.c_str());
            }

            ImGui::PopID();
        }

        if (ImGui::CollapsingHeader("Chat Filter"))
        {
            ImGui::PushID("ID Chat Filter");

            ImGui::Checkbox("Enabled", &g_chatFilterIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Hide chat text containing specific words or sentences");

            ImGui::Separator();

            ImGui::Text("Chat Text:");

            ImGui::SameLine(200);

            ImGui::PushItemWidth(400);
            static char g_chatFilterInputText[1024];
            ImGui::InputText("##Chat Filter Input Text", g_chatFilterInputText, IM_ARRAYSIZE(g_chatFilterInputText));
            ImGui::PopItemWidth();

            ImGui::SameLine();

            if (ImGui::Button("Add"))
            {
                EQAPP_ChatFilter_Add(g_chatFilterInputText);
            }

            if (ImGui::Button("Clear List"))
            {
                g_chatFilterList.clear();
            }
            ImGui::SameLine();
            ImGui::Text("(click text to remove)");

            if (ImGui::Button("Reload"))
            {
                EQAPP_ChatFilter_Load();
            }

            ImGui::PopID();

            size_t listIndex = 0;
            float listHeight = 1.0f;

            if (g_chatFilterList.size() > 0)
            {
                if (g_chatFilterList.size() < 10)
                {
                    listHeight = 200.0f;
                }
                else
                {
                    listHeight = 400.0f;
                }
            }

            ImGui::BeginChild("ID Chat Filter List", ImVec2(600.0f, listHeight), true);

            static std::string chatTextEx;

            for (auto& chatText : g_chatFilterList)
            {
                chatTextEx = chatText;

                std::stringstream ssPushId;
                ssPushId << "ID Chat Filter List Index " << listIndex;

                ImGui::PushID(ssPushId.str().c_str());

                if (ImGui::Button(chatTextEx.c_str()))
                {
                    EQAPP_ChatFilter_Remove(chatTextEx.c_str());
                }

                ImGui::PopID();
            }

            ImGui::EndChild();

            ImGui::PopID();
        }

        if (ImGui::CollapsingHeader("Beep"))
        {
            ImGui::PushID("ID Spawn Beep");

            ImGui::Checkbox("Spawn Beep", &g_spawnBeepIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Play a beep sound when a spawn with this name spawns");

            ImGui::Text("Spawn Name:");
            ImGui::SameLine(200);

            static char g_spawnBeepInputText[EQ_SIZE_SPAWN_INFO_NAME];
            if (ImGui::InputText("##Spawn Beep Input Text", g_spawnBeepInputText, IM_ARRAYSIZE(g_spawnBeepInputText)))
            {
                g_spawnBeepName = g_spawnBeepInputText;
            }

            if (g_spawnBeepName.size() != 0)
            {
                ImGui::Text(g_spawnBeepName.c_str());
            }

            ImGui::PopID();

            ImGui::Separator();

            ImGui::PushID("ID Target Beep");

            ImGui::Checkbox("Target Beep", &g_targetBeepIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Play a beep sound at specified interval when you have a target with this name");

            ImGui::Text("Spawn Name:");
            ImGui::SameLine(200);

            static char g_targetBeepInputText[EQ_SIZE_SPAWN_INFO_NAME];
            if (ImGui::InputText("##Target Beep Input Text", g_targetBeepInputText, IM_ARRAYSIZE(g_targetBeepInputText)))
            {
                g_targetBeepName = g_targetBeepInputText;
            }

            ImGui::Text("Delay:"); ImGui::SameLine(200);
            if (ImGui::Button(" 1s ")) EQAPP_TargetBeep_Set(g_targetBeepName, 1); ImGui::SameLine();
            if (ImGui::Button(" 2s ")) EQAPP_TargetBeep_Set(g_targetBeepName, 2); ImGui::SameLine();
            if (ImGui::Button(" 3s ")) EQAPP_TargetBeep_Set(g_targetBeepName, 3); ImGui::SameLine();
            if (ImGui::Button(" 4s ")) EQAPP_TargetBeep_Set(g_targetBeepName, 4); ImGui::SameLine();
            if (ImGui::Button(" 5s ")) EQAPP_TargetBeep_Set(g_targetBeepName, 5); ImGui::SameLine();
            if (ImGui::Button(" 6s ")) EQAPP_TargetBeep_Set(g_targetBeepName, 6); ImGui::SameLine();
            if (ImGui::Button(" 7s ")) EQAPP_TargetBeep_Set(g_targetBeepName, 7); ImGui::SameLine();
            if (ImGui::Button(" 8s ")) EQAPP_TargetBeep_Set(g_targetBeepName, 8); ImGui::SameLine();
            if (ImGui::Button(" 9s ")) EQAPP_TargetBeep_Set(g_targetBeepName, 9); ImGui::SameLine();
            if (ImGui::Button(" 10s ")) EQAPP_TargetBeep_Set(g_targetBeepName, 10);

            if (g_targetBeepName.size() != 0)
            {
                std::stringstream ssTargetBeepText;
                ssTargetBeepText << g_targetBeepName.c_str() << " (" << g_targetBeepTimerDelayInSeconds << "s)";

                ImGui::Text(ssTargetBeepText.str().c_str());
            }

            ImGui::PopID();

            ImGui::Separator();

            ImGui::PushID("ID Player Alert");

            ImGui::Checkbox("Player Alert", &g_playerAlertIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Plays a beep sound when the number of players in the zone exceeds the limit");

            ImGui::InputInt("Minimum number of players in zone", (int*)&g_playerAlertMinimumNumPlayersInZone, 1, 10);

            ImGui::Text("Delay:"); ImGui::SameLine(200);
            if (ImGui::Button(" 1s ")) EQAPP_PlayerAlert_Set(g_playerAlertMinimumNumPlayersInZone, 1); ImGui::SameLine();
            if (ImGui::Button(" 2s ")) EQAPP_PlayerAlert_Set(g_playerAlertMinimumNumPlayersInZone, 2); ImGui::SameLine();
            if (ImGui::Button(" 3s ")) EQAPP_PlayerAlert_Set(g_playerAlertMinimumNumPlayersInZone, 3); ImGui::SameLine();
            if (ImGui::Button(" 4s ")) EQAPP_PlayerAlert_Set(g_playerAlertMinimumNumPlayersInZone, 4); ImGui::SameLine();
            if (ImGui::Button(" 5s ")) EQAPP_PlayerAlert_Set(g_playerAlertMinimumNumPlayersInZone, 5); ImGui::SameLine();
            if (ImGui::Button(" 6s ")) EQAPP_PlayerAlert_Set(g_playerAlertMinimumNumPlayersInZone, 6); ImGui::SameLine();
            if (ImGui::Button(" 7s ")) EQAPP_PlayerAlert_Set(g_playerAlertMinimumNumPlayersInZone, 7); ImGui::SameLine();
            if (ImGui::Button(" 8s ")) EQAPP_PlayerAlert_Set(g_playerAlertMinimumNumPlayersInZone, 8); ImGui::SameLine();
            if (ImGui::Button(" 9s ")) EQAPP_PlayerAlert_Set(g_playerAlertMinimumNumPlayersInZone, 9); ImGui::SameLine();
            if (ImGui::Button(" 10s ")) EQAPP_PlayerAlert_Set(g_playerAlertMinimumNumPlayersInZone, 10);

            std::stringstream ssPlayerAlertText;
            ssPlayerAlertText << g_playerAlertMinimumNumPlayersInZone << " (" << g_playerAlertTimerDelayInSeconds << "s)";

            ImGui::Text(ssPlayerAlertText.str().c_str());

            ImGui::PopID();
        }

        if (ImGui::CollapsingHeader("Draw Distance"))
        {
            ImGui::PushID("ID Draw Distance");

            ImGui::Checkbox("Enabled", &g_drawDistanceIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Lets you see far away by modifying fog and max view distance");

            ImGui::Separator();

            ImGui::SliderFloat("Distance", &g_drawDistance, 100.0f, 20000.0f, 0);

            if (ImGui::Button("100")) g_drawDistance = 100.0f; ImGui::SameLine();
            if (ImGui::Button("200")) g_drawDistance = 200.0f; ImGui::SameLine();
            if (ImGui::Button("400")) g_drawDistance = 400.0f; ImGui::SameLine();
            if (ImGui::Button("800")) g_drawDistance = 800.0f; ImGui::SameLine();
            if (ImGui::Button("1000")) g_drawDistance = 1000.0f; ImGui::SameLine();
            if (ImGui::Button("2000")) g_drawDistance = 2000.0f; ImGui::SameLine();
            if (ImGui::Button("4000")) g_drawDistance = 4000.0f; ImGui::SameLine();
            if (ImGui::Button("8000")) g_drawDistance = 8000.0f; ImGui::SameLine();
            if (ImGui::Button("10000")) g_drawDistance = 10000.0f; ImGui::SameLine();
            if (ImGui::Button("20000")) g_drawDistance = 20000.0f;

            ImGui::PopID();
        }

        if (ImGui::CollapsingHeader("Change Height"))
        {
            ImGui::PushID("ID Change Height");

            ImGui::Checkbox("Enabled", &g_changeHeightIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Shrink players or pets that are too tall or too big");

            ImGui::Separator();

            ImGui::Checkbox("Players", &g_changeHeightPlayersIsEnabled);
            ImGui::SameLine(200);
            ImGui::InputFloat("##Change Height Players Size", &g_changeHeightPlayersSize, 1.0f, 10.0f, 0);

            ImGui::Checkbox("Pets", &g_changeHeightPetsIsEnabled);
            ImGui::SameLine(200);
            ImGui::InputFloat("##Change Height Pets Size", &g_changeHeightPetsSize, 1.0f, 10.0f, 0);

            ImGui::PopID();
        }

        if (ImGui::CollapsingHeader("Set Target"))
        {
            ImGui::PushID("ID Set Target");

            ImGui::Checkbox("Enabled", &g_setTargetIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Lets you target from any distance with improved /target command");

            ImGui::Separator();

            ImGui::Checkbox("Use Max Distance", &g_setTargetMaxDistanceIsEnabled);
            ImGui::InputFloat("Max Distance", &g_setTargetMaxDistance, 1.0f, 100.0f, 0);

            ImGui::PopID();
        }

        if (ImGui::CollapsingHeader("Spawn Cast Spell"))
        {
            ImGui::PushID("ID Spawn Cast Spell");

            ImGui::Checkbox("Enabled", &g_spawnCastSpellIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Show what spells players and NPCs are casting");

            ImGui::Checkbox("ESP", &g_spawnCastSpellEspIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Show spell casting information at spawn location on screen");

            ImGui::Separator();

            ImGui::Checkbox("Cast Bars", &g_spawnCastSpellDrawBarsIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Show name, timer and progress bar for spells currently being casted");

            ImGui::Text(" ");

            ImGui::Checkbox("Show Cast Bars for Players", &g_spawnCastSpellDrawBarsForPlayerIsEnabled);
            ImGui::Checkbox("Show Cast Bars for NPCs", &g_spawnCastSpellDrawBarsForNpcIsEnabled);
            ImGui::Checkbox("Show Cast Bars for Healer classes only", &g_spawnCastSpellDrawBarsForHealerClassOnlyIsEnabled);

            ImGui::Text(" ");

            ImGui::InputInt("Max Cast Bars shown", (int*)&g_spawnCastSpellDrawBarsMax, 1, 10);
            ImGui::InputInt("Minimum spell casting time in milliseconds", (int*)&g_spawnCastSpellDrawBarsMinimumSpellCastTime, 1000, 10000);

            ImGui::PopID();
        }

        if (ImGui::CollapsingHeader("Zone Actors"))
        {
            ImGui::PushID("ID Zone Actors No Collision");

            ImGui::Checkbox("No Collision", &g_zoneActorsNoCollisionIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Walk through objects in zones without getting stuck");

            if (ImGui::Button("Apply"))
            {
                EQAPP_ZoneActors_NoCollision_Execute();
            }
            ImGui::SameLine(200);
            if (ImGui::Button("Restore"))
            {
                EQAPP_ZoneActors_NoCollision_Restore();
            }

            if (ImGui::Button("Reload"))
            {
                EQAPP_ZoneActors_NoCollision_Load();
            }

            for (auto& zoneActorNoCollisionName : g_zoneActorsNoCollisionList)
            {
                ImGui::Text(zoneActorNoCollisionName.c_str());
            }

            ImGui::PopID();
        }

        if (ImGui::CollapsingHeader("Set Race"))
        {
            ImGui::PushID("ID Set Race");

            if (ImGui::InputInt("Race ID", &g_setRaceId, 1, 100))
            {
                uint32_t spawnInfo = EQ_GetTargetSpawn();
                if (spawnInfo == NULL)
                {
                    spawnInfo = EQ_GetPlayerSpawn();
                }

                if (spawnInfo != NULL)
                {
                   if (g_setRaceId != 0)
                   {
                        int spawnGender = EQ_ReadMemory<uint8_t>(spawnInfo + EQ_OFFSET_SPAWN_INFO_GENDER);

                        EQ_SetSpawnForm(spawnInfo, g_setRaceId, spawnGender);
                    }
                }
            }

            ImGui::PopID();
        }

        if (ImGui::CollapsingHeader("Other"))
        {
            ImGui::PushID("ID Always Attack");
            ImGui::Checkbox("Always Attack", &g_alwaysAttackIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Do not need to turn attack back on after killing a mob");
            ImGui::PopID();

            ImGui::PushID("ID Line To Target");
            ImGui::Checkbox("Line to Target", &g_lineToTargetIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Draw a line to the spawn you are targeting");
            ImGui::PopID();

            ImGui::PushID("ID Hide Corpse Looted");
            ImGui::Checkbox("Hide Corpse Looted", &g_hideCorpseLootedIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("The '/hidecorpse looted' command is always on");
            ImGui::PopID();

            ImGui::PushID("ID Max Swimming Skill");
            ImGui::Checkbox("Max Swimming Skill", &g_maxSwimmingSkillIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Lets you swim faster");
            ImGui::PopID();

            ImGui::PushID("ID Replace Races");
            ImGui::Checkbox("Replace Races", &g_replaceRacesIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Replaces invisible men with humans and skeletons with better models");
            ImGui::PopID();

            ImGui::PushID("ID Auto Join Group");
            ImGui::Checkbox("Auto Join Group", &g_autoGroupIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Automatically join groups when you are invited");
            ImGui::PopID();

            ImGui::Separator();

            ImGui::PushID("ID Free Camera");
            if (ImGui::Button("Free Camera"))
            {
                EQAPP_FreeCamera_Toggle();
            }
            ImGui::SameLine();
            EQAPP_IMGUI_TextBool(g_freeCameraIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Use arrow keys to fly around and duck or crouch to disable");
            ImGui::PopID();

            ImGui::PushID("ID Census");
            if (ImGui::Button("Census"))
            {
                EQAPP_Census_Toggle();
            }
            ImGui::SameLine();
            EQAPP_IMGUI_TextBool(g_censusIsEnabled);
            ImGui::SameLine(200);
            ImGui::Text("Do a '/who all' for all zones to find people");
            ImGui::PopID();

            ImGui::Separator();

            ImGui::PushID("ID Open All Doors");
            if (ImGui::Button("Open All Doors"))
            {
                EQAPP_Doors_OpenAll(true);
            }
            ImGui::SameLine(200);
            ImGui::Text("Open all doors including locked doors and timed doors");
            ImGui::PopID();

            ImGui::PushID("ID Close All Doors");
            if (ImGui::Button("Close All Doors"))
            {
                EQAPP_Doors_OpenAll(false);
            }
            ImGui::SameLine(200);
            ImGui::Text("Force all doors to close");
            ImGui::PopID();

            ImGui::Separator();

            ImGui::PushID("ID Add Map Labels");
            if (ImGui::Button("Add Map Labels"))
            {
                EQAPP_MapLabels_Add();
            }
            ImGui::SameLine(200);
            ImGui::Text("Shows all spawns on the map");
            ImGui::PopID();

            ImGui::PushID("ID Remove Map Labels");
            if (ImGui::Button("Remove Map Labels"))
            {
                EQAPP_MapLabels_Remove();
            }
            ImGui::SameLine(200);
            ImGui::Text("Removes the spawns from the map");
            ImGui::PopID();

            ImGui::Separator();

            ImGui::PushID("ID Map Locations Write To File");
            if (ImGui::Button("Save Map Locations"))
            {
                EQAPP_MapLocations_WriteToFile();
            }
            ImGui::SameLine(200);
            ImGui::Text("Save the locations of all spawns in the zone to map format");
            ImGui::PopID();

            ImGui::PushID("ID Character File Write");
            if (ImGui::Button("Save Character"))
            {
                EQAPP_CharacterFile_Write();
            }
            ImGui::SameLine(200);
            ImGui::Text("Save information about your character in text and json formats");
            ImGui::PopID();
        }

        ImGui::End();
    }
};

