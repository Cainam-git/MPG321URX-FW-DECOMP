/* leon2m FUN_a00ba184 @ 0xa00ba184-0xa00ba3e8 (153 words), flags -mcpu=v8 -O3 -g. Callers: FUN_a00956a0,
 * FUN_a0095704, FUN_a009f42c, FUN_a00a5e68, FUN_a00a6b98.
 * Copies the 24 halfwords at 0x19820a into a local table (FUN_a013c910). Nothing happens while byte
 * 0xa802d290+0x190 is 0. Byte 0x17b selects: 1 -> FUN_a0146a80(0, i, 4, 0x1702, 1) for i = 0..2; other values
 * except 2 -> the same with 0x1802; 2 -> FUN_a00ba068 fills four bytes, FUN_a00b9f30 fills three words from them,
 * v = FUN_a00b9c68 of the low halfwords of those words (0xffff becomes 180), idx = (v / 15 + 12) % 24 and d = the
 * distance between idx and byte 0xa802b090 on a circle of 24. When force is set, d > 1, byte 0xa802b090 is 0 or
 * byte 0x190 differs from byte 0xa802b091, FUN_a0146a80(0, i, 4, table[idx], 1) runs for i = 0..2 and the bytes
 * 0xa802b090 = idx and 0xa802b091 = byte 0x190 are stored.
 * Source form: old-style (K&R) definition, so force arrives as int and is masked where it is used; idx is an
 * unsigned short.
 */
struct R290 { unsigned char p000[0x17b]; unsigned char b17b; unsigned char p17c[0x190 - 0x17c]; unsigned char b190; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a802b090, DAT_a802b091;
extern const unsigned short DAT_0019820a[24];
extern void *FUN_a013c910(void *dst, const void *src, unsigned int n);
extern void FUN_a00ba068(unsigned char *p1, unsigned char *p2, unsigned char *p3, unsigned char *p4);
extern void FUN_a00b9f30(int *a, int *b, int *c, unsigned char d, unsigned char e, unsigned char f, unsigned char g);
extern unsigned short FUN_a00b9c68(short a, short b, short c);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);

void FUN_a00ba184(force)
    unsigned char force;
{
    unsigned short tab[24];
    unsigned char b57, b58, b59, b60;
    int x = 0, y = 0, z = 0;
    unsigned char i, d;
    unsigned short idx;
    unsigned short v, q;

    FUN_a013c910(tab, DAT_0019820a, 0x30);
    if (DAT_a802d290.b190 == 0)
        return;
    if (DAT_a802d290.b17b == 2) {
        FUN_a00ba068(&b57, &b58, &b59, &b60);
        FUN_a00b9f30(&x, &y, &z, b57, b58, b59, b60);
        v = FUN_a00b9c68(x, y, z);
        if (v == 0xffff)
            v = 180;
        if (v == 0xffff)
            return;
        q = v / 15;
        idx = (q + 12) % 24;
        if (DAT_a802b090 < idx)
            d = idx - DAT_a802b090;
        else if (DAT_a802b090 > idx)
            d = DAT_a802b090 - idx;
        else
            d = 0;
        if (d > 0xb)
            d = 24 - d;
        if (force != 0 || d > 1 || DAT_a802b090 == 0 || DAT_a802d290.b190 != DAT_a802b091) {
            v = tab[idx];
            for (i = 0; i <= 2; i++)
                FUN_a0146a80(0, i, 4, v, 1);
            DAT_a802b090 = idx;
            DAT_a802b091 = DAT_a802d290.b190;
        }
    } else if (DAT_a802d290.b17b == 1) {
        for (i = 0; i <= 2; i++)
            FUN_a0146a80(0, i, 4, 0x1702, 1);
    } else {
        for (i = 0; i <= 2; i++)
            FUN_a0146a80(0, i, 4, 0x1802, 1);
    }
}
