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
#define CGA_ATTR_FG_BLACK  0x00 /* If BG is black, this will give white FG  */
#define CGA_ATTR_FG_BLUE   0x01
#define CGA_ATTR_FG_GREEN  0x02
#define CGA_ATTR_FG_CYAN   0x03
#define CGA_ATTR_FG_RED    0x04
#define CGA_ATTR_FG_PURPLE 0x05
#define CGA_ATTR_FG_GOLD   0x06
#define CGA_ATTR_FG_WHITE  0x07

// Emphasized text
#define CGA_ATTR_EM        0x08

// Background color
#define CGA_ATTR_BG_BLACK  0x00
#define CGA_ATTR_BG_BLUE   0x10
#define CGA_ATTR_BG_GREEN  0x20
#define CGA_ATTR_BG_CYAN   0x30
#define CGA_ATTR_BG_RED    0x40
#define CGA_ATTR_BG_PURPLE 0x50
#define CGA_ATTR_BG_GOLD   0x60
#define CGA_ATTR_BG_WHITE  0x70

// lib/cga.h
uint8_t get_cga_attr(void);
void    set_cga_attr(uint8_t attr);

#endif /* !JOS_INC_CGA_H */
