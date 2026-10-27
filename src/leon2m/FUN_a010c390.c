/* FUN_a010c390 (leon2m 0xa010c390-0xa010c4a0, 272 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Selects s = DAT_a802d7c4 (c = 1), DAT_a802d784 (c = 2) or DAT_a802d744 and stores v to its byte +0x26; builds x =
 * (word 4 of register block DAT_0019aed8[k] & ~0xff0000) | (v << 16) | 1 (k = c, or 0 for c above 2) and writes x
 * to word 4 of block c of DAT_0019aed8 and of DAT_0019aecc (blocks 0..2 of both for c above 2). Nothing in the
 * image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a010c194 and
 * FUN_a010c4a0. Source form: the same form as FUN_a010ef64.
 */
struct Ctx { unsigned char p0[0x26]; unsigned char b26; };
extern struct Ctx DAT_a802d744, DAT_a802d784, DAT_a802d7c4;
extern volatile unsigned int *const DAT_0019aed8[];
extern volatile unsigned int *const DAT_0019aecc[];

void FUN_a010c390(unsigned char c, unsigned char v)
{
    struct Ctx *s;
    unsigned int x, i;
    unsigned char k;

    switch (c) {
    case 1:
        s = &DAT_a802d7c4;
        break;
    case 2:
        s = &DAT_a802d784;
        break;
    default:
        s = &DAT_a802d744;
        break;
    }
    s->b26 = v;
    k = c;
    if (c > 2)
        k = 0;
    x = (DAT_0019aed8[k][4] & ~0xff0000u) | (v << 16) | 1;
    if (c > 2) {
        for (i = 0; i <= 2; i++)
            DAT_0019aed8[i][4] = x;
    } else
        DAT_0019aed8[c][4] = x;
    if (c > 2) {
        for (i = 0; i <= 2; i++)
            DAT_0019aecc[i][4] = x;
    } else
        DAT_0019aecc[c][4] = x;
}
