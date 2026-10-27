/* FUN_a00f6c38 (leon2m 0xa00f6c38-0xa00f6c6c, 52 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Sets bit (DAT_a802b7b4 + 4) of the word register 0xcf00ee80 and writes back the low byte of the result. Nothing
 * in the image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a00f6b34 and
 * FUN_a00f6c6c. Source form: the result is cast to unsigned char before the register write.
 */
#define REG (*(volatile unsigned int *)0xcf00ee80)
extern unsigned char DAT_a802b7b4;

void FUN_a00f6c38(void)
{
    REG = (unsigned char)(REG | (1 << (DAT_a802b7b4 + 4)));
}
