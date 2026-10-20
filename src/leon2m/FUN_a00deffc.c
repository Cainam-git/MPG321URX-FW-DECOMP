/* leon2m FUN_a00deffc @ 0xa00deffc-0xa00df074 (30 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 30 words. Prints a 32-bit value as 8 hex digits on the UART.
 * Code facts: for i = 0..7 (do/while, cmp 7; ble): c = ROM hex table DAT_00198fa0[(val >> (28 - 4 i)) & 0xf]
 * (ldub [table + idx]); poll ROM func_0x4008c250(0xc00b0014) until bit 5 (0x20) is set or 0xfffff tries (u32
 * counter, incremented before the test, cmp 0xffffe; bleu); then ROM func_0x4008c25c(0xc00b0000, (signed char)c).
 * The shift is written 28 - i * 4: loop strength reduction then makes the %l3 giv (init 0x1c, -4 per pass), and
 * its init lands after the hoisted 0xc00b0000 sethi like the fw. A separate 'sh' variable puts 'mov 0x1c' first
 * (96.67). A constant table pointer gives [idx + base] (93.33); the table is the symbol DAT_00198fa0. void.
 * Aids: none.
 */
extern char DAT_00198fa0[];
extern int func_0x4008c250(unsigned int);
extern int func_0x4008c25c(unsigned int, signed char);

void FUN_a00deffc(unsigned int val)
{
  int i = 0;

  do {
    signed char c = DAT_00198fa0[(val >> (28 - i * 4)) & 0xf];
    unsigned int n = 0;
    do {
      n++;
      if (func_0x4008c250(0xc00b0014) & 0x20)
        break;
    } while (n < 0xfffff);
    func_0x4008c25c(0xc00b0000, c);
    i++;
  } while (i <= 7);
}
