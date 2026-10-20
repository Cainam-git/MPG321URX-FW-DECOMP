/* FUN_a00c0a04 (leon2s 0xa00c0a04-0xa00c0a88, 132 bytes), flags -mcpu=v8 -Os -g.
 * Finds the first record i (0..5) of the 16-byte records DAT_a807d5c8 whose byte 4 has bit n set. For i <= 3
 * returns 1 when bit 5 of the ROM read func_0xa0fb7e98(i, 0x2e) is set, else 0; for i = 4, 5 returns bit 0 of the
 * ROM read func_0xa0fb6bb8(i - 4, 0x2a9). Returns 0 when no record has the bit. The bit-5 test is an if with
 * two returns (a "!= 0" expression folds into a shift).
 */
struct rec16 { unsigned char b0[4]; unsigned char b4; unsigned char rest[11]; };
extern struct rec16 DAT_a807d5c8[];
extern unsigned char func_0xa0fb7e98(unsigned char, unsigned int);
extern unsigned char func_0xa0fb6bb8(unsigned char, unsigned int);

unsigned char FUN_a00c0a04(int n)
{
    unsigned char i;

    for (i = 0; i <= 5; i++) {
        if ((DAT_a807d5c8[i].b4 >> n) & 1) {
            if (i <= 3)
                {
                    if (func_0xa0fb7e98(i, 0x2e) & 0x20)
                        return 1;
                    return 0;
                }
            return func_0xa0fb6bb8(i - 4, 0x2a9) & 1;
        }
    }
    return 0;
}
