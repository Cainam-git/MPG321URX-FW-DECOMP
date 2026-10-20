/* leon2m FUN_a0091094 @ 0xa0091094-0xa00911a0 (67 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/67 mismatches.
 * Code facts: s = word DAT_a802afec. If s is 0, 0x10b, 0x10c, 0x10d, 0x10e, 0x10f or 0x110 (the
 * first two tests are branch-free subx flags joined by orcc): FUN_a008ec48(0xff, 0);
 * FUN_a008ed00(0x49, 1); tail FUN_a008edb8(0x42, 0x43). Else if s - 0x108 < 2: FUN_a008ec48 for
 * 0x45, 0x46, 0x47, 0x48 (each with 1), tail FUN_a008edb8(0xff, 0). Else: FUN_a008ec48 for 0x47,
 * 0x48, 0x45, 0x46, tail FUN_a008edb8(0xff, 0). void, no params.
 * Fixes vs the autoc draft (82.09): the tail callee FUN_a008edb8 takes 2 args (it overwrites %o2;
 * the draft passed a 3rd); positive '||' test with that arm FIRST (draft used the negated '&&'
 * form); void(void). Aids: none.
 */
extern unsigned int DAT_a802afec;
extern void FUN_a008ec48(unsigned char, unsigned char);
extern void FUN_a008ed00(unsigned char, unsigned char);
extern void FUN_a008edb8(unsigned char, unsigned char);

void FUN_a0091094(void)
{
    if (DAT_a802afec == 0 || DAT_a802afec == 0x10b || DAT_a802afec == 0x10c ||
        DAT_a802afec == 0x10d || DAT_a802afec == 0x10e || DAT_a802afec == 0x10f ||
        DAT_a802afec == 0x110) {
        FUN_a008ec48(0xff, 0);
        FUN_a008ed00(0x49, 1);
        FUN_a008edb8(0x42, 0x43);
    } else if (DAT_a802afec - 0x108 < 2) {
        FUN_a008ec48(0x45, 1);
        FUN_a008ec48(0x46, 1);
        FUN_a008ec48(0x47, 1);
        FUN_a008ec48(0x48, 1);
        FUN_a008edb8(0xff, 0);
    } else {
        FUN_a008ec48(0x47, 1);
        FUN_a008ec48(0x48, 1);
        FUN_a008ec48(0x45, 1);
        FUN_a008ec48(0x46, 1);
        FUN_a008edb8(0xff, 0);
    }
}
