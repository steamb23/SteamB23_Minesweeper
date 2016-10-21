/* steamb23console.h
* ============================
* .Net 콘솔 클래스 C++ 포팅
* gist 주소 : https://gist.github.com/steamb23/7d67cc5e7193494847b82fa7a35c0ae7
* ============================
*
* .Net 4.6의 콘솔 클래스를 C++ 로 포팅하였습니다.
*
* ============================
*
* MIT License
* Copyright (c) 2016 SteamB23
*
* Permission is hereby granted, free of charge, to any person
* obtaining a copy of this software and associated documentation
* files (the "Software"), to deal in the Software without
* restriction, including without limitation the rights to use,
* copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following
* conditions:
*
* The above copyright notice and this permission notice shall be
* included in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
* OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
* HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*/

#pragma once

#include <windows.h>

#include <iostream>
#include <string>
namespace SteamB23 {
    enum class ConsoleColor
    {
        Black = 0,
        DarkBlue = 1,
        DarkGreen = 2,
        DarkCyan = 3,
        DarkRed = 4,
        DarkMagenta = 5,
        DarkYellow = 6,
        Gray = 7,
        DarkGray = 8,
        Blue = 9,
        Green = 10,
        Cyan = 11,
        Red = 12,
        Magenta = 13,
        Yellow = 14,
        White = 15
    };
    enum class ConsoleKey
    {
        Backspace = 0x8,
        Tab = 0x9,
        // 0xA,  // Reserved
        // 0xB,  // Reserved
        Clear = 0xC,
        Enter = 0xD,
        // 0E-0F,  // Undefined
        // SHIFT = 0x10,
        // CONTROL = 0x11,
        // Alt = 0x12,
        Pause = 0x13,
        // CAPSLOCK = 0x14,
        // Kana = 0x15,  // Ime Mode
        // Hangul = 0x15,  // Ime Mode
        // 0x16,  // Undefined
        // Junja = 0x17,  // Ime Mode
        // Final = 0x18,  // Ime Mode
        // Hanja = 0x19,  // Ime Mode
        // Kanji = 0x19,  // Ime Mode
        // 0x1A,  // Undefined
        Escape = 0x1B,
        // Convert = 0x1C,  // Ime Mode
        // NonConvert = 0x1D,  // Ime Mode
        // Accept = 0x1E,  // Ime Mode
        // ModeChange = 0x1F,  // Ime Mode
        Spacebar = 0x20,
        PageUp = 0x21,
        PageDown = 0x22,
        End = 0x23,
        Home = 0x24,
        LeftArrow = 0x25,
        UpArrow = 0x26,
        RightArrow = 0x27,
        DownArrow = 0x28,
        Select = 0x29,
        Print = 0x2A,
        Execute = 0x2B,
        PrintScreen = 0x2C,
        Insert = 0x2D,
        Delete = 0x2E,
        Help = 0x2F,
        D0 = 0x30,  // 0 through 9
        D1 = 0x31,
        D2 = 0x32,
        D3 = 0x33,
        D4 = 0x34,
        D5 = 0x35,
        D6 = 0x36,
        D7 = 0x37,
        D8 = 0x38,
        D9 = 0x39,
        // 3A-40 ,  // Undefined
        A = 0x41,
        B = 0x42,
        C = 0x43,
        D = 0x44,
        E = 0x45,
        F = 0x46,
        G = 0x47,
        H = 0x48,
        I = 0x49,
        J = 0x4A,
        K = 0x4B,
        L = 0x4C,
        M = 0x4D,
        N = 0x4E,
        O = 0x4F,
        P = 0x50,
        Q = 0x51,
        R = 0x52,
        S = 0x53,
        T = 0x54,
        U = 0x55,
        V = 0x56,
        W = 0x57,
        X = 0x58,
        Y = 0x59,
        Z = 0x5A,
        LeftWindows = 0x5B,  // Microsoft Natural keyboard
        RightWindows = 0x5C,  // Microsoft Natural keyboard
        Applications = 0x5D,  // Microsoft Natural keyboard
        // 5E ,  // Reserved
        Sleep = 0x5F,  // Computer Sleep Key
        NumPad0 = 0x60,
        NumPad1 = 0x61,
        NumPad2 = 0x62,
        NumPad3 = 0x63,
        NumPad4 = 0x64,
        NumPad5 = 0x65,
        NumPad6 = 0x66,
        NumPad7 = 0x67,
        NumPad8 = 0x68,
        NumPad9 = 0x69,
        Multiply = 0x6A,
        Add = 0x6B,
        Separator = 0x6C,
        Subtract = 0x6D,
        Decimal = 0x6E,
        Divide = 0x6F,
        F1 = 0x70,
        F2 = 0x71,
        F3 = 0x72,
        F4 = 0x73,
        F5 = 0x74,
        F6 = 0x75,
        F7 = 0x76,
        F8 = 0x77,
        F9 = 0x78,
        F10 = 0x79,
        F11 = 0x7A,
        F12 = 0x7B,
        F13 = 0x7C,
        F14 = 0x7D,
        F15 = 0x7E,
        F16 = 0x7F,
        F17 = 0x80,
        F18 = 0x81,
        F19 = 0x82,
        F20 = 0x83,
        F21 = 0x84,
        F22 = 0x85,
        F23 = 0x86,
        F24 = 0x87,
        // 88-8F,  // Undefined
        // NumberLock = 0x90,
        // ScrollLock = 0x91,
        // 0x92,  // OEM Specific
        // 97-9F ,  // Undefined
        // LeftShift = 0xA0,
        // RightShift = 0xA1,
        // LeftControl = 0xA2,
        // RightControl = 0xA3,
        // LeftAlt = 0xA4,
        // RightAlt = 0xA5,
        BrowserBack = 0xA6,  // Windows 2000/XP
        BrowserForward = 0xA7,  // Windows 2000/XP
        BrowserRefresh = 0xA8,  // Windows 2000/XP
        BrowserStop = 0xA9,  // Windows 2000/XP
        BrowserSearch = 0xAA,  // Windows 2000/XP
        BrowserFavorites = 0xAB,  // Windows 2000/XP
        BrowserHome = 0xAC,  // Windows 2000/XP
        VolumeMute = 0xAD,  // Windows 2000/XP
        VolumeDown = 0xAE,  // Windows 2000/XP
        VolumeUp = 0xAF,  // Windows 2000/XP
        MediaNext = 0xB0,  // Windows 2000/XP
        MediaPrevious = 0xB1,  // Windows 2000/XP
        MediaStop = 0xB2,  // Windows 2000/XP
        MediaPlay = 0xB3,  // Windows 2000/XP
        LaunchMail = 0xB4,  // Windows 2000/XP
        LaunchMediaSelect = 0xB5,  // Windows 2000/XP
        LaunchApp1 = 0xB6,  // Windows 2000/XP
        LaunchApp2 = 0xB7,  // Windows 2000/XP
        // B8-B9,  // Reserved
        Oem1 = 0xBA,  // Misc characters, varies by keyboard. For US standard, ;:
        OemPlus = 0xBB,  // Misc characters, varies by keyboard. For US standard, +
        OemComma = 0xBC,  // Misc characters, varies by keyboard. For US standard, ,
        OemMinus = 0xBD,  // Misc characters, varies by keyboard. For US standard, -
        OemPeriod = 0xBE,  // Misc characters, varies by keyboard. For US standard, .
        Oem2 = 0xBF,  // Misc characters, varies by keyboard. For US standard, /?
        Oem3 = 0xC0,  // Misc characters, varies by keyboard. For US standard, `~
        // 0xC1,  // Reserved
        // D8-DA,  // Unassigned
        Oem4 = 0xDB,  // Misc characters, varies by keyboard. For US standard, [{
        Oem5 = 0xDC,  // Misc characters, varies by keyboard. For US standard, \|
        Oem6 = 0xDD,  // Misc characters, varies by keyboard. For US standard, ]}
        Oem7 = 0xDE,  // Misc characters, varies by keyboard. For US standard,
        Oem8 = 0xDF,  // Used for miscellaneous characters; it can vary by keyboard
        // 0xE0,  // Reserved
        // 0xE1,  // OEM specific
        Oem102 = 0xE2,  // Win2K/XP: Either angle or backslash on RT 102-key keyboard
        // 0xE3,  // OEM specific
        Process = 0xE5,  // Windows: IME Process Key
        // 0xE6,  // OEM specific
        Packet = 0xE7,  // Win2K/XP: Used to pass Unicode chars as if keystrokes
        // 0xE8,  // Unassigned
        // 0xE9,  // OEM specific
        Attention = 0xF6,
        CrSel = 0xF7,
        ExSel = 0xF8,
        EraseEndOfFile = 0xF9,
        Play = 0xFA,
        Zoom = 0xFB,
        NoName = 0xFC,  // Reserved
        Pa1 = 0xFD,
        OemClear = 0xFE
    };
    class ConsoleKeyInfo
    {
    public:
        ConsoleKeyInfo(ConsoleKey key, TCHAR _char, bool shift, bool alt, bool ctrl)
            : Key(key), Char(_char), Shift(shift), Alt(alt), Ctrl(ctrl)
        {
        }
        const ConsoleKey Key;
        const TCHAR Char;
        const bool Shift;
        const bool Alt;
        const bool Ctrl;
    };
    class Console
    {
    private:
        // C# System.Console 포팅용 변수
        static INPUT_RECORD _cachedInputRecord;
        static BYTE _defaultColors;
        static BOOL _haveReadDefaultColors;

        static HANDLE GetConsoleInputHandle()
        {
            return GetStdHandle(STD_INPUT_HANDLE);
        }
        static HANDLE GetConsoleOutputHandle()
        {
            return GetStdHandle(STD_OUTPUT_HANDLE);
        }

        static WORD ConsoleColorToColorAttribute(ConsoleColor color, bool isBackground)
        {
            if ((((int)color) & ~0xf) != 0)
                throw 1;

            WORD c = (WORD)color;
            if (isBackground)
                c <<= 4;
            return c;
        }
        static ConsoleColor ColorAttributeToConsoleColor(WORD c)
        {
            if ((c & 0xf0) != 0)
                c = c >> 4;
            return (ConsoleColor)c;
        }

        static CONSOLE_SCREEN_BUFFER_INFO GetBufferInfo()
        {
            bool junk;
            return GetBufferInfo(true, junk);
        }
        static CONSOLE_SCREEN_BUFFER_INFO GetBufferInfo(bool throwOnNoConsole, bool & succeeded)
        {
#pragma warning(disable : 4800)
            succeeded = false;
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            bool success;

            HANDLE hConsole = GetConsoleOutputHandle();
            if (hConsole == INVALID_HANDLE_VALUE)
            {
                if (!throwOnNoConsole)
                    return CONSOLE_SCREEN_BUFFER_INFO();
                else
                    throw 0;
            }
            success = GetConsoleScreenBufferInfo(hConsole, &csbi);
            if (!success)
            {
                success = GetConsoleScreenBufferInfo(GetStdHandle(STD_ERROR_HANDLE), &csbi);
                if (!success)
                    success = GetConsoleScreenBufferInfo(GetStdHandle(STD_INPUT_HANDLE), &csbi);

                if (!success)
                {
                    int errorCode = GetLastError();
                    if (errorCode == ERROR_INVALID_HANDLE && !throwOnNoConsole)
                        return CONSOLE_SCREEN_BUFFER_INFO();
                    throw errorCode;
                }
            }
            if (!_haveReadDefaultColors)
            {
                // Fetch the default foreground and background color for the
                // ResetColor method.
                _defaultColors = (BYTE)(csbi.wAttributes & 0xff);
                _haveReadDefaultColors = true;
            }

            succeeded = true;
            return csbi;
#pragma warning(default : 4800)
        }

        static bool IsModKey(INPUT_RECORD ir)
        {
            WORD keyCode = ir.Event.KeyEvent.wVirtualKeyCode;
            return ((keyCode >= 0x10 && keyCode <= 0x12) || keyCode == 0x14 || keyCode == 0x90 || keyCode == 0x91);
        }
    public:
        // 키를 읽습니다.
        static ConsoleKeyInfo ReadKey()
        {
            INPUT_RECORD ir;
            DWORD numEventRead = -1;
            bool r;

            if (_cachedInputRecord.EventType == KEY_EVENT)
            {
                ir = _cachedInputRecord;
                if (_cachedInputRecord.Event.KeyEvent.wRepeatCount == 0)
                {
                    _cachedInputRecord.EventType = -1;
                }
                else
                {
                    _cachedInputRecord.Event.KeyEvent.wRepeatCount--;
                }
            }
            else
            {
#pragma warning(disable : 4800)
                while (true)
                {
                    r = ReadConsoleInput(GetConsoleInputHandle(), &ir, 1, &numEventRead);

                    //if (!r || numEventsRead == 0)
                    //{
                    //	// This will fail when stdin is redirected from a file or pipe. 
                    //	// We could theoretically call Console.Read here, but I 
                    //	// think we might do some things incorrectly then.
                    //	throw new InvalidOperationException(Environment.GetResourceString("InvalidOperation_ConsoleReadKeyOnFile"));
                    //}

                    WORD keyCode = ir.Event.KeyEvent.wVirtualKeyCode;

                    if (!(ir.EventType == KEY_EVENT && ir.Event.KeyEvent.bKeyDown))
                        if (keyCode != 0x12)
                            continue;

                    char ch = ir.Event.KeyEvent.uChar.AsciiChar;
                    if (ch == 0)
                        if (IsModKey(ir))
                            continue;

                    WORD key = keyCode;
                    if (((ir.Event.KeyEvent.dwControlKeyState & 0x0003) != 0) && ((key >= VK_NUMPAD0 && key <= VK_NUMPAD9)
                        || (key == VK_CLEAR) || (key == VK_INSERT)
                        || (key >= 0x21 && key <= 0x28)))
                        continue;


                    if (ir.Event.KeyEvent.wRepeatCount > 1)
                    {
                        ir.Event.KeyEvent.wRepeatCount--;
                        _cachedInputRecord = ir;
                    }
                    break;
                }
#pragma warning(default : 4800)
            }

            DWORD state = ir.Event.KeyEvent.dwControlKeyState;

            bool shift;
            bool alt;
            bool control;
            shift = (state & 0x0010) != 0;
            alt = (state & (0x0002 | 0x0001)) != 0;
            control = (state & (0x0008 | 0x0004)) != 0;

#ifdef _UNICODE
            return ConsoleKeyInfo((ConsoleKey)ir.Event.KeyEvent.wVirtualKeyCode, ir.Event.KeyEvent.uChar.UnicodeChar, shift, alt, control);
#else
            return ConsoleKeyInfo((ConsoleKey)ir.Event.KeyEvent.wVirtualKeyCode, ir.Event.KeyEvent.uChar.AsciiChar, shift, alt, control);
#endif
        }
        // 화면을 지웁니다.
        static void Clear()
        {
            COORD coordScreen = COORD();
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            int conSize;

            HANDLE hConsole = GetConsoleOutputHandle();
            GetConsoleScreenBufferInfo(hConsole, &csbi);
            conSize = csbi.dwSize.X * csbi.dwSize.Y;

            DWORD numCellsWritten = 0;
            FillConsoleOutputCharacter(hConsole, ' ', conSize, coordScreen, &numCellsWritten);
            numCellsWritten = 0;
            FillConsoleOutputAttribute(hConsole, csbi.wAttributes, conSize, coordScreen, &numCellsWritten);
            SetConsoleCursorPosition(hConsole, coordScreen);
        }
        // 타이틀을 가져옵니다.
        static LPTSTR GetTitle()
        {
            LPTSTR result = new TCHAR[260];
            GetConsoleTitle(result, 260);
            return result;
        }
        // 타이틀을 설정합니다.
        static bool SetTitle(LPCTSTR value)
        {
            return SetConsoleTitle(value) != 0;
        }

        // 배경색을 가져옵니다.
        static ConsoleColor GetBackgroundColor()
        {
            bool succeeded;
            CONSOLE_SCREEN_BUFFER_INFO csbi = GetBufferInfo(false, succeeded);
            return ConsoleColor::Black;
            WORD c = csbi.wAttributes & 0xf0;
            return ColorAttributeToConsoleColor(c);
        }
        // 배경색을 설정합니다.
        static void SetBackgroundColor(ConsoleColor value)
        {
            WORD c = ConsoleColorToColorAttribute(value, true);

            bool succeeded;
            CONSOLE_SCREEN_BUFFER_INFO csbi = GetBufferInfo(false, succeeded);

            WORD attrs = csbi.wAttributes;
            attrs &= ~0xf0;
            attrs |= c;

            SetConsoleTextAttribute(GetConsoleOutputHandle(), attrs);
        }
        // 글자색을 가져옵니다.
        static ConsoleColor GetForegroundColor()
        {
            bool succeeded;
            CONSOLE_SCREEN_BUFFER_INFO csbi = GetBufferInfo(false, succeeded);
            return ConsoleColor::Gray;
            WORD c = csbi.wAttributes & 0x0f;
            return ColorAttributeToConsoleColor(c);
        }
        // 글자색을 설정합니다.
        static void SetForegroundColor(ConsoleColor value)
        {
            WORD c = ConsoleColorToColorAttribute(value, false);

            bool succeeded;
            CONSOLE_SCREEN_BUFFER_INFO csbi = GetBufferInfo(false, succeeded);

            WORD attrs = csbi.wAttributes;
            attrs &= ~0x0f;
            attrs |= c;

            SetConsoleTextAttribute(GetConsoleOutputHandle(), attrs);
        }
        // 색설정을 초기화합니다.
        static void ResetColor()
        {
            bool succeeded;
            CONSOLE_SCREEN_BUFFER_INFO csbi = GetBufferInfo(false, succeeded);

            if (!succeeded)
                return;

            WORD defaultAttrs = _defaultColors;
            SetConsoleTextAttribute(GetConsoleOutputHandle(), defaultAttrs);
        }

        // 커서의 위치를 설정합니다.
        static bool SetCursorPosition(int left, int top)
        {
            if (left < 0 || left >= INT16_MAX)
                return false;
            if (top < 0 || top >= INT16_MAX)
                return false;
#pragma warning(disable : 4800)
            return SetConsoleCursorPosition(GetConsoleOutputHandle(), { (short)left,(short)top });
#pragma warning(default : 4800)
        }
        static int GetCursorLeft()
        {
            bool succeeded;
            CONSOLE_SCREEN_BUFFER_INFO csbi = GetBufferInfo(false, succeeded);
            return csbi.dwCursorPosition.X;
        }
        static bool SetCursorLeft(int value)
        {
            return SetCursorPosition(value, GetCursorTop());
        }
        static int GetCursorTop()
        {
            bool succeeded;
            CONSOLE_SCREEN_BUFFER_INFO csbi = GetBufferInfo(false, succeeded);
            return csbi.dwCursorPosition.Y;
        }
        static bool SetCursorTop(int value)
        {
            return SetCursorPosition(GetCursorLeft(), value);
        }
    };
}