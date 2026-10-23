/* FUN_a00866e0 (leon2s 0xa00866e0-0xa008686c, 396 bytes), flags -mcpu=v8 -Os -g.
 * For i from lo to hi (0..0, or DAT_a80761c0..DAT_a80761bf when sel != 0) fills the 6-byte record
 * ARR_a807cd2e[i]: byte 1 = 0x12; byte 2 = 0x1e, or DAT_a807cd00[0] when that is <= 0x1d; byte 3 = 4, or
 * DAT_a807cd00[1] when that is <= 3; byte 5 = DAT_a80789f0 << 2 when FUN_a0086400(i, 0x90, 0xe, 0,
 * &DAT_a80789f0) returns 1 and the read byte is 1..4, 1 for another byte, 10 when the read fails. Byte 0 gets
 * bit 4 set, bit 3 = bit 6 of the byte read by FUN_a0086400(i, 0x90, 7, 0, &DAT_a80789f0) when that returns 1
 * (else 0), bits 1, 2, 5 and 6 cleared and bit 7 set.
 * DAT_a807cd00 is volatile as in its other users (every access is a separate load).
 * Source form: the bit-3 update is a nested if with the clear written in both else arms.
 */
extern unsigned char ARR_a807cd2e[][6];
extern volatile unsigned char DAT_a807cd00[];
extern unsigned char DAT_a80789f0;
extern unsigned char DAT_a80761bf;
extern unsigned char DAT_a80761c0;
extern unsigned char FUN_a0086400(unsigned char, unsigned int, unsigned int, unsigned int, unsigned char *);

void FUN_a00866e0(unsigned char sel)
{
    unsigned char lo = 0;
    unsigned char hi = 0;
    unsigned char i;
    unsigned char *rec;

    if (sel) {
        lo = DAT_a80761c0;
        hi = DAT_a80761bf;
    }
    for (i = lo; i <= hi; i++) {
        rec = ARR_a807cd2e[i];
        rec[1] = 0x12;
        rec[2] = 0x1e;
        if (DAT_a807cd00[0] <= 0x1d)
            rec[2] = DAT_a807cd00[0];
        rec[3] = 4;
        if (DAT_a807cd00[1] <= 3)
            rec[3] = DAT_a807cd00[1];
        if (FUN_a0086400(i, 0x90, 0xe, 0, &DAT_a80789f0) == 1) {
            rec[5] = DAT_a80789f0;
            if ((unsigned char)(DAT_a80789f0 - 1) <= 3)
                rec[5] = DAT_a80789f0 << 2;
            else
                rec[5] = 1;
        } else
            rec[5] = 10;
        ARR_a807cd2e[i][0] |= 0x10;
        if (FUN_a0086400(i, 0x90, 7, 0, &DAT_a80789f0) == 1) {
            if (DAT_a80789f0 & 0x40)
                ARR_a807cd2e[i][0] |= 8;
            else
                ARR_a807cd2e[i][0] &= ~8;
        } else
            ARR_a807cd2e[i][0] &= ~8;
        ARR_a807cd2e[i][0] = (ARR_a807cd2e[i][0] & ~0x66) | 0x80;
    }
}
