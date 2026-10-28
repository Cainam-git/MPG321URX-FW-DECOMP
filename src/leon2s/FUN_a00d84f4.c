/* FUN_a00d84f4 (leon2s 0xa00d84f4-0xa00d8714, 544 bytes), flags -mcpu=v8 -Os -g.
 * void (void). Clears the 14-byte stack record in with func_0xa0fc15ac(&in, 0, 0xe), fills it with
 * FUN_a00d73b4(&in, 0, 1, 0x13), builds the stack record m (bits 24..30 = 0x11, bits 20..23 = bits 20..23 of
 * in word 0, bits 9..15 = bits 8..14 of in word 0, halfword +4 = in halfword +4) and passes it to
 * FUN_a00d791c(&m, 2, 1, 3, 5). With R = the register block DAT_a807609c[DAT_a8078832] and t = bits 20..23 of
 * in word 0: t 8: halfword +4 nonzero writes bits 8..14 of in word 0 to R + 0x284, sets and clears bit 4 of
 * R + 0x2b0 and copies m halfword +4 to DAT_a80787f8; zero clears R + 0x284 and DAT_a80787f8. t 1:
 * DAT_a8078847 = 1 / 0 (halfword +4 nonzero / zero), sets bit 6 of R + 0x2ac, writes R + 0x284 (bits 8..14 of
 * in word 0 / 0), sets and clears bit 4 of R + 0x2b0 and clears bit 6 of R + 0x2ac.
 * The register blocks are reached through DAT_a807609c, an array of volatile word pointers.
 * Source form: in the t 1 case each arm repeats the three closing register writes.
 */
struct In { unsigned int a : 8, f20 : 4, b19 : 4, x15 : 1, f8 : 7, lo : 8; unsigned short h4; unsigned char rest[8]; };
union InU { struct In s; unsigned int w; };
struct Msg { unsigned int b31 : 1, f24 : 7, f20 : 4, r16 : 4, f9 : 7, lo : 9; unsigned short h4; unsigned short h6; };
extern unsigned char DAT_a8078832;
extern unsigned char DAT_a8078847;
extern unsigned short DAT_a80787f8;
extern volatile unsigned int *DAT_a807609c[];
extern void *func_0xa0fc15ac(void *, int, unsigned int);
extern void FUN_a00d73b4(void *, unsigned char, unsigned char, unsigned char);
extern void FUN_a00d791c(void *, int, int, int, int);

void FUN_a00d84f4(void)
{
    union InU in;
    struct Msg m;
    unsigned int v;

    func_0xa0fc15ac(&in, 0, 0xe);
    FUN_a00d73b4(&in, 0, 1, 0x13);
    m.f24 = 0x11;
    m.f20 = in.s.f20;
    m.f9 = in.s.f8;
    m.h4 = in.s.h4;
    FUN_a00d791c(&m, 2, 1, 3, 5);
    v = in.w;
    if (((v >> 16) & 0xf0) == 0x80) {
        if (in.s.h4 != 0) {
            DAT_a807609c[DAT_a8078832][0x284 / 4] = (v >> 8) & 0x7f;
            DAT_a807609c[DAT_a8078832][0x2b0 / 4] |= 0x10;
            DAT_a807609c[DAT_a8078832][0x2b0 / 4] &= ~0x10;
            DAT_a80787f8 = m.h4;
        } else {
            DAT_a807609c[DAT_a8078832][0x284 / 4] = 0;
            DAT_a80787f8 = 0;
        }
    } else if (((v >> 16) & 0xf0) == 0x10) {
        if (in.s.h4 != 0) {
            DAT_a8078847 = 1;
            DAT_a807609c[DAT_a8078832][0x2ac / 4] |= 0x40;
            DAT_a807609c[DAT_a8078832][0x284 / 4] = (in.w >> 8) & 0x7f;
            DAT_a807609c[DAT_a8078832][0x2b0 / 4] |= 0x10;
            DAT_a807609c[DAT_a8078832][0x2b0 / 4] &= ~0x10;
            DAT_a807609c[DAT_a8078832][0x2ac / 4] &= ~0x40;
        } else {
            DAT_a8078847 = 0;
            DAT_a807609c[DAT_a8078832][0x2ac / 4] |= 0x40;
            DAT_a807609c[DAT_a8078832][0x284 / 4] = 0;
            DAT_a807609c[DAT_a8078832][0x2b0 / 4] |= 0x10;
            DAT_a807609c[DAT_a8078832][0x2b0 / 4] &= ~0x10;
            DAT_a807609c[DAT_a8078832][0x2ac / 4] &= ~0x40;
        }
    }
}
