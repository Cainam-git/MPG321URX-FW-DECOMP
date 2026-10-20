/* leon2m FUN_a010a9e8 @ 0xa010a9e8 (-mcpu=v8 -O3 -g, gcc 3.4.4; hand, finished with the permuter)
 * FRC output frame length (lines), 16 bits.
 *   0xCF011A80 bit 7 set: sum of the four 32-bit registers 0xCF011AE0, 0xCF011AE8, 0xCF011AF0, 0xCF011AF8 (read with
 *     FUN_a00f3078), then scaled by chip variant FUN_a011cf88() and the bits of 0xCF011E40:
 *       variant > 0x82 and bit 3 -> x2;  variant > 0x83 and bit 2 -> x4;  variant > 0x83 and bit 1 -> x8 (cumulative).
 *   bit 7 clear: the register 0xCF011C38 (in Free Run mode FUN_a0109bbc writes the fixed output frame length there;
 *     in Lock mode it is 0x3FFF).
 *   The result is truncated to 16 bits (the variable is unsigned short; same value as a 32-bit sum returned as 16 bits).
 * Callers: FUN_a01070b4 (panel limitation check: "vtotal" when FRC is on) and FUN_a012b9a8.
 * Note: the four summed registers are 0xCF011AE0.., not 0xCF011EE0..: objdump's hint followed a sethi in an annulled
 * delay slot.
 */


extern int FUN_a00f3078(int);
extern unsigned char FUN_a011cf88(void);
unsigned short FUN_a010a9e8(void)
{
  unsigned short n;
  if ((*((volatile unsigned int *) 0xcf011a80)) & 0x80)
  {
    n = FUN_a00f3078(0xcf011ae0);
    n += FUN_a00f3078(0xcf011ae8);
    n += FUN_a00f3078(0xcf011af0);
    n += FUN_a00f3078(0xcf011af8);
    n = ((FUN_a011cf88() > 0x82) && ((*((volatile unsigned int *) 0xcf011e40)) & 8)) ? (n + n) : (n);
    if ((FUN_a011cf88() > 0x83) && ((*((volatile unsigned int *) 0xcf011e40)) & 4))
    {
      n <<= 2;
    }
    if ((FUN_a011cf88() > 0x83) && ((*((volatile unsigned int *) 0xcf011e40)) & 2))
    {
      n <<= 3;
    }
  }
  else
  {
    n = FUN_a00f3078(0xcf011c38);
  }
  return n;
}
