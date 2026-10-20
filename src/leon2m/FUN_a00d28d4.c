/* leon2m FUN_a00d28d4 @ 0xa00d28d4  tool command: factory mode + Burn In on (hand;
 * -mcpu=v8 -O3 -g)
 *
 * When command byte 7 is 1: settings word 0 |= 0x4000 (factory mode bit), Burn In byte +0x1D5 (0xA802D465) = 1,
 * marker +0x1F6 = 0x55AA, +0x1D6 = 0x55, save the 0x1FC-byte settings block (FUN_a014aed0(0x30, block, 0, 0x1fc));
 * returns 0xE0 when the block still holds bit 14, Burn In 1 and 0x55AA, else 0xE4. Any other byte 7: 0xE4, nothing
 * written. Gate writer: the only tool path that turns the colour cycler's Burn In gate on, together
 * with FUN_a00d1ce4 and the factory menu.
 */
extern unsigned char DAT_a802d290[];
extern int FUN_a014aed0();

int FUN_a00d28d4(unsigned char *param_1)
{
    unsigned char v = param_1[7];
    int r = 0xe4;
    if (v == 1) {
        *(unsigned int *)DAT_a802d290 |= 0x4000;
        DAT_a802d290[0x1d5] = v;
        *(unsigned short *)(DAT_a802d290 + 0x1f6) = 0x55aa;
        DAT_a802d290[0x1d6] = 0x55;
        FUN_a014aed0(0x30, DAT_a802d290, 0, 0x1fc);
        if ((*(unsigned int *)DAT_a802d290 & 0x4000) && DAT_a802d290[0x1d5] == 1 && *(unsigned short *)(DAT_a802d290 + 0x1f6) == 0x55aa)
            r = 0xe0;
        else
            r = 0xe4;
    }
    return r;
}
