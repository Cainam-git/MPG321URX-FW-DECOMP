/* leon2s FUN_a00ca6d4 @ 0xa00ca6d4-0xa00ca8c4, -mcpu=v8 -Os -g.
 * (u8 port), returns 0 or 1. FUN_a00c76c0(port, 5, 1, 1) and (port, 5, 2, 1); FUN_a00c87e8(port, 0xf, 0x8000);
 * the 16 bytes DAT_9f1c1e48[0x4f + i] (ROM table outside the image) go to FUN_a00c7654(port, 0x12, b), or to
 * FUN_a00c7654(2, 1, b) for port 2. Then FUN_a00c87e8 steps 1, 3 and 0xf, each followed by an empty u8 count
 * loop, FUN_a00c76c0(port, 8, 3, 1), FUN_a00c7654(port, 6, 8), and a poll of bits 0..1 of FUN_a00c7770(port, 8)
 * with a u8 counter from 0xff: 1 is returned when it runs out. Otherwise FUN_a00c87e8(port, 0x10, 0x8000), a
 * count loop, FUN_a00c87e8(port, 6, 0x8000), DAT_a807d088[0..31] = FUN_a00c7770(port, 1), a count loop, and 0.
 */
extern const unsigned char DAT_9f1c1e48[];
extern unsigned char DAT_a807d088[];
extern void FUN_a00c76c0(unsigned char, unsigned short, unsigned char, unsigned char);
extern void FUN_a00c87e8(unsigned char, unsigned char, unsigned short);
extern void FUN_a00c7654(unsigned char, unsigned short, unsigned char);
extern unsigned char FUN_a00c7770(unsigned char, unsigned short);

unsigned char FUN_a00ca6d4(unsigned char port)
{
    unsigned char i, t;

    FUN_a00c76c0(port, 5, 1, 1);
    FUN_a00c76c0(port, 5, 2, 1);
    FUN_a00c87e8(port, 0xf, 0x8000);
    for (i = 0; i <= 0xf; i++) {
        if (port != 2)
            FUN_a00c7654(port, 0x12, DAT_9f1c1e48[0x4f + i]);
        else
            FUN_a00c7654(2, 1, DAT_9f1c1e48[0x4f + i]);
    }
    FUN_a00c87e8(port, 1, 0x8000);
    for (i = 0; i <= 0xa; i++)
        ;
    FUN_a00c87e8(port, 3, 0x8000);
    for (i = 0; i <= 0xa; i++)
        ;
    FUN_a00c87e8(port, 0xf, 0x8000);
    for (i = 0; i <= 0xf; i++)
        ;
    FUN_a00c76c0(port, 8, 3, 1);
    FUN_a00c7654(port, 6, 8);
    t = 0xff;
    while ((FUN_a00c7770(port, 8) & 3) == 0) {
        t--;
        if (t == 0)
            return 1;
    }
    FUN_a00c87e8(port, 0x10, 0x8000);
    for (i = 0; i <= 0x1f; i++)
        ;
    FUN_a00c87e8(port, 6, 0x8000);
    for (i = 0; i <= 0x1f; i++)
        DAT_a807d088[i] = FUN_a00c7770(port, 1);
    for (i = 0; i <= 0x1f; i++)
        ;
    return 0;
}
