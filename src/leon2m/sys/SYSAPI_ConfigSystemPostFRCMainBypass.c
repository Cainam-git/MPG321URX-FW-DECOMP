/* SYSAPI_ConfigSystemPostFRCMainBypass  (FUN_a0148eb4)
 *
 * Switch the bypass of the frame-rate converter for the main picture on or off.
 * Name basis: proven - prints 'SYSAPI_ConfigSystemPostFRCMainBypass = %d' (original name)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0148eb4 @ 0xa0148eb4 (-mcpu=v8 -O3 -g).
 * Source form: the decompiler's type names and the CONCAT44 return of the second parameter are kept; the build
 * depends on them.
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

/* Word 0 of the system configuration record: bit 26 is the frame-rate converter bypass of the main picture. */
#define SYS_CONFIG_MAIN_BYPASS_SHIFT 26
#define SYS_CONFIG_MAIN_BYPASS_MASK  0xfbffffff     /* all bits but bit 26 */
extern unsigned int sys_config;
extern int dbg_printf();

/*
 * Switch the frame-rate converter bypass of the main picture on or off, and log the request.
 *
 *   on  bit 0 is copied into bit 26 of the configuration word
 *   unused  second parameter; it only appears in the (unused) return value
 */
void SYSAPI_ConfigSystemPostFRCMainBypass(unsigned char on,undefined4 unused)

{
  uint bypass_bit;
  
  dbg_printf("SYSAPI_ConfigSystemPostFRCMainBypass = %d \r\n",on & 0xff);
  bypass_bit = (on & 1) << SYS_CONFIG_MAIN_BYPASS_SHIFT;
  sys_config = sys_config & SYS_CONFIG_MAIN_BYPASS_MASK | bypass_bit;
  return CONCAT44(unused,bypass_bit);
}
