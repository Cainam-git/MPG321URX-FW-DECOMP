/* leon2m FUN_a0096f40 @ 0xa0096f40-0xa0096fe8 (42 words), flags -mcpu=v8 -O3 -g.
 * Code facts: if FUN_a01445fc(byte 0xa802d290+0x1e) == 1 (u8): FUN_a00a8ee8((word 0xa802afec - 30) & 0xff),
 * FUN_a00aa01c((word - 30) & 0xff, 0), FUN_a00a900c(FUN_a01445fc(byte +0x1e), 0), word = 6, FUN_a00b4144(4, 1),
 * FUN_a00a9468(1, 2), tail FUN_a00b34d4(0, 1); else byte +0x1e = FUN_a014459c(1), tail FUN_a00b8804(0, 1).
 * FUN_a014459c takes 1 argument (= 1; fw 'mov 1, %o0' before the branch, its own asm masks %i0) and
 * FUN_a00b8804 takes 2 (0, 1); the function has no parameters.
 * Source form: the record as a struct pointer (fw sethi|or into %l0). Aids: none.
 */
struct R290 { unsigned char pad[0x1e]; unsigned char b1e; };
extern struct R290 DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern void FUN_a00a8ee8(unsigned char);
extern void FUN_a00a900c(unsigned char, int);
extern void FUN_a00a9468(int, int);
extern void FUN_a00aa01c(unsigned char, int);
extern void FUN_a00b34d4(unsigned int, unsigned int);
extern void FUN_a00b4144(int, int);
extern unsigned char FUN_a01445fc(unsigned char);
extern unsigned char FUN_a014459c(unsigned char);
extern void FUN_a00b8804(int, int);

void FUN_a0096f40(void)
{
    struct R290 *p = &DAT_a802d290;

    if (FUN_a01445fc(p->b1e) == 1) {
        FUN_a00a8ee8(_DAT_a802afec - 30);
        FUN_a00aa01c(_DAT_a802afec - 30, 0);
        FUN_a00a900c(FUN_a01445fc(p->b1e), 0);
        _DAT_a802afec = 6;
        FUN_a00b4144(4, 1);
        FUN_a00a9468(1, 2);
        FUN_a00b34d4(0, 1);
    } else {
        p->b1e = FUN_a014459c(1);
        FUN_a00b8804(0, 1);
    }
}
