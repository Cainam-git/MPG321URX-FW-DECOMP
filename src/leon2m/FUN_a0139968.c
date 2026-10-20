/* leon2m FUN_a0139968 @ 0xa0139968-0xa0139a30 (50 words), flags -mcpu=v8 -O3 -g.
 * (autoc draft 90.00).
 * Code facts: (int-width p: the fw stores %i0 unextended with stb and masks it per use). If the byte DAT_a802cb99
 * differs from (u8)p: v = 0xffffffff; ROM read func_0x4008c4d0(2, 0x20, &v, 1); then up to 100 rounds while v != 0
 * of { delay func_0x4008d1a0(1); n--; read again; stop when n == 0 }; if v == 0 afterwards: v = (u8)p | 0x20000000
 * and ROM write func_0x4008c5f8(2, 0x20, &v, 1). Always ends with DAT_a802cb99 = p.
 * Fixes vs draft: the decrement sits BEFORE the second read (fw add/cmp, not addcc); the u8 copy of p taken after
 * the first read is an 'unsigned short c = (unsigned char)p' (fw 'and %i0,0xff,%l1' at the copy and 'and %l1,0xff'
 * at the use; an unsigned char copy gives 'mov %i0,%l1'). ROM prototypes as in the other accepted files. No aids.
 */
extern void func_0x4008c4d0(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void func_0x4008c5f8(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void func_0x4008d1a0(int ms);
extern unsigned char DAT_a802cb99;
void FUN_a0139968(unsigned int p)
{
    unsigned int v;
    unsigned short c;
    int n;

    if (DAT_a802cb99 != (unsigned char)p) {
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
            v = c | 0x20000000;
            func_0x4008c5f8(2, 0x20, &v, 1);
        }
    }
    DAT_a802cb99 = p;
}
