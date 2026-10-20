/* leon2m FUN_a00fc200 @ 0xa00fc200-0xa00fc2fc, flags -mcpu=v8 -O3 -g.
 * Writes 0x28 to 0xcf01201c, 1 to 0xcf012000 and 0x53 to 0xcf012044. For p = 0..3 it calls
 * FUN_a00fe880(3, 1 << p, 1) (one case per value); other values skip the call. Then it writes 0xff to
 * 0xcf012034, sets the bytes DAT_a802c97d = 0x0f, DAT_a802c97e = 0x0f, DAT_a802c97f = 0xff (in that order:
 * the store order decides the register choice), and writes 0x78 >> s to 0xcf012004, where s is bits 0..1
 * of 0xcf011480 (s == 0 is a separate branch that writes 0x78). volatile only on the 0xcf0xxxxx registers.
 */
#define R(a) (*(volatile unsigned int *)(a))

extern void FUN_a00fe880(unsigned char, unsigned char, unsigned int);
extern unsigned char DAT_a802c97d;
extern unsigned char DAT_a802c97e;
extern unsigned char DAT_a802c97f;

void FUN_a00fc200(unsigned char p)
{
    unsigned int s;

    R(0xcf01201c) = 0x28;
    R(0xcf012000) = 1;
    R(0xcf012044) = 0x53;
    switch (p) {
    case 0:
        FUN_a00fe880(3, 1, 1);
        break;
    case 1:
        FUN_a00fe880(3, 2, 1);
        break;
    case 2:
        FUN_a00fe880(3, 4, 1);
        break;
    case 3:
        FUN_a00fe880(3, 8, 1);
        break;
    }
    R(0xcf012034) = 0xff;
    DAT_a802c97d = 0xf;
    DAT_a802c97e = 0xf;
    DAT_a802c97f = 0xff;
    s = R(0xcf011480) & 3;
    if (s == 0)
        R(0xcf012004) = 0x78;
    else
        R(0xcf012004) = 0x78 >> s;
}
