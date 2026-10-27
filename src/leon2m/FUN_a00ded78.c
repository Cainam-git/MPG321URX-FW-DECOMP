/* FUN_a00ded78 (leon2m 0xa00ded78-0xa00deda0, 40 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * When the byte DAT_a802b0c4 is non-zero, stores x to word i of the word array at DAT_a802b0c4 + 0xc. Nothing in
 * the image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a00decf4 and
 * FUN_a00deda0. Source form: one structure (flag byte at +0, word array at +0xc).
 */
struct C4 { unsigned char en; unsigned char p1[0xb]; unsigned int v[4]; };
extern struct C4 DAT_a802b0c4;

void FUN_a00ded78(unsigned int i, unsigned int x)
{
    if (DAT_a802b0c4.en != 0)
        DAT_a802b0c4.v[i] = x;
}
