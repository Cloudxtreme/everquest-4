#pragma once

// direct input key scan codes (DIK_*)
#define EQ_KEY_NULL            0x00
#define EQ_KEY_ESCAPE          0x01
#define EQ_KEY_1               0x02
#define EQ_KEY_2               0x03
#define EQ_KEY_3               0x04
#define EQ_KEY_4               0x05
#define EQ_KEY_5               0x06
#define EQ_KEY_6               0x07
#define EQ_KEY_7               0x08
#define EQ_KEY_8               0x09
#define EQ_KEY_9               0x0A
#define EQ_KEY_0               0x0B
#define EQ_KEY_MINUS           0x0C
#define EQ_KEY_DASH            EQ_KEY_MINUS
#define EQ_KEY_EQUALS          0x0D
#define EQ_KEY_BACK            0x0E
#define EQ_KEY_BACKSPACE       EQ_KEY_BACK
#define EQ_KEY_TAB             0x0F
#define EQ_KEY_Q               0x10
#define EQ_KEY_W               0x11
#define EQ_KEY_E               0x12
#define EQ_KEY_R               0x13
#define EQ_KEY_T               0x14
#define EQ_KEY_Y               0x15
#define EQ_KEY_U               0x16
#define EQ_KEY_I               0x17
#define EQ_KEY_O               0x18
#define EQ_KEY_P               0x19
#define EQ_KEY_LBRACKET        0x1A
#define EQ_KEY_LEFT_BRACKET    EQ_KEY_LBRACKET
#define EQ_KEY_RBRACKET        0x1B
#define EQ_KEY_RIGHT_BRACKET   EQ_KEY_RBRACKET
#define EQ_KEY_RETURN          0x1C
#define EQ_KEY_ENTER           EQ_KEY_RETURN
#define EQ_KEY_LCONTROL        0x1D
#define EQ_KEY_LEFT_CONTROL    EQ_KEY_LCONTROL
#define EQ_KEY_A               0x1E
#define EQ_KEY_S               0x1F
#define EQ_KEY_D               0x20
#define EQ_KEY_F               0x21
#define EQ_KEY_G               0x22
#define EQ_KEY_H               0x23
#define EQ_KEY_J               0x24
#define EQ_KEY_K               0x25
#define EQ_KEY_L               0x26
#define EQ_KEY_SEMICOLON       0x27
#define EQ_KEY_APOSTROPHE      0x28
#define EQ_KEY_GRAVE           0x29
#define EQ_KEY_TILDE           EQ_KEY_GRAVE
#define EQ_KEY_LSHIFT          0x2A
#define EQ_KEY_LEFT_SHIFT      EQ_KEY_LSHIFT
#define EQ_KEY_BACKSLASH       0x2B
#define EQ_KEY_Z               0x2C
#define EQ_KEY_X               0x2D
#define EQ_KEY_C               0x2E
#define EQ_KEY_V               0x2F
#define EQ_KEY_B               0x30
#define EQ_KEY_N               0x31
#define EQ_KEY_M               0x32
#define EQ_KEY_COMMA           0x33
#define EQ_KEY_PERIOD          0x34
#define EQ_KEY_SLASH           0x35
#define EQ_KEY_RSHIFT          0x36
#define EQ_KEY_RIGHT_SHIFT     EQ_KEY_RSHIFT
#define EQ_KEY_MULTIPLY        0x37
#define EQ_KEY_NUMPADSTAR      EQ_KEY_NUMPAD_MULTIPLY
#define EQ_KEY_NUMPAD_MULTIPLY EQ_KEY_NUMPAD_MULTIPLY
#define EQ_KEY_LMENU           0x38
#define EQ_KEY_LALT            EQ_KEY_LMENU
#define EQ_KEY_LEFT_LALT       EQ_KEY_LMENU
#define EQ_KEY_SPACE           0x39
#define EQ_KEY_SPACEBAR        EQ_KEY_SPACE
#define EQ_KEY_CAPITAL         0x3A
#define EQ_KEY_CAPSLOCK        EQ_KEY_CAPITAL
#define EQ_KEY_CAPS_LOCK       EQ_KEY_CAPITAL
#define EQ_KEY_F1              0x3B
#define EQ_KEY_F2              0x3C
#define EQ_KEY_F3              0x3D
#define EQ_KEY_F4              0x3E
#define EQ_KEY_F5              0x3F
#define EQ_KEY_F6              0x40
#define EQ_KEY_F7              0x41
#define EQ_KEY_F8              0x42
#define EQ_KEY_F9              0x43
#define EQ_KEY_F10             0x44
#define EQ_KEY_NUMLOCK         0x45
#define EQ_KEY_NUM_LOCK        EQ_KEY_NUMLOCK
#define EQ_KEY_SCROLL          0x46
#define EQ_KEY_SCROLL_LOCK     EQ_KEY_SCROLL
#define EQ_KEY_NUMPAD7         0x47
#define EQ_KEY_NUMPAD8         0x48
#define EQ_KEY_NUMPAD9         0x49
#define EQ_KEY_SUBTRACT        0x4A
#define EQ_KEY_NUMPADMINUS     EQ_KEY_SUBTRACT
#define EQ_KEY_NUMPAD_SUBTRACT EQ_KEY_SUBTRACT
#define EQ_KEY_NUMPAD4         0x4B
#define EQ_KEY_NUMPAD5         0x4C
#define EQ_KEY_NUMPAD6         0x4D
#define EQ_KEY_ADD             0x4E
#define EQ_KEY_NUMPADPLUS      0x4E
#define EQ_KEY_NUMPAD_ADD      0x4E
#define EQ_KEY_NUMPAD1         0x4F
#define EQ_KEY_NUMPAD2         0x50
#define EQ_KEY_NUMPAD3         0x51
#define EQ_KEY_NUMPAD0         0x52
#define EQ_KEY_DECIMAL         0x53
#define EQ_KEY_NUMPADPERIOD    EQ_KEY_DECIMAL
#define EQ_KEY_NUMPAD_PERIOD   EQ_KEY_DECIMAL
#define EQ_KEY_OEM_102         0x56
#define EQ_KEY_F11             0x57
#define EQ_KEY_F12             0x58
#define EQ_KEY_F13             0x64
#define EQ_KEY_F14             0x65
#define EQ_KEY_F15             0x66
#define EQ_KEY_KANA            0x70
#define EQ_KEY_ABNT_C1         0x73
#define EQ_KEY_CONVERT         0x79
#define EQ_KEY_NOCONVERT       0x7B
#define EQ_KEY_NO_CONVERT      EQ_KEY_NOCONVERT
#define EQ_KEY_YEN             0x7D
#define EQ_KEY_ABNT_C2         0x7E
#define EQ_KEY_NUMPADEQUALS    0x8D
#define EQ_KEY_NUMPAD_EQUALS   EQ_KEY_NUMPADEQUALS
#define EQ_KEY_PREVTRACK       0x90
#define EQ_KEY_CIRCUMFLEX      EQ_KEY_PREVTRACK
#define EQ_KEY_PREV_TRACK      EQ_KEY_PREVTRACK
#define EQ_KEY_AT              0x91
#define EQ_KEY_COLON           0x92
#define EQ_KEY_UNDERLINE       0x93
#define EQ_KEY_KANJI           0x94
#define EQ_KEY_STOP            0x95
#define EQ_KEY_AX              0x96
#define EQ_KEY_UNLABELED       0x97
#define EQ_KEY_NEXTTRACK       0x99
#define EQ_KEY_NEXT_TRACK      EQ_KEY_NEXTTRACK
#define EQ_KEY_NUMPADENTER     0x9C
#define EQ_KEY_NUMPAD_ENTER    EQ_KEY_NUMPADENTER
#define EQ_KEY_RCONTROL        0x9D
#define EQ_KEY_RIGHT_CONTROL   EQ_KEY_RCONTROL
#define EQ_KEY_MUTE            0xA0
#define EQ_KEY_CALCULATOR      0xA1
#define EQ_KEY_PLAYPAUSE       0xA2
#define EQ_KEY_PLAY_PAUSE      EQ_KEY_PLAYPAUSE
#define EQ_KEY_MEDIASTOP       0xA4
#define EQ_KEY_MEDIA_STOP      EQ_KEY_MEDIASTOP
#define EQ_KEY_VOLUMEDOWN      0xAE
#define EQ_KEY_VOLUME_DOWN     EQ_KEY_VOLUMEDOWN
#define EQ_KEY_VOLUMEUP        0xB0
#define EQ_KEY_VOLUME_UP       EQ_KEY_VOLUMEUP
#define EQ_KEY_WEBHOME         0xB2
#define EQ_KEY_WEB_HOME        EQ_KEY_WEBHOME
#define EQ_KEY_NUMPADCOMMA     0xB3
#define EQ_KEY_NUMPAD_COMMA    EQ_KEY_NUMPADCOMMA
#define EQ_KEY_DIVIDE          0xB5
#define EQ_KEY_NUMPADSLASH     EQ_KEY_DIVIDE
#define EQ_KEY_NUMPAD_DIVIDE   EQ_KEY_DIVIDE
#define EQ_KEY_SYSRQ           0xB7
#define EQ_KEY_RMENU           0xB8
#define EQ_KEY_RALT            EQ_KEY_RMENU
#define EQ_KEY_RIGHT_ALT       EQ_KEY_RMENU
#define EQ_KEY_PAUSE           0xC5
#define EQ_KEY_HOME            0xC7
#define EQ_KEY_UP              0xC8
#define EQ_KEY_UPARROW         EQ_KEY_UP
#define EQ_KEY_UP_ARROW        EQ_KEY_UP
#define EQ_KEY_PRIOR           0xC9
#define EQ_KEY_PGUP            EQ_KEY_PRIOR
#define EQ_KEY_PAGE_UP         EQ_KEY_PRIOR
#define EQ_KEY_LEFT            0xCB
#define EQ_KEY_LEFTARROW       EQ_KEY_LEFT
#define EQ_KEY_LEFT_ARROW      EQ_KEY_LEFT
#define EQ_KEY_RIGHT           0xCD
#define EQ_KEY_RIGHTARROW      EQ_KEY_RIGHT
#define EQ_KEY_RIGHT_ARROW     EQ_KEY_RIGHT
#define EQ_KEY_END             0xCF
#define EQ_KEY_DOWN            0xD0
#define EQ_KEY_DOWNARROW       EQ_KEY_DOWN
#define EQ_KEY_DOWN_ARROW      EQ_KEY_DOWN
#define EQ_KEY_NEXT            0xD1
#define EQ_KEY_PGDN            EQ_KEY_NEXT
#define EQ_KEY_PAGE_DOWN       EQ_KEY_NEXT
#define EQ_KEY_INSERT          0xD2
#define EQ_KEY_DELETE          0xD3
#define EQ_KEY_LWIN            0xDB
#define EQ_KEY_LEFT_START      EQ_KEY_LWIN
#define EQ_KEY_RWIN            0xDC
#define EQ_KEY_RIGHT_START     EQ_KEY_RWIN
#define EQ_KEY_APPS            0xDD
#define EQ_KEY_POWER           0xDE
#define EQ_KEY_SLEEP           0xDF
#define EQ_KEY_WAKE            0xE3
#define EQ_KEY_WEBSEARCH       0xE5
#define EQ_KEY_WEB_SEARCH      EQ_KEY_WEBSEARCH
#define EQ_KEY_WEBFAVORITES    0xE6
#define EQ_KEY_WEB_FAVORITES   EQ_KEY_WEBFAVORITES
#define EQ_KEY_WEBREFRESH      0xE7
#define EQ_KEY_WEB_REFRESH     EQ_KEY_WEBREFRESH
#define EQ_KEY_WEBSTOP         0xE8
#define EQ_KEY_WEB_STOP        EQ_KEY_WEBSTOP
#define EQ_KEY_WEBFORWARD      0xE9
#define EQ_KEY_WEB_FORWARD     EQ_KEY_WEBFORWARD
#define EQ_KEY_WEBBACK         0xEA
#define EQ_KEY_WEB_BACK        EQ_KEY_WEBBACK
#define EQ_KEY_MYCOMPUTER      0xEB
#define EQ_KEY_MY_COMPUTER     EQ_KEY_MYCOMPUTER
#define EQ_KEY_MAIL            0xEC
#define EQ_KEY_MEDIASELECT     0xED
#define EQ_KEY_MEDIA_SELECT    EQ_KEY_MEDIASELECT
