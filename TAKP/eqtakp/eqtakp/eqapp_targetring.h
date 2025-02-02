#pragma once

bool g_TargetRingIsEnabled = false;

EQ_SpellID_t g_TargetRingSpellID = 3848;

void EQAPP_TargetRing_Toggle();
void EQAPP_TargetRing_Execute();

void EQAPP_TargetRing_Toggle()
{
    EQ_ToggleBool(g_TargetRingIsEnabled);
    EQAPP_PrintBool("Target Ring", g_TargetRingIsEnabled);
}

void EQAPP_TargetRing_Execute()
{
    auto targetSpawn = EQ_GetTargetSpawn();
    if (targetSpawn != NULL)
    {
        auto spell = EQ_GetSpellByID(g_TargetRingSpellID);
        if (spell != NULL)
        {
            auto target = (EQClass::EQPlayer*)targetSpawn;

            float targetSpawnFloorZ = EQ_CLASS_POINTER_CDisplay->GetPlayerFloorHeight(target, targetSpawn->Y, targetSpawn->X, targetSpawn->Z, true);

            EQ::Location location;
            location.Y = targetSpawn->Y;
            location.X = targetSpawn->X;
            location.Z = targetSpawnFloorZ + 0.1f;

            uint32_t spellDuration = 50;

            if (targetSpawn->MovementSpeed > 0.0f)
            {
                spellDuration = 10;
            }

            EQ_FUNCTION_DoSpellEffect(2, spell, target, target, &location, NULL, spellDuration);
        }
    }
}
