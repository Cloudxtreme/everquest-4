#pragma once

bool g_itemDisplayWindowIsEnabled = true;

bool g_itemDisplayWindowItemsIsEnabled = true;
bool g_itemDisplayWindowSpellsIsEnabled = true;

void EQAPP_ItemDisplayWindow_HandleEvent_CItemDisplayWnd__SetItem(void* this_ptr, EQ::Item_ptr item, bool unknown);
void EQAPP_ItemDisplayWindow_HandleEvent_CItemDisplayWnd__SetSpell(void* this_ptr, uint16_t spellID, bool hasDescription, int unknown);

void EQAPP_ItemDisplayWindow_HandleEvent_CItemDisplayWnd__SetItem(void* this_ptr, EQ::Item_ptr item, bool unknown)
{
    if (item == NULL || EQ_POINTER_CItemDisplayWnd->DisplayText == NULL)
    {
        return;
    }

    if (EQ_POINTER_CItemDisplayWnd->DisplayText->Length == 0)
    {
        return;
    }

    std::string itemName = item->Name;
    if (itemName.size() == 0)
    {
        return;
    }

    std::stringstream itemFilename;
    itemFilename << "items/" << item->ID << ".txt";

    std::string itemFileContents = EQAPP_ReadFileContents(itemFilename.str().c_str());
    if (itemFileContents.size() != 0)
    {
        std::stringstream itemFileText;
        itemFileText << "<BR>" << itemFileContents << "<BR>";

        EQ_CXStr_Append(&EQ_POINTER_CItemDisplayWnd->DisplayText, itemFileText.str().c_str());
    }

    EQ_CXStr_Append(&EQ_POINTER_CItemDisplayWnd->DisplayText, "<BR><c \"#FF00FF\">");

    std::stringstream ssItemIDText;
    ssItemIDText << "ID: " << item->ID << " (0x" << std::hex << item->ID << std::dec << ")<BR>";

    EQ_CXStr_Append(&EQ_POINTER_CItemDisplayWnd->DisplayText, ssItemIDText.str().c_str());

    std::stringstream buffer;

    if (item->Cost > 0)
    {
        std::string itemCostString = EQ_GetItemCostString(item->Cost);

        buffer.str(std::string());
        buffer << "Vendors for: " << itemCostString << "<BR>";

        EQ_CXStr_Append(&EQ_POINTER_CItemDisplayWnd->DisplayText, buffer.str().c_str());
    }

    if (item->IsContainer == 0)
    {
        uint16_t itemSpellID = item->Common.SpellID;
        if (itemSpellID != 0 && itemSpellID != EQ_SPELL_ID_NULL)
        {
            auto spell = EQ_GetSpellByID(itemSpellID);
            if (spell != NULL)
            {
                buffer.str(std::string());
                buffer << "Spell ID: " << spell->ID << " (" << spell->Name << ")<BR>";

                EQ_CXStr_Append(&EQ_POINTER_CItemDisplayWnd->DisplayText, buffer.str().c_str());
            }

            if (itemSpellID == EQ_SPELL_ID_HASTE)
            {
                buffer.str(std::string());
                buffer << "Haste: " << (int)((item->Common.Haste) + 1) << "%<BR>";

                EQ_CXStr_Append(&EQ_POINTER_CItemDisplayWnd->DisplayText, buffer.str().c_str());
            }
            else
            {
                buffer.str(std::string());

                if (item->Common.EffectFlag == EQ_ITEM_EFFECT_FLAG_COMBAT)
                {
                    buffer << "Procs at Level: " << (int)item->Common.CastingLevel << "<BR>";
                }
                else if (item->Common.EffectFlag == EQ_ITEM_EFFECT_FLAG_WORN)
                {
                    buffer << "Effective at Level: " << (int)item->Common.CastingLevel << "<BR>";
                }
                else if (item->Common.EffectFlag == EQ_ITEM_EFFECT_FLAG_MUST_EQUIP)
                {
                    buffer << "Cast at Level: " << (int)item->Common.CastingLevel << "<BR>";
                }

                EQ_CXStr_Append(&EQ_POINTER_CItemDisplayWnd->DisplayText, buffer.str().c_str());
            }
        }

        if ((itemName.find("Spell:") != std::string::npos) || (itemName.find("Ancient:") != std::string::npos)|| (itemName.find("Song:") != std::string::npos))
        {
            if (itemSpellID != EQ_SPELL_ID_NULL)
            {
                auto spellBookIndex = EQ_GetSpellBookSpellIndexBySpellID(itemSpellID);
                if (spellBookIndex != -1)
                {
                    buffer.str(std::string());
                    buffer << "This spell is already scribed in your spell book.<BR>";

                    EQ_CXStr_Append(&EQ_POINTER_CItemDisplayWnd->DisplayText, buffer.str().c_str());
                }
            }
        }
    }

    EQ_CXStr_Append(&EQ_POINTER_CItemDisplayWnd->DisplayText, "</c>");

    if (item->IsContainer == 0)
    {
        uint16_t itemSpellID = item->Common.SpellID;
        if (itemSpellID != 0 && itemSpellID != EQ_SPELL_ID_NULL)
        {
            auto spell = EQ_GetSpellByID(itemSpellID);
            if (spell != NULL)
            {
                std::stringstream spellFilename;
                spellFilename << "spells/" << spell->ID << ".txt";

                std::string spellFileContents = EQAPP_ReadFileContents(spellFilename.str().c_str());
                if (spellFileContents.size() != 0)
                {
                    std::stringstream spellFileText;
                    spellFileText << "<BR><c \"#FFFF00\">" << spell->Name << "</c><BR>" << spellFileContents << "<BR>";

                    EQ_CXStr_Append(&EQ_POINTER_CItemDisplayWnd->DisplayText, spellFileText.str().c_str());
                }
            }
        }
    }
}

void EQAPP_ItemDisplayWindow_HandleEvent_CItemDisplayWnd__SetSpell(void* this_ptr, uint16_t spellID, bool hasDescription, int unknown)
{
    if (spellID == EQ_SPELL_ID_NULL)
    {
        return;
    }

    auto spell = EQ_POINTER_SpellList->Spell[spellID];

    if (spell == NULL || EQ_POINTER_CItemDisplayWnd->DisplayText == NULL)
    {
        return;
    }

    std::stringstream spellFilename;
    spellFilename << "spells/" << spell->ID << ".txt";

    std::string spellFileContents = EQAPP_ReadFileContents(spellFilename.str().c_str());
    if (spellFileContents.size() != 0)
    {
        std::stringstream spellFileText;
        spellFileText << "<BR>" << spellFileContents << "<BR>";

        EQ_CXStr_Append(&EQ_POINTER_CItemDisplayWnd->DisplayText, spellFileText.str().c_str());
    }

    EQ_CXStr_Append(&EQ_POINTER_CItemDisplayWnd->DisplayText, "<BR><c \"#FF00FF\">");

    std::stringstream ssSpellIDText;
    ssSpellIDText << "ID: " << spell->ID << " (0x" << std::hex << spell->ID << std::dec << ")<BR>";

    EQ_CXStr_Append(&EQ_POINTER_CItemDisplayWnd->DisplayText, ssSpellIDText.str().c_str());

    std::stringstream buffer;

    if (spell->RecastTime > 0)
    {
        float spellRecastTime = (float)(spell->RecastTime / 1000);

        buffer.str(std::string());
        buffer << "Recast Time: " << std::fixed << std::setprecision(1) << spellRecastTime << "<BR>";

        EQ_CXStr_Append(&EQ_POINTER_CItemDisplayWnd->DisplayText, buffer.str().c_str());
    }

    if (spell->RecoveryTime > 0)
    {
        float spellRecoveryTime = (float)(spell->RecoveryTime / 1000);

        buffer.str(std::string());
        buffer << "Recovery Time: " << std::fixed << std::setprecision(1) << spellRecoveryTime << "<BR>";

        EQ_CXStr_Append(&EQ_POINTER_CItemDisplayWnd->DisplayText, buffer.str().c_str());
    }

    if (spell->Range > 0.0f)
    {
        buffer.str(std::string());
        buffer << "Range: " << std::fixed << std::setprecision(1) << spell->Range << "<BR>";

        EQ_CXStr_Append(&EQ_POINTER_CItemDisplayWnd->DisplayText, buffer.str().c_str());
    }

    if (spell->AOERange > 0.0f)
    {
        buffer.str(std::string());
        buffer << "AOE Range: " << std::fixed << std::setprecision(1) << spell->AOERange << "<BR>";

        EQ_CXStr_Append(&EQ_POINTER_CItemDisplayWnd->DisplayText, buffer.str().c_str());
    }

    if (spell->Duration > 0)
    {
        std::string spellDuration = EQ_GetTickTimeString(spell->Duration);

        buffer.str(std::string());
        buffer << "Duration: " << spellDuration << "<BR>";

        EQ_CXStr_Append(&EQ_POINTER_CItemDisplayWnd->DisplayText, buffer.str().c_str());
    }

    if (spell->AOEDuration > 0)
    {
        std::string spellAOEDuration = EQ_GetTickTimeString(spell->AOEDuration);

        buffer.str(std::string());
        buffer << "AOE Duration: " << spellAOEDuration << "<BR>";

        EQ_CXStr_Append(&EQ_POINTER_CItemDisplayWnd->DisplayText, buffer.str().c_str());
    }

    if (spell->DurationFormula > 0)
    {
        buffer.str(std::string());
        buffer << "Duration Formula: " << spell->DurationFormula << "<BR>";

        EQ_CXStr_Append(&EQ_POINTER_CItemDisplayWnd->DisplayText, buffer.str().c_str());
    }

    EQ_CXStr_Append(&EQ_POINTER_CItemDisplayWnd->DisplayText, "</c>");
}
