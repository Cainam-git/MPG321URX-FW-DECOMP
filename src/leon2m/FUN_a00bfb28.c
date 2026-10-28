/* leon2m FUN_a00bfb28 @ 0xa00bfb28-0xa00bfcc4 (103 words).
 * Builds a 0x13-byte record in DAT_a802d078: "5b00[" (bytes 0..4), bytes 5..16 = FUN_a0145920(6 .. 14, 18, 19, 20),
 * byte 17 = sum of bytes 5..16, byte 18 = '\r'. Then clears the receive state of the port (FUN_a00ba950, inlined)
 * and calls FUN_a01487e8(port, 0x13, DAT_a802d078) (tail call).
 * Source form: FUN_a00ba950 is defined here as a static copy (GCC inlines it and repeats the port test).
 */
extern unsigned char DAT_a802b09a, DAT_a802b098, DAT_a802b09c;
extern unsigned char DAT_a802d040[], DAT_a802d098[], DAT_a802d0d0[];
extern unsigned char DAT_a802d078[0x25];
extern unsigned char FUN_a0145920(unsigned char);
extern void FUN_a01487e8(unsigned char, unsigned short, unsigned char *);

static void FUN_a00ba950(unsigned char port)
{
    if (port == 2) {
        DAT_a802b09a = 0;
        DAT_a802d040[0] = 0;
        DAT_a802d040[1] = 0;
        DAT_a802d040[7] = 0;
        DAT_a802d040[10] = 0;
        DAT_a802d040[0x19] = 0;
    } else if (port == 3) {
        DAT_a802b098 = 0;
        DAT_a802d098[0] = 0;
        DAT_a802d098[1] = 0;
        DAT_a802d098[7] = 0;
        DAT_a802d098[10] = 0;
        DAT_a802d098[0x19] = 0;
    } else {
        DAT_a802b09c = 0;
        DAT_a802d0d0[0] = 0;
        DAT_a802d0d0[1] = 0;
        DAT_a802d0d0[7] = 0;
        DAT_a802d0d0[10] = 0;
        DAT_a802d0d0[0x19] = 0;
    }
}

void FUN_a00bfb28(unsigned char port)
{
    unsigned char i, sum = 0;

    DAT_a802d078[0] = '5';
    DAT_a802d078[1] = 'b';
    DAT_a802d078[4] = '[';
    DAT_a802d078[2] = '0';
    DAT_a802d078[3] = '0';
    DAT_a802d078[5] = FUN_a0145920(6);
    DAT_a802d078[6] = FUN_a0145920(7);
    DAT_a802d078[7] = FUN_a0145920(8);
    DAT_a802d078[8] = FUN_a0145920(9);
    DAT_a802d078[9] = FUN_a0145920(10);
    DAT_a802d078[10] = FUN_a0145920(11);
    DAT_a802d078[11] = FUN_a0145920(12);
    DAT_a802d078[12] = FUN_a0145920(13);
    DAT_a802d078[13] = FUN_a0145920(14);
    DAT_a802d078[14] = FUN_a0145920(18);
    DAT_a802d078[15] = FUN_a0145920(19);
    DAT_a802d078[16] = FUN_a0145920(20);
    for (i = 5; i <= 16; i++)
        sum += DAT_a802d078[i];
    DAT_a802d078[17] = sum;
    DAT_a802d078[18] = '\r';
    FUN_a00ba950(port);
    FUN_a01487e8(port, 0x13, DAT_a802d078);
}
