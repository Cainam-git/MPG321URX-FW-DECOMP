/* FUN_a01101a8 (leon2m 0xa01101a8-0xa011023c, 148 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Selects s = DAT_a802d804 (c = 1) or DAT_a802d704; sets word +8 to (w0 + ((w8 - w4) << 5)) >> 5 and word +4 to w0
 * >> 5, then writes them to the word registers 0xd0032280/0xd003a280 (c = 0) or 0xd0032284/0xd003a284. Nothing in
 * the image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a01100a4 and
 * FUN_a011023c. Source form: s initialised to DAT_a802d704 and replaced for c == 1.
 */
struct Ctx { unsigned int w0, w4, w8; };
extern struct Ctx DAT_a802d704, DAT_a802d804;

void FUN_a01101a8(unsigned char c)
{
    struct Ctx *s = &DAT_a802d704;

    if (c == 1)
        s = &DAT_a802d804;
    s->w8 = (s->w0 + ((s->w8 - s->w4) << 5)) >> 5;
    s->w4 = s->w0 >> 5;
    if (c == 0) {
        *(volatile unsigned int *)0xd0032280 = s->w4;
        *(volatile unsigned int *)0xd003a280 = s->w8;
    } else {
        *(volatile unsigned int *)0xd0032284 = s->w4;
        *(volatile unsigned int *)0xd003a284 = s->w8;
    }
}
