/* FUN_a0086c48 (leon2s 0xa0086c48-0xa0086df4, 428 bytes), flags -mcpu=v8 -Os -g.
 * Fills the 4-byte output out for port: out[1] = byte 3 and out[0] = byte 2 of the 6-byte record
 * ARR_a807cd2e[port], out[3] = 1, out[2] = 6. Port 0: out[1] and out[0] are limited to DAT_a807cd68[1] and
 * DAT_a807cd68[0], which are then set to 4 and 0x1e; when FUN_a0086bd8() returns non-zero, c = FUN_a00a6bb8(k,
 * 0x80) when FUN_a00858f0(0) is 0x71 (k = 0) or 0x81 (k = 1) and FUN_a00ad27c(k) is 1, else 0xff; unless c is
 * 0xff, out[0] = 6, 10, 0x14 or 0x1e for c & 3 = 0, 1, 2, 3, out[2] = out[0] and out[1] = (c & 0x1c) >> 2.
 * Other ports: out[1] and out[0] are limited to DAT_a807cd00[1] and DAT_a807cd00[0].
 * DAT_a807cd00 and DAT_a807cd68 are volatile as in their other users (every access is a separate load).
 * Source form: the call result is an int set to -1 and then narrowed to the byte c; if/else chain on c & 3.
 */
extern unsigned char ARR_a807cd2e[][6];
extern volatile unsigned char DAT_a807cd00[];
extern volatile unsigned char DAT_a807cd68[];
extern unsigned char FUN_a0086bd8(void);
extern unsigned char FUN_a00858f0(unsigned char);
extern unsigned char FUN_a00ad27c(unsigned char port);
extern unsigned int FUN_a00a6bb8(unsigned int param_1, unsigned short param_2);

void FUN_a0086c48(unsigned char port, unsigned char *out)
{
    unsigned char v;
    int r;
    unsigned char c;

    out[1] = ARR_a807cd2e[port][3];
    out[0] = ARR_a807cd2e[port][2];
    out[3] = 1;
    out[2] = 6;
    if (port == 0) {
        if (out[1] > DAT_a807cd68[1])
            out[1] = DAT_a807cd68[1];
        if (out[0] > DAT_a807cd68[0])
            out[0] = DAT_a807cd68[0];
        DAT_a807cd68[0] = 0x1e;
        DAT_a807cd68[1] = 4;
        if (!FUN_a0086bd8())
            return;
        v = FUN_a00858f0(0);
        r = -1;
        if (v == 0x71) {
            if (FUN_a00ad27c(0) == 1)
                r = FUN_a00a6bb8(0, 0x80);
        } else if (v == 0x81) {
            if (FUN_a00ad27c(1) == 1)
                r = FUN_a00a6bb8(1, 0x80);
        }
        c = r;
        if (c == 0xff)
            return;
        if ((c & 3) == 0)
            out[0] = 6;
        else if ((c & 3) == 1)
            out[0] = 10;
        else if ((c & 3) == 2)
            out[0] = 0x14;
        else
            out[0] = 0x1e;
        out[2] = out[0];
        out[1] = (c & 0x1c) >> 2;
    } else {
        if (out[1] > DAT_a807cd00[1])
            out[1] = DAT_a807cd00[1];
        if (out[0] > DAT_a807cd00[0])
            out[0] = DAT_a807cd00[0];
    }
}
