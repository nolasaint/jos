/* See COPYRIGHT for copyright information. */

#ifndef JOS_INC_CGA_H
#define JOS_INC_CGA_H

#include <inc/types.h>

/**
 * CGA Text Buffer
 *
 *
 * Figure 1: standard CGA text buffer
 *
 * +-------------------------------+-------------------------------+
 * |        Attribute  Bits        |        Character  Bits        |
 * +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
 * | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
 * +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
 *  |-| |---------| |-------------|
 *   |       |             |
 *   |       |             +-- Foreground color
 *   |       |
 *   |       +---------------- Background color
 *   |
 *   +------------------------ Blink flag
 *
 * In VGA-compatible text mode, each character displayed on-screen is
 * represented by a CPU-addressible 2-byte word. The higher byte denotes the
 * character on the screen, while the lower byte holds attributes that denote
 * how the character is styled on-screen.
 *
 * For more information, see:
 *   https://wikipedia.org/wiki/VGA-compatible_text_mode
 *   https://wikipedia.org/wiki/Color_Graphics_Adapter
 *   https://wikipedia.org/wiki/Video_Graphics_Array
 *
 * ----------------------------------------------------------------------------
 *
 * Figure 2: QEMU-emulated i386 CGA text buffer
 *
 * +-------------------------------+-------------------------------+
 * |        Attribute  Bits        |        Character  Bits        |
 * +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
 * | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
 * +---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
 *  |-| |---------| |-| |---------|
 *   |       |       |       |
 *   |       |       |       +-- Foreground color
 *   |       |       |
 *   |       |       +---------- Emphasis flag
 *   |       |
 *   |       +------------------ Background color
 *   |
 *   +-------------------------- Unused
 *
 * In the QEMU-emulated i386 our JOS is running on, the attribute bits are
 * arranged differently. This file provides macros for setting various CGA
 * attributes. This layout is illustrated above in figure 2.
 *
 * The emphasis flag emboldens and lightens the color of text.
 *
 * This file provides definition for various macros to manipulate these
 * attribute bits.
 */

// Foreground color
#define CGA_ATTR_FG_BLACK  0x0000
#define CGA_ATTR_FG_BLUE   0x0100
#define CGA_ATTR_FG_GREEN  0x0200
#define CGA_ATTR_FG_CYAN   0x0300
#define CGA_ATTR_FG_RED    0x0400
#define CGA_ATTR_FG_PURPLE 0x0500
#define CGA_ATTR_FG_GOLD   0x0600
#define CGA_ATTR_FG_WHITE  0x0700

// Emphasized text
#define CGA_ATTR_EM        0x0800

// Background color
#define CGA_ATTR_BG_BLACK  0x0000
#define CGA_ATTR_BG_BLUE   0x1000
#define CGA_ATTR_BG_GREEN  0x2000
#define CGA_ATTR_BG_CYAN   0x3000
#define CGA_ATTR_BG_RED    0x4000
#define CGA_ATTR_BG_PURPLE 0x5000
#define CGA_ATTR_BG_GOLD   0x6000
#define CGA_ATTR_BG_WHITE  0x7000

// lib/cga.h
uint32_t get_cga_attr(void);
int      set_cga_attr(uint32_t attr);

#endif /* !JOS_INC_CGA_H */
