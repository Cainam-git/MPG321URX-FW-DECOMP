/* FUN_a0135004 (leon2m 0xa0135004-0xa01350dc, 216 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Clears m[0..3]; when the bytes DAT_a802cb97 and DAT_a802cb96 differ, copies the five words of entry DAT_a802cb96
 * of the 0x14-byte array DAT_a802da6c to m[0..4] and advances DAT_a802cb96 (wrapping to 0 above 0x24). Nothing in
 * the image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a0134de0 and
 * FUN_a01350dc. Source form: m is a plain word pointer, so every store through it may alias the byte index and GCC
 * reloads DAT_a802cb96 for each word.
 */
struct Msg { unsigned int w[5]; };
extern struct Msg DAT_a802da6c[];
extern unsigned char DAT_a802cb97, DAT_a802cb96;

void FUN_a0135004(unsigned int *m)
{
    unsigned char n;

    m[0] = 0;
    m[1] = 0;
    m[2] = 0;
    m[3] = 0;
    if (DAT_a802cb97 != DAT_a802cb96) {
        m[0] = DAT_a802da6c[DAT_a802cb96].w[0];
        m[1] = DAT_a802da6c[DAT_a802cb96].w[1];
        m[2] = DAT_a802da6c[DAT_a802cb96].w[2];
        m[3] = DAT_a802da6c[DAT_a802cb96].w[3];
        m[4] = DAT_a802da6c[DAT_a802cb96].w[4];
        n = DAT_a802cb96 + 1;
        if (n > 0x24)
            DAT_a802cb96 = 0;
        else
            DAT_a802cb96 = n;
    }
}
