/* leon2m FUN_a00fa5b4 @ 0xa00fa5b4-0xa00fa6b4 (64 words), flags -mcpu=v8 -O3 -g.
 * When the byte 0xA802B7FE is non-zero: clears the halfword 0xA8026A94, copies the halfword 0xA802BEC0 to 0xA802BEC2
 * and to all 0x120 entries of the halfword arrays 0xA802BA40, 0xA802BC80 and 0xA802B800; then for j = 0..11,
 * k = 0..23 writes entry j * 24 + k of 0xA802B800 to the register 0xD00400A4 and (index | 0x200) with bit 24 clear
 * to 0xD00400A0; finally writes 0 to 0xD00400A4, the last value without bit 9 to 0xD00400A0 and stores it in the
 * word 0xA802C860. The same block is the second half of FUN_a00fa6b4.
 * Source form: as in FUN_a00fa6b4 (fset helper, pointer local for the second loop, same statement order).
 * Compiler aids: none.
 */
#define R(a) (*(volatile unsigned int *)(a))
static unsigned int fset(unsigned int x, unsigned int hi, unsigned int lo, unsigned int v)
{
    unsigned int m = (1 << hi) | ((1 << hi) - (1 << lo));

    return (x & ~m) | ((v << lo) & m);
}

extern unsigned short DAT_a802bec0;
extern unsigned short DAT_a802bec2;
extern unsigned char DAT_a802b7fe;
extern unsigned short DAT_a8026a94;
extern unsigned short DAT_a802ba40[0x120];
extern unsigned short DAT_a802bc80[0x120];
extern unsigned short DAT_a802b800[0x120];
extern unsigned int DAT_a802c860;

void FUN_a00fa5b4(void)
{
    unsigned int i;
    unsigned char j, k;
    unsigned short idx;
    unsigned int w;
    unsigned short *t;

    if (DAT_a802b7fe != 0) {
        DAT_a802bec2 = DAT_a802bec0;
        DAT_a8026a94 = 0;
        for (i = 0; i < 0x120; i++) {
            DAT_a802bc80[i] = DAT_a802bec0;
            DAT_a802b800[i] = DAT_a802bec0;
            DAT_a802ba40[i] = DAT_a802bec0;
        }
        t = DAT_a802b800;
        for (j = 0; j < 12; j++) {
            for (k = 0; k < 24; k++) {
                idx = j * 24 + k;
                R(0xd00400a4) = t[idx];
                w = fset(idx, 9, 9, 1);
                w = fset(w, 24, 24, 0);
                R(0xd00400a0) = w;
            }
        }
        R(0xd00400a4) = 0;
        w = fset(w, 9, 9, 0);
        DAT_a802c860 = w;
        R(0xd00400a0) = w;
    }
}
