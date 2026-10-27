/* FUN_a00e4f8c (leon2m 0xa00e4f8c-0xa00e52e8, 860 bytes), flags -mcpu=v8 -O3 -g. Called by FUN_a00e5fc8.
 * FUN_a00e4f8c(unit, mode, b): register fields are read with FUN_a00e0754 with (reg, mask, shift) from entry b of
 * three word tables (b == -1 passes the table addresses themselves, as in FUN_a00e9c80 / FUN_a00ec340).
 *  - mode 4: got = FUN_a00e0b00(unit, b) (64-bit); bits = the low 8 bits of DAT_a8026988 in reverse order; mask = the
 *    64-bit value with byte i = 0xff for every set bit i of bits (__lshrdi3 / __ashldi3 library calls); when
 *    got == mask the result is 1 if field(0xa8026458/448/438) != 1; otherwise 0.
 *  - other modes: returns 1 when field(0xa80263e8/3d8, 0xa802b6a8) == 0, field(0xa8026408/3f8, 0xa802b6b8) == 0xff,
 *    field(0xa80263c8/3b8, 0xa802b698) == 0, field(0xa80263a8/398, 0xa802b688) == 0xff and
 *    field(0xa8026458/448/438) != 1 (all five fields are read), else 0.
 * Source form: each read is its own if (b == -1)/else statement; the five comparisons are kept in variables and
 * the second arm returns their && chain.
 */
extern unsigned int FUN_a00e0754(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned long long FUN_a00e0b00(unsigned int unit, int b);
extern unsigned int DAT_a8026988;
extern unsigned int DAT_a80263e8[], DAT_a80263d8[], DAT_a802b6a8[], DAT_a8026408[], DAT_a80263f8[], DAT_a802b6b8[],
    DAT_a80263c8[], DAT_a80263b8[], DAT_a802b698[], DAT_a80263a8[], DAT_a8026398[], DAT_a802b688[], DAT_a8026458[],
    DAT_a8026448[], DAT_a8026438[];

unsigned int FUN_a00e4f8c(unsigned int unit, int mode, int b)
{
    unsigned int r;
    unsigned int a, c, d, e, f;
    unsigned long long got, bits, mask;
    int i;

    if (mode == 4) {
        r = 0;
        got = FUN_a00e0b00(unit, b);
        bits = 0;
        mask = 0;
        for (i = 0; i < 8; i++)
            bits |= (((1 << i) & DAT_a8026988) >> i) << (7 - i);
        for (i = 0; i < 8; i++)
            if ((bits >> i) & 1)
                mask |= 0xffULL << (i * 8);
        if (got == mask) {
            if (b == -1)
                e = FUN_a00e0754(unit, (unsigned int)DAT_a8026458, (unsigned int)DAT_a8026448, (unsigned int)DAT_a8026438);
            else
                e = FUN_a00e0754(unit, DAT_a8026458[b], DAT_a8026448[b], DAT_a8026438[b]);
            if (e != 1)
                r = 1;
        }
    } else {
        if (b == -1)
            a = FUN_a00e0754(unit, (unsigned int)DAT_a80263e8, (unsigned int)DAT_a80263d8, (unsigned int)DAT_a802b6a8) == 0;
        else
            a = FUN_a00e0754(unit, DAT_a80263e8[b], DAT_a80263d8[b], DAT_a802b6a8[b]) == 0;
        if (b == -1)
            c = FUN_a00e0754(unit, (unsigned int)DAT_a8026408, (unsigned int)DAT_a80263f8, (unsigned int)DAT_a802b6b8) == 0xff;
        else
            c = FUN_a00e0754(unit, DAT_a8026408[b], DAT_a80263f8[b], DAT_a802b6b8[b]) == 0xff;
        if (b == -1)
            d = FUN_a00e0754(unit, (unsigned int)DAT_a80263c8, (unsigned int)DAT_a80263b8, (unsigned int)DAT_a802b698) == 0;
        else
            d = FUN_a00e0754(unit, DAT_a80263c8[b], DAT_a80263b8[b], DAT_a802b698[b]) == 0;
        if (b == -1)
            f = FUN_a00e0754(unit, (unsigned int)DAT_a80263a8, (unsigned int)DAT_a8026398, (unsigned int)DAT_a802b688) == 0xff;
        else
            f = FUN_a00e0754(unit, DAT_a80263a8[b], DAT_a8026398[b], DAT_a802b688[b]) == 0xff;
        if (b == -1)
            e = FUN_a00e0754(unit, (unsigned int)DAT_a8026458, (unsigned int)DAT_a8026448, (unsigned int)DAT_a8026438) != 1;
        else
            e = FUN_a00e0754(unit, DAT_a8026458[b], DAT_a8026448[b], DAT_a8026438[b]) != 1;
        return a && c && d && f && e;
    }
    return r;
}
