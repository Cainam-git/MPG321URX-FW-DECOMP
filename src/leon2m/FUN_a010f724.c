/* FUN_a010f724 (leon2m 0xa010f724-0xa010f7a4, 128 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Selects s = DAT_a802d804 (c = 1) or DAT_a802d704; clears bit 1 of byte +0x3e of s and writes words +4 and +8 of s
 * to the word registers 0xd0032280 and 0xd003a280 (c = 0) or 0xd0032284 and 0xd003a284. Nothing in the image refers
 * to it: no call, branch, sethi/or constant or address word. It lies between FUN_a010f65c and FUN_a010f7a4. Source
 * form: s initialised to DAT_a802d704 and replaced for c == 1.
 */
struct Ctx { unsigned int w0, w4, w8; unsigned char p0c[0x3e - 0xc]; unsigned char b3e, p3f; };
extern struct Ctx DAT_a802d704, DAT_a802d804;

void FUN_a010f724(unsigned char c)
{
    struct Ctx *s = &DAT_a802d704;

    if (c == 1)
        s = &DAT_a802d804;
    s->b3e &= ~2;
    if (c == 0) {
        *(volatile unsigned int *)0xd0032280 = s->w4;
        *(volatile unsigned int *)0xd003a280 = s->w8;
    } else {
        *(volatile unsigned int *)0xd0032284 = s->w4;
        *(volatile unsigned int *)0xd003a284 = s->w8;
    }
}
