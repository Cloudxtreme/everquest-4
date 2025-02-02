g_PriestBotIsEnabled = 0

g_PriestBotTargetName = "Skaj"

function PriestBot_Toggle()
    if g_PriestBotIsEnabled == 0 then
        g_PriestBotIsEnabled = 1
        EQ_PrintTextToChat("Priest Bot: On")
        EQ_ClearTarget()
    else
        g_PriestBotIsEnabled = 0
        EQ_PrintTextToChat("Priest Bot: Off")
    end

    return 1
end

function PriestBot_BigHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Target " .. g_PriestBotTargetName)
    EQ_InterpretCommand("//Cast 1")
end

function PriestBot_FastHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Target " .. g_PriestBotTargetName)
    EQ_InterpretCommand("//Cast 3")
end

function PriestBot_InstantHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Target " .. g_PriestBotTargetName)
    EQ_InterpretCommand("//Cast 4")
end

function PriestBot_SaveHeal()
    EQ_InterpretCommand("//StopFollow")
    EQ_InterpretCommand("//Target " .. g_PriestBotTargetName)
    EQ_InterpretCommand("//Cast 7")
end

function OnInterpretCommand(commandText)
    if commandText == "//PriestBot" then
        PriestBot_Toggle()
        return 1
    end

    if commandText == "//PriestBotOn" then
        if g_PriestBotIsEnabled == 0 then
            PriestBot_Toggle()
        end
        return 1
    end

    if commandText == "//PriestBotOff" then
        if g_PriestBotIsEnabled == 1 then
            PriestBot_Toggle()
        end
        return 1
    end

    if String_BeginsWith(commandText, "//PriestBotTarget ") == true then
        local tokens = String_Split(commandText, " ")

        if tokens[2] ~= nil then
            g_PriestBotTargetName = tokens[2]

            EQ_PrintTextToChat("Priest Bot Target: " .. g_PriestBotTargetName)
        end

        return 1
    end
end

function OnDrawHUD()
    if g_PriestBotIsEnabled == 1 then
        return 1, "- Priest Bot: " .. g_PriestBotTargetName
    end
end

function OnFrame()
    if g_PriestBotIsEnabled == 0 then
        return
    end

    local playerSpawn = EQ_GetPlayerSpawn()
    if playerSpawn == 0 then
        return
    end

    local targetSpawn = EQ_GetTargetSpawn()
    if targetSpawn == playerSpawn then
        return
    end

    if targetSpawn ~= 0 then
        local targetType = EQ_GetSpawnType(targetSpawn)
        if targetType ~= EQ_SPAWN_TYPE_PLAYER then
            return
        end
    end

    EQ_InterpretCommand("//Target " .. g_PriestBotTargetName)

    targetSpawn = EQ_GetTargetSpawn()
    if targetSpawn == 0 then
        return
    end

    local targetHP = EQ_GetSpawnHPCurrent(targetSpawn)
    if targetHP > 0 then
        local playerHP = EQ_GetSpawnHPCurrent(playerSpawn)

        math.randomseed(os.time() + playerHP)

        local fastHealHP = math.random(80, 90)

        if targetHP <= 35 then
            PriestBot_SaveHeal()
            PriestBot_InstantHeal()
        elseif targetHP <= 50 then
            PriestBot_InstantHeal()
            PriestBot_FastHeal()
        elseif targetHP <= fastHealHP then
            --EQ_InterpretCommand("/tell " .. g_PriestBotTargetName .. " I am fast healing you because you are at " .. fastHealHP .. "% health.")
            PriestBot_FastHeal()
            PriestBot_BigHeal()
        end
    end
end
