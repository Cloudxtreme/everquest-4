#pragma once

#include <cstdint>

#include <string>
#include <unordered_map>

#include "eq_cxwnd.h"
#include "eq_constants.h"

uint32_t EQ_ADDRESS_WindowHWND = 0x0; // HWND hWnd    in IDA press G, jump to address: hWnd

uint32_t EQ_ADDRESS_AutoAttack    = 0x0; // uint8_t    /attack
uint32_t EQ_ADDRESS_AutoFire      = 0x0; // uint8_t
uint32_t EQ_ADDRESS_AutoRun       = 0x0; // uint32_t
uint32_t EQ_ADDRESS_MouseLook     = 0x0; // uint8_t    holding down right-click to look around
uint32_t EQ_ADDRESS_NetStatus     = 0x0; // uint8_t    byte_F30435 = sub_9CFF30("Defaults", "NetStat", 0, 0); // 0xF30435
/*
search for 1 and 0
*/

uint32_t EQ_ADDRESS_EQZoneInfo = 0x0; // struct

uint32_t EQ_ADDRESS_FUNCTION_CollisionCallbackForActors = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CastRay = 0x0; // called by CastRay2 function
uint32_t EQ_ADDRESS_FUNCTION_CastRay2 = 0x0; // CCollisionInfoLineSegmentVisibility::`vftable'
uint32_t EQ_ADDRESS_FUNCTION_DrawNetStatus = 0x0; // "%ldms"    "%0.2f%%"
uint32_t EQ_ADDRESS_FUNCTION_ExecuteCmd = 0x0; // "ExecuteCmd has received a CMD_EXITGAME.\n"    "/%s %s"    "%c%s %s "    "help.html"
uint32_t EQ_ADDRESS_FUNCTION_DoSpellEffect= 0x0;
uint32_t EQ_ADDRESS_FUNCTION_PlaySoundAtLocation= 0x0;
uint32_t EQ_ADDRESS_FUNCTION_GetTime= 0x0;
uint32_t EQ_ADDRESS_FUNCTION_UpdateLight = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_GetGaugeValueFromEQ = 0x0;

// class EQPlayer
uint32_t EQ_ADDRESS_POINTER_ControlledSpawn    = 0x0;
uint32_t EQ_ADDRESS_POINTER_PlayerSpawn        = 0x0; // pinstLocalPlayer    "Local Player's World location at time of crash: %f, %f, %f.\n"
uint32_t EQ_ADDRESS_POINTER_TargetSpawn        = 0x0; // pinstTarget    ExecuteCmd() case CLEAR_TARGET

// class StringTable
uint32_t EQ_ADDRESS_POINTER_StringTable = 0x0;

uint32_t EQ_ADDRESS_FUNCTION_StringTable__getString = 0x0;

// class CDBStr
uint32_t EQ_ADDRESS_POINTER_CDBStr = 0x0;

uint32_t EQ_ADDRESS_FUNCTION_CDBStr__GetString = 0x0;

// class EQ_Character
uint32_t EQ_ADDRESS_POINTER_EQ_Character = 0x0;

uint32_t EQ_ADDRESS_FUNCTION_EQ_Character__encum_factor = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQ_Character__TakeFallDamage = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQ_Character__CanIBreathe = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQ_Character__CanISeeInvis = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQ_Character__StunMe = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQ_Character__UnStunMe = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQ_Character__ProcessEnvironment = 0x0;

// class CharacterZoneClient
uint32_t EQ_ADDRESS_FUNCTION_CharacterZoneClient__SetNoGrav = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CharacterZoneClient__TotalSpellAffects = 0x0;

// class EQ_PC
uint32_t EQ_ADDRESS_POINTER_EQ_PC = 0x0;

uint32_t EQ_ADDRESS_FUNCTION_EQ_PC__DestroyHeldItemOrMoney = 0x0;

// manager for class EQPlayer
uint32_t EQ_ADDRESS_POINTER_EQPlayerManager = 0x0; // pinstSpawnManager

uint32_t EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID = 0x0; // "Your inventory is full!"
uint32_t EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName = 0x0; // "Incorrect Usage. Type /xtarget for correct usage."

uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight = 0x0; // PlayerZoneClient__ChangeHeight    "%s is now able to kill anyone (or be killed) as if they were an NPC." and "FORMAT: /becomenpc"
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__ChangePosition = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__GetLevel = 0x0; // (Lvl: %d)
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__GetActorClient = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__TurnOffAutoFollow = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__IsTargetable = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteState = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteTint = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__ChangeLight = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQPlayer__push_along_heading = 0x0;

uint32_t EQ_ADDRESS_POINTER_EQSwitchManager = 0x0;

uint32_t EQ_ADDRESS_FUNCTION_EQSwitch__UseSwitch = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_EQSwitch__ChangeState = 0x0;

// class EQSpell
uint32_t EQ_ADDRESS_FUNCTION_EQSpell__SpellAffects = 0x0;

// class CXWndManager
uint32_t EQ_ADDRESS_POINTER_CXWndManager = 0x0; // pinstCXWndManager

uint32_t EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows = 0x0; // "DoAllDrawing() failed\n"    GetTickCount()

// class CXWnd
uint32_t EQ_ADDRESS_FUNCTION_CXWnd__IsReallyVisible = 0x0;

// class CEverQuest
uint32_t EQ_ADDRESS_POINTER_CEverQuest = 0x0; // pinstCEverQuest

uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone = 0x0; // "Initializing world."    "Zone initialized."
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd = 0x0; // "#%s %s"
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat = 0x0; // "You cannot purchase an item from yourself!"
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__HandleMouseWheel = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__SendNewText = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CEverQuest__DropHeldItemOnGround = 0x0;

uint32_t EQ_ADDRESS_POINTER_CDisplay = 0x0; // pinstCDisplay    "CDisplay::CreatePlayerActor - FATAL ERROR - mySpriteDef is NULL. "

uint32_t EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2 = 0x0; // "%ldms"    "%0.2f%%"
uint32_t EQ_ADDRESS_FUNCTION_CDisplay__CreateActor = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CDisplay__GetIntensity = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CDisplay__CreateLight = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CDisplay__DeleteLight = 0x0;

uint32_t EQ_ADDRESS_POINTER_CCamera = 0x0; // calculated at runtime

uint32_t EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation = 0x0; // calculated at runtime

uint32_t EQ_ADDRESS_POINTER_CRender = 0x0; // __DrawHandler_x    "ResetDevice() failed!" CRender+0x64()    EQ_LoadingS__SetProgressBar() "%s..."    CDisplay__WriteTextHD2() follow draw text functions

uint32_t EQ_ADDRESS_FUNCTION_CRender__ResetDevice = 0x0; // calculated at runtime
uint32_t EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack = 0x0; // calculated at runtime
uint32_t EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene = 0x0; // calculated at runtime
uint32_t EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay = 0x0; // calculated at runtime

uint32_t EQ_ADDRESS_POINTER_CAlertWnd = 0x0;

uint32_t EQ_ADDRESS_POINTER_CSpellBookWnd = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft = 0x0;
uint32_t EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellScribeTicksLeft = 0x0;

uint32_t EQ_ADDRESS_FUNCTION_IDirect3DDevice9__DrawIndexedPrimitive = 0x0;

void EQ_InitializeAddresses();

void EQ_InitializeAddresses()
{
#ifdef EQ_TEST_SERVER
    // Jul 12 2019 11:24:59

    EQ_SIZE_CXWnd = 0x1E0;
    EQ_SIZE_CSidlScreenWnd = 0x228;

    EQ_OFFSET_SPAWN_STANDING_STATE             = 0x3b8;
    EQ_OFFSET_SPAWN_FOLLOW_SPAWN               = 0xf34;
    EQ_OFFSET_SPAWN_HP_CURRENT                 = 0x250;
    EQ_OFFSET_SPAWN_HP_MAX                     = 0x3c8;
    EQ_OFFSET_SPAWN_MANA_CURRENT               = 0x5fc;
    EQ_OFFSET_SPAWN_MANA_MAX                   = 0x608;
    EQ_OFFSET_SPAWN_ENDURANCE_CURRENT          = 0x5f4;
    EQ_OFFSET_SPAWN_ENDURANCE_MAX              = 0x3d4;
    EQ_OFFSET_SPAWN_CharacterZoneClient        = 0x4f0;
    EQ_OFFSET_EQ_Character____CharacterBase    = 0x284c;
    EQ_OFFSET_CharInfo2__Bandolier             = 0x7434;

    EQ_ADDRESS_WindowHWND = 0x00F41154;

    EQ_ADDRESS_AutoAttack    = 0x00F3B55B;
    EQ_ADDRESS_AutoFire      = 0x00F3B55C;
    EQ_ADDRESS_AutoRun       = 0x00E9C8C8;
    EQ_ADDRESS_MouseLook     = 0x00E9C8AA;
    EQ_ADDRESS_NetStatus     = 0x00E9C8AD;

    EQ_ADDRESS_EQZoneInfo = 0x00E9CAA0;

    EQ_ADDRESS_POINTER_ControlledSpawn    = 0x00E8CCA8;
    EQ_ADDRESS_POINTER_PlayerSpawn        = 0x00E8CC50;
    EQ_ADDRESS_POINTER_TargetSpawn        = 0x00E8CCA4;

    EQ_ADDRESS_FUNCTION_CollisionCallbackForActors    = 0x0051DB20;
    EQ_ADDRESS_FUNCTION_CastRay                       = 0x0059C280;
    EQ_ADDRESS_FUNCTION_CastRay2                      = 0x0059C2D0;
    EQ_ADDRESS_FUNCTION_DrawNetStatus                 = 0x006289F0;
    EQ_ADDRESS_FUNCTION_ExecuteCmd                    = 0x00594B50;
    EQ_ADDRESS_FUNCTION_DoSpellEffect                 = 0x005FADE0;
    EQ_ADDRESS_FUNCTION_PlaySoundAtLocation           = 0x00539F90;
    EQ_ADDRESS_FUNCTION_GetTime                       = 0x008F1D00;
    EQ_ADDRESS_FUNCTION_UpdateLight                   = 0x005B9840;
    EQ_ADDRESS_FUNCTION_GetGaugeValueFromEQ           = 0x008040D0;

    EQ_ADDRESS_POINTER_StringTable = 0x00E8F3C8;
    EQ_ADDRESS_FUNCTION_StringTable__getString    = 0x008B8180;

    EQ_ADDRESS_POINTER_CDBStr = 0x00DDA3CC;
    EQ_ADDRESS_FUNCTION_CDBStr__GetString    = 0x0052F8F0;

    EQ_ADDRESS_POINTER_EQ_Character = 0x00E8F11C;
    EQ_ADDRESS_FUNCTION_EQ_Character__encum_factor          = 0x004D0E70;
    EQ_ADDRESS_FUNCTION_EQ_Character__TakeFallDamage        = 0x004D8E60;
    EQ_ADDRESS_FUNCTION_EQ_Character__CanIBreathe           = 0x004DDBB0;
    EQ_ADDRESS_FUNCTION_EQ_Character__CanISeeInvis          = 0x004DEA40;
    EQ_ADDRESS_FUNCTION_EQ_Character__StunMe                = 0x004D35D0;
    EQ_ADDRESS_FUNCTION_EQ_Character__UnStunMe              = 0x004D36F0;
    EQ_ADDRESS_FUNCTION_EQ_Character__ProcessEnvironment    = 0x004DE8F0;
    EQ_ADDRESS_FUNCTION_EQ_Character__TotalSpellAffects     = 0x004C2920;

    EQ_ADDRESS_FUNCTION_CharacterZoneClient__SetNoGrav    = 0x004B8E60;

    EQ_ADDRESS_POINTER_EQ_PC = 0x00E8F11C;
    EQ_ADDRESS_FUNCTION_EQ_PC__DestroyHeldItemOrMoney    = 0x00637150;

    EQ_ADDRESS_POINTER_EQPlayerManager = 0x00F3E748;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID      = 0x00651420;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName    = 0x006514D0;

    EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight          = 0x006592E0;
    EQ_ADDRESS_FUNCTION_EQPlayer__ChangePosition        = 0x00659D10;
    EQ_ADDRESS_FUNCTION_EQPlayer__GetLevel              = 0x0065B890;
    EQ_ADDRESS_FUNCTION_EQPlayer__GetActorClient        = 0x00592BC0;
    EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI        = 0x00644F30;
    EQ_ADDRESS_FUNCTION_EQPlayer__TurnOffAutoFollow     = 0x00645250;
    EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot        = 0x0064AF10;
    EQ_ADDRESS_FUNCTION_EQPlayer__IsTargetable          = 0x0098B890;
    EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteState    = 0x00646330;
    EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteTint     = 0x00647200;
    EQ_ADDRESS_FUNCTION_EQPlayer__ChangeLight           = 0x0064D840;
    EQ_ADDRESS_FUNCTION_EQPlayer__push_along_heading    = 0x005C7E20;

    EQ_ADDRESS_POINTER_EQSwitchManager = 0x00E8C970;
    EQ_ADDRESS_FUNCTION_EQSwitch__UseSwitch      = 0x005CC8F0;
    EQ_ADDRESS_FUNCTION_EQSwitch__ChangeState    = 0x005CCDD0;

    EQ_ADDRESS_FUNCTION_EQSpell__SpellAffects    = 0x004B84A0;

    EQ_ADDRESS_POINTER_CXWndManager = 0x016D8198;
    EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows    = 0x00928D00;

    EQ_ADDRESS_FUNCTION_CXWnd__IsReallyVisible    = 0x00924CD0;

    EQ_ADDRESS_POINTER_CEverQuest = 0x0104B19C;
    EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert        = 0x005EA3D0;
    EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone               = 0x005E4BC0;
    EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd            = 0x005F88D0;
    EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat                = 0x004E6400;
    EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState            = 0x005D1260;
    EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp                = 0x005D3A40;
    EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp                = 0x005D49D0;
    EQ_ADDRESS_FUNCTION_CEverQuest__HandleMouseWheel        = 0x005D50B0;
    EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting            = 0x005DEBE0;
    EQ_ADDRESS_FUNCTION_CEverQuest__SendNewText             = 0x005DF900;
    EQ_ADDRESS_FUNCTION_CEverQuest__DropHeldItemOnGround    = 0x005D14D0;

    EQ_ADDRESS_POINTER_CDisplay = 0x0E8F3BC;
    EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2         = 0x00534D10;
    EQ_ADDRESS_FUNCTION_CDisplay__CreateActor          = 0x00537DE0;
    EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor    = 0x00533940;
    EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor          = 0x00537D50;
    EQ_ADDRESS_FUNCTION_CDisplay__GetIntensity         = 0x00534C80;
    EQ_ADDRESS_FUNCTION_CDisplay__CreateLight          = 0x00538400;
    EQ_ADDRESS_FUNCTION_CDisplay__DeleteLight          = 0x005383D0;

    //EQ_ADDRESS_POINTER_CCamera = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation    = 0x0; // calculated at runtime

    EQ_ADDRESS_POINTER_CRender = 0x016D8FD8;
    //EQ_ADDRESS_FUNCTION_CRender__ResetDevice    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay         = 0x0; // calculated at runtime

    EQ_ADDRESS_POINTER_CAlertWnd = 0x0DDAADC;

    EQ_ADDRESS_POINTER_CSpellBookWnd = 0x00DDAAA4;
    EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft       = 0x007FC7E0;
    EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellScribeTicksLeft    = 0x007FC940;
#else
    // Aug 15 2019 14:36:17

    EQ_SIZE_CXWnd = 0x1D8;
    EQ_SIZE_CSidlScreenWnd = 0x220;

    EQ_OFFSET_SPAWN_STANDING_STATE             = 0x216;
    EQ_OFFSET_SPAWN_FOLLOW_SPAWN               = 0xf24;
    EQ_OFFSET_SPAWN_HP_CURRENT                 = 0x3b8;
    EQ_OFFSET_SPAWN_HP_MAX                     = 0x438;
    EQ_OFFSET_SPAWN_MANA_CURRENT               = 0x210;
    EQ_OFFSET_SPAWN_MANA_MAX                   = 0x200;
    EQ_OFFSET_SPAWN_ENDURANCE_CURRENT          = 0x480;
    EQ_OFFSET_SPAWN_ENDURANCE_MAX              = 0x324;
    EQ_OFFSET_SPAWN_CharacterZoneClient        = 0x2d8;
    EQ_OFFSET_EQ_Character____CharacterBase    = 0x284c;
    EQ_OFFSET_CharInfo2__Bandolier             = 0x7434;

    EQ_ADDRESS_WindowHWND = 0x00F4365C;

    EQ_ADDRESS_AutoAttack              = 0x00F3DA63;
    EQ_ADDRESS_AutoFire                = 0x00F3DA64;
    EQ_ADDRESS_AutoRun                 = 0x00E9EDD0;
    EQ_ADDRESS_MouseLook               = 0x00E9EDB2;
    EQ_ADDRESS_NetStatus               = 0x00E9EDB5;

    EQ_ADDRESS_EQZoneInfo = 0x00E9EFA8;

    EQ_ADDRESS_POINTER_ControlledSpawn    = 0x00E8F3A0;
    EQ_ADDRESS_POINTER_PlayerSpawn        = 0x00E8F348;
    EQ_ADDRESS_POINTER_TargetSpawn        = 0x00E8F39C;

    EQ_ADDRESS_FUNCTION_CollisionCallbackForActors    = 0x0051DB50;
    EQ_ADDRESS_FUNCTION_CastRay                       = 0x0059D150;
    EQ_ADDRESS_FUNCTION_CastRay2                      = 0x0059D1A0;
    EQ_ADDRESS_FUNCTION_DrawNetStatus                 = 0x006291C0;
    EQ_ADDRESS_FUNCTION_ExecuteCmd                    = 0x00595A50;
    EQ_ADDRESS_FUNCTION_DoSpellEffect                 = 0x005FB9A0;
    EQ_ADDRESS_FUNCTION_PlaySoundAtLocation           = 0x0053B350;
    EQ_ADDRESS_FUNCTION_GetTime                       = 0x008F3840;
    EQ_ADDRESS_FUNCTION_UpdateLight                   = 0x005BA720;
    EQ_ADDRESS_FUNCTION_GetGaugeValueFromEQ           = 0x00805EA0;
    //EQ_ADDRESS_FUNCTION_get_bearing                   = 0x0059CCA0;
    //EQ_ADDRESS_FUNCTION_get_melee_range               = 0x0059D390;

    EQ_ADDRESS_POINTER_StringTable = 0x00E8EFCC;
    EQ_ADDRESS_FUNCTION_StringTable__getString    = 0x008B9B40;

    EQ_ADDRESS_POINTER_CDBStr = 0x00DDC8CC;
    EQ_ADDRESS_FUNCTION_CDBStr__GetString    = 0x00530CB0;

    EQ_ADDRESS_POINTER_EQ_Character = 0x00E9148C;
    EQ_ADDRESS_FUNCTION_EQ_Character__encum_factor          = 0x004D1340;
    EQ_ADDRESS_FUNCTION_EQ_Character__TakeFallDamage        = 0x004D9330;
    EQ_ADDRESS_FUNCTION_EQ_Character__CanIBreathe           = 0x004DE080;
    EQ_ADDRESS_FUNCTION_EQ_Character__CanISeeInvis          = 0x004DEF10;
    EQ_ADDRESS_FUNCTION_EQ_Character__StunMe                = 0x004D3AA0;
    EQ_ADDRESS_FUNCTION_EQ_Character__UnStunMe              = 0x004D3BC0;
    EQ_ADDRESS_FUNCTION_EQ_Character__ProcessEnvironment    = 0x004DEDC0;

    EQ_ADDRESS_FUNCTION_CharacterZoneClient__SetNoGrav            = 0x004B9240;
    EQ_ADDRESS_FUNCTION_CharacterZoneClient__TotalSpellAffects    = 0x004C2D20;

    EQ_ADDRESS_POINTER_EQ_PC = 0x00E9148C;
    EQ_ADDRESS_FUNCTION_EQ_PC__DestroyHeldItemOrMoney    = 0x006376A0;

    EQ_ADDRESS_POINTER_EQPlayerManager = 0x00F40C50;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID      = 0x00651DD0;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName    = 0x00651E80;

    EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight          = 0x00659CC0;
    EQ_ADDRESS_FUNCTION_EQPlayer__ChangePosition        = 0x0065A6F0;
    EQ_ADDRESS_FUNCTION_EQPlayer__GetLevel              = 0x0065C270;
    EQ_ADDRESS_FUNCTION_EQPlayer__GetActorClient        = 0x00593AB0;
    EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI        = 0x00645460;
    EQ_ADDRESS_FUNCTION_EQPlayer__TurnOffAutoFollow     = 0x00645780;
    EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot        = 0x0064B850;
    EQ_ADDRESS_FUNCTION_EQPlayer__IsTargetable          = 0x0098D8E0;
    EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteState    = 0x00646C70;
    EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteTint     = 0x00647B40;
    EQ_ADDRESS_FUNCTION_EQPlayer__ChangeLight           = 0x0064E180;
    EQ_ADDRESS_FUNCTION_EQPlayer__push_along_heading    = 0x005C8B10;

    EQ_ADDRESS_POINTER_EQSwitchManager = 0x00E8EE78;
    EQ_ADDRESS_FUNCTION_EQSwitch__UseSwitch      = 0x005CD570;
    EQ_ADDRESS_FUNCTION_EQSwitch__ChangeState    = 0x005CDA50;

    EQ_ADDRESS_FUNCTION_EQSpell__SpellAffects    = 0x004B8880;

    EQ_ADDRESS_POINTER_CXWndManager = 0x016DA6A0;
    EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows    = 0x0092AB80;

    EQ_ADDRESS_FUNCTION_CXWnd__IsReallyVisible    = 0x00926BF0;

    EQ_ADDRESS_POINTER_CEverQuest = 0x0104CC68;
    EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert        = 0x005EAF90;
    EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone               = 0x005E5780;
    EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd            = 0x005F9490;
    EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat                = 0x004E6880;
    EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState            = 0x005D1E10;
    EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp                = 0x005D45F0;
    EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp                = 0x005D5590;
    EQ_ADDRESS_FUNCTION_CEverQuest__HandleMouseWheel        = 0x005D5C70;
    EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting            = 0x005DF7A0;
    EQ_ADDRESS_FUNCTION_CEverQuest__SendNewText             = 0x005E04C0;
    EQ_ADDRESS_FUNCTION_CEverQuest__DropHeldItemOnGround    = 0x005D2080;

    EQ_ADDRESS_POINTER_CDisplay = 0x0E918D0;
    EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2         = 0x005360B0;
    EQ_ADDRESS_FUNCTION_CDisplay__CreateActor          = 0x005391A0;
    EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor    = 0x00534CE0;
    EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor          = 0x00539110;
    EQ_ADDRESS_FUNCTION_CDisplay__GetIntensity         = 0x00536020;
    EQ_ADDRESS_FUNCTION_CDisplay__CreateLight          = 0x005397C0;
    EQ_ADDRESS_FUNCTION_CDisplay__DeleteLight          = 0x00539790;

    //EQ_ADDRESS_POINTER_CCamera = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation    = 0x0; // calculated at runtime

    EQ_ADDRESS_POINTER_CRender = 0x016DB4E0;
    //EQ_ADDRESS_FUNCTION_CRender__ResetDevice    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay         = 0x0; // calculated at runtime

    EQ_ADDRESS_POINTER_CAlertWnd = 0x0DDD0E4;

    EQ_ADDRESS_POINTER_CSpellBookWnd = 0x00DDCBA0;
    EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft       = 0x007FD790;
    EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellScribeTicksLeft    = 0x007FD8F0;
#endif // EQ_TEST_SERVER
}

/*
void EQ_InitializeAddresses()
{
    // Jun 13 2019 09:58:49

    EQ_SIZE_CXWnd = 0x1E8;
    EQ_SIZE_CSidlScreenWnd = 0x230;

    EQ_OFFSET_SPAWN_STANDING_STATE             = 0x60f;
    EQ_OFFSET_SPAWN_FOLLOW_SPAWN               = 0xf30;
    EQ_OFFSET_SPAWN_HP_CURRENT                 = 0x3a0;
    EQ_OFFSET_SPAWN_HP_MAX                     = 0x558;
    EQ_OFFSET_SPAWN_MANA_CURRENT               = 0x1ec;
    EQ_OFFSET_SPAWN_MANA_MAX                   = 0x518;
    EQ_OFFSET_SPAWN_ENDURANCE_CURRENT          = 0x1a4;
    EQ_OFFSET_SPAWN_ENDURANCE_MAX              = 0x394;
    EQ_OFFSET_SPAWN_CharacterZoneClient        = 0x610;
    EQ_OFFSET_EQ_Character____CharacterBase    = 0x284c;
    EQ_OFFSET_CharInfo2__Bandolier             = 0x75b4;

    EQ_ADDRESS_WindowHWND = 0x00F339F4;

    EQ_ADDRESS_AutoAttack    = 0x00F2DDFB;
    EQ_ADDRESS_AutoFire      = 0x00F2DDFC;
    EQ_ADDRESS_AutoRun       = 0x00E8F168;
    EQ_ADDRESS_MouseLook     = 0x00E8F14A;
    EQ_ADDRESS_NetStatus     = 0x00E8F14D;

    EQ_ADDRESS_EQZoneInfo = 0x00E8F340;

    EQ_ADDRESS_POINTER_ControlledSpawn    = 0x00E7F448;
    EQ_ADDRESS_POINTER_PlayerSpawn        = 0x00E7F3F0;
    EQ_ADDRESS_POINTER_TargetSpawn        = 0x00E7F444;

    EQ_ADDRESS_FUNCTION_DetectVirtualMachine          = 0x008F4080;
    EQ_ADDRESS_FUNCTION_CollisionCallbackForActors    = 0x0051D0C0;
    EQ_ADDRESS_FUNCTION_CastRay                       = 0x0059ADA0;
    EQ_ADDRESS_FUNCTION_CastRay2                      = 0x0059ADF0;
    EQ_ADDRESS_FUNCTION_DrawNetStatus                 = 0x00626CC0;
    EQ_ADDRESS_FUNCTION_ExecuteCmd                    = 0x00593660;
    EQ_ADDRESS_FUNCTION_DoSpellEffect                 = 0x005F9170;
    EQ_ADDRESS_FUNCTION_PlaySoundAtLocation           = 0x005394A0;
    EQ_ADDRESS_FUNCTION_GetTime                       = 0x008EF9C0;
    EQ_ADDRESS_FUNCTION_UpdateLight                   = 0x005B7EE0;
    EQ_ADDRESS_FUNCTION_GetGaugeValueFromEQ           = 0x00802030;

    EQ_ADDRESS_POINTER_StringTable = 0x00E81B68;
    EQ_ADDRESS_FUNCTION_StringTable__getString    = 0x008B5EB0;

    EQ_ADDRESS_POINTER_CDBStr = 0x00DCCC6C;
    EQ_ADDRESS_FUNCTION_CDBStr__GetString    = 0x0052EE00;

    EQ_ADDRESS_POINTER_EQ_Character = 0x00E7F920;
    EQ_ADDRESS_FUNCTION_EQ_Character__encum_factor          = 0x004D0BD0;
    EQ_ADDRESS_FUNCTION_EQ_Character__TakeFallDamage        = 0x004D8BB0;
    EQ_ADDRESS_FUNCTION_EQ_Character__CanIBreathe           = 0x004DD900;
    EQ_ADDRESS_FUNCTION_EQ_Character__CanISeeInvis          = 0x004DE770;
    EQ_ADDRESS_FUNCTION_EQ_Character__StunMe                = 0x004D3330;
    EQ_ADDRESS_FUNCTION_EQ_Character__UnStunMe              = 0x004D3450;
    EQ_ADDRESS_FUNCTION_EQ_Character__ProcessEnvironment    = 0x004DE620;
    EQ_ADDRESS_FUNCTION_EQ_Character__TotalSpellAffects     = 0x004C2500;

    EQ_ADDRESS_FUNCTION_CharacterZoneClient__SetNoGrav    = 0x004B8A60;

    EQ_ADDRESS_POINTER_EQPlayerManager = 0x00F30FE8;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID      = 0x0064FA30;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName    = 0x0064FAE0;

    EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight          = 0x00657800;
    EQ_ADDRESS_FUNCTION_EQPlayer__ChangePosition        = 0x00658230;
    EQ_ADDRESS_FUNCTION_EQPlayer__GetLevel              = 0x00659D90;
    EQ_ADDRESS_FUNCTION_EQPlayer__GetActorClient        = 0x005916E0;
    EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI        = 0x006434E0;
    EQ_ADDRESS_FUNCTION_EQPlayer__TurnOffAutoFollow     = 0x00643800;
    EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot        = 0x006494A0;
    EQ_ADDRESS_FUNCTION_EQPlayer__IsTargetable          = 0x0097E840;
    EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteState    = 0x006448E0;
    EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteTint     = 0x006457B0;
    EQ_ADDRESS_FUNCTION_EQPlayer__ChangeLight           = 0x0064BDD0;
    EQ_ADDRESS_FUNCTION_EQPlayer__push_along_heading    = 0x005C61F0;

    EQ_ADDRESS_POINTER_EQSwitchManager = 0x00E7F210;
    EQ_ADDRESS_FUNCTION_EQSwitch__UseSwitch      = 0x005CACB0;
    EQ_ADDRESS_FUNCTION_EQSwitch__ChangeState    = 0x005CB190;

    EQ_ADDRESS_FUNCTION_EQSpell__SpellAffects    = 0x004B80A0;

    EQ_ADDRESS_POINTER_CXWndManager = 0x016CAA30;
    EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows    = 0x0091B8F0;

    EQ_ADDRESS_FUNCTION_CXWnd__IsReallyVisible    = 0x00917880;

    EQ_ADDRESS_POINTER_CEverQuest = 0x0103DA3C;
    EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert    = 0x005E8770;
    EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone           = 0x005E2F60;
    EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd        = 0x005F6C60;
    EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat            = 0x004E5EF0;
    EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState        = 0x005CF610;
    EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp            = 0x005D1DF0;
    EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp            = 0x005D2D80;
    EQ_ADDRESS_FUNCTION_CEverQuest__HandleMouseWheel    = 0x005D3460;
    EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting        = 0x005DCF90;
    EQ_ADDRESS_FUNCTION_CEverQuest__SendNewText         = 0x005DDCB0;

    EQ_ADDRESS_POINTER_CDisplay = 0x0E81B64;
    EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2         = 0x00534220;
    EQ_ADDRESS_FUNCTION_CDisplay__CreateActor          = 0x005372F0;
    EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor    = 0x00532E50;
    EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor          = 0x00537260;
    EQ_ADDRESS_FUNCTION_CDisplay__GetIntensity         = 0x00534190;
    EQ_ADDRESS_FUNCTION_CDisplay__CreateLight          = 0x00537910;
    EQ_ADDRESS_FUNCTION_CDisplay__DeleteLight          = 0x005378E0;

    //EQ_ADDRESS_POINTER_CCamera = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation    = 0x0; // calculated at runtime

    EQ_ADDRESS_POINTER_CRender = 0x016CB870;
    //EQ_ADDRESS_FUNCTION_CRender__ResetDevice    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay         = 0x0; // calculated at runtime

    EQ_ADDRESS_POINTER_CAlertWnd = 0x0DCD538;

    EQ_ADDRESS_POINTER_CSpellBookWnd = 0x00DCD514;
    EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellMemTicksLeft       = 0x007FA800;
    EQ_ADDRESS_FUNCTION_CSpellBookWnd__GetSpellScribeTicksLeft    = 0x007FA960;
}
*/

/*
void EQ_InitializeAddresses()
{
    // May 20 2019 12:50:50

    EQ_SIZE_CXWnd = 0x1E8;
    EQ_SIZE_CSidlScreenWnd = 0x230;

    EQ_OFFSET_SPAWN_STANDING_STATE       = 0x4b4;
    EQ_OFFSET_SPAWN_FOLLOW_SPAWN         = 0xf2c;
    EQ_OFFSET_SPAWN_HP_CURRENT           = 0x588;
    EQ_OFFSET_SPAWN_HP_MAX               = 0x390;
    EQ_OFFSET_SPAWN_MANA_CURRENT         = 0x2e4;
    EQ_OFFSET_SPAWN_MANA_MAX             = 0x3d0;
    EQ_OFFSET_SPAWN_ENDURANCE_CURRENT    = 0x1a0;
    EQ_OFFSET_SPAWN_ENDURANCE_MAX        = 0x4f8;
    EQ_OFFSET_SPAWN_CharacterZoneClient        = 0x4bc;

    EQ_ADDRESS_WindowHWND = 0x00F328F4;

    EQ_ADDRESS_AutoAttack    = 0x00F2CCFB;
    EQ_ADDRESS_AutoFire      = 0x00F2CCFC;
    EQ_ADDRESS_AutoRun       = 0x00E8E068;
    EQ_ADDRESS_MouseLook     = 0x00E8E04A;
    EQ_ADDRESS_NetStatus     = 0x00E8E04D;

    EQ_ADDRESS_EQZoneInfo = 0x00E8E240;

    EQ_ADDRESS_POINTER_PlayerSpawn    = 0x00E805BC;
    EQ_ADDRESS_POINTER_TargetSpawn    = 0x00E80690;

    EQ_ADDRESS_FUNCTION_DetectVirtualMachine          = 0x008F37C0;
    EQ_ADDRESS_FUNCTION_CollisionCallbackForActors    = 0x0051D6D0;
    EQ_ADDRESS_FUNCTION_CastRay                       = 0x0059BCA0;
    EQ_ADDRESS_FUNCTION_CastRay2                      = 0x0059BCF0;
    EQ_ADDRESS_FUNCTION_DrawNetStatus                 = 0x006279B0;
    EQ_ADDRESS_FUNCTION_ExecuteCmd                    = 0x005945C0;
    EQ_ADDRESS_FUNCTION_DoSpellEffect                 = 0x005F9DA0;
    EQ_ADDRESS_FUNCTION_PlaySoundAtLocation           = 0x0053A330;
    EQ_ADDRESS_FUNCTION_GetTime                       = 0x008EEB80;
    EQ_ADDRESS_FUNCTION_UpdateLight                   = 0x005B8DD0;
    EQ_ADDRESS_FUNCTION_GetGaugeValueFromEQ           = 0x00801820;

    EQ_ADDRESS_POINTER_StringTable = 0x00E80480;
    EQ_ADDRESS_FUNCTION_StringTable__getString    = 0x008B5330;

    EQ_ADDRESS_POINTER_CDBStr = 0x00DCBB6C;
    EQ_ADDRESS_FUNCTION_CDBStr__GetString    = 0x0052FC80;

    EQ_ADDRESS_POINTER_EQ_Character = 0x00E7E264;
    EQ_ADDRESS_FUNCTION_EQ_Character__encum_factor          = 0x004D0BE0;
    EQ_ADDRESS_FUNCTION_EQ_Character__TakeFallDamage        = 0x004D8BA0;
    EQ_ADDRESS_FUNCTION_EQ_Character__CanIBreathe           = 0x004DD9D0;
    EQ_ADDRESS_FUNCTION_EQ_Character__CanISeeInvis          = 0x004DE840;
    EQ_ADDRESS_FUNCTION_EQ_Character__StunMe                = 0x004D3340;
    EQ_ADDRESS_FUNCTION_EQ_Character__UnStunMe              = 0x004D3460;
    EQ_ADDRESS_FUNCTION_EQ_Character__ProcessEnvironment    = 0x004DE6F0;
    EQ_ADDRESS_FUNCTION_EQ_Character__TotalSpellAffects     = 0x004C2410;
    EQ_ADDRESS_FUNCTION_CharacterZoneClient__SetNoGrav             = 0x004B8960;

    EQ_ADDRESS_POINTER_EQPlayerManager = 0x00F2FEE8;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID      = 0x0064FD90;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName    = 0x0064FDB0;

    EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight          = 0x006579A0;
    EQ_ADDRESS_FUNCTION_EQPlayer__ChangePosition        = 0x006583D0;
    EQ_ADDRESS_FUNCTION_EQPlayer__GetLevel              = 0x00659F30;
    EQ_ADDRESS_FUNCTION_EQPlayer__GetActorClient        = 0x00592620;
    EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI        = 0x00643930;
    EQ_ADDRESS_FUNCTION_EQPlayer__TurnOffAutoFollow     = 0x00643C50;
    EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot        = 0x006498F0;
    EQ_ADDRESS_FUNCTION_EQPlayer__IsTargetable          = 0x0097D670;
    EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteState    = 0x00644D30;
    EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteTint     = 0x00645C00;
    EQ_ADDRESS_FUNCTION_EQPlayer__ChangeLight           = 0x0064C210;

    EQ_ADDRESS_POINTER_EQSwitchManager = 0x00E7E110;
    EQ_ADDRESS_FUNCTION_EQSwitch__UseSwitch      = 0x005CBB70;
    EQ_ADDRESS_FUNCTION_EQSwitch__ChangeState    = 0x005CC050;

    EQ_ADDRESS_FUNCTION_EQSpell__SpellAffects    = 0x004B7FA0;

    EQ_ADDRESS_POINTER_CXWndManager = 0x016C9938;
    EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows    = 0x0091AFC0;

    EQ_ADDRESS_FUNCTION_CXWnd__IsReallyVisible    = 0x00916F30;

    EQ_ADDRESS_POINTER_CEverQuest = 0x0103D948;
    EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert    = 0x005E9540;
    EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone           = 0x005E3D30;
    EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd        = 0x005F7890;
    EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat            = 0x004E61E0;
    EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState        = 0x005D0440;
    EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp            = 0x005D2C20;
    EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp            = 0x005D3BB0;
    EQ_ADDRESS_FUNCTION_CEverQuest__HandleMouseWheel    = 0x005D4290;
    EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting        = 0x005DDD60;

    EQ_ADDRESS_POINTER_CDisplay = 0x0E806A0;
    EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2         = 0x005350B0;
    EQ_ADDRESS_FUNCTION_CDisplay__CreateActor          = 0x00538180;
    EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor    = 0x00533CE0;
    EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor          = 0x005380F0;
    EQ_ADDRESS_FUNCTION_CDisplay__GetIntensity         = 0x00535020;
    EQ_ADDRESS_FUNCTION_CDisplay__CreateLight          = 0x005387A0;
    EQ_ADDRESS_FUNCTION_CDisplay__DeleteLight          = 0x00538770;

    //EQ_ADDRESS_POINTER_CCamera = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation    = 0x0; // calculated at runtime

    EQ_ADDRESS_POINTER_CRender = 0x016CA778;
    //EQ_ADDRESS_FUNCTION_CRender__ResetDevice    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay         = 0x0; // calculated at runtime

    EQ_ADDRESS_POINTER_CAlertWnd = 0x0DCC180;
}
*/

/*
void EQ_InitializeAddresses()
{
    // May 13 2019 11:56:03

    EQ_ADDRESS_WindowHWND = 0x00F328F4;

    EQ_ADDRESS_AutoAttack    = 0x00F2CCFB;
    EQ_ADDRESS_AutoFire      = 0x00F2CCFC;
    EQ_ADDRESS_AutoRun       = 0x00E8E068;
    EQ_ADDRESS_MouseLook     = 0x00E8E04A;
    EQ_ADDRESS_NetStatus     = 0x00E8E04D;

    EQ_ADDRESS_EQZoneInfo = 0x00E8E240;

    EQ_ADDRESS_FUNCTION_CollisionCallbackForActors    = 0x0051D6D0;
    EQ_ADDRESS_FUNCTION_CastRay                       = 0x0059BCA0;
    EQ_ADDRESS_FUNCTION_CastRay2                      = 0x0059BCF0;
    EQ_ADDRESS_FUNCTION_DrawNetStatus                 = 0x006279B0;
    EQ_ADDRESS_FUNCTION_ExecuteCmd                    = 0x005945C0;

    EQ_ADDRESS_POINTER_PlayerSpawn    = 0x00E805BC;
    EQ_ADDRESS_POINTER_TargetSpawn    = 0x00E80690;

    EQ_ADDRESS_POINTER_EQPlayerManager = 0x00F2FEE8;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID      = 0x0064FD90;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName    = 0x0064FDB0;

    EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight    = 0x006579A0;
    EQ_ADDRESS_FUNCTION_EQPlayer__GetLevel        = 0x00659F30;

    EQ_ADDRESS_POINTER_EQSwitchManager = 0x00E7E110;
    EQ_ADDRESS_FUNCTION_EQSwitch__UseSwitch      = 0x005CBB70;
    EQ_ADDRESS_FUNCTION_EQSwitch__ChangeState    = 0x005CC050;

    EQ_ADDRESS_POINTER_CXWndManager = 0x016C9938;
    EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows    = 0x0091AFC0;

    EQ_ADDRESS_POINTER_CEverQuest = 0x0103D948;
    EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert    = 0x005E9540;
    EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone           = 0x005E3D30;
    EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd        = 0x005F7890;
    EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat            = 0x004E61E0;
    EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState        = 0x005D0440;
    EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp            = 0x005D2C20;
    EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp            = 0x005D3BB0;
    EQ_ADDRESS_FUNCTION_CEverQuest__HandleMouseWheel    = 0x005D4290;

    EQ_ADDRESS_POINTER_CDisplay = 0x0E806A0;
    EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2         = 0x005350B0;
    EQ_ADDRESS_FUNCTION_CDisplay__CreateActor          = 0x00538180;
    EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor    = 0x00533CE0;
    EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor          = 0x005380F0;

    //EQ_ADDRESS_POINTER_CCamera = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation    = 0x0; // calculated at runtime

    EQ_ADDRESS_POINTER_CRender = 0x016CA778;
    //EQ_ADDRESS_FUNCTION_CRender__ResetDevice    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay         = 0x0; // calculated at runtime
}
*/

/*
void EQ_InitializeAddresses()
{
    // Apr 18 2019 17:51:12

    EQ_ADDRESS_WindowHWND = 0x00F318E4;

    EQ_ADDRESS_AutoAttack    = 0x00F2BCEB;
    EQ_ADDRESS_AutoRun       = 0x00E8D058;
    EQ_ADDRESS_MouseLook     = 0x00E8D03A;
    EQ_ADDRESS_NetStatus     = 0x00E8D03D;

    EQ_ADDRESS_FUNCTION_CollisionCallbackForActors    = 0x0051D410;
    EQ_ADDRESS_FUNCTION_CastRay                       = 0x0059BB10;
    EQ_ADDRESS_FUNCTION_CastRay2                      = 0x0059BB60;
    EQ_ADDRESS_FUNCTION_DrawNetStatus                 = 0x00627100;
    EQ_ADDRESS_FUNCTION_ExecuteCmd                    = 0x00594400;

    EQ_ADDRESS_POINTER_PlayerSpawn    = 0x00E7F5A4;
    EQ_ADDRESS_POINTER_TargetSpawn    = 0x00E7F678;

    EQ_ADDRESS_POINTER_EQPlayerManager = 0x00F2EED8;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID      = 0x0064F690;
    EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName    = 0x0064F6B0;

    EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight    = 0x006572C0;
    EQ_ADDRESS_FUNCTION_EQPlayer__GetLevel        = 0x00659850;

    EQ_ADDRESS_POINTER_CXWndManager = 0x016C8928;
    EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows    = 0x0091A620;

    EQ_ADDRESS_POINTER_CEverQuest = 0x0103C944;
    EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert    = 0x005E8FE0;
    EQ_ADDRESS_FUNCTION_CEverQuest__EnterZone           = 0x005E37D0;
    EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd        = 0x005F7330;
    EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat            = 0x004E6440;
    EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState        = 0x005CFEE0;

    EQ_ADDRESS_POINTER_CDisplay = 0x0E7F68C;
    EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2    = 0x00534E20;

    //EQ_ADDRESS_POINTER_CCamera = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CCamera__SetCameraLocation    = 0x0; // calculated at runtime

    EQ_ADDRESS_POINTER_CRender = 0x016C9768;
    //EQ_ADDRESS_FUNCTION_CRender__ResetDevice    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__ClearRenderToBlack    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__RenderPartialScene    = 0x0; // calculated at runtime
    //EQ_ADDRESS_FUNCTION_CRender__UpdateDisplay         = 0x0; // calculated at runtime
}
*/