/* FUN_a009584c (leon2s, 0xa009584c-0xa00958d4, 136 bytes, 34 words).
 * Flags: -mcpu=v8 -Os -g. Judge: jf 100.00 match=True, rawcmp_l2s 0/34 mismatches.
 * Code facts: returns 0 when (u8)FUN_a0070404() or (u8)FUN_a0070414() is non-zero. Otherwise for
 * unit 0 and then 1: if (u8)FUN_a0091bac(unit) != 0, FUN_a00950a0(unit, 9) and FUN_a0091578(unit);
 * returns 1.
 * Fix vs draft: the two early checks are ONE '||' test with one 'return 0' (fw: the clr %i0 sits in
 * the first bne delay slot); two separate ifs put it in the call delay slot. Aids: none.
 */
extern unsigned char FUN_a0070404(void);   /* 0xa0070404 */
extern unsigned char FUN_a0070414(void);   /* 0xa0070414 */
extern int FUN_a0091bac(int);     /* 0xa0091bac */
extern void FUN_a00950a0(int, int); /* 0xa00950a0 */
extern void FUN_a0091578(int);    /* 0xa0091578 */

int FUN_a009584c(void)
{
    if ((FUN_a0070404() & 0xff) || (FUN_a0070414() & 0xff))
        return 0;
    if (FUN_a0091bac(0) & 0xff) {
        FUN_a00950a0(0, 9);
        FUN_a0091578(0);
    }
    if (FUN_a0091bac(1) & 0xff) {
        FUN_a00950a0(1, 9);
        FUN_a0091578(1);
    }
    return 1;
}
