/* leon2m FUN_a00d253c @ 0xa00d253c-0xa00d25f4 (46 words), flags -mcpu=v8 -O3 (no -g). No direct callers (reached
 * through a table).
 * Command handler taking a pointer to a received frame. Frame byte 6 == 0: byte 0xa802d2af (0xa802d290+0x1f) = 1,
 * then FUN_a00d91fc(0), FUN_a0148268(0, 1), FUN_a0148268(1, 1) and FUN_a00da254(). Frame byte 6 == 1: byte
 * 0xa802d2af = 2, the same four calls, byte 0xa802d2b0 = FUN_a014459c(frame byte 7), FUN_a00d5938(1). Then
 * FUN_a00d8c1c() and FUN_a00d5cd8() run and the function returns 0xe0.
 */
struct R290 { unsigned char p000[0x1f]; unsigned char b01f; unsigned char b020; };
extern struct R290 DAT_a802d290;
extern void FUN_a00d91fc(int);
extern void FUN_a0148268(int, int);
extern void FUN_a00da254(void);
extern unsigned char FUN_a014459c(unsigned char);
extern void FUN_a00d5938(int);
extern void FUN_a00d8c1c(void);
extern void FUN_a00d5cd8(void);

int FUN_a00d253c(unsigned char *p)
{
    if (p[6] == 0) {
        DAT_a802d290.b01f = 1;
        FUN_a00d91fc(0);
        FUN_a0148268(0, 1);
        FUN_a0148268(1, 1);
        FUN_a00da254();
    } else if (p[6] == 1) {
        DAT_a802d290.b01f = 2;
        FUN_a00d91fc(0);
        FUN_a0148268(0, 1);
        FUN_a0148268(1, 1);
        FUN_a00da254();
        DAT_a802d290.b020 = FUN_a014459c(p[7]);
        FUN_a00d5938(1);
    }
    FUN_a00d8c1c();
    FUN_a00d5cd8();
    return 0xe0;
}
