/* FUN_a0097ff4 (leon2s 0xa0097ff4-0xa0098048, 84 bytes), flags -mcpu=v8 -Os -g.
 * rec = 0x34-byte record (port) of ARR_a807db00; with w = rec word 1 (offset +4, read before each call) it sets
 * bit 0x1b of the bitmap at w + 0x34 through FUN_a00a73ac, then sets (on == 1) or clears (FUN_a00a73d4) bit 0x18
 * of the same bitmap; the second call is a tail call.
 */
extern void FUN_a00a73ac(unsigned int, int);
extern void FUN_a00a73d4(unsigned int, int);
extern unsigned char ARR_a807db00[];

void FUN_a0097ff4(unsigned char port, unsigned char on)
{
    unsigned int *base = (unsigned int *)(ARR_a807db00 + port * 0x34);

    FUN_a00a73ac(0x1b, base[1] + 0x34);
    if (on == 1)
        FUN_a00a73ac(0x18, base[1] + 0x34);
    else
        FUN_a00a73d4(0x18, base[1] + 0x34);
}
