/* leon2m FUN_a01138fc @ 0xa01138fc-0xa01139c8 (204 bytes), flags -mcpu=v8 -O3 -g -msoft-float. No direct callers found.
 * FUN_a01138fc(p, addr, n): writes n blocks of 32 bytes from the word array p to the indirect register port at
 * 0xcf011f88: for block i the address addr + i goes to 0xcf011fa0 / fa4 / fa8 / fac (addr, addr >> 8, >> 16, >> 24),
 * 0x80 to 0xcf011f84, then the words p[i * 8 .. i * 8 + 7], each as four bytes from the most significant byte down
 * (ldub / lduh / ldub / ld of the word, low eight bits written). volatile: hardware registers only.
 * Source form: the word is read through a union of a plain word and four 8-bit bit-fields; the inner index j is
 * initialised in its declaration ('j = 0', overwritten by the inner loop before any read), which sets the order in
 * which the six hoisted register addresses are built (as in the sibling FUN_a0113eb4, the flags include
 * -msoft-float).
 */
#define REG(a) (*(volatile unsigned int *)(a))

union Q { unsigned int w; struct { unsigned int a:8, b:8, c:8, d:8; } f; };

void FUN_a01138fc(union Q *p, unsigned int addr, unsigned int n)
{
    unsigned int i, j = 0, k;

    k = 0;
    for (i = 0; i < n; i++) {
        REG(0xcf011fa0) = addr;
        REG(0xcf011fa4) = addr >> 8;
        REG(0xcf011fa8) = addr >> 16;
        REG(0xcf011fac) = addr >> 24;
        REG(0xcf011f84) = 0x80;
        for (j = k; j < k + 8; j++) {
            REG(0xcf011f88) = p[j].f.a;
            REG(0xcf011f88) = p[j].f.b;
            REG(0xcf011f88) = p[j].f.c;
            REG(0xcf011f88) = p[j].f.d;
        }
        k += 8;
        addr++;
    }
}
