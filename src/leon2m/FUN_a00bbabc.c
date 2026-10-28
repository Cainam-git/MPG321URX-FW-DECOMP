/* leon2m FUN_a00bbabc @ 0xa00bbabc-0xa00bbda0 (185 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a0085984 (twice). Same
 * layout as FUN_a00ce348 (which uses port 4). r = FUN_a00bb560(2); clear = byte 0xa802b09a = 0 and the 0x32 bytes at
 * 0xa802d040 cleared; reply(c) = the 6 bytes "5600" c "\r" at 0xa802d128 sent with FUN_a01487e8(2, 6, 0xa802d128). r
 * 0x10, 0x20, 0x40: clear, then reply('-'); 0x80: clear; 2: c = first row 0..0x82 of FUN_a015463c whose bytes 2..6
 * match bytes 2..6 at 0xa802d040 (0xff = any; 0xff when none), reply('6') when c is above 0x82, then clear; 4: c =
 * FUN_a00bb908(2), prints "##ucCmdIndex=%d\r\n" with c, clear, prints "##ucCmdStatus=%d\r\n" with 0 and clears byte
 * 0xa802b099. Other values: nothing.
 * Exact form: case order 0x80, 0x40, 0x20, 0x10, 2, 4 (the case order decides the block layout).
 */
extern unsigned char FUN_a00bb560(unsigned char);
extern void FUN_a01487e8(unsigned char, unsigned short, unsigned char *);
extern unsigned char FUN_a015463c(unsigned short, unsigned short);
extern unsigned char FUN_a00bb908(unsigned char);
extern int FUN_a00df170();
extern char s_00198298[], s_001982b0[];
extern unsigned char DAT_a802d128[];
extern unsigned char DAT_a802d040[];
extern unsigned char DAT_a802b09a, DAT_a802b099;

static void rx_clear(void)
{
    unsigned char i;

    DAT_a802b09a = 0;
    for (i = 0; i <= 0x31; i++)
        DAT_a802d040[i] = 0;
}

static void reply(unsigned char c)
{
    DAT_a802d128[0] = '5';
    DAT_a802d128[1] = '6';
    DAT_a802d128[2] = '0';
    DAT_a802d128[3] = '0';
    DAT_a802d128[4] = c;
    DAT_a802d128[5] = '\r';
    FUN_a01487e8(2, 6, DAT_a802d128);
}

static unsigned char find_cmd(void)
{
    unsigned char idx, j;

    for (idx = 0; idx <= 0x82; idx++) {
        for (j = 2; j <= 6; j++) {
            if (FUN_a015463c(idx, j) != 0xff && FUN_a015463c(idx, j) != DAT_a802d040[j])
                break;
        }
        if (j == 7)
            return idx;
    }
    return 0xff;
}

void FUN_a00bbabc(void)
{
    unsigned char c;

    switch (FUN_a00bb560(2)) {
    case 0x80:
        rx_clear();
        break;
    case 0x40:
        rx_clear();
        reply('-');
        break;
    case 0x20:
        rx_clear();
        reply('-');
        break;
    case 0x10:
        rx_clear();
        reply('-');
        break;
    case 2:
        c = find_cmd();
        if (c > 0x82)
            reply('6');
        rx_clear();
        break;
    case 4:
        c = FUN_a00bb908(2);
        FUN_a00df170(s_00198298, c);
        rx_clear();
        FUN_a00df170(s_001982b0, 0);
        DAT_a802b099 = 0;
        break;
    }
}
