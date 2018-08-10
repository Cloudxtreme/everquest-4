g_PriestBot2IsEnabled = 0

function PriestBot2_Toggle()
    if g_PriestBot2IsEnabled == 0 then
        g_PriestBot2IsEnabled = 1
        EQ_PrintTextToChat("Priest Bot 2: On")
    else
        g_PriestBot2IsEnabled = 0
        EQ_PrintTextToChat("Priest Bot 2: Off")
    end

    return 1
end

function PriestBot2_BigHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 1")
end

function PriestBot2_FastHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 3")
end

function PriestBot2_InstantHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 4")
end

function PriestBot2_SaveHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Cast 7")
end

function OnInterpretCommand(commandText)
    if commandText == "//PriestBot2" then
        PriestBot2_Toggle()
        return 1
    end

    if commandText == "//PriestBot2On" then
        if g_PriestBotIsEnabled == 0 then
            PriestBot_Toggle()
            return 1
        end
    end

    if commandText == "//PriestBot2Off" then
        if g_PriestBot2IsEnabled == 1 then
            PriestBot2_Toggle()
            return 1
        end
    end
end

function OnDrawHUD()
    if g_PriestBot2IsEnabled == 1 then
        return 1, "- Priest Bot 2"
    end
end

function OnFrame()
    if g_PriestBot2IsEnabled == 0 then
        return
    end

    local targetSpawn = EQ_GetTargetSpawn()
    if targetSpawn == 0 then
        return
    end

    local targetType = EQ_GetSpawnType(targetSpawn)
    if targetType ~= EQ_SPAWN_TYPE_PLAYER then
        return
    end

    local targetHP = EQ_GetSpawnHPCurrent(targetSpawn)
    if targetHP > 0 then
        local playerSpawn = EQ_GetPlayerSpawn()
        if playerSpawn == 0 then
            return
        end

        local playerHP = EQ_GetSpawnHPCurrent(playerSpawn)

        math.randomseed(os.time() + playerHP)

        local fastHealHP = math.random(80, 90)

        if targetHP <= 35 then
            PriestBot2_SaveHeal()
            PriestBot2_InstantHeal()
        elseif targetHP <= 50 then
            PriestBot2_InstantHeal()
            PriestBot2_FastHeal()
        elseif targetHP <= fastHealHP then
            --EQ_InterpretCommand("/tell " .. g_PriestBotTargetName .. " I am fast healing you because you are at " .. fastHealHP .. "% health.")
            PriestBot2_FastHeal()
            PriestBot2_BigHeal()
        end
    end
end
