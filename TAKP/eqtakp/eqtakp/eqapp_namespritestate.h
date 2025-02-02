#pragma once

bool g_NameSpriteStateIsEnabled = true;

bool g_NameSpriteStateRemoveLastNamesIsEnabled = true;

void EQAPP_NameSpriteState_Toggle();
void EQAPP_NameSpriteState_RemoveLastNames_Toggle();
bool EQAPP_NameSpriteState_HandleEvent_CDisplay__SetNameSpriteState(void* this_ptr, class EQPlayer* player, bool show);

void EQAPP_NameSpriteState_Toggle()
{
    EQ_ToggleBool(g_NameSpriteStateIsEnabled);
    EQAPP_PrintBool("Name Sprite State", g_NameSpriteStateIsEnabled);
}

void EQAPP_NameSpriteState_RemoveLastNames_Toggle()
{
    EQ_ToggleBool(g_NameSpriteStateRemoveLastNamesIsEnabled);
    EQAPP_PrintBool("Name Sprite State Remove Last Names", g_NameSpriteStateRemoveLastNamesIsEnabled);
}

bool EQAPP_NameSpriteState_HandleEvent_CDisplay__SetNameSpriteState(void* this_ptr, class EQPlayer* player, bool show)
{
    if (EQ_IsInGame() == false)
    {
        return false;
    }

    EQ::Spawn_ptr spawn = (EQ::Spawn_ptr)player;
    if (spawn == NULL)
    {
        return false;
    }

    if (spawn->Actor == NULL)
    {
        return false;
    }

    if (spawn->Actor->ModelBoneHeadPoint == NULL)
    {
        return false;
    }

    if (spawn->Actor->ModelBoneHeadPoint->StringSprite == NULL)
    {
        return false;
    }

    if (spawn->Actor->ModelBoneHeadPoint->StringSprite->Type != EQ_STRINGSPRITE_TYPE_1)
    {
        return false;
    }

    if (spawn->Actor->ModelBoneHeadPoint->StringSprite->ID == 0)
    {
        return false;
    }

    if (spawn->Actor->ModelBoneHeadPoint->StringSprite->Text == NULL)
    {
        return false;
    }

    if (spawn->Actor->ModelBoneHeadPoint->StringSprite->TextLength == 0)
    {
        return false;
    }

    auto playerSpawn = EQ_GetPlayerSpawn();
    if (playerSpawn == NULL)
    {
        return false;
    }

    if (g_NameSpriteStateRemoveLastNamesIsEnabled == true)
    {
        if (spawn->Type == EQ_SPAWN_TYPE_PLAYER)
        {
            spawn->LastName[0] = '\0';
        }
    }

    auto targetSpawn = EQ_GetTargetSpawn();

    if (spawn->Type == EQ_SPAWN_TYPE_PLAYER || spawn->Type == EQ_SPAWN_TYPE_NPC)
    {
        std::string nameSpriteText = spawn->Actor->ModelBoneHeadPoint->StringSprite->Text;

        std::stringstream replacementText;

        int hpPercent = 0;

        if (spawn == playerSpawn)
        {
            uint32_t hpCurrent = spawn->HPCurrent;
            uint32_t hpMax     = spawn->HPMax;

            if (hpCurrent > 0 && hpMax > 0)
            {
                hpPercent = (hpCurrent * 100) / hpMax;
            }
        }
        else
        {
            hpPercent = spawn->HPCurrent;
        }

        if (spawn->Type == EQ_SPAWN_TYPE_PLAYER)
        {
            if (spawn == targetSpawn && (hpPercent > 0 && hpPercent < 100))
            {
                replacementText << hpPercent << "% - ";
            }

            replacementText << nameSpriteText;
        }
        else if (spawn->Type == EQ_SPAWN_TYPE_NPC)
        {
            replacementText << "[" << (int)spawn->Level << "] ";

            if (spawn == targetSpawn && (hpPercent > 0 && hpPercent < 100))
            {
                replacementText << hpPercent << "% - ";
            }

            replacementText << nameSpriteText;

            if (spawn->PetOwnerSpawnID != 0)
            {
                replacementText << "\n(Pet)";
            }

            if (spawn->Class == EQ_CLASS_BANKER)
            {
                replacementText << "\n(Banker)";
            }
            else if (spawn->Class == EQ_CLASS_MERCHANT)
            {
                replacementText << "\n(Merchant)";
            }
            else if (spawn->Class >= EQ_CLASS_GUILDMASTER_BEGIN && spawn->Class <= EQ_CLASS_GUILDMASTER_END)
            {
                replacementText << "\n(" << EQ_GetClassShortName(spawn->Class) << " Guildmaster)";
            }
        }

        auto fontTexture = EQ_GetStringSpriteFontTexture();

        EQ_CLASS_POINTER_CDisplay->ChangeDagStringSprite(spawn->Actor->ModelBoneHeadPoint, fontTexture, replacementText.str().c_str());
    }

    return true;
}