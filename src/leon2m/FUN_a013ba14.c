/* leon2m FUN_a013ba14 @ 0xa013ba14-0xa013bb50 (79 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp 0/79 mismatches (behaviour read from the asm).
 * What it does: dc6c callee, a 'timing usable' test for one port. t = FUN_a013cd4c(port) (the channel record whose
 * port field is port); h = FUN_a013cd4c(port)->h3c (called a second time). h one of 0x5b01, 0x5c01, 0x5d01, 0x800,
 * 0x5f01, 0x6001, 0x6101, 0x5800, 0x5900, 0x2200, 0x5700, 0x5a00, 0x6301, 0x6201 -> return 0. Otherwise return 1
 * when t->h06 <= 0x95 or > 0x1964 or t->h08 <= 0xc7 or t->h08 >= 0x993, else 0.
 * Unless h3c is a listed code, the result is 0 only when the record's u16 h06 is in
 * 0x96..0x1964 and h08 in 0xc8..0x992 (h06 / h08 = record +6 / +8; the values themselves are not followed here).
 * Matching form: the first pair as one '(h == 0x5b01 || h == 0x5c01) == 0' test (gcc folds only that pair into the
 * fw xor/subx/orcc store-flag; a '!(...)' gives De Morgan addx/btst); the other 12 codes as separate 'goto yes'
 * tests into ONE shared 'f = 1' block (the fw single 'mov 1' block; else-if arms give separate blocks and the last
 * one is if-converted); the h06 range as two ifs (one || is folded into a range test); 'if (h08 >= 0x993) return 1;
 * return 0;' (fw subx). Flag 'int f' tested 'if (f & 1)': plain 'if (f)' lets jump bypassing thread the flag away
 * (73.42), an unsigned char flag gives 'btst 0xff' instead of the fw 'cmp %g1, 0' (98.73). This is the same
 * 'b & 1' flag lever as in FUN_a01215e8. Aids: none (no volatile, no asm, no hint).
 */
struct Rec { unsigned char p00[6]; unsigned short h06, h08; unsigned char p0a[0x3c - 0x0a]; unsigned short h3c; };
extern struct Rec *FUN_a013cd4c(unsigned char port);
unsigned char FUN_a013ba14(unsigned char port)
{
    struct Rec *t = FUN_a013cd4c(port);
    unsigned short h = FUN_a013cd4c(port)->h3c;
    int f;
    if ((h == 0x5b01 || h == 0x5c01) == 0) {
        if (h == 0x5d01)
            goto yes;
        if (h == 0x800)
            goto yes;
        if (h == 0x5f01)
            goto yes;
        if (h == 0x6001)
            goto yes;
        if (h == 0x6101)
            goto yes;
        if (h == 0x5800)
            goto yes;
        if (h == 0x5900)
            goto yes;
        if (h == 0x2200)
            goto yes;
        if (h == 0x5700)
            goto yes;
        if (h == 0x5a00)
            goto yes;
        if (h == 0x6301)
            goto yes;
        if (h == 0x6201)
            goto yes;
        f = 0;
        goto done;
    }
yes:
    f = 1;
done:
    if (f & 1)
        return 0;
    if (t->h06 <= 0x95)
        return 1;
    if (t->h06 > 0x1964)
        return 1;
    if (t->h08 <= 0xc7)
        return 1;
    if (t->h08 >= 0x993)
        return 1;
    return 0;
}
