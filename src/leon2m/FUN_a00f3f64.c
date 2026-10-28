/* leon2m FUN_a00f3f64 @ 0xa00f3f64-0xa00f40e4, flags -mcpu=v8 -O3 -g -msoft-float.
 * Probe sweep for block blk: FUN_a00f37d0(0), block register 0x36 = 0x42; for pos = 4, 8, .. 0x40: when the
 * progress byte DAT_a802b7b1 <= 99 and the callback DAT_a802b79c is set, DAT_a802b79c(DAT_a802b7b1++); wait for
 * bit 1 of block register 0x36 to clear (FUN_a0121374(blk) == 1 or more than 0x63 timer ticks: DAT_a802b7ac = 1,
 * return 0); FUN_a00f37d0(pos), register 0x36 = 0x42, value = (FUN_a00f1ce4(blk, 0x45) << 16) +
 * FUN_a00f1ce4(blk, 0x43); a new minimum stores (pos - 4) & 0x3f in DAT_a802b7af, a new maximum in DAT_a802b7b0.
 * Returns max - min.
 * Source form: do-while loop over pos (the loop pass keeps the high parts of DAT_a802b7b1 and DAT_a802b7ac in
 *   registers as in the firmware); the wait as 'for (;;)' with the input-lost return in place.
 *   The other matched functions of this file (FUN_a00f40e4, FUN_a00f446c, FUN_a00f4e60, FUN_a00f51b4) give the
 *   same bytes with -msoft-float; this one needs it (it changes which loop invariants are moved).
 */
extern unsigned char DAT_a802b7ac, DAT_a802b7af, DAT_a802b7b0, DAT_a802b7b1;
extern void (*DAT_a802b79c)(unsigned char pct);
extern void FUN_a00f37d0(unsigned char v);
extern unsigned char FUN_a00f1a90(unsigned char blk, unsigned char reg);
extern void FUN_a00f1ad4(unsigned char blk, unsigned char reg, unsigned char val);
extern unsigned short FUN_a00f1ce4(unsigned char blk, unsigned char reg);
extern unsigned char FUN_a0121374(unsigned char blk);
extern unsigned short func_0x4008d588(void);
extern unsigned short func_0x4008d594(unsigned short start);

unsigned int FUN_a00f3f64(unsigned char blk)
{
    unsigned char pos, ok;
    unsigned int val, min, max;
    unsigned short t0;

    FUN_a00f37d0(0);
    FUN_a00f1ad4(blk, 0x36, 0x42);
    max = 0;
    min = 0xffffffff;
    pos = 4;
    do {
        if (DAT_a802b7b1 <= 99 && DAT_a802b79c != 0)
            DAT_a802b79c(DAT_a802b7b1++);
        t0 = func_0x4008d588();
        ok = 0;
        for (;;) {
            if (FUN_a0121374(blk) == 1) {
                DAT_a802b7ac = 1;
                return 0;
            }
            if (!(FUN_a00f1a90(blk, 0x36) & 2)) {
                ok = 1;
                break;
            }
            if (func_0x4008d594(t0) > 0x63)
                break;
        }
        if (ok == 0) {
            DAT_a802b7ac = 1;
            return 0;
        }
        FUN_a00f37d0(pos);
        FUN_a00f1ad4(blk, 0x36, 0x42);
        val = (FUN_a00f1ce4(blk, 0x45) << 16) + FUN_a00f1ce4(blk, 0x43);
        if (val < min) {
            DAT_a802b7af = (pos - 4) & 0x3f;
            min = val;
        }
        if (val > max) {
            DAT_a802b7b0 = (pos - 4) & 0x3f;
            max = val;
        }
        pos += 4;
    } while (pos <= 0x41);
    return max - min;
}
