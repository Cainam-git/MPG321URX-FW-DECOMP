/* FUN_a0120678 (leon2m 0xa0120678-0xa01207ac, 308 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Sets bits 0..1 of the word register 0xcf011428, then writes 1 (on = 1) or 0 to the register 0xcf000000 + 4 *
 * (DAT_001a2fb0[c] + 0x1a) for c = 0, 1, or to the registers of entries 0 and 1 for c = 2. Nothing in the image
 * refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a0120638 and FUN_a01207ac.
 * Source form: a static put(c, reg, value) helper (register 0xcf011428 |= 3, then the write) inlined in each arm.
 */
#define R28 (*(volatile unsigned int *)0xcf011428)
#define REGI(i) (*(volatile unsigned int *)(0xcf000000 | ((i) << 2)))
extern const unsigned short DAT_001a2fb0[];
static void put(unsigned int c, unsigned int r, unsigned char v)
{
    unsigned char i;
    R28 |= 3;
    if (c == 2) {
        for (i = 0; i <= 1; i++)
            REGI(DAT_001a2fb0[i] + r) = v;
    } else if (c <= 1)
        REGI(DAT_001a2fb0[c] + r) = v;
}
void FUN_a0120678(unsigned int c, unsigned char on)
{
    if (on == 1)
        put(c, 0x1a, 1);
    else
        put(c, 0x1a, 0);
}
