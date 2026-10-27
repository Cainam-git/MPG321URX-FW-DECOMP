/* FUN_a00fa560 (leon2m 0xa00fa560-0xa00fa5b4, 84 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Reads the word register 0xd0040014 (v), stores bits 16..25 of v ((v << 6) >> 22) to the halfword DAT_a802bec0,
 * and compares t = v >> 30 with the byte DAT_a802c85e: when they differ stores t there and 1 to the byte
 * DAT_a802b7fe, otherwise stores 0 to DAT_a802b7fe. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a00f9f10 and FUN_a00fa5b4. Source form: the top two bits are kept
 * in an unsigned char local.
 */
#define REG (*(volatile unsigned int *)0xd0040014)
extern unsigned short DAT_a802bec0;
extern unsigned char DAT_a802c85e, DAT_a802b7fe;

void FUN_a00fa560(void)
{
    unsigned int v = REG;
    unsigned char top;

    DAT_a802bec0 = (v << 6) >> 22;
    top = v >> 30;
    if (top != DAT_a802c85e) {
        DAT_a802c85e = top;
        DAT_a802b7fe = 1;
    } else
        DAT_a802b7fe = 0;
}
