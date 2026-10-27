/* FUN_a011b4b0 (leon2m 0xa011b4b0-0xa011b4f0, 64 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes the byte v to the word register 0xcf011780 (c = 0) or 0xcf011794 (c non-zero), then runs a delay loop of
 * 0xa0 nops. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a011b428 and FUN_a011b4f0. Source form: one register write in each arm of the if/else.
 */
#define REG380 (*(volatile unsigned int *)0xcf011780)
#define REG394 (*(volatile unsigned int *)0xcf011794)

void FUN_a011b4b0(unsigned char c, unsigned char v)
{
    int i;

    if (c == 0)
        REG380 = v;
    else
        REG394 = v;
    for (i = 0; i < 0xa0; i++)
        __asm__("nop");
}
