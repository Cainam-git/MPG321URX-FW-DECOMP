/* FUN_a014110c (leon2m 0xa014110c-0xa014118c, 128 bytes), flags -mcpu=v8 -O3 -g.
 * When c differs from the byte DAT_a802a47c or FUN_a011898c() returns non-zero: calls
 * FUN_a01186e0(DAT_a8027bb0[c]), stores c to DAT_a802a47c and calls FUN_a0118628(2) (byte DAT_a802e1a7 = 0) or
 * FUN_a0118628(3); finally calls FUN_a01185d4() as a tail call. Called by FUN_a014913c, FUN_a014c7bc. Source form:
 * FUN_a011898c is declared returning unsigned char (its low byte is tested).
 */
extern unsigned char DAT_a802a47c, DAT_a802e1a7;
extern unsigned int DAT_a8027bb0[];
extern void FUN_a01186e0(unsigned int arg);
extern void FUN_a0118628(unsigned int m);
extern void FUN_a01185d4(void);
extern unsigned char FUN_a011898c(void);

void FUN_a014110c(unsigned char c)
{
    if (DAT_a802a47c != c || FUN_a011898c()) {
        FUN_a01186e0(DAT_a8027bb0[c]);
        DAT_a802a47c = c;
        if (DAT_a802e1a7 == 0)
            FUN_a0118628(2);
        else
            FUN_a0118628(3);
    }
    FUN_a01185d4();
}
