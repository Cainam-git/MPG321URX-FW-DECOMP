/* FUN_a00a6544 (leon2s, 0xa00a6544-0xa00a657c, 56 bytes, 14 words, leaf).
 * Flags: -mcpu=v8 -Os -g.
 * base = *DAT_a00b4da0[(u8)param_1] (a table of pointers to u16 block bases, read with lduh); returns the
 * hardware word at 0xce000000 | (base + param_3). param_2 is not used.
 * The pointed-to base is a u16 (firmware lduh). volatile only on the 0xce000000 hardware read.
 */
extern unsigned short *DAT_a00b4da0[];

unsigned int FUN_a00a6544(unsigned int param_1, unsigned char param_2, unsigned short param_3)
{
  return *(volatile unsigned int *)((*DAT_a00b4da0[param_1 & 0xff] + param_3) | 0xce000000);
}
