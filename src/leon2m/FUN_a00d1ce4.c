/* leon2m FUN_a00d1ce4 @ 0xa00d1ce4, flags -mcpu=v8 -O3 -g (also exact at -O2 -g)
 * Tool command handler: sets the factory "Burn In" settings byte DAT_a802d290[0x1d5] (0xA802D465) from
 * command byte 7 when it is 1 or 0 (other values leave it), then saves the 0x1FC-byte settings block
 * (FUN_a014aed0(0x30, block, 0, 0x1fc)) and returns 0xE0 (ack).
 */
extern unsigned char DAT_a802d290[];
extern int FUN_a014aed0();

int FUN_a00d1ce4(unsigned char *param_1)
{
    if (param_1[7] == 1)
        DAT_a802d290[0x1d5] = 1;
    else if (param_1[7] == 0)
        DAT_a802d290[0x1d5] = 0;
    FUN_a014aed0(0x30, DAT_a802d290, 0, 0x1fc);
    return 0xe0;
}
