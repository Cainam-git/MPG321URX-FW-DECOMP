/* FUN_a00f9528 (leon2m 0xa00f9528-0xa00f9880, 856 bytes), flags -mcpu=v8 -O3 -g.
 * void (unsigned char blk, unsigned char reset). Called by FUN_a0148bc4. With reset set: writes 0 to register
 * 0x32 of blk (FUN_a00f1ad4), sets the three sums DAT_a802b7cc / DAT_a802b7d0 / DAT_a802b7d4 to 0x10, writes 0
 * then 0x85 to register 0x30 and sets the state byte DAT_a802b7c8 to 0. Otherwise, by the state 0 / 1 / 2 and
 * only while bit 7 of register 0x30 (FUN_a00f1a90) is clear: for i = 0..7 it writes i to register 0x31, reads
 * the 24-bit value v from registers 0x35 / 0x34 / 0x33 (high to low) and adds (i * 32) * v to DAT_a802b7d4
 * (state 0), DAT_a802b7d0 (state 1) or DAT_a802b7cc (state 2); then writes 0 and 0x8d / 0x95 / 0x85 to
 * register 0x30 and moves to state 1 / 2 / 0. State 2 also stores the three sums divided by 5000 into
 * DAT_a802b7c4 (from b7cc), DAT_a802b7c0 (from b7d0) and DAT_a802b7bc (from b7d4) and resets the sums to 0x10.
 * Source forms: v built by separate statements (v = r35 << 8; v |= r34; v <<= 8; v |= r33); in state 2 the
 * b7d0 and b7d4 sums are read into locals before the two divisions; the reset path writes b7cc, b7d0, b7d4 in
 * that order.
 */
extern unsigned char DAT_a802b7c8;
extern unsigned int DAT_a802b7cc, DAT_a802b7d0, DAT_a802b7d4;
extern unsigned int DAT_a802b7bc, DAT_a802b7c0, DAT_a802b7c4;
extern unsigned char FUN_a00f1a90(unsigned char blk, unsigned char reg);
extern void FUN_a00f1ad4(unsigned char blk, unsigned char reg, unsigned char val);

void FUN_a00f9528(unsigned char blk, unsigned char reset)
{
    unsigned short i;
    unsigned int v, k;
    unsigned int a, b;

    if (reset) {
        FUN_a00f1ad4(blk, 0x32, 0);
        DAT_a802b7cc = 0x10;
        DAT_a802b7d0 = 0x10;
        DAT_a802b7d4 = 0x10;
        FUN_a00f1ad4(blk, 0x30, 0);
        FUN_a00f1ad4(blk, 0x30, 0x85);
        DAT_a802b7c8 = 0;
        return;
    }
    switch (DAT_a802b7c8) {
    case 0:
        if (!(FUN_a00f1a90(blk, 0x30) & 0x80)) {
            for (i = 0; i < 8; i++) {
                FUN_a00f1ad4(blk, 0x31, i);
                v = FUN_a00f1a90(blk, 0x35) << 8;
                v |= FUN_a00f1a90(blk, 0x34);
                v <<= 8;
                v |= FUN_a00f1a90(blk, 0x33);
                k = i * 32;
                DAT_a802b7d4 += k * v;
            }
            FUN_a00f1ad4(blk, 0x30, 0);
            FUN_a00f1ad4(blk, 0x30, 0x8d);
            DAT_a802b7c8 = 1;
        }
        break;
    case 1:
        if (!(FUN_a00f1a90(blk, 0x30) & 0x80)) {
            for (i = 0; i < 8; i++) {
                FUN_a00f1ad4(blk, 0x31, i);
                v = FUN_a00f1a90(blk, 0x35) << 8;
                v |= FUN_a00f1a90(blk, 0x34);
                v <<= 8;
                v |= FUN_a00f1a90(blk, 0x33);
                k = i * 32;
                DAT_a802b7d0 += k * v;
            }
            FUN_a00f1ad4(blk, 0x30, 0);
            FUN_a00f1ad4(blk, 0x30, 0x95);
            DAT_a802b7c8 = 2;
        }
        break;
    case 2:
        if (!(FUN_a00f1a90(blk, 0x30) & 0x80)) {
            for (i = 0; i < 8; i++) {
                FUN_a00f1ad4(blk, 0x31, i);
                v = FUN_a00f1a90(blk, 0x35) << 8;
                v |= FUN_a00f1a90(blk, 0x34);
                v <<= 8;
                v |= FUN_a00f1a90(blk, 0x33);
                k = i * 32;
                DAT_a802b7cc += k * v;
            }
            DAT_a802b7c4 = DAT_a802b7cc / 5000;
            b = DAT_a802b7d0;
            a = DAT_a802b7d4;
            DAT_a802b7c0 = b / 5000;
            DAT_a802b7bc = a / 5000;
            DAT_a802b7d4 = 0x10;
            DAT_a802b7d0 = 0x10;
            DAT_a802b7cc = 0x10;
            FUN_a00f1ad4(blk, 0x30, 0);
            FUN_a00f1ad4(blk, 0x30, 0x85);
            DAT_a802b7c8 = 0;
        }
        break;
    }
}
