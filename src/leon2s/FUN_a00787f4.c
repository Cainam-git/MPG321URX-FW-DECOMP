/* leon2s FUN_a00787f4 @ 0xa00787f4-0xa007890c, flags -mcpu=v8 -Os -g.
 * For port p, two passes over i = 0..2 (each with an 'i < 3' test inside the loop):
 *   first pass: a = DAT_a00b3b0a[i], FUN_a00a7424(1, 4, p, a); b = DAT_a00b3b04[i], FUN_a00a7424(0, 0, p, b);
 *   FUN_a00a7488(p, b, 0xff00ffff, 0x2c0000); FUN_a00a7488(p, a, 0xff00ffff, 0xff0000).
 *   Then FUN_a00b1794(1); second pass: FUN_a00a7424(1, 0, p, DAT_a00b3b04[i]), FUN_a00a7424(0, 4, p, DAT_a00b3b0a[i]).
 * Source form: unsigned int parameter p, unsigned short loop counter; the calls of one pass mask the port in
 *   different spellings ((char)p & 0xff, (unsigned char)p, p & 0xff, (unsigned short)p & 0xff); equal spellings
 *   are merged into one register by GCC.
 */
extern unsigned short DAT_a00b3b04[3];
extern unsigned short DAT_a00b3b0a[3];
extern void FUN_a00a7424(int mode, unsigned int bit, unsigned int reg, unsigned short val);
extern void FUN_a00a7488(unsigned int param_1, unsigned short param_2, unsigned int param_3, unsigned int param_4);
extern void FUN_a00b1794(unsigned int);

void FUN_a00787f4(unsigned int p)
{
    unsigned short i;
    unsigned short a, b;

    for (i = 0; i < 3; i++) {
        if (i < 3) {
            a = DAT_a00b3b0a[i];
            FUN_a00a7424(1, 4, (char)p & 0xff, a);
            b = DAT_a00b3b04[i];
            FUN_a00a7424(0, 0, (unsigned char)p, b);
            FUN_a00a7488(p & 0xff, b, 0xff00ffff, 0x2c0000);
            FUN_a00a7488((unsigned short)p & 0xff, a, 0xff00ffff, 0xff0000);
        }
    }
    FUN_a00b1794(1);
    for (i = 0; i < 3; i++) {
        if (i < 3) {
            FUN_a00a7424(1, 0, p & 0xff, DAT_a00b3b04[i]);
            FUN_a00a7424(0, 4, (unsigned short)p & 0xff, DAT_a00b3b0a[i]);
        }
    }
}
