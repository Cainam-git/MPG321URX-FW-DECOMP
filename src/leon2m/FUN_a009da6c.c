/* leon2m FUN_a009da6c @ 0xa009da6c-0xa009db20 (45 words), flags -mcpu=v8 -O3 -g. BYTE-EXACT:
 * jf 100.00 match=True, rawcmp.py 0 mismatches / 45 words.
 * Code facts: w = word 0xa802afec; FUN_a00a93bc((w - 60) & 0xff); loop: v = ((low halfword of w) - 58) % 3,
 * w = v + 60, until FUN_a00aad30(v & 0xff) returns 1; byte 0xa802d40c = w - 60; FUN_a00a9650((w - 60) & 0xff, 1);
 * tail FUN_a00a813c(1, byte 0xa8025c56, 0) if w - 60 == that byte, else (.., 1) (two calls, cross-jumped).
 * Fix vs the autoc draft (75.56): '(unsigned short)_DAT_a802afec' for the halfword (fw lduh [%i2+0x3ee] on the
 * word's sethi; see FUN_a00920f4); the store to 0xa802d40c and the compare/2-call tail written from the asm.
 * Aids: none.
 */
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802d40c;
extern unsigned char DAT_a8025c56;
extern void FUN_a00a93bc(unsigned char);
extern unsigned char FUN_a00aad30(unsigned char);
extern void FUN_a00a9650(unsigned char, int);
extern void FUN_a00a813c(int, unsigned char, int);

void FUN_a009da6c(void)
{
    int v;

    FUN_a00a93bc(_DAT_a802afec - 60);
    do {
        v = ((unsigned short)_DAT_a802afec - 58) % 3;
        _DAT_a802afec = v + 60;
    } while (FUN_a00aad30(v) != 1);
    DAT_a802d40c = _DAT_a802afec - 60;
    FUN_a00a9650(_DAT_a802afec - 60, 1);
    if (_DAT_a802afec - 60 == DAT_a8025c56)
        FUN_a00a813c(1, DAT_a8025c56, 0);
    else
        FUN_a00a813c(1, DAT_a8025c56, 1);
}
