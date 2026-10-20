/* leon2m FUN_a00fd074 @ 0xa00fd074  MATCH (-mcpu=v8 -O3 -g)
 * Writes 0x44 to 0xCF012084 and v to 0xCF012088, then runs one transfer step xfer(m) with m = DAT_a802c97d, or the
 * two steps xfer(8) and xfer(4) when m is 0xF. Caller: FUN_a014782c.
 * xfer(mode) (static, inlined): writes 0x2E to the status register 0xCF012034; passes (mode, 2) to the function
 * pointer _DAT_a802c970 when it is set, otherwise writes mode to 0xCF012080 and 2 to 0xCF012040; takes the start
 * tick func_0x4008d588() and, while none of the status bits 0x2E is set, calls func_0x4008ced8() and stops after
 * more than 1000 ticks (func_0x4008d594); finally reads the status register once (value unused) and writes 0x2E.
 */
#define R(a) (*(volatile unsigned int *)(a))

extern void (*_DAT_a802c970)(int, int);
extern unsigned char DAT_a802c97d;
extern unsigned short func_0x4008d588(void);
extern unsigned short func_0x4008d594(unsigned short start);
extern void func_0x4008ced8(void);

static void xfer(unsigned char mode)
{
    unsigned short t0;

    R(0xcf012034) = 0x2e;
    if (_DAT_a802c970 != 0)
        _DAT_a802c970(mode, 2);
    else {
        R(0xcf012080) = mode;
        R(0xcf012040) = 2;
    }
    t0 = func_0x4008d588();
    while (!(R(0xcf012034) & 0x2e)) {
        func_0x4008ced8();
        if (func_0x4008d594(t0) > 1000)
            break;
    }
    (void)R(0xcf012034);
    R(0xcf012034) = 0x2e;
}

void FUN_a00fd074(unsigned char v)
{
    unsigned char m;

    R(0xcf012084) = 0x44;
    R(0xcf012088) = v;
    m = DAT_a802c97d;
    if (m == 0xf) {
        xfer(8);
        xfer(4);
    } else
        xfer(m);
}
