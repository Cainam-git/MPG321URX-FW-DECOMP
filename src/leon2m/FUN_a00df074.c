/* leon2m FUN_a00df074 @ 0xa00df074-0xa00df0f4 (32 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Writes a 16-bit value as 4 hex digits to register 0xC00B0000, most significant digit first.
 * For i = 0..3 (do/while, cmp 3; ble): c = ROM hex table DAT_00198fa0[(val >> (12 - 4 i)) & 0xf]; poll ROM
 * func_0x4008c250(0xc00b0014) until bit 5 (0x20) is set or 0xfffff tries (u32 counter, incremented before the
 * test, cmp 0xffffe; bleu); then ROM func_0x4008c25c(0xc00b0000, (signed char)c). Same code as FUN_a00deffc,
 * which writes 32-bit values. void.
 * Source form: the shift count is its own variable 'int sh = 12 - i * 4;' computed before the table read. The
 *   zero-extension of val (srl) then lives one instruction in the loop body; with -msoft-float the first loop
 *   pass leaves it in place and the second pass hoists it after the table address and the 0xffffe bound, which
 *   gives the firmware's entry order and registers. The neighbouring matched functions of this file
 *   (FUN_a00deffc, FUN_a00def40, FUN_a00df278) give the same bytes with -msoft-float.
 */
extern char DAT_00198fa0[];
extern int func_0x4008c250(unsigned int);
extern int func_0x4008c25c(unsigned int, signed char);

void FUN_a00df074(unsigned short val)
{
  int i = 0;

  do {
    int sh = 12 - i * 4;
    signed char c = DAT_00198fa0[(val >> sh) & 0xf];
    unsigned int n = 0;
    do {
      n++;
      if (func_0x4008c250(0xc00b0014) & 0x20)
        break;
    } while (n < 0xfffff);
    func_0x4008c25c(0xc00b0000, c);
    i++;
  } while (i <= 3);
}
