#pragma once

bool g_lineToTargetIsEnabled = true;
DWORD g_lineToTargetColor = 0xFFFF00FF;

void EQAPP_LineToTarget_Execute();

void EQAPP_LineToTarget_Execute()
{
    if (g_lineToTargetIsEnabled == false)
    {
        return;
    }

    DWORD targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn == NULL)
    {
        return;
    }

    float targetY = EQ_GetSpawnY(targetSpawn);
    float targetX = EQ_GetSpawnX(targetSpawn);
    float targetZ = EQ_GetSpawnZ(targetSpawn);

    int screenX = -1;
    int screenY = -1;
    bool result = EQ_WorldSpaceToScreenSpace(targetX, targetY, targetZ, screenX, screenY);
    if (result == true)
    {
        DWORD windowWidth  = EQ_GetWindowWidth();
        DWORD windowHeight = EQ_GetWindowHeight();

        EQ_DrawLine((float)(windowWidth * 0.5f), (float)windowHeight, 0.0f, (float)screenX, (float)screenY, 0.0f, g_lineToTargetColor);
    }
}

