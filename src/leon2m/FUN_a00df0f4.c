/* leon2m FUN_a00df0f4 @ 0xa00df0f4-0xa00df170 (31 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Writes an 8-bit value as 2 hex digits to register 0xC00B0000, high digit first.
 * For i = 0..1: c = ROM hex table DAT_00198fa0[(val >> (4 - 4 i)) & 0xf]; poll ROM func_0x4008c250(0xc00b0014)
 * until bit 5 (0x20) is set or 0xfffff polls have passed, then ROM func_0x4008c25c(0xc00b0000, (signed char)c).
 * Same code as FUN_a00df074 (16-bit values) and FUN_a00deffc (32-bit values). void.
 * Source form: the wait-and-write is the static helper of FUN_a00df170 (wait loop
 *   'for (t = 0; !(status & 0x20); ) if (++t > 0xffffe) break;'), inlined. Its loop shape gives the block
 *   frequencies with which global allocation puts the shift count in %l2 and 0xc00b0000 in %l3 as in the
 *   firmware. The same bytes come out without -msoft-float.
 */
extern char DAT_00198fa0[];
extern int func_0x4008c250(unsigned int);
extern int func_0x4008c25c(unsigned int, signed char);

static void uart_putc(signed char c)
{
  unsigned int t;
  for (t = 0; !(func_0x4008c250(0xc00b0014) & 0x20); )
    if (++t > 0xffffe) break;
  func_0x4008c25c(0xc00b0000, c);
}

void FUN_a00df0f4(unsigned char val)
{
  int i;
  for (i = 0; i < 2; i++)
    uart_putc(DAT_00198fa0[(val >> (4 - i * 4)) & 0xf]);
}
