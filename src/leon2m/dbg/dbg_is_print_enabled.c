/* dbg_is_print_enabled  (FUN_a00dd614)
 *
 * Return whether a class of debug messages is switched on.
 * Returns: non-zero when enabled
 * Name basis: proven - print mask at 0xA802B0B0 ANDed with the class bit; tested before many prints
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dd614 @ 0xa00dd614, flags -mcpu=v8 -O2 -g.
 * Source form: the decompiler's typedefs and macros are kept; the result is
 * 'dbg_print_mask & class_bits & 0xff' with a blank line between the header and the brace.
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
#define true 1
#define false 0
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern unsigned int dbg_print_mask;

/*
 * Return the bits of class_bits that are set in the debug print mask, limited to the low 8 bits: only the
 * classes 0x01..0x80 can be switched on. Callers test it before printing a message of that class.
 */
uint dbg_is_print_enabled(uint class_bits)

{
  return dbg_print_mask & class_bits & 0xff;
}
