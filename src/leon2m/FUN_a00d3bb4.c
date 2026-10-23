/* leon2m FUN_a00d3bb4 @ 0xa00d3bb4-0xa00d3d30 (95 words).
 * Reads the 0x1fc-byte record DAT_a802d290 with FUN_a014ae1c(0x30, DAT_a802d290, 0, 0x1fc); when its halfword
 * +0x1f8 or +0 differs from the default record at 0x198524, copies the defaults over it (FUN_a013c910) and writes
 * it back with FUN_a014aed0(0x30, DAT_a802d290, 0, 0x1fc). Then reads the 28-byte record DAT_a802d274 with
 * FUN_a014ae1c(0x30, &DAT_a802d274, 0x2e0, 0x1c); when its halfword +0x1a or +0 differs from the default record at
 * 0x198508, copies the defaults over it and writes it with FUN_a014aed0(0x30, &DAT_a802d274, 0x2e0, 0x1c) (tail
 * call). Same records as FUN_a00d57e8.
 * Source form: the pointer assignment sits in 'do { } while (once)' with once = 0, a no-code aid (the loop compiles
 * to nothing); it keeps the pointer's address add after the first call and the argument order of that call as in
 * the firmware.
 */
struct S290 {
    unsigned short h0;
    unsigned char pad[0x1f8 - 2];
    unsigned short h1f8;
    unsigned short h1fa;
};
struct S274 { unsigned short h[14]; };
extern struct S290 DAT_a802d290;
extern const struct S290 DAT_00198524;
extern struct S274 DAT_a802d274;
extern const struct S274 DAT_00198508;
extern void *FUN_a013c910(void *dst, const void *src, int n);
extern int FUN_a014ae1c(int, void *, int, int);
extern int FUN_a014aed0(int, void *, int, int);

void FUN_a00d3bb4(void)
{
    struct S290 *p;
    int once = 0;

    FUN_a014ae1c(0x30, &DAT_a802d290, 0, 0x1fc);
    do {
        p = &DAT_a802d290;
    } while (once);
    if (p->h1f8 != DAT_00198524.h1f8 || p->h0 != DAT_00198524.h0) {
        FUN_a013c910(p, &DAT_00198524, 0x1fc);
        FUN_a014aed0(0x30, p, 0, 0x1fc);
    }
    FUN_a014ae1c(0x30, &DAT_a802d274, 0x2e0, 0x1c);
    if (DAT_a802d274.h[13] != DAT_00198508.h[13] || DAT_a802d274.h[0] != DAT_00198508.h[0]) {
        DAT_a802d274 = DAT_00198508;
        FUN_a014aed0(0x30, &DAT_a802d274, 0x2e0, 0x1c);
    }
}
