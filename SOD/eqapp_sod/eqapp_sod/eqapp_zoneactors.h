#pragma once

bool g_zoneActorsNoCollisionIsEnabled = true;
std::vector<std::string> g_zoneActorsNoCollisionList;
std::vector<std::string>::iterator g_zoneActorsNoCollisionListIterator;

void EQAPP_ZoneActors_Debug();

void EQAPP_ZoneActors_NoCollision_Load();
void EQAPP_ZoneActors_NoCollision_Print();
void EQAPP_ZoneActors_NoCollision_Execute();
void EQAPP_ZoneActors_NoCollision_Restore();

void EQAPP_ZoneActors_Debug()
{
    std::cout << "ESP Zone Actors Debug:" << std::endl;
    std::cout << "Saving zone actors to file..." << std::endl;

    std::string zoneShortName = EQ_GetZoneShortName();
    if (zoneShortName.size() == 0)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "zone short name is NULL");
        return;
    }

    std::stringstream filePath;
    filePath << g_applicationName << "/zoneactors/" << zoneShortName << ".txt";

    std::fstream file;
    file.open(filePath.str().c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
    if (file.is_open() == false)
    {
        std::stringstream ss;
        ss << "failed to open file: " << filePath.str();

        EQAPP_PrintErrorMessage(__FUNCTION__, ss.str());
        return;
    }

    file << "# Name Y X Z Rotation Scale" << std::endl;

    uint32_t playerSpawn = EQ_GetPlayerSpawn();

    float playerY = EQ_GetSpawnY(playerSpawn);
    float playerX = EQ_GetSpawnX(playerSpawn);
    float playerZ = EQ_GetSpawnZ(playerSpawn);

    uint32_t pointer1 = EQ_ReadMemory<uint32_t>(EQ_POINTER_0x00B112C0);
    if (pointer1 != NULL)
    {
        uint32_t pointer2 = EQ_ReadMemory<uint32_t>(pointer1 + EQ_OFFSET_0x00B112C0_POINTER_2);
        if (pointer2 != NULL)
        {
            uint32_t zoneActor = EQ_ReadMemory<uint32_t>(pointer2 + EQ_OFFSET_0x00B112C0_POINTER_2_ZONE_ACTOR_INFO_FIRST);
            while (zoneActor)
            {
                uint32_t zoneActor0x0C = EQ_ReadMemory<uint32_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x0C);
                if (zoneActor0x0C == 2)
                {
                    zoneActor = EQ_ReadMemory<uint32_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_NEXT); // next
                    continue;
                }

                int zoneActor0x2C = EQ_ReadMemory<uint8_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x2C);
                int zoneActor0x2D = EQ_ReadMemory<uint8_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x2D);
                int zoneActor0x2E = EQ_ReadMemory<uint8_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x2E);
                int zoneActor0x2F = EQ_ReadMemory<uint8_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x2F);

                uint32_t zoneActor0x54 = EQ_ReadMemory<uint32_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x54);

                float zoneActorY = EQ_ReadMemory<float>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_Y);
                float zoneActorX = EQ_ReadMemory<float>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_X);
                float zoneActorZ = EQ_ReadMemory<float>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_Z);

                float zoneActorRotation = EQ_ReadMemory<float>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_ROTATION);
                float zoneActorScale = EQ_ReadMemory<float>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_SCALE);

                float zoneActorDistance = EQ_CalculateDistance3d(playerX, playerY, playerZ, zoneActorX, zoneActorY, zoneActorZ);

                std::string zoneActorName = "ZONEACTOR";

                uint32_t zoneActor0x14 = EQ_ReadMemory<uint32_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x14);
                if (zoneActor0x14 != NULL)
                {
                    uint32_t zoneActor0x14x18 = EQ_ReadMemory<uint32_t>(zoneActor0x14 + EQ_OFFSET_ZONE_ACTOR_INFO_0x14_0x18);
                    if (zoneActor0x14x18 != NULL)
                    {
                        char* zoneActorNamePointer = EQ_ReadMemory<char*>(zoneActor0x14x18 + EQ_OFFSET_ZONE_ACTOR_INFO_NAME_0x14_0x18_0x08);
                        if (zoneActorNamePointer != NULL)
                        {
                            zoneActorName = std::string(zoneActorNamePointer);
                        }
                    }
                }

                std::string zoneActorExName = "ZONEACTOREX";

                uint32_t zoneActorSpawnInfo = NULL;

                float zoneActorExY1 = 0.0f;
                float zoneActorExX1 = 0.0f;
                float zoneActorExZ1 = 0.0f;

                float zoneActorExY2 = 0.0f;
                float zoneActorExX2 = 0.0f;
                float zoneActorExZ2 = 0.0f;

                float zoneActorExY3 = 0.0f;
                float zoneActorExX3 = 0.0f;
                float zoneActorExZ3 = 0.0f;

                uint32_t zoneActorEx = EQ_ReadMemory<uint32_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_ACTOR_INFO);
                if (zoneActorEx != NULL)
                {
                    zoneActorSpawnInfo = EQ_ReadMemory<uint32_t>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_SPAWN_INFO);

                    if (zoneActorSpawnInfo == NULL)
                    {
                        char* zoneActorExNamePointer = (char*)(zoneActorEx - EQ_OFFSET_ACTOR_INFO_NAME);
                        if (zoneActorExNamePointer != NULL)
                        {
                            zoneActorExName = std::string(zoneActorExNamePointer);
                        }
                    }

                    zoneActorExY1 = EQ_ReadMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_Y1);
                    zoneActorExX1 = EQ_ReadMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_X1);
                    zoneActorExZ1 = EQ_ReadMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_Z1);

                    zoneActorExY2 = EQ_ReadMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_Y2);
                    zoneActorExX2 = EQ_ReadMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_X2);
                    zoneActorExZ2 = EQ_ReadMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_Z2);

                    zoneActorExY3 = EQ_ReadMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_Y3);
                    zoneActorExX3 = EQ_ReadMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_X3);
                    zoneActorExZ3 = EQ_ReadMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_Z3);
                }

                std::cout << "Name: " << zoneActorName << std::endl;

                std::cout << "Distance: " << (int)zoneActorDistance << std::endl;

                std::cout << "Y: " << zoneActorY << std::endl;
                std::cout << "X: " << zoneActorX << std::endl;
                std::cout << "Z: " << zoneActorZ << std::endl;

                std::cout << "Rotation: " << zoneActorRotation << std::endl;
                std::cout << "Scale: " << zoneActorScale << std::endl;

                std::cout << "0x2C: " << zoneActor0x2C << std::endl;
                std::cout << "0x2D: " << zoneActor0x2D << std::endl;
                std::cout << "0x2E: " << zoneActor0x2E << std::endl;
                std::cout << "0x2F: " << zoneActor0x2F << std::endl;

                std::cout << "0x54: " << std::hex << zoneActor0x54 << std::dec << std::endl;

                std::cout << "Name Ex: " << zoneActorExName << std::endl;

                if (zoneActorSpawnInfo != NULL)
                {
                    std::cout << "Spawn Info: " << zoneActorSpawnInfo << std::endl;
                }

                std::cout << "Y1: " << zoneActorExY1 << std::endl;
                std::cout << "X1: " << zoneActorExX1 << std::endl;
                std::cout << "Z1: " << zoneActorExZ1 << std::endl;

                std::cout << "Y2: " << zoneActorExY2 << std::endl;
                std::cout << "X2: " << zoneActorExX2 << std::endl;
                std::cout << "Z2: " << zoneActorExZ2 << std::endl;

                std::cout << "Y3: " << zoneActorExY3 << std::endl;
                std::cout << "X3: " << zoneActorExX3 << std::endl;
                std::cout << "Z3: " << zoneActorExZ3 << std::endl;

                std::cout << "--------------------------------------------------" << std::endl;

                if (zoneActorSpawnInfo == NULL && zoneActorName.size() > 0)
                {
                    file << zoneActorName << " " << zoneActorY << " " << zoneActorX << " " << zoneActorZ << " " << zoneActorRotation << " " << zoneActorScale << std::endl;
                }

                zoneActor = EQ_ReadMemory<uint32_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_NEXT); // next
            }
        }
    }

    file.close();
}

void EQAPP_ZoneActors_NoCollision_Load()
{
    std::cout << "Loading Zone Actors No Collision..." << std::endl;

    std::string zoneShortName = EQ_GetZoneShortName();
    if (zoneShortName.size() == 0)
    {
        EQAPP_PrintErrorMessage(__FUNCTION__, "zone short name is NULL");
        return;
    }

    g_zoneActorsNoCollisionList.clear();

    EQAPP_ReadFileToList("zoneactorsnocollision.txt", g_zoneActorsNoCollisionList);

    std::stringstream filePath;
    filePath << "zoneactorsnocollision/" << zoneShortName << ".txt";

    EQAPP_ReadFileToList(filePath.str().c_str(), g_zoneActorsNoCollisionList);

    g_zoneActorsNoCollisionListIterator = g_zoneActorsNoCollisionList.begin();
}

void EQAPP_ZoneActors_NoCollision_Print()
{
    std::cout << "Zone Actors No Collision: " << std::endl;

    for (auto& text : g_zoneActorsNoCollisionList)
    {
        std::cout << text << std::endl;
    }
}

void EQAPP_ZoneActors_NoCollision_Execute()
{
    if (g_zoneActorsNoCollisionIsEnabled == false)
    {
        return;
    }

    if (EQ_IsInGame() == false)
    {
        return;
    }

    uint32_t playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    float playerY = EQ_GetSpawnY(playerSpawn);
    float playerX = EQ_GetSpawnX(playerSpawn);
    float playerZ = EQ_GetSpawnZ(playerSpawn);

    uint32_t pointer1 = EQ_ReadMemory<uint32_t>(EQ_POINTER_0x00B112C0);
    if (pointer1 != NULL)
    {
        uint32_t pointer2 = EQ_ReadMemory<uint32_t>(pointer1 + EQ_OFFSET_0x00B112C0_POINTER_2);
        if (pointer2 != NULL)
        {
            uint32_t zoneActor = EQ_ReadMemory<uint32_t>(pointer2 + EQ_OFFSET_0x00B112C0_POINTER_2_ZONE_ACTOR_INFO_FIRST);

            while (zoneActor)
            {
                uint32_t zoneActor0x0C = EQ_ReadMemory<uint32_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x0C);
                if (zoneActor0x0C == 2)
                {
                    zoneActor = EQ_ReadMemory<uint32_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_NEXT); // next
                    continue;
                }

                std::string zoneActorName = "ZONEACTOR";

                uint32_t zoneActor0x14 = EQ_ReadMemory<uint32_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x14);
                if (zoneActor0x14 != NULL)
                {
                    uint32_t zoneActor0x14x18 = EQ_ReadMemory<uint32_t>(zoneActor0x14 + EQ_OFFSET_ZONE_ACTOR_INFO_0x14_0x18);
                    if (zoneActor0x14x18 != NULL)
                    {
                        char* zoneActorNamePointer = EQ_ReadMemory<char*>(zoneActor0x14x18 + EQ_OFFSET_ZONE_ACTOR_INFO_NAME_0x14_0x18_0x08);
                        if (zoneActorNamePointer != NULL)
                        {
                            zoneActorName = std::string(zoneActorNamePointer);
                        }
                    }
                }

                uint32_t zoneActorSpawnInfo = NULL;

                uint32_t zoneActorEx = EQ_ReadMemory<uint32_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_ACTOR_INFO);
                if (zoneActorEx != NULL)
                {
                    zoneActorSpawnInfo = EQ_ReadMemory<uint32_t>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_SPAWN_INFO);
                    if (zoneActorSpawnInfo == NULL)
                    {
                        for (auto& zoneActorNoCollisionName : g_zoneActorsNoCollisionList)
                        {
                            if (zoneActorNoCollisionName == zoneActorName)
                            {
                                if (g_debugIsEnabled == true)
                                {
                                    std::cout << "Applying Zone Actor No Collision to: " << zoneActorName << std::endl;
                                }

                                EQ_WriteMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_Y2, 0.0f);
                                EQ_WriteMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_X2, 0.0f);
                                EQ_WriteMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_Z2, -20000.0f);

                                break;
                            }
                        }
                    }
                }

                zoneActor = EQ_ReadMemory<uint32_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_NEXT); // next
            }
        }
    }
}

void EQAPP_ZoneActors_NoCollision_Restore()
{
    if (EQ_IsInGame() == false)
    {
        return;
    }

    uint32_t playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return;
    }

    float playerY = EQ_GetSpawnY(playerSpawn);
    float playerX = EQ_GetSpawnX(playerSpawn);
    float playerZ = EQ_GetSpawnZ(playerSpawn);

    uint32_t pointer1 = EQ_ReadMemory<uint32_t>(EQ_POINTER_0x00B112C0);
    if (pointer1 != NULL)
    {
        uint32_t pointer2 = EQ_ReadMemory<uint32_t>(pointer1 + EQ_OFFSET_0x00B112C0_POINTER_2);
        if (pointer2 != NULL)
        {
            uint32_t zoneActor = EQ_ReadMemory<uint32_t>(pointer2 + EQ_OFFSET_0x00B112C0_POINTER_2_ZONE_ACTOR_INFO_FIRST);

            while (zoneActor)
            {
                uint32_t zoneActor0x0C = EQ_ReadMemory<uint32_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x0C);
                if (zoneActor0x0C == 2)
                {
                    zoneActor = EQ_ReadMemory<uint32_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_NEXT); // next
                    continue;
                }

                std::string zoneActorName = "ZONEACTOR";

                uint32_t zoneActor0x14 = EQ_ReadMemory<uint32_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_0x14);
                if (zoneActor0x14 != NULL)
                {
                    uint32_t zoneActor0x14x18 = EQ_ReadMemory<uint32_t>(zoneActor0x14 + EQ_OFFSET_ZONE_ACTOR_INFO_0x14_0x18);
                    if (zoneActor0x14x18 != NULL)
                    {
                        char* zoneActorNamePointer = EQ_ReadMemory<char*>(zoneActor0x14x18 + EQ_OFFSET_ZONE_ACTOR_INFO_NAME_0x14_0x18_0x08);
                        if (zoneActorNamePointer != NULL)
                        {
                            zoneActorName = std::string(zoneActorNamePointer);
                        }
                    }
                }

                uint32_t zoneActorSpawnInfo = NULL;

                float zoneActorExY1 = 0.0f;
                float zoneActorExX1 = 0.0f;
                float zoneActorExZ1 = 0.0f;

                uint32_t zoneActorEx = EQ_ReadMemory<uint32_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_ACTOR_INFO);
                if (zoneActorEx != NULL)
                {
                    zoneActorSpawnInfo = EQ_ReadMemory<uint32_t>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_SPAWN_INFO);
                    if (zoneActorSpawnInfo == NULL)
                    {
                        for (auto& zoneActorNoCollisionName : g_zoneActorsNoCollisionList)
                        {
                            if (zoneActorNoCollisionName == zoneActorName)
                            {
                                if (g_debugIsEnabled == true)
                                {
                                    std::cout << "Restore Zone Actor Collision to: " << zoneActorName << std::endl;
                                }

                                zoneActorExY1 = EQ_ReadMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_Y1);
                                zoneActorExX1 = EQ_ReadMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_X1);
                                zoneActorExZ1 = EQ_ReadMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_Z1);

                                EQ_WriteMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_Y2, zoneActorExY1);
                                EQ_WriteMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_X2, zoneActorExX1);
                                EQ_WriteMemory<float>(zoneActorEx + EQ_OFFSET_ACTOR_INFO_Z2, zoneActorExZ1);

                                break;
                            }
                        }
                    }
                }

                zoneActor = EQ_ReadMemory<uint32_t>(zoneActor + EQ_OFFSET_ZONE_ACTOR_INFO_NEXT); // next
            }
        }
    }
}

