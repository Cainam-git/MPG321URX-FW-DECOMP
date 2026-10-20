/*
 * FUN_a00a2a28 (leon2s, 0xa00a2a28-0xa00a2a80, 88 bytes), flags -mcpu=v8 -Os -g.
 * Code facts: for both 0x34-byte port records ARR_a807db00[0..1] (u8 counter): FUN_a00a73ac(0x14, ctl + 0x34
 * bytes) and FUN_a00a73ac(0x15, ctl + 0x34 bytes), where ctl is the register pointer at record +4 (reloaded
 * after the first call). Returns 0 (fw 'restore %g0, 0, %o0'; the draft returned param_2 << 32).
 * The draft used the mid-record name ARR_a807db04. Aids: none.
 */
struct Port34 { unsigned int pad0; unsigned int *ctl; unsigned char pad8[0x2c]; };
extern struct Port34 ARR_a807db00[];
extern void FUN_a00a73ac(unsigned int, unsigned int *);

int FUN_a00a2a28(void)
{
    unsigned char i;

    for (i = 0; i <= 1; i++) {
        struct Port34 *p = &ARR_a807db00[i];
        FUN_a00a73ac(0x14, p->ctl + 13);
        FUN_a00a73ac(0x15, p->ctl + 13);
    }
    return 0;
}
