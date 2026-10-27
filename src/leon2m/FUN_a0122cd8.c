/* FUN_a0122cd8 (leon2m 0xa0122cd8-0xa0122d0c, 52 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores a to the byte DAT_a802c9ec when a is 1..16 and b to the byte DAT_a8027b0c when b is below 32. Nothing in
 * the image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a01227f0 and
 * FUN_a0122d0c. Source form: the a test is (unsigned char)(a - 1) < 16.
 */
extern unsigned char DAT_a802c9ec;
extern unsigned char DAT_a8027b0c;

void FUN_a0122cd8(unsigned char a, unsigned char b)
{
    if ((unsigned char)(a - 1) < 16)
        DAT_a802c9ec = a;
    if (b < 32)
        DAT_a8027b0c = b;
}
