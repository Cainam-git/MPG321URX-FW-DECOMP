/* FUN_a010c54c (leon2m 0xa010c54c-0xa010c61c, 208 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Selects s = DAT_a802d804 (c = 1) or DAT_a802d704 and stores the low byte of v to its byte +0x26; stores v & 0xff
 * to word 5 of register block c of DAT_0019aec4 and of DAT_0019aebc (blocks 0 and 1 of both for c above 1). Nothing
 * in the image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a010c4a0 and
 * FUN_a010c61c. Source form: v is an unsigned int parameter; its masked copy is taken into a local before the byte
 * store.
 */
struct Ctx { unsigned char p0[0x26]; unsigned char b26; };
extern struct Ctx DAT_a802d704, DAT_a802d804;
extern volatile unsigned int *const DAT_0019aec4[];
extern volatile unsigned int *const DAT_0019aebc[];

void FUN_a010c54c(unsigned char c, unsigned int v)
{
    struct Ctx *s = &DAT_a802d704;
    unsigned int i, x;

    if (c == 1)
        s = &DAT_a802d804;
    x = (unsigned char)v;
    s->b26 = v;
    if (c > 1) {
        for (i = 0; i < 2; i++)
            DAT_0019aec4[i][5] = x;
    } else
        DAT_0019aec4[c][5] = x;
    if (c > 1) {
        for (i = 0; i < 2; i++)
            DAT_0019aebc[i][5] = x;
    } else
        DAT_0019aebc[c][5] = x;
}
