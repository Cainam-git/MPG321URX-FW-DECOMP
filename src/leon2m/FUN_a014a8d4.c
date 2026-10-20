/* leon2m FUN_a014a8d4 @ 0xa014a8d4-0xa014aa48 (93 words).
 * Sets bit 16 of word 0x70 in the 0x78-byte records at 0xa802df30 to bit 0 of on and halfword 0x74 to v. Channel 4
 * writes all four records; channels 0..3 write their own record, and any other value reports
 * "SYS remapping channel OOR" and uses record 0. Finally FUN_a00df170 prints
 * "MDHDLRs[%d].bDisplayDelay = %d" with the channel and the bit read back from record ch (for channel 4 that is
 * word 0xa802e180, the word after the four records).
 */
struct Rec { unsigned char head[0x70]; unsigned int pad : 15; unsigned int delay : 1; unsigned int low : 16;
             unsigned short v; unsigned short tail; };
extern struct Rec DAT_a802df30[4];
extern int FUN_a00df170();
extern char s_001a6dd8[];
extern char s_001a7048[];

static int remap(int ch)
{
    switch (ch) {
    case 0: return 0;
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

void FUN_a014a8d4(unsigned char ch, unsigned int on, unsigned short v)
{
    if (ch == 4) {
        DAT_a802df30[0].delay = on;
        DAT_a802df30[1].delay = on;
        DAT_a802df30[2].delay = on;
        DAT_a802df30[3].delay = on;
        DAT_a802df30[0].v = v;
        DAT_a802df30[1].v = v;
        DAT_a802df30[2].v = v;
        DAT_a802df30[3].v = v;
    } else {
        ch = remap(ch);
        if (ch > 3) { FUN_a00df170(s_001a6dd8); ch = 0; }
        DAT_a802df30[ch].delay = on;
        DAT_a802df30[ch].v = v;
    }
    FUN_a00df170(s_001a7048, ch, DAT_a802df30[ch].delay);
}
