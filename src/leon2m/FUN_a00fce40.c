/* leon2m FUN_a00fce40 @ 0xa00fce40 (-mcpu=v8 -O3 -g)
 * Writes 0x8C to 0xCF012084, clears the four bytes DAT_a802c978[3..0] (the bytes FUN_a00fcdd8 returns as a word),
 * then runs xfer(m, 1) with m = DAT_a802c97d, or xfer(8, 1) and xfer(4, 1) when m is 0xF. Caller: FUN_a014782c.
 * xfer(mode, op) is the inlined step of FUN_a00fd074 (there with op 2): status 0xCF012034 = 0x2E; the function
 * pointer _DAT_a802c970(mode, op), or 0xCF012080 = mode and 0xCF012040 = op; wait up to 1000 ticks for a status bit
 * of 0x2E (calling func_0x4008ced8 meanwhile); read the status once and write 0x2E.
 * Source form: the byte clears in descending index order.
 */
#define R(a) (*(volatile unsigned int *)(a))

extern void (*_DAT_a802c970)(int, int);
extern unsigned char DAT_a802c97d;
extern unsigned char DAT_a802c978[4];
extern unsigned short func_0x4008d588(void);
extern unsigned short func_0x4008d594(unsigned short start);
extern void func_0x4008ced8(void);

static void xfer(unsigned char mode, unsigned char op)
{
    unsigned short t0;

    R(0xcf012034) = 0x2e;
    if (_DAT_a802c970 != 0)
        _DAT_a802c970(mode, op);
    else {
        R(0xcf012080) = mode;
        R(0xcf012040) = op;
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

void FUN_a00fce40(void)
{
    unsigned char m;

    R(0xcf012084) = 0x8c;
    DAT_a802c978[3] = 0;
    DAT_a802c978[2] = 0;
    DAT_a802c978[1] = 0;
    DAT_a802c978[0] = 0;
    m = DAT_a802c97d;
    if (m == 0xf) {
        xfer(8, 1);
        xfer(4, 1);
    } else
        xfer(m, 1);
}
