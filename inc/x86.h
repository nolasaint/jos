#ifndef JOS_INC_X86_H
#define JOS_INC_X86_H

#include <inc/types.h>

static __inline void breakpoint(void) __attribute__((always_inline));
static __inline uint8_t inb(int port) __attribute__((always_inline));
static __inline void insb(int port, void *addr, int cnt) __attribute__((always_inline));
static __inline uint16_t inw(int port) __attribute__((always_inline));
static __inline void insw(int port, void *addr, int cnt) __attribute__((always_inline));
static __inline uint32_t inl(int port) __attribute__((always_inline));
static __inline void insl(int port, void *addr, int cnt) __attribute__((always_inline));
static __inline void outb(int port, uint8_t data) __attribute__((always_inline));
static __inline void outsb(int port, const void *addr, int cnt) __attribute__((always_inline));
static __inline void outw(int port, uint16_t data) __attribute__((always_inline));
static __inline void outsw(int port, const void *addr, int cnt) __attribute__((always_inline));
static __inline void outsl(int port, const void *addr, int cnt) __attribute__((always_inline));
static __inline void outl(int port, uint32_t data) __attribute__((always_inline));
static __inline void invlpg(void *addr) __attribute__((always_inline));
static __inline void lidt(void *p) __attribute__((always_inline));
static __inline void lldt(uint16_t sel) __attribute__((always_inline));
static __inline void ltr(uint16_t sel) __attribute__((always_inline));
static __inline void lcr0(uint32_t val) __attribute__((always_inline));
static __inline uint32_t rcr0(void) __attribute__((always_inline));
static __inline uint32_t rcr2(void) __attribute__((always_inline));
static __inline void lcr3(uint32_t val) __attribute__((always_inline));
static __inline uint32_t rcr3(void) __attribute__((always_inline));
static __inline void lcr4(uint32_t val) __attribute__((always_inline));
static __inline uint32_t rcr4(void) __attribute__((always_inline));
static __inline void tlbflush(void) __attribute__((always_inline));
static __inline uint32_t read_eflags(void) __attribute__((always_inline));
static __inline void write_eflags(uint32_t eflags) __attribute__((always_inline));
static __inline uint32_t read_ebp(void) __attribute__((always_inline));
static __inline uint32_t read_esp(void) __attribute__((always_inline));
static __inline uint32_t read_arg(uint32_t ebp, size_t n) __attribute__((always_inline));
static __inline uint32_t read_pre_ebp(uint32_t) __attribute__((always_inline));
static __inline uint32_t read_ret_eip(uint32_t) __attribute__((always_inline));
static __inline void cpuid(uint32_t info, uint32_t *eaxp, uint32_t *ebxp, uint32_t *ecxp, uint32_t *edxp);
static __inline uint64_t read_tsc(void) __attribute__((always_inline));

static __inline void
breakpoint(void)
{
  __asm __volatile("int3");
}

static __inline uint8_t
inb(int port)
{
  uint8_t data;
  __asm __volatile("inb %w1,%0" : "=a" (data) : "d" (port));

  return data;
}

static __inline void
insb(int port, void *addr, int cnt)
{
  __asm __volatile("cld\n\trepne\n\tinsb"                 :
                   "=D" (addr), "=c" (cnt)                :
                   "d" (port), "0" (addr), "1" (cnt)      :
                   "memory", "cc");
}

static __inline uint16_t
inw(int port)
{
  uint16_t data;
  __asm __volatile("inw %w1,%0" : "=a" (data) : "d" (port));

  return data;
}

static __inline void
insw(int port, void *addr, int cnt)
{
  __asm __volatile("cld\n\trepne\n\tinsw"                 :
                   "=D" (addr), "=c" (cnt)                :
                   "d" (port), "0" (addr), "1" (cnt)      :
                   "memory", "cc");
}

static __inline uint32_t
inl(int port)
{
  uint32_t data;
  __asm __volatile("inl %w1,%0" : "=a" (data) : "d" (port));

  return data;
}

static __inline void
insl(int port, void *addr, int cnt)
{
  __asm __volatile("cld\n\trepne\n\tinsl"                 :
                   "=D" (addr), "=c" (cnt)                :
                   "d" (port), "0" (addr), "1" (cnt)      :
                   "memory", "cc");
}

static __inline void
outb(int port, uint8_t data)
{
  __asm __volatile("outb %0,%w1" : : "a" (data), "d" (port));
}

static __inline void
outsb(int port, const void *addr, int cnt)
{
  __asm __volatile("cld\n\trepne\n\toutsb"                :
                   "=S" (addr), "=c" (cnt)                :
                   "d" (port), "0" (addr), "1" (cnt)      :
                   "cc");
}

static __inline void
outw(int port, uint16_t data)
{
  __asm __volatile("outw %0,%w1" : : "a" (data), "d" (port));
}

static __inline void
outsw(int port, const void *addr, int cnt)
{
  __asm __volatile("cld\n\trepne\n\toutsw"                :
                   "=S" (addr), "=c" (cnt)                :
                   "d" (port), "0" (addr), "1" (cnt)      :
                   "cc");
}

static __inline void
outsl(int port, const void *addr, int cnt)
{
  __asm __volatile("cld\n\trepne\n\toutsl"                :
                   "=S" (addr), "=c" (cnt)                :
                   "d" (port), "0" (addr), "1" (cnt)      :
                   "cc");
}

static __inline void
outl(int port, uint32_t data)
{
  __asm __volatile("outl %0,%w1" : : "a" (data), "d" (port));
}

static __inline void
invlpg(void *addr)
{
  __asm __volatile("invlpg (%0)" : : "r" (addr) : "memory");
}

static __inline void
lidt(void *p)
{
  __asm __volatile("lidt (%0)" : : "r" (p));
}

static __inline void
lgdt(void *p)
{
  __asm __volatile("lgdt (%0)" : : "r" (p));
}

static __inline void
lldt(uint16_t sel)
{
  __asm __volatile("lldt %0" : : "r" (sel));
}

static __inline void
ltr(uint16_t sel)
{
  __asm __volatile("ltr %0" : : "r" (sel));
}

static __inline void
lcr0(uint32_t val)
{
  __asm __volatile("movl %0,%%cr0" : : "r" (val));
}

static __inline uint32_t
rcr0(void)
{
  uint32_t val;
  __asm __volatile("movl %%cr0,%0" : "=r" (val));

  return val;
}

static __inline uint32_t
rcr2(void)
{
  uint32_t val;
  __asm __volatile("movl %%cr2,%0" : "=r" (val));

  return val;
}

static __inline void
lcr3(uint32_t val)
{
  __asm __volatile("movl %0,%%cr3" : : "r" (val));
}

static __inline uint32_t
rcr3(void)
{
  uint32_t val;
  __asm __volatile("movl %%cr3,%0" : "=r" (val));

  return val;
}

static __inline void
lcr4(uint32_t val)
{
  __asm __volatile("movl %0,%%cr4" : : "r" (val));
}

static __inline uint32_t
rcr4(void)
{
  uint32_t cr4;
  __asm __volatile("movl %%cr4,%0" : "=r" (cr4));

  return cr4;
}

static __inline void
tlbflush(void)
{
  uint32_t cr3;
  __asm __volatile("movl %%cr3,%0" : "=r" (cr3));
  __asm __volatile("movl %0,%%cr3" : : "r" (cr3));
}

static __inline uint32_t
read_eflags(void)
{
  uint32_t eflags;
  __asm __volatile("pushfl; popl %0" : "=r" (eflags));

  return eflags;
}

static __inline void
write_eflags(uint32_t eflags)
{
  __asm __volatile("pushl %0; popfl" : : "r" (eflags));
}

static __inline uint32_t
read_ebp(void)
{
  uint32_t ebp;
  __asm __volatile("movl %%ebp,%0" : "=r" (ebp));

  return ebp;
}

static __inline uint32_t
read_esp(void)
{
  uint32_t esp;
  __asm __volatile("movl %%esp,%0" : "=r" (esp));

  return esp;
}

static __inline void
cpuid(uint32_t info, uint32_t *eaxp, uint32_t *ebxp, uint32_t *ecxp, uint32_t *edxp)
{
  uint32_t eax, ebx, ecx, edx;

  asm volatile ("cpuid"
                : "=a" (eax), "=b" (ebx), "=c" (ecx), "=d" (edx)
                : "a" (info));
  if (eaxp)
    *eaxp = eax;
  if (ebxp)
    *ebxp = ebx;
  if (ecxp)
    *ecxp = ecx;
  if (edxp)
    *edxp = edx;
}

static __inline uint64_t
read_tsc(void)
{
  uint64_t tsc;
  __asm __volatile("rdtsc" : "=A" (tsc));

  return tsc;
}

static inline uint32_t
xchg(volatile uint32_t *addr, uint32_t newval)
{
  uint32_t result;

  // The + in "+m" denotes a read-modify-write operand.
  asm volatile ("lock; xchgl %0, %1" :
                "+m" (*addr), "=a" (result) :
                "1" (newval) :
                "cc");
  return result;
}

// Read argument n from stack frame at ebp
static __inline uint32_t
read_arg(uint32_t ebp, size_t n)
{
  uint32_t arg;
  uint32_t offset = (n + 1) * 4;

  __asm __volatile ("movl %2, %%eax\n\t;"
                    "addl %1, %%eax\n\t;"
                    "movl (%%eax), %0;"                   :
                    "=r" (arg)                            :
                    "g" (offset), "g" (ebp)               :
                    "%eax");
  return arg;
}

// Read previous ebp (previous stack frame)
static __inline uint32_t
read_pre_ebp(uint32_t cur_ebp)
{
  uint32_t pre_ebp;

  __asm __volatile ("movl %1, %%eax\n\t;"
                    "movl (%%eax), %0\n\t;"               :
                    "=r" (pre_ebp)                        :
                    "g" (cur_ebp)                         :
                    "%eax");
  return pre_ebp;
}

// Read caller's eip
static __inline uint32_t
read_ret_eip(uint32_t ebp)
{
  uint32_t ret_eip;
  __asm __volatile ("movl %1, %%eax\n\t;"
                    "movl 4(%%eax), %0\n\t;"              :
                    "=r" (ret_eip)                        :
                    "g" (ebp)                             :
                    "%eax");

  return ret_eip;
}

#endif /* !JOS_INC_X86_H */
