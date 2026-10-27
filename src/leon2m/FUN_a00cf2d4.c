/* leon2m FUN_a00cf2d4 @ 0xa00cf2d4-0xa00cfa14 (464 words), flags -mcpu=v8 -O3 -g. Called by FUN_a0088724.
 * Fills the byte buffer buf according to byte rx[4] of the byte record rx:
 *  - 0x10, 0x12: FUN_a00cead4(buf, 0, byte 0xa802d299 / 0xa802d29a, 0, 0); 0x16: FUN_a00cead4(buf, 0, 0xff, 0, 0)
 *    when rx[5] is 2, else FUN_a00cead4(buf, 0xff, 0, 0, byte 0xa802b0a2); 0x18, 0x1a, 0x6c, 0x6e, 0x70: the latter
 *    form with byte 0xa802b0a1, 0xa802b0a0, 0xa802d2a5, 0xa802d2a6, 0xa802d2a7.
 *  - 0x60: FUN_a00cead4(buf, 3, 1, 0, k) with k from byte 0xa802d2ae (4: 0x11, 6: 0x12, 7: 0x11, 0xb and 0xc:
 *    0xf, 0xd: 0x10, 2: 3, others 1).
 *  - 0xcc: buf[0..8] = 0x6e, 0x88, 2, 0, 0xfe, 1, 0, 0xff, 0, then buf[7] from byte 0xa802d298 through a 20-entry
 *    switch (jump table 0xa00ceb24; values 0..19 give 1, 2, 3, 4, 5, 0xa, 7, 6, 9, 8, 0xd, 0x23, 2, 0x19, 0xc, 2,
 *    0x25, 0x18, 2, 0xf; above 19 gives 2), then FUN_a0089f60(0x50).
 *  - 0xe1 with rx[5..7] = a5 03 00: buf[0..6] = 0x6e, 0x88, 2, 0, 0xfe, 2, 0xb0 and FUN_a0089f60(0x50); a7 07 00 and
 *    e6 06 00: buf[0..1] = 0x6e, 0x95 / 0x89, FUN_a0089f60(0x50), then the 18 / 6 bytes after the length byte of the
 *    table at 0x198340 / 0x198338 are copied to buf[5..].
 *  - 0xe2: rx[5] = 1..6 selects byte 0xa802e1f0..0xa802e1f5 for FUN_a00cead4(buf, 0, value, 0, 0).
 *  - 0xe9 with rx[6] and rx[7] zero: buf[0..1] = 0x6e, 0x91, FUN_a0089f60(0x50), the 14 bytes after the length
 *    byte at 0x198328 are copied to buf[5..].
 *  - 0xef: rx[5] = 0x13: buf[0] = 0x6e, buf[1] = byte 0xa802d276 + 0x80, FUN_a0089f60(0x50),
 *    FUN_a014ae1c(0x30, 0xa802d274, 0x2e0, 0x1c), then byte 0xa802d276 bytes from 0xa802d277 to buf[2..]. Otherwise
 *    buf[0..1] = 0x6e, 0x88; for rx[5] = 0x42 and again for 0x43: FUN_a014b0c4(0xff, 0xa802d148, &len) (len = 0x100,
 *    a halfword on the stack) when rx[6] and rx[7] are zero, then the 32 bytes at 0xa802d148 + rx[6] * 0x100 + rx[7]
 *    to buf[2..]; finally FUN_a0089f60(0x50).
 * Source form: the case blocks in the order 0x10, 0x12, 0x16, 0x18, 0x1a, 0x6c, 0x6e, 0x70, 0x60, 0xcc, 0xe2, 0xe1,
 * 0xe9, 0xef (this order gives the register choices); the 6, 14 and 18 byte copy loops compare with a limit held in a
 * variable n (cmp n; bcs), the 32 byte loops with the constant (cmp 0x1f; bleu).
 */
struct S274 {
    unsigned char pad[2];
    unsigned char n;
    unsigned char data[0x19];
};
extern struct S274 DAT_a802d274;
extern unsigned char DAT_a802d148[];
extern unsigned char DAT_a802d298, DAT_a802d299, DAT_a802d29a, DAT_a802d2a5, DAT_a802d2a6, DAT_a802d2a7, DAT_a802d2ae;
extern unsigned char DAT_a802b0a0, DAT_a802b0a1, DAT_a802b0a2;
extern unsigned char DAT_a802e1f0, DAT_a802e1f1, DAT_a802e1f2, DAT_a802e1f3, DAT_a802e1f4, DAT_a802e1f5;
extern const unsigned char DAT_00198328[], DAT_00198338[], DAT_00198340[];
extern void FUN_a00cead4(unsigned char *, unsigned char, unsigned char, unsigned char, unsigned char);
extern void FUN_a0089f60(unsigned char);
extern int FUN_a014ae1c(int, void *, int, int);
extern void FUN_a014b0c4(int, void *, unsigned short *);

void FUN_a00cf2d4(unsigned char *rx, unsigned char *buf)
{
    unsigned char i, a, b, code, n;
    unsigned short len;

    switch (rx[4]) {
    case 0x10:
        FUN_a00cead4(buf, 0, DAT_a802d299, 0, 0);
        break;
    case 0x12:
        FUN_a00cead4(buf, 0, DAT_a802d29a, 0, 0);
        break;
    case 0x16:
        if (rx[5] == 2)
            FUN_a00cead4(buf, 0, 0xff, 0, 0);
        else
            FUN_a00cead4(buf, 0xff, 0, 0, DAT_a802b0a2);
        break;
    case 0x18:
        FUN_a00cead4(buf, 0xff, 0, 0, DAT_a802b0a1);
        break;
    case 0x1a:
        FUN_a00cead4(buf, 0xff, 0, 0, DAT_a802b0a0);
        break;
    case 0x6c:
        FUN_a00cead4(buf, 0xff, 0, 0, DAT_a802d2a5);
        break;
    case 0x6e:
        FUN_a00cead4(buf, 0xff, 0, 0, DAT_a802d2a6);
        break;
    case 0x70:
        FUN_a00cead4(buf, 0xff, 0, 0, DAT_a802d2a7);
        break;
    case 0x60:
        if (DAT_a802d2ae == 4)
            code = 0x11;
        else if (DAT_a802d2ae == 6)
            code = 0x12;
        else if (DAT_a802d2ae == 7)
            code = 0x11;
        else if (DAT_a802d2ae == 0xb)
            code = 0xf;
        else if (DAT_a802d2ae == 0xc)
            code = 0xf;
        else if (DAT_a802d2ae == 0xd)
            code = 0x10;
        else if (DAT_a802d2ae == 2)
            code = 3;
        else
            code = 1;
        FUN_a00cead4(buf, 3, 1, 0, code);
        break;
    case 0xcc:
        buf[0] = 0x6e;
        buf[1] = 0x88;
        buf[2] = 2;
        buf[3] = 0;
        buf[4] = 0xfe;
        buf[5] = 1;
        buf[6] = 0;
        buf[7] = 0xff;
        buf[8] = 0;
        switch (DAT_a802d298) {
        case 0: buf[7] = 1; break;
        case 1: buf[7] = 2; break;
        case 2: buf[7] = 3; break;
        case 3: buf[7] = 4; break;
        case 4: buf[7] = 5; break;
        case 5: buf[7] = 0xa; break;
        case 6: buf[7] = 7; break;
        case 7: buf[7] = 6; break;
        case 8: buf[7] = 9; break;
        case 9: buf[7] = 8; break;
        case 10: buf[7] = 0xd; break;
        case 11: buf[7] = 0x23; break;
        case 13: buf[7] = 0x19; break;
        case 14: buf[7] = 0xc; break;
        case 16: buf[7] = 0x25; break;
        case 17: buf[7] = 0x18; break;
        case 19: buf[7] = 0xf; break;
        default: buf[7] = 2; break;
        }
        FUN_a0089f60(0x50);
        break;
    case 0xe2:
        if (rx[5] == 1)
            FUN_a00cead4(buf, 0, DAT_a802e1f0, 0, 0);
        else if (rx[5] == 2)
            FUN_a00cead4(buf, 0, DAT_a802e1f1, 0, 0);
        else if (rx[5] == 3)
            FUN_a00cead4(buf, 0, DAT_a802e1f2, 0, 0);
        else if (rx[5] == 4)
            FUN_a00cead4(buf, 0, DAT_a802e1f3, 0, 0);
        else if (rx[5] == 5)
            FUN_a00cead4(buf, 0, DAT_a802e1f4, 0, 0);
        else if (rx[5] == 6)
            FUN_a00cead4(buf, 0, DAT_a802e1f5, 0, 0);
        break;
    case 0xe1:
        if (rx[5] == 0xa5 && rx[6] == 3 && rx[7] == 0) {
            buf[0] = 0x6e;
            buf[1] = 0x88;
            buf[2] = 2;
            buf[3] = 0;
            buf[4] = 0xfe;
            buf[5] = 2;
            buf[6] = 0xb0;
            FUN_a0089f60(0x50);
        } else if (rx[5] == 0xa7 && rx[6] == 7 && rx[7] == 0) {
            buf[0] = 0x6e;
            buf[1] = 0x95;
            FUN_a0089f60(0x50);
            n = 0x12;
            for (i = 0; i < n; i++)
                buf[i + 5] = DAT_00198340[i + 1];
        } else if (rx[5] == 0xe6 && rx[6] == 6 && rx[7] == 0) {
            buf[0] = 0x6e;
            buf[1] = 0x89;
            FUN_a0089f60(0x50);
            n = 6;
            for (i = 0; i < n; i++)
                buf[i + 5] = DAT_00198338[i + 1];
        }
        break;
    case 0xe9:
        if (rx[6] == 0 && rx[7] == 0) {
            buf[0] = 0x6e;
            buf[1] = 0x91;
            FUN_a0089f60(0x50);
            n = 0xe;
            for (i = 0; i < n; i++)
                buf[i + 5] = DAT_00198328[i + 1];
        }
        break;
    case 0xef:
        len = 0x100;
        if (rx[5] == 0x13) {
            buf[0] = 0x6e;
            buf[1] = DAT_a802d274.n + 0x80;
            FUN_a0089f60(0x50);
            FUN_a014ae1c(0x30, &DAT_a802d274, 0x2e0, 0x1c);
            for (i = 0; i < DAT_a802d274.n; i++)
                buf[i + 2] = DAT_a802d274.data[i];
        } else {
            a = rx[6];
            b = rx[7];
            buf[0] = 0x6e;
            buf[1] = 0x88;
            if (rx[5] == 0x42) {
                if (a == 0 && b == 0)
                    FUN_a014b0c4(0xff, DAT_a802d148, &len);
                for (i = 0; i < 0x20; i++)
                    buf[i + 2] = DAT_a802d148[a * 0x100 + b + i];
            }
            if (rx[5] == 0x43) {
                if (a == 0 && b == 0)
                    FUN_a014b0c4(0xff, DAT_a802d148, &len);
                for (i = 0; i < 0x20; i++)
                    buf[i + 2] = DAT_a802d148[a * 0x100 + b + i];
            }
            FUN_a0089f60(0x50);
        }
        break;
    }
}
