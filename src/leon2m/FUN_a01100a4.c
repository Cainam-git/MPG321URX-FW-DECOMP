/* FUN_a01100a4 (leon2m 0xa01100a4-0xa01101a8, 260 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Selects s = DAT_a802d7c4 (c = 1), DAT_a802d784 (c = 2) or DAT_a802d744; sets word +4 of s to w0 >> 5 and writes
 * it, or-ed with 0x4000000 (c = 1) or 0x8000000 (c = 2), to word 9 of register block DAT_0019aed8[c]; sets word +8
 * to (w0 + ((w8 - w4) << 5)) >> 5 (old w4) and writes it the same way to word 9 of DAT_0019aecc[c]. Nothing in the
 * image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a0110084 and
 * FUN_a01101a8. Source form: a switch selecting the structure pointer (as FUN_a010ed50); the flag if/else is
 * written for each register.
 */
struct Ctx { unsigned int w0, w4, w8; };
extern struct Ctx DAT_a802d744, DAT_a802d784, DAT_a802d7c4;
extern volatile unsigned int *const DAT_0019aed8[];
extern volatile unsigned int *const DAT_0019aecc[];
void FUN_a01100a4(unsigned char c)
{
    struct Ctx *s;
    unsigned int t, x;

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
    t = s->w0 + ((s->w8 - s->w4) << 5);
    s->w4 = s->w0 >> 5;
    x = s->w4;
    if (c == 1)
        x |= 0x4000000;
    else if (c == 2)
        x |= 0x8000000;
    DAT_0019aed8[c][9] = x;
    s->w8 = t >> 5;
    x = s->w8;
    if (c == 1)
        x |= 0x4000000;
    else if (c == 2)
        x |= 0x8000000;
    DAT_0019aecc[c][9] = x;
}
