/* leon2m FUN_a00e7dc8 @ 0xa00e7dc8-0xa00e7eb0, flags -mcpu=v8 -O3 -g. Called nine times from FUN_a00e7eb0.
 * Parameters p0..p3; p1 and p2 are named byte_idx and dq_idx by the firmware's error strings.
 * byte_idx outside 0..3 or dq_idx outside 0..7: calls FUN_a00df80c and FUN_a00e0bc0, passes
 * "Error: byte_idx=%d, sould never here.\n" or "Error: dq_idx=%d, sould never here.\n" with byte_idx (both
 * strings get byte_idx) to FUN_a00df170 and returns -1.
 * Otherwise it computes a = 0x1bf, m = 1 << (dq_idx + 1) for byte_idx 3 (dq_idx 7: a = 0x1bd, m = 0x40);
 * a = byte_idx * 3 + 0x1b6, m = 1 << (dq_idx + 4) for dq_idx 0..3; a = byte_idx * 3 + 0x1b7,
 * m = 1 << (dq_idx - 4) for dq_idx 4..7. It calls FUN_a00e05d8(p0, a, m, p3 == 1 ? m : 0) and returns 0.
 * The indices are signed ints: each range test (x < 0 || x > n) folds into one unsigned compare.
 */
extern void FUN_a00df80c(void);
extern void FUN_a00e0bc0(void);
extern int FUN_a00df170(const char *fmt, ...);
extern int FUN_a00e05d8(unsigned int, unsigned int, unsigned int, unsigned int);

int FUN_a00e7dc8(unsigned int dev, int byte_idx, int dq_idx, int set)
{
    unsigned int reg, mask;

    if (byte_idx < 0 || byte_idx > 3) {
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170("Error: byte_idx=%d, sould never here.\n", byte_idx);
        return -1;
    }
    if (dq_idx < 0 || dq_idx > 7) {
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170("Error: dq_idx=%d, sould never here.\n", byte_idx);
        return -1;
    }
    if (byte_idx == 3) {
        if (dq_idx > 6) {
            reg = 0x1bd;
            mask = 0x40;
        } else {
            reg = 0x1bf;
            mask = 1 << (dq_idx + 1);
        }
    } else if (dq_idx < 4) {
        reg = byte_idx * 3 + 0x1b6;
        mask = 1 << (dq_idx + 4);
    } else {
        reg = byte_idx * 3 + 0x1b7;
        mask = 1 << (dq_idx - 4);
    }
    FUN_a00e05d8(dev, reg, mask, set == 1 ? mask : 0);
    return 0;
}
