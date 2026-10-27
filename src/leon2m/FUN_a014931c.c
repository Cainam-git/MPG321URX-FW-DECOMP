/* leon2m FUN_a014931c @ 0xa014931c-0xa0149588 (155 words), flags -mcpu=v8 -O3 -g, leaf. Callers: FUN_a00d5fe4,
 * FUN_a00d6000, FUN_a00d601c, FUN_a00d6038, FUN_a014c7bc.
 * k = remap(ch) (1, 0, 2, 3 unchanged, anything else -1). For k 0..3, v is stored in byte 0x1e + k of
 * 0xa802e3d0; e = bits 12..15 of word 0 of record k of the 0x78-byte records at 0xa802df30. When byte 0xa of entry
 * e of the 0x2a-byte table at 0xa802e224 is 0x71, FUN_a01328d4(k, x) is tail-called: x = v & 3 for k == 0 and,
 * for k 1..3, when bit 23 of word 0xa802e3d0 is set; x = 0 otherwise.
 * Source form: remap is the static helper of FUN_a0147560 (inlined); every case indexes the records with k (GCC
 * folds the constant index in cases 1..3 only).
 */
struct E3d0 { unsigned int w0; unsigned char p04[0x1e - 4]; unsigned char b1e, b1f, b20, b21; };
struct Chan { unsigned int w0; unsigned char rest[0x74]; };
struct SrcT { unsigned char p00[0x0a]; unsigned char b0a; unsigned char p0b[0x2a - 0x0b]; };
extern struct E3d0 DAT_a802e3d0;
extern struct Chan DAT_a802df30[4];
extern struct SrcT DAT_a802e224[];
extern void FUN_a01328d4(int, int);

static int remap(int ch)
{
    switch (ch) {
    case 1: return 1;
    case 0: return 0;
    case 2: return 2;
    case 3: return 3;
    }
    return -1;
}

void FUN_a014931c(unsigned char ch, unsigned char v)
{
    unsigned char k = remap(ch);

    switch (k) {
    case 0:
        DAT_a802e3d0.b1e = v;
        if (DAT_a802e224[(DAT_a802df30[k].w0 >> 12) & 0xf].b0a == 0x71)
            FUN_a01328d4(0, v & 3);
        break;
    case 1:
        DAT_a802e3d0.b1f = v;
        if (DAT_a802e3d0.w0 & 0x800000) {
            if (DAT_a802e224[(DAT_a802df30[k].w0 >> 12) & 0xf].b0a == 0x71)
                FUN_a01328d4(1, v & 3);
        } else if (DAT_a802e224[(DAT_a802df30[k].w0 >> 12) & 0xf].b0a == 0x71)
            FUN_a01328d4(1, 0);
        break;
    case 2:
        DAT_a802e3d0.b20 = v;
        if (DAT_a802e3d0.w0 & 0x800000) {
            if (DAT_a802e224[(DAT_a802df30[k].w0 >> 12) & 0xf].b0a == 0x71)
                FUN_a01328d4(2, v & 3);
        } else if (DAT_a802e224[(DAT_a802df30[k].w0 >> 12) & 0xf].b0a == 0x71)
            FUN_a01328d4(2, 0);
        break;
    case 3:
        DAT_a802e3d0.b21 = v;
        if (DAT_a802e3d0.w0 & 0x800000) {
            if (DAT_a802e224[(DAT_a802df30[k].w0 >> 12) & 0xf].b0a == 0x71)
                FUN_a01328d4(3, v & 3);
        } else if (DAT_a802e224[(DAT_a802df30[k].w0 >> 12) & 0xf].b0a == 0x71)
            FUN_a01328d4(3, 0);
        break;
    }
}
