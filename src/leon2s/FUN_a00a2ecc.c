/*
 * FUN_a00a2ecc (leon2s, 0xa00a2ecc-0xa00a2f70, 164 bytes), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0/41.
 * Code facts: for both 0x34-byte port records ARR_a807db00[0..1] (u8 counter): word 12 of the block at
 * record +0x30 = 0x80008000, FUN_a00a73ac(0x1c, that block + 0x34 bytes); the register word at record +4:
 * bits 20..23 = 5, FUN_a00a73d4(1, reg), and when FUN_a00a7408(1, reg) != 0 bits 16..19 = 2. Returns 0.
 * FUN_a00a73d4 and FUN_a00a7408 take the register pointer as their 2nd argument (the draft had none).
 * Aids: none (no volatile needed).
 */
struct Port34 { unsigned int pad0; unsigned int *ctl; unsigned char pad8[0x28]; unsigned int *blk; };
extern struct Port34 ARR_a807db00[];
extern void FUN_a00a73ac(unsigned int, unsigned int *);
extern void FUN_a00a73d4(unsigned int, unsigned int *);
extern unsigned int FUN_a00a7408(unsigned int, unsigned int *);

int FUN_a00a2ecc(void)
{
    unsigned char i;

    for (i = 0; i <= 1; i++) {
        struct Port34 *p = &ARR_a807db00[i];
        p->blk[12] = 0x80008000;
        FUN_a00a73ac(0x1c, p->blk + 13);
        *p->ctl = (*p->ctl & ~0xf00000) | 0x500000;
        FUN_a00a73d4(1, p->ctl);
        if (FUN_a00a7408(1, p->ctl) != 0)
            *p->ctl = (*p->ctl & ~0xf0000) | 0x20000;
    }
    return 0;
}
