/* sys_store_request_byte  (FUN_a01111e4)
 *
 * Store a byte from the caller's buffer.
 * Name basis: descriptive - byte at 0xA802C988
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01111e4 @ 0xa01111e4, flags -mcpu=v8 -O2 -g (section default).
 * Source form: Ghidra's type and symbol names are kept.
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
extern unsigned char sys_request_byte;

/*
 * Copy the byte at *value into sys_request_byte.
 * Called by System_Initialize (with 0, when bits 20..22 of the active panel row's first word are 0) and by
 * sys_request_with_zero_byte. The panel's V-by-One start sequence reads the byte and writes 0x20 to register
 * 0xCF00EDE4 when it is not 0.
 */
void sys_store_request_byte(undefined1 *value)

{
  sys_request_byte = *value;
  return;
}