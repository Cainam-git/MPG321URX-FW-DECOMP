/* leon2m FUN_a00ba068 @ 0xa00ba068-0xa00ba184 (71 words), flags -mcpu=v8 -O3 -g. Called by FUN_a00ba184.
 * With a = halfword 0xa802d43c + 30, b = halfword 0xa802d43e + 36, w = FUN_a014837c(0) >> 4 and
 * h = FUN_a014837c(1) >> 4 (16-bit values), computes q = (a + w / 2) / w and stores *p1, *p3 = 0, 0 for q == 0,
 * 15, 15 for q == 16, and q - 1, q otherwise. Then r = (b + h / 2) / h gives *p2, *p4 = 0, *p1 for r == 0,
 * 15, 15 for r == 16, and r - 1, r otherwise. All four results are bytes.
 * The two halfwords are members of the structure at 0xa802d290 (offsets 0x1ac and 0x1ae).
 */
struct R290 { unsigned char p000[0x1ac]; unsigned short h1ac; unsigned short h1ae; };
extern struct R290 DAT_a802d290;
extern unsigned short FUN_a014837c(int);

void FUN_a00ba068(unsigned char *p1, unsigned char *p2, unsigned char *p3, unsigned char *p4)
{
    unsigned short a, b, w, h;
    unsigned char q;

    a = DAT_a802d290.h1ac + 30;
    b = DAT_a802d290.h1ae + 36;
    w = FUN_a014837c(0) >> 4;
    h = FUN_a014837c(1) >> 4;
    q = (a + w / 2) / w;
    if (q == 0) {
        *p1 = q;
        *p3 = q;
    } else if (q == 16) {
        *p1 = q - 1;
        *p3 = q - 1;
    } else {
        *p1 = q - 1;
        *p3 = q;
    }
    q = (b + h / 2) / h;
    if (q == 0) {
        *p2 = q;
        *p4 = *p1;
    } else if (q == 16) {
        *p2 = q - 1;
        *p4 = q - 1;
    } else {
        *p2 = q - 1;
        *p4 = q;
    }
}
