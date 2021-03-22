#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>

#include <kbd.h>

#if defined(_M_IA64)
#pragma section(".data")
#define ALLOC_SECTION_LDATA __declspec(allocate(".data"))
#else
#pragma data_seg(".data")
#define ALLOC_SECTION_LDATA
#endif

/***************************************************************************\
* ausVK[] - Virtual Scan Code to Virtual Key conversion table
\***************************************************************************/

static ALLOC_SECTION_LDATA USHORT ausVK[] = {
    T00, T01, T02, T03, T04, T05, T06, T07,
    T08, T09, T0A, T0B, T0C, T0D, T0E, T0F,
    T10, T11, T12, T13, T14, T15, T16, T17,
    T18, T19, T1A, T1B, T1C, T1D, T1E, T1F,
    T20, T21, T22, T23, T24, T25, T26, T27,
    T28, T29, T2A, T2B, T2C, T2D, T2E, T2F,
    T30, T31, T32, T33, T34, T35,

    /*
     * Right-hand Shift key must have KBDEXT bit set.
     */
    T36 | KBDEXT,

    T37 | KBDMULTIVK,               // numpad_* + Shift/Alt -> SnapShot

    T38, T39, T3A, T3B, T3C, T3D, T3E,
    T3F, T40, T41, T42, T43, T44,

    /*
     * NumLock Key:
     *     KBDEXT     - VK_NUMLOCK is an Extended key
     *     KBDMULTIVK - VK_NUMLOCK or VK_PAUSE (without or with CTRL)
     */
    T45 | KBDEXT | KBDMULTIVK,

    T46 | KBDMULTIVK,

    /*
     * Number Pad keys:
     *     KBDNUMPAD  - digits 0-9 and decimal point.
     *     KBDSPECIAL - require special processing by Windows
     */
    T47 | KBDNUMPAD | KBDSPECIAL,   // Numpad 7 (Home)
    T48 | KBDNUMPAD | KBDSPECIAL,   // Numpad 8 (Up),
    T49 | KBDNUMPAD | KBDSPECIAL,   // Numpad 9 (PgUp),
    T4A,
    T4B | KBDNUMPAD | KBDSPECIAL,   // Numpad 4 (Left),
    T4C | KBDNUMPAD | KBDSPECIAL,   // Numpad 5 (Clear),
    T4D | KBDNUMPAD | KBDSPECIAL,   // Numpad 6 (Right),
    T4E,
    T4F | KBDNUMPAD | KBDSPECIAL,   // Numpad 1 (End),
    T50 | KBDNUMPAD | KBDSPECIAL,   // Numpad 2 (Down),
    T51 | KBDNUMPAD | KBDSPECIAL,   // Numpad 3 (PgDn),
    T52 | KBDNUMPAD | KBDSPECIAL,   // Numpad 0 (Ins),
    T53 | KBDNUMPAD | KBDSPECIAL,   // Numpad . (Del),

    T54, T55, T56, T57, T58, T59, T5A, T5B,
    T5C, T5D, T5E, T5F, T60, T61, T62, T63,
    T64, T65, T66, T67, T68, T69, T6A, T6B,
    T6C, T6D, T6E, T6F, T70, T71, T72, T73,
    T74, T75, T76, T77, T78, T79, T7A, T7B,
    T7C, T7D, T7E

};

static ALLOC_SECTION_LDATA VSC_VK aE0VscToVk[] = {
        { 0x10, X10 | KBDEXT              },  // Speedracer: Previous Track
        { 0x19, X19 | KBDEXT              },  // Speedracer: Next Track
        { 0x1D, X1D | KBDEXT              },  // RControl
        { 0x20, X20 | KBDEXT              },  // Speedracer: Volume Mute
        { 0x21, X21 | KBDEXT              },  // Speedracer: Launch App 2
        { 0x22, X22 | KBDEXT              },  // Speedracer: Media Play/Pause
        { 0x24, X24 | KBDEXT              },  // Speedracer: Media Stop
        { 0x2E, X2E | KBDEXT              },  // Speedracer: Volume Down
        { 0x30, X30 | KBDEXT              },  // Speedracer: Volume Up
        { 0x32, X32 | KBDEXT              },  // Speedracer: Browser Home
        { 0x35, X35 | KBDEXT              },  // Numpad Divide
        { 0x37, X37 | KBDEXT              },  // Snapshot
        { 0x38, X38 | KBDEXT              },  // RMenu
        { 0x47, X47 | KBDEXT              },  // Home
        { 0x48, X48 | KBDEXT              },  // Up
        { 0x49, X49 | KBDEXT              },  // Prior
        { 0x4B, X4B | KBDEXT              },  // Left
        { 0x4D, X4D | KBDEXT              },  // Right
        { 0x4F, X4F | KBDEXT              },  // End
        { 0x50, X50 | KBDEXT              },  // Down
        { 0x51, X51 | KBDEXT              },  // Next
        { 0x52, X52 | KBDEXT              },  // Insert
        { 0x53, X53 | KBDEXT              },  // Delete
        { 0x5B, X5B | KBDEXT              },  // Left Win
        { 0x5C, X5C | KBDEXT              },  // Right Win
        { 0x5D, X5D | KBDEXT              },  // Application
        { 0x5F, X5F | KBDEXT              },  // Speedracer: Sleep
        { 0x65, X65 | KBDEXT              },  // Speedracer: Browser Search
        { 0x66, X66 | KBDEXT              },  // Speedracer: Browser Favorites
        { 0x67, X67 | KBDEXT              },  // Speedracer: Browser Refresh
        { 0x68, X68 | KBDEXT              },  // Speedracer: Browser Stop
        { 0x69, X69 | KBDEXT              },  // Speedracer: Browser Forward
        { 0x6A, X6A | KBDEXT              },  // Speedracer: Browser Back
        { 0x6B, X6B | KBDEXT              },  // Speedracer: Launch App 1
        { 0x6C, X6C | KBDEXT              },  // Speedracer: Launch Mail
        { 0x6D, X6D | KBDEXT              },  // Speedracer: Launch Media Selector
        { 0x1C, X1C | KBDEXT              },  // Numpad Enter
        { 0x46, X46 | KBDEXT              },  // Break (Ctrl + Pause)
        { 0,      0                       }
};

static ALLOC_SECTION_LDATA VSC_VK aE1VscToVk[] = {
        { 0x1D, Y1D                       },  // Pause
        { 0   ,   0                       }
};

/***************************************************************************\
* aVkToBits[]  - map Virtual Keys to Modifier Bits
*
* See kbd.h for a full description.
*
* The keyboard has only three shifter keys:
*     SHIFT (L & R) affects alphabnumeric keys,
*     CTRL  (L & R) is used to generate control characters
*     ALT   (L & R) used for generating characters by number with numpad
\***************************************************************************/
static ALLOC_SECTION_LDATA VK_TO_BIT aVkToBits[] = {
    { VK_SHIFT    ,   KBDSHIFT     },
    { VK_CONTROL  ,   KBDCTRL      },
    { VK_MENU     ,   KBDALT       },
    { 0           ,   0           }
};

/***************************************************************************\
* aModification[]  - map character modifier bits to modification number
*
* See kbd.h for a full description.
*
\***************************************************************************/

static ALLOC_SECTION_LDATA MODIFIERS CharModifiers = {
    &aVkToBits[0],
    7,
    {
    //  Modification# //  Keys Pressed
    //  ============= // =============
        0,            // 
        1,            // Shift 
        2,            // Control 
        SHFT_INVALID, // Shift + Control 
        SHFT_INVALID, // Menu 
        SHFT_INVALID, // Shift + Menu 
        3,            // Control + Menu 
        4             // Shift + Control + Menu 
     }
};

/***************************************************************************\
*
* aVkToWch2[]  - Virtual Key to WCHAR translation for 2 shift states
* aVkToWch3[]  - Virtual Key to WCHAR translation for 3 shift states
* aVkToWch4[]  - Virtual Key to WCHAR translation for 4 shift states
* aVkToWch5[]  - Virtual Key to WCHAR translation for 5 shift states
* aVkToWch6[]  - Virtual Key to WCHAR translation for 6 shift states
*
* Table attributes: Unordered Scan, null-terminated
*
* Search this table for an entry with a matching Virtual Key to find the
* corresponding unshifted and shifted WCHAR characters.
*
* Special values for VirtualKey (column 1)
*     0xff          - dead chars for the previous entry
*     0             - terminate the list
*
* Special values for Attributes (column 2)
*     CAPLOK bit    - CAPS-LOCK affect this key like SHIFT
*
* Special values for wch[*] (column 3 & 4)
*     WCH_NONE      - No character
*     WCH_DEAD      - Dead Key (diaresis) or invalid (US keyboard has none)
*     WCH_LGTR      - Ligature (generates multiple characters)
*
\***************************************************************************/

static ALLOC_SECTION_LDATA VK_TO_WCHARS2 aVkToWch2[] = {
//                      |         |  Shift  |
//                      |=========|=========|
  {VK_TAB       ,0      ,'\t'     ,'\t'     },
  {VK_ADD       ,0      ,'+'      ,'+'      },
  {VK_DIVIDE    ,0      ,'/'      ,'/'      },
  {VK_MULTIPLY  ,0      ,'*'      ,'*'      },
  {VK_SUBTRACT  ,0      ,'-'      ,'-'      },
  {0            ,0      ,0        ,0        }
};

static ALLOC_SECTION_LDATA VK_TO_WCHARS3 aVkToWch3[] = {
//                      |         |  Shift  |  Ctrl   |
//                      |=========|=========|=========|
  {VK_BACK      ,0      ,'\b'     ,'\b'     ,0x007f   },
  {VK_ESCAPE    ,0      ,0x001b   ,0x001b   ,0x001b   },
  {VK_RETURN    ,0      ,'\r'     ,'\r'     ,'\n'     },
  {VK_CANCEL    ,0      ,0x0003   ,0x0003   ,0x0003   },
  {0            ,0      ,0        ,0        ,0        }
};

static ALLOC_SECTION_LDATA VK_TO_WCHARS5 aVkToWch5[] = {
//                      |         |  Shift  |  Ctrl   |  Ctl+Alt|S+Ctl+Alt|
//                      |=========|=========|=========|=========|=========|
  {'1'          ,0      ,'1'      ,'!'      ,WCH_NONE ,0x00a1   ,0x00b9   },
  {'2'          ,0      ,'2'      ,'@'      ,WCH_NONE ,0x00b2   ,WCH_NONE },
  {'3'          ,0      ,'3'      ,'#'      ,WCH_NONE ,0x00b3   ,WCH_NONE },
  {'4'          ,0      ,'4'      ,'$'      ,WCH_NONE ,0x00a4   ,0x00a3   },
  {'5'          ,0      ,'5'      ,'%'      ,WCH_NONE ,0x20ac   ,WCH_NONE },
  {'6'          ,0      ,'6'      ,WCH_DEAD ,WCH_NONE ,0x00bc   ,WCH_NONE },
  {0xff         ,0      ,WCH_NONE ,'^'      ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'7'          ,0      ,'7'      ,'&'      ,WCH_NONE ,0x00bd   ,WCH_NONE },
  {'8'          ,0      ,'8'      ,'*'      ,WCH_NONE ,0x00be   ,WCH_NONE },
  {'9'          ,0      ,'9'      ,'('      ,WCH_NONE ,0x2018   ,WCH_NONE },
  {'0'          ,0      ,'0'      ,')'      ,WCH_NONE ,0x2019   ,WCH_NONE },
  {VK_OEM_MINUS ,0      ,'-'      ,'_'      ,WCH_NONE ,0x00a5   ,WCH_NONE },
  {VK_OEM_PLUS  ,0      ,'='      ,'+'      ,WCH_NONE ,0x00d7   ,0x00f7   },
  {'Q'          ,CAPLOK | CAPLOKALTGR,'q'      ,'Q'      ,WCH_NONE ,0x00e4   ,0x00c4   },
  {'W'          ,CAPLOK | CAPLOKALTGR,'w'      ,'W'      ,WCH_NONE ,0x00e5   ,0x00c5   },
  {'E'          ,CAPLOK | CAPLOKALTGR,'e'      ,'E'      ,WCH_NONE ,0x00e9   ,0x00c9   },
  {'R'          ,CAPLOK ,'r'      ,'R'      ,WCH_NONE ,0x00ae   ,WCH_NONE },
  {'T'          ,CAPLOK | CAPLOKALTGR,'t'      ,'T'      ,WCH_NONE ,0x00fe   ,0x00de   },
  {'Y'          ,CAPLOK | CAPLOKALTGR,'y'      ,'Y'      ,WCH_NONE ,0x00fc   ,0x00dc   },
  {'U'          ,CAPLOK | CAPLOKALTGR,'u'      ,'U'      ,WCH_NONE ,0x00fa   ,0x00da   },
  {'I'          ,CAPLOK | CAPLOKALTGR,'i'      ,'I'      ,WCH_NONE ,0x00ed   ,0x00cd   },
  {'O'          ,CAPLOK | CAPLOKALTGR,'o'      ,'O'      ,WCH_NONE ,0x00f3   ,0x00d3   },
  {'P'          ,CAPLOK | CAPLOKALTGR,'p'      ,'P'      ,WCH_NONE ,0x00f6   ,0x00d6   },
  {VK_OEM_4     ,0      ,'['      ,'{'      ,0x001b   ,0x00ab   ,WCH_NONE },
  {VK_OEM_6     ,0      ,']'      ,'}'      ,0x001d   ,0x00bb   ,WCH_NONE },
  {'A'          ,CAPLOK | CAPLOKALTGR,'a'      ,'A'      ,WCH_NONE ,0x00e1   ,0x00c1   },
  {'S'          ,CAPLOK ,'s'      ,'S'      ,WCH_NONE ,0x00df   ,0x00a7   },
  {'D'          ,CAPLOK | CAPLOKALTGR,'d'      ,'D'      ,WCH_NONE ,0x00f0   ,0x00d0   },
  {'F'          ,CAPLOK ,'f'      ,'F'      ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'G'          ,CAPLOK ,'g'      ,'G'      ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'H'          ,CAPLOK ,'h'      ,'H'      ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'J'          ,CAPLOK ,'j'      ,'J'      ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'K'          ,CAPLOK ,'k'      ,'K'      ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'L'          ,CAPLOK | CAPLOKALTGR,'l'      ,'L'      ,WCH_NONE ,0x00f8   ,0x00d8   },
  {VK_OEM_1     ,0      ,';'      ,':'      ,WCH_NONE ,0x00b6   ,0x00b0   },
  {VK_OEM_7     ,0      ,WCH_DEAD ,WCH_DEAD ,WCH_NONE ,0x00b4   ,0x00a8   },
  {0xff         ,0      ,'\''     ,'\"'     ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_3     ,0      ,WCH_DEAD ,WCH_DEAD ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {0xff         ,0      ,'`'      ,'~'      ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_5     ,0      ,'\\'     ,'|'      ,0x001c   ,0x00ac   ,0x00a6   },
  {'Z'          ,CAPLOK | CAPLOKALTGR,'z'      ,'Z'      ,WCH_NONE ,0x00e6   ,0x00c6   },
  {'X'          ,CAPLOK ,'x'      ,'X'      ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'C'          ,CAPLOK ,'c'      ,'C'      ,WCH_NONE ,0x00a9   ,0x00a2   },
  {'V'          ,CAPLOK ,'v'      ,'V'      ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'B'          ,CAPLOK ,'b'      ,'B'      ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {'N'          ,CAPLOK | CAPLOKALTGR,'n'      ,'N'      ,WCH_NONE ,0x00f1   ,0x00d1   },
  {'M'          ,CAPLOK ,'m'      ,'M'      ,WCH_NONE ,0x00b5   ,WCH_NONE },
  {VK_OEM_COMMA ,CAPLOKALTGR,','      ,'<'      ,WCH_NONE ,0x00e7   ,0x00c7   },
  {VK_OEM_PERIOD,0      ,'.'      ,'>'      ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {VK_OEM_2     ,0      ,'/'      ,'?'      ,WCH_NONE ,0x00bf   ,WCH_NONE },
  {VK_SPACE     ,0      ,' '      ,' '      ,' '      ,WCH_NONE ,WCH_NONE },
  {VK_OEM_102   ,0      ,'\\'     ,'|'      ,0x001c   ,WCH_NONE ,WCH_NONE },
  {VK_DECIMAL   ,0      ,'.'      ,'.'      ,WCH_NONE ,WCH_NONE ,WCH_NONE },
  {0            ,0      ,0        ,0        ,0        ,0        ,0        }
};

// Put this last so that VkKeyScan interprets number characters
// as coming from the main section of the kbd (aVkToWch2 and
// aVkToWch5) before considering the numpad (aVkToWch1).

static ALLOC_SECTION_LDATA VK_TO_WCHARS1 aVkToWch1[] = {
    { VK_NUMPAD0   , 0      ,  '0'   },
    { VK_NUMPAD1   , 0      ,  '1'   },
    { VK_NUMPAD2   , 0      ,  '2'   },
    { VK_NUMPAD3   , 0      ,  '3'   },
    { VK_NUMPAD4   , 0      ,  '4'   },
    { VK_NUMPAD5   , 0      ,  '5'   },
    { VK_NUMPAD6   , 0      ,  '6'   },
    { VK_NUMPAD7   , 0      ,  '7'   },
    { VK_NUMPAD8   , 0      ,  '8'   },
    { VK_NUMPAD9   , 0      ,  '9'   },
    { 0            , 0      ,  '\0'  }
};

static ALLOC_SECTION_LDATA VK_TO_WCHAR_TABLE aVkToWcharTable[] = {
    {  (PVK_TO_WCHARS1)aVkToWch3, 3, sizeof(aVkToWch3[0]) },
    {  (PVK_TO_WCHARS1)aVkToWch5, 5, sizeof(aVkToWch5[0]) },
    {  (PVK_TO_WCHARS1)aVkToWch2, 2, sizeof(aVkToWch2[0]) },
    {  (PVK_TO_WCHARS1)aVkToWch1, 1, sizeof(aVkToWch1[0]) },
    {                       NULL, 0, 0                    },
};

/***************************************************************************\
* aKeyNames[], aKeyNamesExt[]  - Virtual Scancode to Key Name tables
*
* Table attributes: Ordered Scan (by scancode), null-terminated
*
* Only the names of Extended, NumPad, Dead and Non-Printable keys are here.
* (Keys producing printable characters are named by that character)
\***************************************************************************/

static ALLOC_SECTION_LDATA VSC_LPWSTR aKeyNames[] = {
    0x01,    L"Esc",
    0x0e,    L"Backspace",
    0x0f,    L"Tab",
    0x1c,    L"Enter",
    0x1d,    L"Ctrl",
    0x2a,    L"Shift",
    0x36,    L"Right Shift",
    0x37,    L"Num *",
    0x38,    L"Alt",
    0x39,    L"Space",
    0x3a,    L"Caps Lock",
    0x3b,    L"F1",
    0x3c,    L"F2",
    0x3d,    L"F3",
    0x3e,    L"F4",
    0x3f,    L"F5",
    0x40,    L"F6",
    0x41,    L"F7",
    0x42,    L"F8",
    0x43,    L"F9",
    0x44,    L"F10",
    0x45,    L"Pause",
    0x46,    L"Scroll Lock",
    0x47,    L"Num 7",
    0x48,    L"Num 8",
    0x49,    L"Num 9",
    0x4a,    L"Num -",
    0x4b,    L"Num 4",
    0x4c,    L"Num 5",
    0x4d,    L"Num 6",
    0x4e,    L"Num +",
    0x4f,    L"Num 1",
    0x50,    L"Num 2",
    0x51,    L"Num 3",
    0x52,    L"Num 0",
    0x53,    L"Num Del",
    0x54,    L"Sys Req",
    0x57,    L"F11",
    0x58,    L"F12",
    0x7c,    L"F13",
    0x7d,    L"F14",
    0x7e,    L"F15",
    0x7f,    L"F16",
    0x80,    L"F17",
    0x81,    L"F18",
    0x82,    L"F19",
    0x83,    L"F20",
    0x84,    L"F21",
    0x85,    L"F22",
    0x86,    L"F23",
    0x87,    L"F24",
    0   ,    NULL
};

static ALLOC_SECTION_LDATA VSC_LPWSTR aKeyNamesExt[] = {
    0x1c,    L"Num Enter",
    0x1d,    L"Right Ctrl",
    0x35,    L"Num /",
    0x37,    L"Prnt Scrn",
    0x38,    L"Right Alt",
    0x45,    L"Num Lock",
    0x46,    L"Break",
    0x47,    L"Home",
    0x48,    L"Up",
    0x49,    L"Page Up",
    0x4b,    L"Left",
    0x4d,    L"Right",
    0x4f,    L"End",
    0x50,    L"Down",
    0x51,    L"Page Down",
    0x52,    L"Insert",
    0x53,    L"Delete",
    0x54,    L"<00>",
    0x56,    L"Help",
    0x5b,    L"Left Windows",
    0x5c,    L"Right Windows",
    0x5d,    L"Application",
    0   ,    NULL
};

static ALLOC_SECTION_LDATA DEADKEY_LPWSTR aKeyNamesDead[] = {
    L"^"	L"CIRCUMFLEX ACCENT",
    L"\'"	L"APOSTROPHE",
    L"\""	L"QUOTATION MARK",
    L"`"	L"GRAVE ACCENT",
    L"~"	L"TILDE",
    NULL
};

static ALLOC_SECTION_LDATA DEADKEY aDeadKey[] = {
    DEADTRANS( L'a'   , L'^'   , 0x00e2 , 0x0000),
    DEADTRANS( L'e'   , L'^'   , 0x00ea , 0x0000),
    DEADTRANS( L'u'   , L'^'   , 0x00fb , 0x0000),
    DEADTRANS( L'i'   , L'^'   , 0x00ee , 0x0000),
    DEADTRANS( L'o'   , L'^'   , 0x00f4 , 0x0000),
    DEADTRANS( L'A'   , L'^'   , 0x00c2 , 0x0000),
    DEADTRANS( L'E'   , L'^'   , 0x00ca , 0x0000),
    DEADTRANS( L'U'   , L'^'   , 0x00db , 0x0000),
    DEADTRANS( L'I'   , L'^'   , 0x00ce , 0x0000),
    DEADTRANS( L'O'   , L'^'   , 0x00d4 , 0x0000),
    DEADTRANS( L' '   , L'^'   , L'^'   , 0x0000),

    DEADTRANS( L'c'   , '\''   , 0x00e7 , 0x0000),
    DEADTRANS( L'a'   , '\''   , 0x00e1 , 0x0000),
    DEADTRANS( L'e'   , '\''   , 0x00e9 , 0x0000),
    DEADTRANS( L'u'   , '\''   , 0x00fa , 0x0000),
    DEADTRANS( L'i'   , '\''   , 0x00ed , 0x0000),
    DEADTRANS( L'y'   , '\''   , 0x00fd , 0x0000),
    DEADTRANS( L'o'   , '\''   , 0x00f3 , 0x0000),
    DEADTRANS( L'C'   , '\''   , 0x00c7 , 0x0000),
    DEADTRANS( L'A'   , '\''   , 0x00c1 , 0x0000),
    DEADTRANS( L'E'   , '\''   , 0x00c9 , 0x0000),
    DEADTRANS( L'U'   , '\''   , 0x00da , 0x0000),
    DEADTRANS( L'I'   , '\''   , 0x00cd , 0x0000),
    DEADTRANS( L'Y'   , '\''   , 0x00dd , 0x0000),
    DEADTRANS( L'O'   , '\''   , 0x00d3 , 0x0000),
    DEADTRANS( L' '   , '\''   , '\''   , 0x0000),

    DEADTRANS( L'a'   , '\"'   , 0x00e4 , 0x0000),
    DEADTRANS( L'e'   , '\"'   , 0x00eb , 0x0000),
    DEADTRANS( L'u'   , '\"'   , 0x00fc , 0x0000),
    DEADTRANS( L'i'   , '\"'   , 0x00ef , 0x0000),
    DEADTRANS( L'y'   , '\"'   , 0x00ff , 0x0000),
    DEADTRANS( L'o'   , '\"'   , 0x00f6 , 0x0000),
    DEADTRANS( L'A'   , '\"'   , 0x00c4 , 0x0000),
    DEADTRANS( L'E'   , '\"'   , 0x00cb , 0x0000),
    DEADTRANS( L'U'   , '\"'   , 0x00dc , 0x0000),
    DEADTRANS( L'I'   , '\"'   , 0x00cf , 0x0000),
    DEADTRANS( L'O'   , '\"'   , 0x00d6 , 0x0000),
    DEADTRANS( L' '   , '\"'   , '\"'   , 0x0000),

    DEADTRANS( L'a'   , L'`'   , 0x00e0 , 0x0000),
    DEADTRANS( L'e'   , L'`'   , 0x00e8 , 0x0000),
    DEADTRANS( L'u'   , L'`'   , 0x00f9 , 0x0000),
    DEADTRANS( L'i'   , L'`'   , 0x00ec , 0x0000),
    DEADTRANS( L'o'   , L'`'   , 0x00f2 , 0x0000),
    DEADTRANS( L'A'   , L'`'   , 0x00c0 , 0x0000),
    DEADTRANS( L'E'   , L'`'   , 0x00c8 , 0x0000),
    DEADTRANS( L'U'   , L'`'   , 0x00d9 , 0x0000),
    DEADTRANS( L'I'   , L'`'   , 0x00cc , 0x0000),
    DEADTRANS( L'O'   , L'`'   , 0x00d2 , 0x0000),
    DEADTRANS( L' '   , L'`'   , L'`'   , 0x0000),

    DEADTRANS( L'n'   , L'~'   , 0x00f1 , 0x0000),
    DEADTRANS( L'a'   , L'~'   , 0x00e3 , 0x0000),
    DEADTRANS( L'o'   , L'~'   , 0x00f5 , 0x0000),
    DEADTRANS( L'N'   , L'~'   , 0x00d1 , 0x0000),
    DEADTRANS( L'A'   , L'~'   , 0x00c3 , 0x0000),
    DEADTRANS( L'O'   , L'~'   , 0x00d5 , 0x0000),
    DEADTRANS( L' '   , L'~'   , L'~'   , 0x0000),

    0, 0
};

static ALLOC_SECTION_LDATA KBDTABLES KbdTables = {
    /*
     * Modifier keys
     */
    &CharModifiers,

    /*
     * Characters tables
     */
    aVkToWcharTable,

    /*
     * Diacritics
     */
    aDeadKey,

    /*
     * Names of Keys
     */
    aKeyNames,
    aKeyNamesExt,
    aKeyNamesDead,

    /*
     * Scan codes to Virtual Keys
     */
    ausVK,
    sizeof(ausVK) / sizeof(ausVK[0]),
    aE0VscToVk,
    aE1VscToVk,

    /*
     * Locale-specific special processing
     */
    MAKELONG(KLLF_ALTGR, KBD_VERSION),

    /*
     * Ligatures
     */
    0,
    0,
    NULL
};

__declspec(dllexport) PKBDTABLES KbdLayerDescriptor(VOID)
{
    return &KbdTables;
}
