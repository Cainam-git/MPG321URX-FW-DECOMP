/* FUN_a010ed50 (leon2m 0xa010ed50-0xa010edbc, 108 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Selects s = DAT_a802d7c4 (c = 1), DAT_a802d784 (c = 2) or DAT_a802d744 (other c); clears bit 1 of byte +0x3e of s
 * and writes word +4 of s to word 9 of register block DAT_0019aed8[c] and word +8 to word 9 of DAT_0019aecc[c].
 * Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a010eca8 and FUN_a010edbc. Source form: a switch selecting the structure pointer.
 */
struct Ctx { unsigned int w0, w4, w8; unsigned char p0c[0x3e - 0xc]; unsigned char b3e, p3f; };
extern struct Ctx DAT_a802d744, DAT_a802d784, DAT_a802d7c4;
extern volatile unsigned int *const DAT_0019aed8[];
extern volatile unsigned int *const DAT_0019aecc[];
void FUN_a010ed50(unsigned char c)
{
    struct Ctx *s;
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
    s->b3e &= ~2;
    DAT_0019aed8[c][9] = s->w4;
    DAT_0019aecc[c][9] = s->w8;
}
