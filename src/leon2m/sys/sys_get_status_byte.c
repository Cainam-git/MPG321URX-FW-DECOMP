/* sys_get_status_byte  (FUN_a0152f70)
 *
 * Return the status byte at 0xA802CF90.
 * Returns: status byte
 * Name basis: descriptive - plain getter
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0152f70 @ 0xa0152f70 (-mcpu=v8 -O2, no -g). A leaf routine without a register window.
 * Source form: the decompiler's type name is kept.
 */
typedef unsigned char undefined1;

extern unsigned char sys_boot_source;   /* the boot source reported by the 8051 (printed as "Boot from") */

/* Return sys_boot_source. */
undefined1 sys_get_status_byte(void)

{
  return sys_boot_source;
}
