/* FUN_a00883d0 (leon2s 0xa00883d0-0xa008899c, 1484 bytes), flags -mcpu=v8 -Os -g.
 * Called by DPTX_IsHPDAction_Off and eDP_IsHPDAction_Off with (port, address of a local byte record).
 * Returns 0 unless bit 1 of rec[2] is set. Then FUN_a0086360(port, 0x80, 0x201, 2) and
 * FUN_a0086400(port, 0x90, 0x218, 0, buf), buf = DAT_a80789f0, and tests buf[0]:
 * - bit 0: FUN_a0086360(.., 0x260, 1); FUN_a008639c(.., 0x219, buf), buf[0] -> DAT_a807cd68[0] and
 *   FUN_a0086360(.., 0x100, buf[0]); FUN_a008639c(.., 0x220, buf), buf[0] -> DAT_a807cd68[1] and
 *   FUN_a0086360(.., 0x101, buf[0]); returns 1.
 * - bit 1: FUN_a008639c(.., 0x221, buf); FUN_a00a7940(port, 0x78, 1, m) with m = 1 when buf[0] & 0xf, else 0,
 *   and bit 4 of 0xcf013000 set or cleared to match; returns 0.
 * - bit 3: FUN_a0086360(.., 0x201, buf[1]); FUN_a0086400(.., 0, 5, buf), buf[3] bit 0 -> DAT_a807cd02 (port 0)
 *   or DAT_a807cd2c; FUN_a0086400(.., 0x206, 2, buf), bits 0-1 and 2-3 of buf[0] as 0..3 to FUN_a00aaf94;
 *   FUN_a0086400(.., 0x218, 2, buf); FUN_a00aa88c(port, 0). Record r = DAT_a807cd68 (port 0) or DAT_a807cd00:
 *   r[0] = buf[1] when it is 0x1e, 0x14 or 10, else 6, then FUN_a00aa5e8(port, r[0], DAT_a807cd02 or
 *   DAT_a807cd2c, 1); FUN_a0086400(.., 0x220, 2, buf), r[1] = 0x81/0x82/0x84 for 1/2/4 (port 0 tests buf[0]
 *   for 1 and buf[1] for 2 and 4, other ports buf[0] for all three); FUN_a0086400(.., 0x232, 2, buf);
 *   FUN_a008639c(.., 0x248, buf); FUN_a00a7b64(port, 100, 7) for port != 0; FUN_a00aa930(port, 0);
 *   FUN_a00a78fc(port, 2, r[0]); FUN_a00a78fc(port, 3, r[1] | (FUN_a00a78b4(port, 3) & 0x40));
 *   buf[0] = 1, 3, 4, 5, 6, 7 -> FUN_a00aa930(port, 0, 6, 8, 9, 10, 3); returns 2.
 * - none of these bits: returns 0.
 * Source forms: buf and the record bytes are volatile (the code reads them again for every test and after
 * every store, and keeps the record stores out of delay slots); the first two r[0] value tests load into v,
 * the third into a second variable w; the two selectors are unsigned char locals cleared at the start and
 * passed as (x & 3); nested ifs with one final 'return 0' (one exit block shared by the three 0 results).
 */
extern volatile unsigned char DAT_a80789f0[];
extern volatile unsigned char DAT_a807cd68[];
extern volatile unsigned char DAT_a807cd00[];
extern volatile unsigned char DAT_a807cd02;
extern volatile unsigned char DAT_a807cd2c;
#define _DAT_cf013000 (*(volatile unsigned int *)0xcf013000)

extern unsigned char FUN_a0086360(unsigned char, unsigned char, unsigned int, unsigned char);
extern unsigned char FUN_a008639c(unsigned char, unsigned char, unsigned int, volatile unsigned char *);
extern unsigned char FUN_a0086400(unsigned char, unsigned char, unsigned int, char, volatile unsigned char *);
extern void FUN_a00a7940(unsigned int, short, unsigned int, unsigned int);
extern void FUN_a00aaf94(unsigned char, unsigned char, unsigned char);
extern void FUN_a00aa88c(unsigned int, unsigned int);
extern void FUN_a00aa5e8(unsigned char, unsigned char, unsigned char, unsigned char);
extern void FUN_a00a7b64(unsigned char, short, unsigned char);
extern void FUN_a00aa930(unsigned char, unsigned char);
extern void FUN_a00a78fc(unsigned int, unsigned short, unsigned int);
extern unsigned char FUN_a00a78b4(unsigned int, unsigned short);

unsigned char FUN_a00883d0(unsigned char port, unsigned char *rec)
{
    unsigned char a = 0;
    unsigned char b = 0;
    unsigned char v;
    unsigned char w;
    unsigned int r;

    if (rec[2] & 2) {
        FUN_a0086360(port, 0x80, 0x201, 2);
        FUN_a0086400(port, 0x90, 0x218, 0, DAT_a80789f0);
        if (DAT_a80789f0[0] & 1) {
            FUN_a0086360(port, 0x80, 0x260, 1);
            FUN_a008639c(port, 0x90, 0x219, DAT_a80789f0);
            DAT_a807cd68[0] = DAT_a80789f0[0];
            FUN_a0086360(port, 0x80, 0x100, DAT_a80789f0[0]);
            FUN_a008639c(port, 0x90, 0x220, DAT_a80789f0);
            DAT_a807cd68[1] = DAT_a80789f0[0];
            FUN_a0086360(port, 0x80, 0x101, DAT_a80789f0[0]);
            return 1;
        }
        if (DAT_a80789f0[0] & 2) {
            FUN_a008639c(port, 0x90, 0x221, DAT_a80789f0);
            if (DAT_a80789f0[0] & 0xf) {
                FUN_a00a7940(port, 0x78, 1, 1);
                _DAT_cf013000 |= 0x10;
            } else {
                FUN_a00a7940(port, 0x78, 1, 0);
                _DAT_cf013000 &= ~0x10;
            }
        } else if (DAT_a80789f0[0] & 8) {
            FUN_a0086360(port, 0x80, 0x201, DAT_a80789f0[1]);
            FUN_a0086400(port, 0x90, 0, 5, DAT_a80789f0);
            if (port == 0)
                DAT_a807cd02 = DAT_a80789f0[3] & 1;
            else
                DAT_a807cd2c = DAT_a80789f0[3] & 1;
            FUN_a0086400(port, 0x90, 0x206, 2, DAT_a80789f0);
            if ((DAT_a80789f0[0] & 3) == 0)
                a = 0;
            else if ((DAT_a80789f0[0] & 3) == 1)
                a = 1;
            else if ((DAT_a80789f0[0] & 3) == 2)
                a = 2;
            else if ((DAT_a80789f0[0] & 3) == 3)
                a = 3;
            if ((DAT_a80789f0[0] & 0xc) == 0)
                b = 0;
            else if ((DAT_a80789f0[0] & 0xc) == 4)
                b = 1;
            else if ((DAT_a80789f0[0] & 0xc) == 8)
                b = 2;
            else if ((DAT_a80789f0[0] & 0xc) == 0xc)
                b = 3;
            FUN_a00aaf94(port, b & 3, a & 3);
            FUN_a0086400(port, 0x90, 0x218, 2, DAT_a80789f0);
            FUN_a00aa88c(port, 0);
            if (port == 0) {
                if ((v = DAT_a80789f0[1]) == 0x1e || (v = DAT_a80789f0[1]) == 0x14)
                    DAT_a807cd68[0] = v;
                else if ((w = DAT_a80789f0[1]) == 10)
                    DAT_a807cd68[0] = w;
                else
                    DAT_a807cd68[0] = 6;
                FUN_a00aa5e8(port, DAT_a807cd68[0], DAT_a807cd02, 1);
            } else {
                if ((v = DAT_a80789f0[1]) == 0x1e || (v = DAT_a80789f0[1]) == 0x14)
                    DAT_a807cd00[0] = v;
                else if ((w = DAT_a80789f0[1]) == 10)
                    DAT_a807cd00[0] = w;
                else
                    DAT_a807cd00[0] = 6;
                FUN_a00aa5e8(port, DAT_a807cd00[0], DAT_a807cd2c, 1);
            }
            FUN_a0086400(port, 0x90, 0x220, 2, DAT_a80789f0);
            if (port == 0) {
                if (DAT_a80789f0[0] == 1)
                    DAT_a807cd68[1] = 0x81;
                else if (DAT_a80789f0[1] == 2)
                    DAT_a807cd68[1] = 0x82;
                else if (DAT_a80789f0[1] == 4)
                    DAT_a807cd68[1] = 0x84;
            } else {
                if (DAT_a80789f0[0] == 1)
                    DAT_a807cd00[1] = 0x81;
                else if (DAT_a80789f0[0] == 2)
                    DAT_a807cd00[1] = 0x82;
                else if (DAT_a80789f0[0] == 4)
                    DAT_a807cd00[1] = 0x84;
            }
            FUN_a0086400(port, 0x90, 0x232, 2, DAT_a80789f0);
            FUN_a008639c(port, 0x90, 0x248, DAT_a80789f0);
            if (port != 0)
                FUN_a00a7b64(port, 100, 7);
            FUN_a00aa930(port, 0);
            if (port == 0) {
                FUN_a00a78fc(port, 2, DAT_a807cd68[0]);
                r = FUN_a00a78b4(port, 3) & 0x40;
                FUN_a00a78fc(port, 3, DAT_a807cd68[1] | r);
            } else {
                FUN_a00a78fc(port, 2, DAT_a807cd00[0]);
                r = FUN_a00a78b4(port, 3) & 0x40;
                FUN_a00a78fc(port, 3, DAT_a807cd00[1] | r);
            }
            switch (DAT_a80789f0[0]) {
            case 1:
                FUN_a00aa930(port, 0);
                break;
            case 2:
                break;
            case 3:
                FUN_a00aa930(port, 6);
                break;
            case 4:
                FUN_a00aa930(port, 8);
                break;
            case 5:
                FUN_a00aa930(port, 9);
                break;
            case 6:
                FUN_a00aa930(port, 10);
                break;
            case 7:
                FUN_a00aa930(port, 3);
                break;
            }
            return 2;
        }
    }
    return 0;
}
