g_CombatAlternateAbilityIsEnabled = 1

g_CombatAlternateAbilityDistance = 25.0

function CombatAlternateAbility_Toggle()
    if g_CombatAlternateAbilityIsEnabled == 0 then
        g_CombatAlternateAbilityIsEnabled = 1
        EQ_PrintTextToChat("Combat Alternate Ability: On")
    else
        g_CombatAlternateAbilityIsEnabled = 0
        EQ_PrintTextToChat("Combat Alternate Ability: Off")
    end
end

function OnInterpretCommand(commandText)
    if commandText == "//CombatAlternateAbility" or commandText == "//CAA" then
        CombatAlternateAbility_Toggle()
        return 1
    end

    if commandText == "//CombatAlternateAbilityOn" or commandText == "//CAAOn" then
        if g_CombatAlternateAbilityIsEnabled == 0 then
            CombatAlternateAbility_Toggle()
            return 1
        end
    end

    if commandText == "//CombatAlternateAbilityOff" or commandText == "//CAAOff" then
        if g_CombatAlternateAbilityIsEnabled == 1 then
            CombatAlternateAbility_Toggle()
            return 1
        end
    end
end

function OnDrawHUD()
    if g_CombatAlternateAbilityIsEnabled == 1 then
        return 1, "- Combat Alternate Ability"
    end
end

function OnThreeSeconds()
    if g_CombatAlternateAbilityIsEnabled == 0 then
        return
    end

    if EQ_IsAutoAttackEnabled() == false then
        return
    end

    local targetSpawn = EQ_GetTargetSpawn()
    if targetSpawn == 0 then
        return
    end

    local targetSpawnType = EQ_GetSpawnType(targetSpawn)
    if targetSpawnType ~= EQ_SPAWN_TYPE_NPC then
        return
    end

    local targetSpawnDistance = EQ_GetSpawnDistance(targetSpawn)
    if targetSpawnDistance > g_CombatAlternateAbilityDistance then
        return
    end

    local targetSpawnLastName = EQ_GetSpawnLastName(targetSpawn)
    if targetSpawnLastName ~= "" then
        return
    end

    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    local playerSpawnLevel = EQ_GetSpawnLevel(playerSpawn)
    if playerSpawnLevel < 50 then
        return
    end

    local playerSpawnStandingState = EQ_GetSpawnStandingState(playerSpawn)
    if playerSpawnStandingState ~= EQ_STANDING_STATE_STANDING then
        return
    end

    local playerSpawnMovementSpeed = EQ_GetSpawnMovementSpeed(playerSpawn)
    if playerSpawnMovementSpeed > 0.0 then
        return
    end

    local playerSpawnZoneID = EQ_GetSpawnZoneID(playerSpawn)
    if EQ_IsZoneIDSafe(playerSpawnZoneID) == true then
        return
    end

    local targetSpawnHPPercent = EQ_GetSpawnHPPercent(targetSpawn)

    local playerSpawnHPPercent = EQ_GetSpawnHPPercent(playerSpawn)
    local playerSpawnEndurancePercent = EQ_GetSpawnEndurancePercent(playerSpawn)

    local playerSpawnClass = EQ_GetSpawnClass(playerSpawn)

    alternateAbilityList = {}

    if playerSpawnClass == EQ_CLASS_BARD then
        if targetSpawnHPPercent > 50 and targetSpawnHPPercent < 90 then
            if playerSpawnEndurancePercent > 75 then
                table.insert(alternateAbilityList, 199) -- Boastful Bellow
                table.insert(alternateAbilityList, 8201) -- Vainglorious Shout
            end

            table.insert(alternateAbilityList, 669) -- Bladed Song
            table.insert(alternateAbilityList, 553) -- Cacophony
            table.insert(alternateAbilityList, 359) -- Dance of Blades
            table.insert(alternateAbilityList, 3506) -- Fierce Eye
            table.insert(alternateAbilityList, 1420) -- Fundament First Spire of the Minstrels
            table.insert(alternateAbilityList, 777) -- Funeral Dirge
            table.insert(alternateAbilityList, 3702) -- Quick Time
            table.insert(alternateAbilityList, 544) -- Song of Stone
        end
    elseif playerSpawnClass == EQ_CLASS_BEASTLORD then
        if targetSpawnHPPercent > 50 and targetSpawnHPPercent < 90 then
            table.insert(alternateAbilityList, 362) -- Roar of Thunder
            table.insert(alternateAbilityList, 981) -- Attack of the Warders
            table.insert(alternateAbilityList, 127) -- Frenzy of Spirit
            table.insert(alternateAbilityList, 245) -- Bestial Alignment
            table.insert(alternateAbilityList, 11080) -- Chameleon Strike
            table.insert(alternateAbilityList, 1432) -- Fundament: Third Spire of the Savage
        end
    elseif playerSpawnClass == EQ_CLASS_BERSERKER then
        if targetSpawnHPPercent > 50 and targetSpawnHPPercent < 90 then
            table.insert(alternateAbilityList, 1109) -- Silent Strikes
            table.insert(alternateAbilityList, 109) -- Rampage
            table.insert(alternateAbilityList, 610) -- Blinding Fury
            table.insert(alternateAbilityList, 1142) -- Drawn to Blood
            table.insert(alternateAbilityList, 373) -- Desperation
            table.insert(alternateAbilityList, 800) -- Vehement Rage
            table.insert(alternateAbilityList, 1502) -- Fundament Third Spire of Savagery
            table.insert(alternateAbilityList, 961) -- Juggernaut Surge

            if playerSpawnHPPercent > 90 then
                table.insert(alternateAbilityList, 387) -- Blood Pact
                table.insert(alternateAbilityList, 465) -- Savage Spirit
                table.insert(alternateAbilityList, 374) -- Untamed Rage
            end
        end
    elseif playerSpawnClass == EQ_CLASS_CLERIC then
        if targetSpawnHPPercent > 50 and targetSpawnHPPercent < 90 then
            table.insert(alternateAbilityList, 254) -- Divine Avatar
            table.insert(alternateAbilityList, 391) -- Celestial Hammer
        end
    elseif playerSpawnClass == EQ_CLASS_DRUID then
        if targetSpawnHPPercent > 50 and targetSpawnHPPercent < 90 then
            table.insert(alternateAbilityList, 520) -- Natures Guardian
            table.insert(alternateAbilityList, 8603) -- Spirits of Nature
            table.insert(alternateAbilityList, 3728) -- Storm Strike
        end
    elseif playerSpawnClass == EQ_CLASS_ENCHANTER then
        if targetSpawnHPPercent > 45 then
            table.insert(alternateAbilityList, 753) -- Dreary Deeds
        end
    elseif playerSpawnClass == EQ_CLASS_MAGICIAN then
        if targetSpawnHPPercent > 50 and targetSpawnHPPercent < 90 then
            table.insert(alternateAbilityList, 8800) -- Force of Elements
            table.insert(alternateAbilityList, 174) -- Servant of Ro
            table.insert(alternateAbilityList, 207) -- Host of the Elements
            table.insert(alternateAbilityList, 1211) -- Focus of Arcanum
            table.insert(alternateAbilityList, 1041) -- Malosinete
            table.insert(alternateAbilityList, 785) -- Heart of Vapor
        end
    elseif playerSpawnClass == EQ_CLASS_RANGER then
        if targetSpawnHPPercent > 50 and targetSpawnHPPercent < 90 then
            table.insert(alternateAbilityList, 874) -- Pack Hunt
            table.insert(alternateAbilityList, 462) -- Auspice of the Hunter
            table.insert(alternateAbilityList, 184) -- Guardian of the Forest
            table.insert(alternateAbilityList, 872) -- Outrider's Attack
            table.insert(alternateAbilityList, 3804) -- Outrider's Accuracy
            table.insert(alternateAbilityList, 2235) -- Imbued Ferocity
        end
    elseif playerSpawnClass == EQ_CLASS_SHADOWKNIGHT then
        if targetSpawnHPPercent > 50 and targetSpawnHPPercent < 90 then
            --table.insert(alternateAbilityList, 9403) -- Visage of Death
            --table.insert(alternateAbilityList,) -- 
        end
    elseif playerSpawnClass == EQ_CLASS_SHAMAN then
        if targetSpawnHPPercent > 45 then
            --table.insert(alternateAbilityList, 856) -- Tigir's Insect Swarm (AOE, 50% slow)
            table.insert(alternateAbilityList, 3729) -- Turgur's Swarm (Target, 75% slow)
        end
        if targetSpawnHPPercent > 50 and targetSpawnHPPercent < 90 then
            table.insert(alternateAbilityList, 861) -- Languid Bite
            table.insert(alternateAbilityList, 177) -- Spirit Call
            table.insert(alternateAbilityList, 50) -- Rabid Bear
            table.insert(alternateAbilityList, 148) -- Malosinete
            table.insert(alternateAbilityList, 857) -- Dampen Resistance
            table.insert(alternateAbilityList, 1492) -- Fundament: Third Spire of the Ancestors
        end
    elseif playerSpawnClass == EQ_CLASS_WARRIOR then
        if targetSpawnHPPercent > 10 then
            table.insert(alternateAbilityList, 3646) -- Blast of Anger
            table.insert(alternateAbilityList, 552) -- Call of Challenge
            table.insert(alternateAbilityList, 3732) -- Gut Punch
            table.insert(alternateAbilityList, 801) -- Knee Strike
            table.insert(alternateAbilityList, 10367) -- Ageless Enmity
            table.insert(alternateAbilityList, 800) -- Vehement Rage
            table.insert(alternateAbilityList, 912) -- Warlords Fury
            table.insert(alternateAbilityList, 131) -- Rage of Rallos Zek
        end
    end

    for _, alternateAbility in ipairs(alternateAbilityList) do
        EQ_UseAlternateAbility(alternateAbility)
    end
end
