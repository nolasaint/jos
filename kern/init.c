/* See COPYRIGHT for copyright information. */

#include <inc/stdio.h>
#include <inc/string.h>
#include <inc/assert.h>

#include <kern/monitor.h>
#include <kern/console.h>

// Test the CGA attributes (lab 1 only)
void
test_cga_attributes(void)
{
  uint8_t i   = 0x00;
  int count    = 0;
  int width    = 16;
  int is_final = 0;

  while (1)
  {
    if (count == width)
    {
      cprintf("\n");
      count = 0;
    }
    else if (count != 0 && count != width)
    {
      cprintf(" ");
    }

    cprintf("%[%02x", i, i);
    count++;

    if (is_final)
    {
      break;
    }
    else
    {
      i += 0x01;

      if (i == 0xFF)
      {
        is_final = 1;
      }
    }
  }

  cprintf("%[\n", 0x00);
}

// Test the stack backtrace function (lab 1 only)
void
test_backtrace(int x)
{
  cprintf("entering test_backtrace %d\n", x);
  if (x > 0)
    test_backtrace(x-1);
  else
    mon_backtrace(0, 0, 0);
  cprintf("leaving test_backtrace %d\n", x);
}

void
i386_init(void)
{
  extern char edata[], end[];

  // Before doing anything else, complete the ELF loading process.
  // Clear the uninitialized global data (BSS) section of our program.
  // This ensures that all static/global variables start out zero.
  memset(edata, 0, end - edata);

  // Initialize the console.
  // Can't call cprintf until after we do this!
  cons_init();

  cprintf("6828 decimal is %o octal!\n", 6828);

  // Test the stack backtrace function (lab 1 only)
  test_backtrace(5);

  test_cga_attributes();

  // Drop into the kernel monitor.
  while (1)
    monitor(NULL);
}


/*
 * Variable panicstr contains argument to first call to panic; used as flag
 * to indicate that the kernel has already called panic.
 */
const char *panicstr;

/*
 * Panic is called on unresolvable fatal errors.
 * It prints "panic: mesg", and then enters the kernel monitor.
 */
void
_panic(const char *file, int line, const char *fmt, ...)
{
  va_list ap;

  if (panicstr)
    goto dead;
  panicstr = fmt;

  // Be extra sure that the machine is in as reasonable state
  __asm __volatile("cli; cld");

  va_start(ap, fmt);
  cprintf("kernel panic at %s:%d: ", file, line);
  vcprintf(fmt, ap);
  cprintf("\n");
  va_end(ap);

dead:
  /* break into the kernel monitor */
  while (1)
    monitor(NULL);
}

/* like panic, but don't */
void
_warn(const char *file, int line, const char *fmt, ...)
{
  va_list ap;

  va_start(ap, fmt);
  cprintf("kernel warning at %s:%d: ", file, line);
  vcprintf(fmt, ap);
  cprintf("\n");
  va_end(ap);
}
