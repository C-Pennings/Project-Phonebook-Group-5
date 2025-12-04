#pragma once
#ifndef COLORS_H
#define COLORS_H

#ifdef _WIN32
#include <windows.h>
static inline void ENABLE_COLORS() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    if (h != INVALID_HANDLE_VALUE) {
        DWORD mode = 0;
        GetConsoleMode(h, &mode);
        mode |= 0x0004;  // ENABLE_VIRTUAL_TERMINAL_PROCESSING
        SetConsoleMode(h, mode);
    }
}
#else
#define ENABLE_COLORS() do {} while(0)
#endif

/* ─────────────────────────────── RESET & EFFECTS ─────────────────────────────── */
#define RESET       "\033[0m"
#define BOLD        "\033[1m"
#define DIM         "\033[2m"
#define ITALIC      "\033[3m"
#define UNDERLINE   "\033[4m"
#define SLOW_BLINK  "\033[5m"
#define FAST_BLINK  "\033[6m"
#define REVERSE     "\033[7m"
#define HIDDEN      "\033[8m"
#define STRIKE      "\033[9m"

#define NO_BOLD       "\033[22m"
#define NO_UNDERLINE  "\033[24m"
#define NO_BLINK      "\033[25m"
#define NO_REVERSE    "\033[27m"
#define NO_HIDDEN     "\033[28m"
#define NO_STRIKE     "\033[29m"

/* ─────────────────────────────── FOREGROUND COLORS ─────────────────────────────── */
#define BLACK       "\033[30m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define BLUE        "\033[34m"
#define MAGENTA     "\033[35m"
#define CYAN        "\033[36m"
#define WHITE       "\033[37m"

#define B_BLACK     "\033[90m"
#define B_RED       "\033[91m"
#define B_GREEN     "\033[92m"
#define B_YELLOW    "\033[93m"
#define B_BLUE      "\033[94m"
#define B_MAGENTA   "\033[95m"
#define B_CYAN      "\033[96m"
#define B_WHITE     "\033[97m"

/* ─────────────────────────────── BACKGROUND COLORS ─────────────────────────────── */
#define BG_BLACK    "\033[40m"
#define BG_RED      "\033[41m"
#define BG_GREEN    "\033[42m"
#define BG_YELLOW   "\033[43m"
#define BG_BLUE     "\033[44m"
#define BG_MAGENTA  "\033[45m"
#define BG_CYAN     "\033[46m"
#define BG_WHITE    "\033[47m"

#define BG_BBLACK   "\033[100m"
#define BG_BRED     "\033[101m"
#define BG_BGREEN   "\033[102m"
#define BG_BYELLOW  "\033[103m"
#define BG_BBLUE    "\033[104m"
#define BG_BMAGENTA "\033[105m"
#define BG_BCYAN    "\033[106m"
#define BG_BWHITE   "\033[107m"

/* ─────────────────────────────── 256-COLOR & TRUE COLOR ─────────────────────────────── */
#define COLOR_256_FG(n) "\033[38;5;" #n "m"
#define COLOR_256_BG(n) "\033[48;5;" #n "m"
#define RGB_FG(r,g,b)   "\033[38;2;" #r ";" #g ";" #b "m"
#define RGB_BG(r,g,b)   "\033[48;2;" #r ";" #g ";" #b "m"

/* ─────────────────────────────── PURE ASCII PRESET COMBOS (NO UNICODE) ─────────────────────────────── */
#define SUCCESS     B_GREEN BOLD "[SUCCESS]" RESET " " B_GREEN
#define ERROR       B_RED   BOLD "[ERROR]"   RESET " " B_RED
#define WARNING     B_YELLOW BOLD "[WARNING]" RESET " " B_YELLOW
#define INFO        B_CYAN  BOLD "[INFO]"    RESET " " B_CYAN
#define HEADER      B_BLUE  BOLD UNDERLINE
#define TITLE       B_CYAN  BOLD
#define HIGHLIGHT   B_YELLOW BOLD

/* Optional: even simpler versions without brackets if you prefer */
#define OK          B_GREEN BOLD "OK"      RESET " "
#define FAIL        B_RED   BOLD "FAIL"    RESET " "
#define NOTE        B_CYAN  BOLD "NOTE"    RESET " "

#endif