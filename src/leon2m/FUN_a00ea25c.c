/* leon2m FUN_a00ea25c @ 0xa00ea25c-0xa00ea308 (43 words), flags -mcpu=v8 -O3 -g.
 * FUN_a00ea25c(a, byte_idx, dq_idx, on): byte_idx > 3 or dq_idx > 7 -> FUN_a00df80c(), FUN_a00e0bc0() and the
 * message "Error: byte_idx=%d, sould never here." / "Error: dq_idx=%d, sould never here." through FUN_a00df170,
 * return -1. Otherwise FUN_a00e05d8(a, byte_idx * 3 + 0x1b5, 1 << dq_idx, on == 1 ? 1 << dq_idx : 0) and return 0.
 * Callers: FUN_a00ea308, FUN_a00ea638. The names byte_idx and dq_idx are taken from the messages.
 * Source form: both range checks come before the computation of the register number and the mask.
 */
extern char s_00199aa8[], s_00199ad0[];
extern int FUN_a00df170(const char *fmt, ...);
extern void FUN_a00df80c(void);
extern void FUN_a00e0bc0(void);
extern void FUN_a00e05d8(unsigned int, unsigned int, unsigned int, unsigned int);

int FUN_a00ea25c(unsigned int a, unsigned int byte_idx, unsigned int dq_idx, unsigned int on)
{
    unsigned int r, m;

    if (byte_idx > 3) {
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170(s_00199aa8, byte_idx);
        return -1;
    }
    if (dq_idx > 7) {
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170(s_00199ad0, dq_idx);
        return -1;
    }
    r = byte_idx * 3 + 0x1b5;
    m = 1 << dq_idx;
    if (on == 1)
        FUN_a00e05d8(a, r, m, m);
    else
        FUN_a00e05d8(a, r, m, 0);
    return 0;
}
