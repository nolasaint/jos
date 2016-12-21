#include <inc/error.h>

#include <inc/cga.h>

// TODO
// TODO Should the CGA attributes should be a uint16_t, or should the highest
// TODO byte simply be ignored?
// TODO

// TODO
// TODO The CGA attributes should be manipulated through a system call (when
// TODO system calls are implemented)
// TODO

// XXX Temporary storage for cga attributes. Move to console.c after syscalls.
static uint32_t cga_attr = CGA_ATTR_BG_BLACK | CGA_ATTR_FG_WHITE;


/**
 * Returns the CGA attributes used for all CGA (VGA) output.
 */
uint32_t
get_cga_attr(void)
{
  return cga_attr;
}

/**
 * Sets the CGA attributes for all CGA (VGA) output.
 *
 * Returns:
 *   0 on success
 *   -E_INVAL if highest byte has any bits set
 */
int
set_cga_attr(uint32_t attr)
{
  // check that highest 8 bits are clear
  if (attr & 0x00FF)
  {
    return -E_INVAL;
  }

  cga_attr = attr;
  return 0;
}
