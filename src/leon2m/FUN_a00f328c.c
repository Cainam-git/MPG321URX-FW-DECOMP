/* leon2m FUN_a00f328c @ 0xa00f328c  MATCH (-mcpu=v8 -O3 -g)
 * Writes a fixed set of 0xCF02xxxx hardware registers: clears 0xCF0200D4, clears bits 0xE0 of 0xCF020114 and bits
 * 0x41 of 0xCF0200CC (read-modify-write), then writes 0x50 to 0xCF020134 and 0x22 to 0xCF020138.
 * Caller: FUN_a011d194.
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a00f328c(void)
{
    R(0xcf0200d4) = 0;
    R(0xcf020114) &= ~0xe0;
    R(0xcf0200cc) &= ~0x41;
    R(0xcf020134) = 0x50;
    R(0xcf020138) = 0x22;
}
