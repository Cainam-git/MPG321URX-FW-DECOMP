/* leon2s FUN_a007a9c0 @ 0xa007a9c0-0xa007aac4, flags -mcpu=v8 -Os -g.
 * For port p: k = (p != 2); for i below the count byte ARR_a807d680[k][0] (0xb0-byte rows), when bit i of mask
 *   is set and i <= 3: FUN_a00a7424(1, 0x10, p, DAT_a00b3b70[i]) and
 *   FUN_a00a7488(p, DAT_a00b3b18[i], 0xff0000f0, (a[i] & 0xf) | (b[i] << 8)).
 *   Then FUN_a007a050(p), FUN_a007a79c / FUN_a007a0a0 / FUN_a007a648 (p, mask & 0xf), FUN_a00b1794(1) and
 *   FUN_a0079a20(p, mask & 0xf).
 * Source form: unsigned int parameter p; the two loop calls mask the port in different spellings (p & 0xff,
 *   (unsigned short)p & 0xff); equal spellings are merged into one register by GCC. The final calls use a
 *   block-local unsigned char copy q = p.
 */
extern unsigned char ARR_a807d680[][0xb0];
extern unsigned short DAT_a00b3b70[4];
extern unsigned short DAT_a00b3b18[4];
extern void FUN_a00a7424(int mode, unsigned int bit, unsigned int reg, unsigned short val);
extern void FUN_a00a7488(unsigned int param_1, unsigned short param_2, unsigned int param_3, unsigned int param_4);
extern void FUN_a007a050(unsigned char);
extern void FUN_a007a79c(unsigned int, int);
extern void FUN_a007a0a0(unsigned char, unsigned char);
extern void FUN_a007a648(unsigned char, unsigned char);
extern void FUN_a00b1794(unsigned int);
extern void FUN_a0079a20(unsigned int port, unsigned char mask);

void FUN_a007a9c0(unsigned int p, unsigned char mask, unsigned char *a, unsigned short *b)
{
    unsigned char k = (unsigned char)p != 2;
    unsigned char i;

    for (i = 0; i < ARR_a807d680[k][0]; i++) {
        if ((mask >> i) & 1)
        if (i <= 3) {
            FUN_a00a7424(1, 0x10, p & 0xff, DAT_a00b3b70[i]);
            FUN_a00a7488((unsigned short)p & 0xff, DAT_a00b3b18[i], 0xff0000f0, (a[i] & 0xf) | (b[i] << 8));
        }
    }
    {
        unsigned char q = p;

        FUN_a007a050(q);
        FUN_a007a79c(q, mask & 0xf);
        FUN_a007a0a0(q, mask & 0xf);
        FUN_a007a648(q, mask & 0xf);
        FUN_a00b1794(1);
        FUN_a0079a20(q, mask & 0xf);
    }
}
