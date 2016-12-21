#include <inc/cga.h>

// TODO
// TODO The CGA attributes should be manipulated through a system call (when
// TODO system calls are implemented)
// TODO

// XXX Temporary storage for cga attributes. Move to console.c after syscalls.
static uint8_t cga_attr = CGA_ATTR_BG_BLACK | CGA_ATTR_FG_WHITE;


/**
 * Returns the CGA attributes used for all VGA output.
 */
uint8_t
get_cga_attr(void)
{
  return cga_attr;
}

/**
 * Sets the CGA attributes for all VGA output.
 */
void
set_cga_attr(uint8_t attr)
{
  cga_attr = attr;
}
