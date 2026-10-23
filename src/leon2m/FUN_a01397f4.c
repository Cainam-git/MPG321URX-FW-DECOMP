/* leon2m FUN_a01397f4 @ 0xa01397f4 (-mcpu=v8 -O3 -g)
 * When p1 (low byte) differs from byte 0xA802A45A: reads a word w (preset to 0xFFFFFFFF) through
 * func_0x4008c4d0(2, 0x20, &w, 1); while it is nonzero, calls func_0x4008d1a0(1) and reads again, at most 100
 * times. When w reads 0, writes (p1 & 0xff) | 0x82000000 through func_0x4008c5f8(2, 0x20, &w, 1). Then stores p1
 * in byte 0xA802A45A. Same code as FUN_a0139968 with other constants.
 * See FUN_a0139968 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern void func_0x4008c4d0(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void func_0x4008c5f8(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void func_0x4008d1a0(int ms);
extern unsigned char DAT_a802a45a;
void FUN_a01397f4(unsigned int p)
{
    unsigned int v;
    unsigned short c;
    int n;

    if (DAT_a802a45a != (unsigned char)p) {
        v = 0xffffffff;
        func_0x4008c4d0(2, 0x20, &v, 1);
        c = (unsigned char)p;
        n = 100;
        while (v != 0) {
            func_0x4008d1a0(1);
            n--;
            func_0x4008c4d0(2, 0x20, &v, 1);
            if (n == 0)
                break;
        }
        if (v == 0) {
            v = c | 0x82000000;
            func_0x4008c5f8(2, 0x20, &v, 1);
        }
    }
    DAT_a802a45a = p;
}
