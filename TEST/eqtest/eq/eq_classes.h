#pragma once

#include "eq_constants.h"
#include "eq_macros.h"
#include "eq_messages.h"

namespace EQClass
{
    class CDBStr;
    class StringTable;

    class CEverQuest;
    class CDisplay;

    class EQ_PC;

    class SpellManager;

    class EQPlayerManager;
    class EQPlayer;

    class EQSwitch;

    class CXPoint;
    class CXStr;

    class CXWndManager;
    class CXWnd;

    class AltAdvManager;

    class Aura;
    class AuraManager;

    class GroundItem;
    class GroundItemManager;

#ifdef EQ_FEATURE_BAZAAR
    class CBazaarWnd;
    class CBazaarConfirmationWnd;
    class CBazaarSearchWnd;
#endif // EQ_FEATURE_BAZAAR
    class CCharacterListWnd;
    class CTaskSelectWnd;
    class CLargeDialogWnd;
    class CConfirmationDialog;
    class CInventoryWnd;

    // EQGraphicsDX9.dll
    class CCamera;
    class CRender;

    class CVector3; // needed by CastRay2

    class CActorEx;
} // namespace EQClass

/* CDBStr */

class EQClass::CDBStr
{
public:
    char* CDBStr::GetString(int index, int subIndex, int* isFound);
};

EQ_MACRO_FUNCTION_FunctionAtAddress(char* EQClass::CDBStr::GetString(int index, int subIndex, int* isFound), EQ_ADDRESS_FUNCTION_CDBStr__GetString);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDBStr__GetString)(void* this_ptr, int index, int subIndex, int* isFound);

EQClass::CDBStr** EQ_CLASS_POINTER_CDBStr_pptr;
EQClass::CDBStr* EQ_CLASS_POINTER_CDBStr;

/* CEverQuest */

class EQClass::CEverQuest
{
public:
    void CEverQuest::DoPercentConvert(char* text, bool isOutgoing);
    void CEverQuest::InterpretCmd(class EQPlayer* player, const char* text);
    void CEverQuest::dsp_chat(const char* text, int textColor, bool one_1, bool one_2, bool zero_1);
#ifdef EQ_FEATURE_CEverQuest__StartCasting
    void CEverQuest::StartCasting(EQMessage::CEverQuest__StartCasting_ptr message);
#endif // EQ_FEATURE_CEverQuest__StartCasting
    void CEverQuest::LMouseUp(int x, int y);
    void CEverQuest::RMouseUp(int x, int y);
#ifdef EQ_FEATURE_GUI
    void CEverQuest::HandleMouseWheel(signed int delta);
#endif // EQ_FEATURE_GUI
    void CEverQuest::SetGameState(int gameState);
};

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CEverQuest::DoPercentConvert(char* text, bool isOutgoing), EQ_ADDRESS_FUNCTION_CEverQuest__DoPercentConvert);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__DoPercentConvert)(void* this_ptr, char* text, bool isOutgoing);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CEverQuest::InterpretCmd(class EQPlayer* player, const char* text), EQ_ADDRESS_FUNCTION_CEverQuest__InterpretCmd);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__InterpretCmd)(void* this_ptr, class EQPlayer* player, const char* text);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CEverQuest::dsp_chat(const char* text, int textColor, bool one_1, bool one_2, bool zero_1), EQ_ADDRESS_FUNCTION_CEverQuest__dsp_chat);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__dsp_chat)(void* this_ptr, const char* text, int textColor, bool one_1, bool one_2, bool zero_1);

#ifdef EQ_FEATURE_CEverQuest__StartCasting

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CEverQuest::StartCasting(EQMessage::CEverQuest__StartCasting_ptr message), EQ_ADDRESS_FUNCTION_CEverQuest__StartCasting);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__StartCasting)(void* this_ptr, EQMessage::CEverQuest__StartCasting_ptr message);

#endif // EQ_FEATURE_CEverQuest__StartCasting

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CEverQuest::LMouseUp(int x, int y), EQ_ADDRESS_FUNCTION_CEverQuest__LMouseUp);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__LMouseUp)(void* this_ptr, int x, int y);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CEverQuest::RMouseUp(int x, int y), EQ_ADDRESS_FUNCTION_CEverQuest__RMouseUp);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__RMouseUp)(void* this_ptr, int x, int y);

#ifdef EQ_FEATURE_GUI

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CEverQuest::HandleMouseWheel(signed int delta), EQ_ADDRESS_FUNCTION_CEverQuest__HandleMouseWheel);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__HandleMouseWheel)(void* this_ptr, signed int delta);

#endif // EQ_FEATURE_GUI

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CEverQuest::SetGameState(int gameState), EQ_ADDRESS_FUNCTION_CEverQuest__SetGameState);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CEverQuest__SetGameState)(void* this_ptr, int gameState);

EQClass::CEverQuest** EQ_CLASS_POINTER_CEverQuest_pptr;
EQClass::CEverQuest* EQ_CLASS_POINTER_CEverQuest;

/* CDisplay */

class EQClass::CDisplay
{
public:
    static int __cdecl CDisplay::WriteTextHD2(const char* text, int x, int y, signed int color);
#ifdef EQ_FEATURE_CREATE_AND_DELETE_ACTORS
    int CDisplay::CreateActor(char* actorDefinition, float y, float x, float z, float a5, float a6, float a7, float a8, float a9, float a10, int a11);
    int CDisplay::CreatePlayerActor(uint32_t spawn, int a2, int a3, int a4, int a5, int a6);
    void CDisplay::DeleteActor(uint32_t cactor);
#endif // EQ_FEATURE_CREATE_AND_DELETE_ACTORS
};

EQ_MACRO_FUNCTION_FunctionAtAddress(int __cdecl EQClass::CDisplay::WriteTextHD2(const char* text, int x, int y, signed int color), EQ_ADDRESS_FUNCTION_CDisplay__WriteTextHD2);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__WriteTextHD2)(void* this_ptr, const char* text, int x, int y, signed int color);

#ifdef EQ_FEATURE_CREATE_AND_DELETE_ACTORS

EQ_MACRO_FUNCTION_FunctionAtAddress(int EQClass::CDisplay::CreateActor(char* actorDefinition, float y, float x, float z, float a5, float a6, float a7, float a8, float a9, float a10, int a11), EQ_ADDRESS_FUNCTION_CDisplay__CreateActor);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__CreateActor)(void* this_ptr, char* actorDefinition, float y, float x, float z, float a5, float a6, float a7, float a8, float a9, float a10, int a11);

EQ_MACRO_FUNCTION_FunctionAtAddress(int EQClass::CDisplay::CreatePlayerActor(uint32_t spawn, int a2, int a3, int a4, int a5, int a6), EQ_ADDRESS_FUNCTION_CDisplay__CreatePlayerActor);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__CreatePlayerActor)(void* this_ptr, uint32_t spawn, int a2, int a3, int a4, int a5, int a6);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CDisplay::DeleteActor(uint32_t cactor), EQ_ADDRESS_FUNCTION_CDisplay__DeleteActor);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CDisplay__DeleteActor)(void* this_ptr, uint32_t cactor);

#endif // EQ_FEATURE_CREATE_AND_DELETE_ACTORS

EQClass::CDisplay** EQ_CLASS_POINTER_CDisplay_pptr;
EQClass::CDisplay* EQ_CLASS_POINTER_CDisplay;

/* EQ_PC */

class EQClass::EQ_PC
{
public:
    void EQ_PC::DestroyHeldItemOrMoney();
};

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::EQ_PC::DestroyHeldItemOrMoney(), EQ_ADDRESS_FUNCTION_EQ_PC__DestroyHeldItemOrMoney);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQ_PC__DestroyHeldItemOrMoney)(void* this_ptr);

EQClass::EQ_PC** EQ_CLASS_POINTER_EQ_PC_pptr;
EQClass::EQ_PC* EQ_CLASS_POINTER_EQ_PC;

/* SpellManager */

class EQClass::SpellManager
{
public:
    //
};

EQClass::SpellManager** EQ_CLASS_POINTER_SpellManager_pptr;
EQClass::SpellManager* EQ_CLASS_POINTER_SpellManager;

/* EQPlayerManager */

class EQClass::EQPlayerManager
{
public:
    uint32_t* EQPlayerManager::GetSpawnByID(uint32_t spawnID);
    uint32_t* EQPlayerManager::GetSpawnByName(const char* spawnName);
};

EQ_MACRO_FUNCTION_FunctionAtAddress(uint32_t* EQClass::EQPlayerManager::GetSpawnByID(uint32_t spawnID), EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByID);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQPlayerManager__GetSpawnByID)(void* this_ptr, uint32_t spawnID);

EQ_MACRO_FUNCTION_FunctionAtAddress(uint32_t* EQClass::EQPlayerManager::GetSpawnByName(const char* spawnName), EQ_ADDRESS_FUNCTION_EQPlayerManager__GetSpawnByName);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQPlayerManager__GetSpawnByName)(void* this_ptr, const char* spawnName);

EQClass::EQPlayerManager** EQ_CLASS_POINTER_EQPlayerManager_pptr;
EQClass::EQPlayerManager* EQ_CLASS_POINTER_EQPlayerManager;

/* EQPlayer */

class EQClass::EQPlayer
{
public:
#ifdef EQ_FEATURE_EQPlayer__FollowPlayerAI
    void EQPlayer::FollowPlayerAI();
#endif // EQ_FEATURE_EQPlayer__FollowPlayerAI
    void EQPlayer::ChangeHeight(float height, float a2, float a3, int a4);
#ifdef EQ_FEATURE_EQPlayer__UpdateItemSlot
    bool EQPlayer::UpdateItemSlot(uint8_t updateItemSlot, const char* itemDefinition, bool b1, bool serverSide, bool b3);
#endif // EQ_FEATURE_EQPlayer__UpdateItemSlot
    bool EQPlayer::IsTargetable();
    int EQPlayer::SetNameSpriteState(bool isNameVisible);
    bool EQPlayer::SetNameSpriteTint();
};

#ifdef EQ_FEATURE_EQPlayer__FollowPlayerAI

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::EQPlayer::FollowPlayerAI(), EQ_ADDRESS_FUNCTION_EQPlayer__FollowPlayerAI);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQPlayer__FollowPlayerAI)(void* this_ptr);

#endif // EQ_FEATURE_EQPlayer__FollowPlayerAI

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::EQPlayer::ChangeHeight(float height, float a2, float a3, int a4), EQ_ADDRESS_FUNCTION_EQPlayer__ChangeHeight);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQPlayer__ChangeHeight)(void* this_ptr, float height, float a2, float a3, int a4);

#ifdef EQ_FEATURE_EQPlayer__UpdateItemSlot

EQ_MACRO_FUNCTION_FunctionAtAddress(bool EQClass::EQPlayer::UpdateItemSlot(uint8_t updateItemSlot, const char* itemDefinition, bool b1, bool serverSide, bool b3), EQ_ADDRESS_FUNCTION_EQPlayer__UpdateItemSlot);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQPlayer__UpdateItemSlot)(void* this_ptr, uint8_t updateItemSlot, const char* itemDefinition, bool b1, bool serverSide, bool b3);

#endif // EQ_FEATURE_EQPlayer__UpdateItemSlot

EQ_MACRO_FUNCTION_FunctionAtAddress(bool EQClass::EQPlayer::IsTargetable(), EQ_ADDRESS_FUNCTION_EQPlayer__IsTargetable);

EQ_MACRO_FUNCTION_FunctionAtAddress(int EQClass::EQPlayer::SetNameSpriteState(bool isNameVisible), EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteState);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQPlayer__SetNameSpriteState)(void* this_ptr, bool isNameVisible);

EQ_MACRO_FUNCTION_FunctionAtAddress(bool EQClass::EQPlayer::SetNameSpriteTint(), EQ_ADDRESS_FUNCTION_EQPlayer__SetNameSpriteTint);
typedef int (__thiscall* EQ_FUNCTION_TYPE_EQPlayer__SetNameSpriteTint)(void* this_ptr);

/* EQSwitch */

class EQClass::EQSwitch
{
public:
    void EQSwitch::UseSwitch(uint32_t spawnID, uint32_t keyID, uint32_t pickSkill, const void* hitLocation = 0);
#ifdef EQ_FEATURE_EQSwitch__ChangeState
    void EQSwitch::ChangeState(uint8_t state, int zero1, int zero2);
#endif // EQ_FEATURE_EQSwitch__ChangeState
};

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::EQSwitch::UseSwitch(uint32_t spawnID, uint32_t keyID, uint32_t pickSkill, const void* hitLocation), EQ_ADDRESS_FUNCTION_EQSwitch__UseSwitch);

#ifdef EQ_FEATURE_EQSwitch__ChangeState

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::EQSwitch::ChangeState(uint8_t state, int zero1, int zero2), EQ_ADDRESS_FUNCTION_EQSwitch__ChangeState);

#endif // EQ_FEATURE_EQSwitch__ChangeState

/* CXPoint */

class EQClass::CXPoint
{
public:
    class CXPoint CXPoint::operator=(class CXPoint);

    uint32_t X;
    uint32_t Y;
};

/* CXStr */

class EQClass::CXStr
{
public:
    CXStr::CXStr(class CXStr const &);
    CXStr::~CXStr(void);
    CXStr::CXStr(char const *);
    void CXStr::operator+=(char const *);
    class CXStr& CXStr::operator=(char const *);
    class CXStr& CXStr::operator=(class CXStr const&);

    EQ::CXStr_ptr ptr;
};

// CXStr(CXStr) constructor
EQ_MACRO_FUNCTION_FunctionAtAddress(EQClass::CXStr::CXStr(class CXStr const &), EQ_ADDRESS_FUNCTION_CXStr__CXStr);

// CXStr(void) deconstructor
EQ_MACRO_FUNCTION_FunctionAtAddress(EQClass::CXStr::~CXStr(void), EQ_ADDRESS_FUNCTION_CXStr__dCXStr);

// CXStr(const char*) constructor
EQ_MACRO_FUNCTION_FunctionAtAddress(EQClass::CXStr::CXStr(char const *), EQ_ADDRESS_FUNCTION_CXStr__CXStr3);

// CXStr += const char*
EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CXStr::operator+=(char const *), EQ_ADDRESS_FUNCTION_CXStr__operator_plus_equal1);

// CXStr = const char*
EQ_MACRO_FUNCTION_FunctionAtAddress(class EQClass::CXStr& EQClass::CXStr::operator=(char const *), EQ_ADDRESS_FUNCTION_CXStr__operator_equal1);

// CXStr = CXStr
EQ_MACRO_FUNCTION_FunctionAtAddress(class EQClass::CXStr& EQClass::CXStr::operator=(class CXStr const&), EQ_ADDRESS_FUNCTION_CXStr__operator_equal);

/* CXWndManager */

class EQClass::CXWndManager
{
public:
    int CXWndManager::DrawCursor();
    int CXWndManager::DrawWindows();
};

EQ_MACRO_FUNCTION_FunctionAtAddress(int EQClass::CXWndManager::DrawCursor(), EQ_ADDRESS_FUNCTION_CXWndManager__DrawCursor);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CXWndManager__DrawCursor)(void* this_ptr);

EQ_MACRO_FUNCTION_FunctionAtAddress(int EQClass::CXWndManager::DrawWindows(), EQ_ADDRESS_FUNCTION_CXWndManager__DrawWindows);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CXWndManager__DrawWindows)(void* this_ptr);

EQClass::CXWndManager** EQ_CLASS_POINTER_CXWndManager_pptr;
EQClass::CXWndManager* EQ_CLASS_POINTER_CXWndManager;

/* CXWnd */

class EQClass::CXWnd
{
public:
    int CXWnd::DrawTooltip(class EQClass::CXWnd* cxwnd);
    void CXWnd::DrawTooltipAtPoint(class EQClass::CXPoint cxpoint);
    int CXWnd::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown);
    void CXWnd::Activate();
    void CXWnd::Deactivate();
    void CXWnd::BringToTop(bool bRecurse = true);
    bool CXWnd::IsActive();
    bool CXWnd::IsReallyVisible(); // is open
    EQClass::CXWnd* CXWnd::GetChildItem(const EQClass::CXStr& name);
    EQClass::CXStr CXWnd::GetWindowTextA();
};

#define EQ_VFTABLE_INDEX_CXWnd__DrawTooltip           0x24
#define EQ_VFTABLE_INDEX_CXWnd__DrawTooltipAtPoint    0x28
#define EQ_VFTABLE_INDEX_CXWnd__WndNotification       0x88
#define EQ_VFTABLE_INDEX_CXWnd__Activate              0x90 // show window
#define EQ_VFTABLE_INDEX_CXWnd__Deactivate            0x94 // hide window

//EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(int EQClass::CXWnd::DrawTooltip(class EQClass::CXWnd*), EQ_VFTABLE_INDEX_CXWnd__DrawTooltip);

//EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(void EQClass::CXWnd::DrawTooltipAtPoint(class EQClass::CXPoint), EQ_VFTABLE_INDEX_CXWnd__DrawTooltipAtPoint);

EQ_MACRO_FUNCTION_FunctionAtAddress(int EQClass::CXWnd::DrawTooltip(class EQClass::CXWnd* cxwnd), EQ_ADDRESS_FUNCTION_CXWnd__DrawTooltip);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CXWnd__DrawTooltip)(void* this_ptr, class EQClass::CXWnd* cxwnd);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CXWnd::DrawTooltipAtPoint(class EQClass::CXPoint cxpoint),  EQ_ADDRESS_FUNCTION_CXWnd__DrawTooltipAtPoint);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(int EQClass::CXWnd::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown), EQ_VFTABLE_INDEX_CXWnd__WndNotification);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(void EQClass::CXWnd::Activate(), EQ_VFTABLE_INDEX_CXWnd__Activate);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(void EQClass::CXWnd::Deactivate(), EQ_VFTABLE_INDEX_CXWnd__Deactivate);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CXWnd::BringToTop(bool bRecurse), EQ_ADDRESS_FUNCTION_CXWnd__BringToTop);

EQ_MACRO_FUNCTION_FunctionAtAddress(bool EQClass::CXWnd::IsActive(), EQ_ADDRESS_FUNCTION_CXWnd__IsActive);

EQ_MACRO_FUNCTION_FunctionAtAddress(bool EQClass::CXWnd::IsReallyVisible(), EQ_ADDRESS_FUNCTION_CXWnd__IsReallyVisible);

EQ_MACRO_FUNCTION_FunctionAtAddress(EQClass::CXWnd* EQClass::CXWnd::GetChildItem(const EQClass::CXStr& name), EQ_ADDRESS_FUNCTION_CXWnd__GetChildItem);

EQ_MACRO_FUNCTION_FunctionAtAddress(EQClass::CXStr EQClass::CXWnd::GetWindowTextA(), EQ_ADDRESS_FUNCTION_CXWnd__GetWindowTextA);

/* AltAdvManager */

class EQClass::AltAdvManager
{
public:
    struct EQData::_ALTABILITY * AltAdvManager::GetAAById(int id, int playerLevel);
};

EQ_MACRO_FUNCTION_FunctionAtAddress(struct EQData::_ALTABILITY * EQClass::AltAdvManager::GetAAById(int id, int playerLevel), EQ_ADDRESS_FUNCTION_AltAdvManager__GetAAById);
typedef int (__thiscall* EQ_FUNCTION_TYPE_AltAdvManager__GetAAById)(void* this_ptr, int id, int playerLevel);

EQClass::AltAdvManager** EQ_CLASS_POINTER_AltAdvManager_pptr;
EQClass::AltAdvManager* EQ_CLASS_POINTER_AltAdvManager;

/* Aura */

class EQClass::Aura
{
public:
/*0x000*/ char Name[0x40];
/*0x040*/ unsigned int SpawnID;
/*0x044*/ int Cost;
/*0x048*/ int IconID;
/*0x04C*/
};

/* AuraManager */

class EQClass::AuraManager
{
public:
    ArrayClass2_RO<EQClass::Aura> Auras;
    static EQClass::AuraManager* AuraManager::GetSingleton();
};

EQ_MACRO_FUNCTION_FunctionAtAddress(EQClass::AuraManager* EQClass::AuraManager::GetSingleton(), EQ_ADDRESS_FUNCTION_AuraManager__GetSingleton);

/* GroundItem */

class EQClass::GroundItem
{
public:
/*0x00*/ GroundItem* Previous;
/*0x04*/ GroundItem* Next;
/*0x08*/ VePointer<EQData::CONTENTS> Contents;
/*0x0C*/ uint32_t DropID; //unique id
/*0x10*/ uint32_t ZoneID;
/*0x14*/ uint32_t  DropSubID; //well zonefile id, but yeah...
/*0x18*/ void* ActorInterface; //CActorInterface
/*0x1C*/ char Name[0x40];
/*0x5C*/ long Expires;
/*0x60*/ float Heading;
/*0x64*/ float Pitch;
/*0x68*/ float Roll;
/*0x6C*/ float Scale;
/*0x70*/ float Y;
/*0x74*/ float X;
/*0x78*/ float Z;
/*0x7C*/ signed int Weight; //-1 means it cannot be picked up
/*0x80*/
};

/* GroundItemManager */
// this used to be EQItemList

class EQClass::GroundItemManager
{
public:
    static EQClass::GroundItemManager& GroundItemManager::Instance();
    EQClass::GroundItem* Top; // First
};

EQ_MACRO_FUNCTION_FunctionAtAddress(EQClass::GroundItemManager& EQClass::GroundItemManager::Instance(), EQ_ADDRESS_FUNCTION_GroundItemManager__Instance);

#ifdef EQ_FEATURE_BAZAAR

/* CBazaarWnd */

class EQClass::CBazaarWnd
{
public:
    int CBazaarWnd::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown);
};

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(int EQClass::CBazaarWnd::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown), EQ_VFTABLE_INDEX_CXWnd__WndNotification);

EQClass::CBazaarWnd** EQ_CLASS_POINTER_CBazaarWnd_pptr;
EQClass::CBazaarWnd* EQ_CLASS_POINTER_CBazaarWnd;

/* CBazaarConfirmationWnd */

class EQClass::CBazaarConfirmationWnd
{
public:
    int CBazaarConfirmationWnd::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown);
};

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(int EQClass::CBazaarConfirmationWnd::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown), EQ_VFTABLE_INDEX_CXWnd__WndNotification);

EQClass::CBazaarConfirmationWnd** EQ_CLASS_POINTER_CBazaarConfirmationWnd_pptr;
EQClass::CBazaarConfirmationWnd* EQ_CLASS_POINTER_CBazaarConfirmationWnd;

/* CBazaarSearchWnd */

class EQClass::CBazaarSearchWnd
{
public:
    int CBazaarSearchWnd::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown);
    void CBazaarSearchWnd::AddItemToList(char* itemName, uint32_t itemPrice, char* traderName, int a4, int a5, int a6, int a7, int a8, void* a9, int a10, void* a11);
    void CBazaarSearchWnd::doQuery();
    bool CBazaarSearchWnd::BuyItem(int quantity);
};

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(int EQClass::CBazaarSearchWnd::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown), EQ_VFTABLE_INDEX_CXWnd__WndNotification);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CBazaarSearchWnd::AddItemToList(char* itemName, uint32_t itemPrice, char* traderName, int a4, int a5, int a6, int a7, int a8, void* a9, int a10, void* a11), EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__AddItemToList);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CBazaarSearchWnd__AddItemToList)(void* this_ptr, char* itemName, uint32_t itemPrice, char* traderName, int a4, int a5, int a6, int a7, int a8, void* a9, int a10, void* a11);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CBazaarSearchWnd::doQuery(), EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__doQuery);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CBazaarSearchWnd__doQuery)(void* this_ptr);

EQ_MACRO_FUNCTION_FunctionAtAddress(bool EQClass::CBazaarSearchWnd::BuyItem(int quantity), EQ_ADDRESS_FUNCTION_CBazaarSearchWnd__BuyItem);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CBazaarSearchWnd__BuyItem)(void* this_ptr, int quantity);

EQClass::CBazaarSearchWnd** EQ_CLASS_POINTER_CBazaarSearchWnd_pptr;
EQClass::CBazaarSearchWnd* EQ_CLASS_POINTER_CBazaarSearchWnd;

#endif // EQ_FEATURE_BAZAAR

/* CCharacterListWnd */

class EQClass::CCharacterListWnd
{
public:
    int CCharacterListWnd::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown);
    void CCharacterListWnd::SelectCharacter(int index, bool switchVisually = true, bool forceUpdate = false);
    void CCharacterListWnd::EnterWorld();
    void CCharacterListWnd::Quit();
};

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(int EQClass::CCharacterListWnd::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown), EQ_VFTABLE_INDEX_CXWnd__WndNotification);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CCharacterListWnd::SelectCharacter(int index, bool switchVisually, bool forceUpdate), EQ_ADDRESS_FUNCTION_CCharacterListWnd__SelectCharacter);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CCharacterListWnd__SelectCharacter)(void* this_ptr, int index, bool switchVisually, bool forceUpdate);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CCharacterListWnd::EnterWorld(), EQ_ADDRESS_FUNCTION_CCharacterListWnd__EnterWorld);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CCharacterListWnd__EnterWorld)(void* this_ptr);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CCharacterListWnd::Quit(), EQ_ADDRESS_FUNCTION_CCharacterListWnd__Quit);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CCharacterListWnd__Quit)(void* this_ptr);

EQClass::CCharacterListWnd** EQ_CLASS_POINTER_CCharacterListWnd_pptr;
EQClass::CCharacterListWnd* EQ_CLASS_POINTER_CCharacterListWnd;

/* CTaskSelectWnd */

class EQClass::CTaskSelectWnd
{
public:
    int CTaskSelectWnd::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown);
};

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(int EQClass::CTaskSelectWnd::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown), EQ_VFTABLE_INDEX_CXWnd__WndNotification);

EQClass::CTaskSelectWnd** EQ_CLASS_POINTER_CTaskSelectWnd_pptr;
EQClass::CTaskSelectWnd* EQ_CLASS_POINTER_CTaskSelectWnd;

/* CLargeDialogWnd */

class EQClass::CLargeDialogWnd
{
public:
    int CLargeDialogWnd::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown);
    void CLargeDialogWnd::Open(bool showYesNo, class EQClass::CXStr bodyText, unsigned long closeTimer, class EQClass::CXStr titleText, bool showVolumeControls, class EQClass::CXStr yesText, class EQClass::CXStr noText) noexcept;
};

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(int EQClass::CLargeDialogWnd::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown), EQ_VFTABLE_INDEX_CXWnd__WndNotification);

EQ_MACRO_FUNCTION_FunctionAtAddress(void EQClass::CLargeDialogWnd::Open(bool showYesNo, class EQClass::CXStr bodyText, unsigned long closeTimer, class EQClass::CXStr titleText, bool showVolumeControls, class EQClass::CXStr yesText, class EQClass::CXStr noText) noexcept, EQ_ADDRESS_FUNCTION_CLargeDialogWnd__Open);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CLargeDialogWnd__Open)(void* this_ptr, bool showYesNo, class EQClass::CXStr bodyText, unsigned long closeTimer, class EQClass::CXStr titleText, bool showVolumeControls, class EQClass::CXStr noText);

EQClass::CLargeDialogWnd** EQ_CLASS_POINTER_CLargeDialogWnd_pptr;
EQClass::CLargeDialogWnd* EQ_CLASS_POINTER_CLargeDialogWnd;

/* CConfirmationDialog */

class EQClass::CConfirmationDialog
{
public:
    int CConfirmationDialog::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown);
    int CConfirmationDialog::Activate(int a1, unsigned int a2, const char* text, int a4, int timer, int a6, int a7);
};

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(int EQClass::CConfirmationDialog::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown), EQ_VFTABLE_INDEX_CXWnd__WndNotification);

EQClass::CConfirmationDialog** EQ_CLASS_POINTER_CConfirmationDialog_pptr;
EQClass::CConfirmationDialog* EQ_CLASS_POINTER_CConfirmationDialog;

/* CInventoryWnd */

class EQClass::CInventoryWnd
{
public:
    int CInventoryWnd::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown);
};

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(int EQClass::CInventoryWnd::WndNotification(uint32_t cxwndAddress, uint32_t cxwndMessage, void* unknown), EQ_VFTABLE_INDEX_CXWnd__WndNotification);

EQClass::CInventoryWnd** EQ_CLASS_POINTER_CInventoryWnd_pptr;
EQClass::CInventoryWnd* EQ_CLASS_POINTER_CInventoryWnd;

/* CCamera */

class EQClass::CCamera
{
public:
    int CCamera::SetCameraLocation(EQ::Location& location, bool canSetLocation);
    bool CCamera::WorldSpaceToScreenSpace(EQ::Location& location, float& screenX, float& screenY);
};

#define EQ_VFTABLE_INDEX_CCamera__SetCameraLocation          0x38
#define EQ_VFTABLE_INDEX_CCamera__WorldSpaceToScreenSpace    0x74

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(int EQClass::CCamera::SetCameraLocation(EQ::Location& location, bool canSetLocation), EQ_VFTABLE_INDEX_CCamera__SetCameraLocation);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CCamera__SetCameraLocation)(void* this_ptr, EQ::Location& location, bool canSetLocation);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(bool EQClass::CCamera::WorldSpaceToScreenSpace(EQ::Location& location, float& screenX, float& screenY), EQ_VFTABLE_INDEX_CCamera__WorldSpaceToScreenSpace);

// calculated at run time
EQClass::CCamera** EQ_CLASS_POINTER_CCamera_pptr;
EQClass::CCamera* EQ_CLASS_POINTER_CCamera;

/* CRender */

class EQClass::CRender
{
public:
    bool CRender::ResetDevice(bool unknown);
    bool CRender::DrawLine(EQ::Vector3f& vectorBegin, EQ::Vector3f& vectorEnd, uint32_t colorARGB);
    bool CRender::DrawWrappedText(uint32_t fontStyle, const char* text, EQ::CXRect& cxrect1, EQ::CXRect& cxrect2, uint32_t colorARGB, uint16_t flags, int startX);
    bool CRender::DrawColoredRectangle(EQ::Rectangle& rectangle, uint32_t colorARGB);
    void CRender::ClearRenderToBlack();
    void CRender::RenderPartialScene();
    void CRender::UpdateDisplay();
    void CRender::TakeScreenshot(const char* fileName);
};

#define EQ_VFTABLE_INDEX_CRender__InitDevice              0x5C
#define EQ_VFTABLE_INDEX_CRender__ResetDevice             0x64    // "ResetDevice() failed!"
#define EQ_VFTABLE_INDEX_CRender__DrawLine                0x88
#define EQ_VFTABLE_INDEX_CRender__DrawWrappedText         0x94
#define EQ_VFTABLE_INDEX_CRender__DrawColoredRectangle    0xA0    // "*ScreenShot.jpg"
#define EQ_VFTABLE_INDEX_CRender__ClearRenderToBlack      0xA8
#define EQ_VFTABLE_INDEX_CRender__RenderPartialScene      0xAC
#define EQ_VFTABLE_INDEX_CRender__RenderUNKNOWN           0xB0    // draws something, called after ClearRenderToBlack() while blind
#define EQ_VFTABLE_INDEX_CRender__UpdateDisplay           0xB4
#define EQ_VFTABLE_INDEX_CRender__TakeScreenshot          0xC4

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(bool EQClass::CRender::ResetDevice(bool unknown), EQ_VFTABLE_INDEX_CRender__ResetDevice);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CRender__ResetDevice)(void* this_ptr, bool unknown);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(bool EQClass::CRender::DrawLine(EQ::Vector3f& vectorBegin, EQ::Vector3f& vectorEnd, uint32_t colorARGB), EQ_VFTABLE_INDEX_CRender__DrawLine);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(bool EQClass::CRender::DrawWrappedText(uint32_t fontStyle, const char* text, EQ::CXRect& cxrect1, EQ::CXRect& cxrect2, uint32_t colorARGB, uint16_t flags, int startX), EQ_VFTABLE_INDEX_CRender__DrawWrappedText);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(bool EQClass::CRender::DrawColoredRectangle(EQ::Rectangle& rectangle, uint32_t colorARGB), EQ_VFTABLE_INDEX_CRender__DrawColoredRectangle);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(void EQClass::CRender::ClearRenderToBlack(), EQ_VFTABLE_INDEX_CRender__ClearRenderToBlack);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CRender__ClearRenderToBlack)(void* this_ptr);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(void EQClass::CRender::RenderPartialScene(), EQ_VFTABLE_INDEX_CRender__RenderPartialScene);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CRender__RenderPartialScene)(void* this_ptr);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(void EQClass::CRender::UpdateDisplay(), EQ_VFTABLE_INDEX_CRender__UpdateDisplay);
typedef int (__thiscall* EQ_FUNCTION_TYPE_CRender__UpdateDisplay)(void* this_ptr);

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(void EQClass::CRender::TakeScreenshot(const char* fileName), EQ_VFTABLE_INDEX_CRender__TakeScreenshot);

EQClass::CRender** EQ_CLASS_POINTER_CRender_pptr;
EQClass::CRender* EQ_CLASS_POINTER_CRender;

/**************************************************/

class EQClass::CVector3
{
public:
    float X;
    float Y;
    float Z;

    float CVector3::NormalizeAndReturnLength(void);
    void CVector3::Normalize(void);

    void CVector3::Set(float x, float y, float z)
    {
        X = x;
        Y = y;
        Z = z;
    }

    inline CVector3& operator-=(const CVector3& vec)
    {
        X -= vec.X;
        Y -= vec.Y;
        Z -= vec.Z;

        return *this;
    }

    inline CVector3& operator+=(const CVector3& vec)
    {
        X += vec.X;
        Y += vec.Y;
        Z += vec.Z;

        return *this;
    }

    inline void Scale(float value)
    {
        X *= value;
        Y *= value;
        Z *= value;
    }

    inline CVector3 operator*(float value) const
    {
        CVector3 vector(*this);
        vector.Scale(value);
        return vector;
    }

    void SetMax()
    {
        X = Y = Z = 3.402823466e+38F;
    }

    float GetLengthSquared() const
    {
        return ((X * X) + (Y * Y) + (Z * Z));
    }

    float GetLength() const
    { 
        return std::sqrtf(GetLengthSquared());
    }

    CVector3 operator-() const
    {
        CVector3 vector;
        vector.Set(-X, -Y, -Z);
        return vector;
    }

    CVector3 operator-(const CVector3& vector) const
    {
        CVector3 result;
        result.Set(X - vector.X, Y - vector.Y, Z - vector.Z);
        return result;
    }

    CVector3 operator+(const CVector3& vector) const
    {
        CVector3 result;
        result.Set(vector.X + X, vector.Y + Y, vector.Z + Z);
        return result;
    }

    float GetDistanceSquared(const CVector3& vector) const
    {
        CVector3 result = *this - vector;
        return result.GetLengthSquared();
    }
};

/**************************************************/

class EQClass::CActorEx
{
public:
    bool CActorEx::CanSetName(uint32_t zero);
    void CActorEx::SetNameColor(uint32_t& colorARGB);
    void CActorEx::ChangeBoneStringSprite(int, int, char* text);
};

#define EQ_VFTABLE_INDEX_CActorEx__CanSetName                0x1A8
#define EQ_VFTABLE_INDEX_CActorEx__SetNameColor              0x194
#define EQ_VFTABLE_INDEX_CActorEx__ChangeBoneStringSprite    0x190

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(bool EQClass::CActorEx::CanSetName(uint32_t zero), EQ_VFTABLE_INDEX_CActorEx__CanSetName);
EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(void EQClass::CActorEx::SetNameColor(uint32_t& colorARGB), EQ_VFTABLE_INDEX_CActorEx__SetNameColor);
EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(void EQClass::CActorEx::ChangeBoneStringSprite(int, int, char* text), EQ_VFTABLE_INDEX_CActorEx__ChangeBoneStringSprite);

/**************************************************/

#ifdef EQ_FEATURE_CollisionCallbackForActors

// these classes are unknown and used in the game's CollisionCallbackForActors() function
// we use them to disable collision with players in the eqapp_actorcollision.h header

class CCollisionCallbackForActors1
{
public:
    uint32_t CCollisionCallbackForActors1::Call_0x20();
    uint32_t CCollisionCallbackForActors1::Call_0x30();
};

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(uint32_t CCollisionCallbackForActors1::Call_0x20(), 0x20);
EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(uint32_t CCollisionCallbackForActors1::Call_0x30(), 0x30);

class CCollisionCallbackForActors2
{
public:
    uint32_t CCollisionCallbackForActors2::Call_0x0C();
};

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(uint32_t CCollisionCallbackForActors2::Call_0x0C(), 0x0C);

class CCollisionCallbackForActors3
{
public:
    uint32_t CCollisionCallbackForActors3::Call_0x44();
};

EQ_MACRO_FUNCTION_FunctionAtVirtualAddress(uint32_t CCollisionCallbackForActors3::Call_0x44(), 0x44);

#endif // EQ_FEATURE_CollisionCallbackForActors
