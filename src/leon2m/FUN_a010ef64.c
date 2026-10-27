/* FUN_a010ef64 (leon2m 0xa010ef64-0xa010f064, 256 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Selects s = DAT_a802d7c4 (c = 1), DAT_a802d784 (c = 2) or DAT_a802d744 and clears bit 0 of its byte +0x3e; takes
 * v = word 1 of register block DAT_0019aed8[k] with bit 14 cleared (k = c, or 0 for c above 2) and writes v to word
 * 1 of block c of DAT_0019aed8 and of DAT_0019aecc (of blocks 0..2 of both tables for c above 2). Nothing in the
 * image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a010edbc and
 * FUN_a010f064. Source form: a switch selecting the structure pointer; separate if (c > 2) loop/else statements per
 * table.
 */
struct Ctx { unsigned char p0[0x3e]; unsigned char b3e; };
extern struct Ctx DAT_a802d744, DAT_a802d784, DAT_a802d7c4;
extern volatile unsigned int *const DAT_0019aed8[];
extern volatile unsigned int *const DAT_0019aecc[];
void FUN_a010ef64(unsigned char c)
{
    struct Ctx *s;
    unsigned int v, i;
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
    s->b3e &= ~1;
    k = c;
    if (c > 2)
        k = 0;
    v = DAT_0019aed8[k][1] & ~0x4000u;
    if (c > 2) {
        for (i = 0; i <= 2; i++)
            DAT_0019aed8[i][1] = v;
    } else
        DAT_0019aed8[c][1] = v;
    if (c > 2) {
        for (i = 0; i <= 2; i++)
            DAT_0019aecc[i][1] = v;
    } else
        DAT_0019aecc[c][1] = v;
}
