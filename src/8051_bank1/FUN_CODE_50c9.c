/* FUN_CODE_50c9, 8051_bank1, range 0x50C9..0x52BE (501 B).
 * Options: OPTIMIZE(8,SPEED) LARGE.
 * Selects two XDATA registers by ch (0xF03B/0xF040, 0xF043/0xF048, 0xF08B/0xF090, 0xF093/0xF098, 0xF09D/0xF0A2,
 * 0xF0BA/0xF0BF), writes 0 and 1 to them, then writes n bytes from p in blocks that end at multiples of 8 of the
 * running address: per block it writes 0x55 to 0xF00A, calls FUN_CODE_4cb9(ch, ctl | ((addr >> 7) & 0x0E), addr,
 * len, p), clears the result bit when that call returns 0, advances addr, p and n by len, and calls FUN_CODE_d94a
 * and FUN_CODE_d44e(10). Finally it writes 0xF8 to the first register and returns the result bit.
 * Compiler aids (each emits no code):
 * - 'w = 0;' before 'w = addr;': w is defined before the byte temp of the load, so Keil assigns it R2:R3 first and
 *   loads addr straight into R2:R3 ('MOVX A,@DPTR; MOV R2,A; INC DPTR; MOVX A,@DPTR; MOV R3,A'); without it the high
 *   byte goes through a temp ('MOV R4,A ... MOV R2,AR4').
 * - '(unsigned char)w == (unsigned char)w ? E : E' (both outcomes identical, Keil merges them): with it Keil loads
 *   the shifted value low byte first ('MOV A,R3; MOV R6,AR2') before the 'w >> 7' loop, as the firmware does.
 * - 'if (FUN_CODE_4cb9(..)) ok &= CY; else ok &= CY;' (both arms identical): FUN_CODE_4cb9 returns a bit, which Keil
 *   passes in the carry flag CY, so each arm is 'ok &= result'. This form keeps w in R2:R3 across the call
 *   ('PUSH AR2/AR3 ... POP') and gives the firmware's 'ANL C,ok; MOV ok,C'.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f00a;
bit FUN_CODE_4cb9(unsigned char ch, unsigned char ctl, unsigned int w, unsigned int n, unsigned char *buf);
extern unsigned int FUN_CODE_d94a(void);
void FUN_CODE_d44e(unsigned int t);

sfr ACC = 0xE0;
sbit CY = 0xD7;
bit FUN_CODE_50c9(unsigned char ch, unsigned char ctl, unsigned char c, unsigned char *p, unsigned int n)
{
    unsigned int addr;
    unsigned char x, len;
    unsigned int t;
    unsigned char volatile *q1, *q2;
    bit ok;
    unsigned int w;

    ok = 1;
    addr = 0;
    x = 0;
    len = 0;
    t = 0;
    q1 = 0;
    q2 = 0;
    switch (ch) {
    case 0:
        q1 = (unsigned char xdata *)0xf03b;
        q2 = (unsigned char xdata *)0xf040;
        break;
    case 1:
        q1 = (unsigned char xdata *)0xf043;
        q2 = (unsigned char xdata *)0xf048;
        break;
    case 2:
        q1 = (unsigned char xdata *)0xf08b;
        q2 = (unsigned char xdata *)0xf090;
        break;
    case 3:
        q1 = (unsigned char xdata *)0xf093;
        q2 = (unsigned char xdata *)0xf098;
        break;
    case 4:
        q1 = (unsigned char xdata *)0xf09d;
        q2 = (unsigned char xdata *)0xf0a2;
        break;
    case 5:
        q1 = (unsigned char xdata *)0xf0ba;
        q2 = (unsigned char xdata *)0xf0bf;
        break;
    }
    *q1 = 0;
    *q2 = 1;
    addr = c;
    while (n != 0) {
        DAT_EXTMEM_f00a = 0x55;
        w = 0;
        w = addr;
        len = 8 - (w & 7);
        if (n < len) len = n;
        x = ctl | ((unsigned char)w == (unsigned char)w ? ((unsigned char)(w >> 7) & 0x0e) : ((unsigned char)(w >> 7) & 0x0e));
        if (FUN_CODE_4cb9(ch, x, w, len, p)) ok &= CY; else ok &= CY;
        addr += len;
        p += len;
        n -= len;
        t = FUN_CODE_d94a();
        FUN_CODE_d44e(10);
    }
    *q1 = 0xf8;
    return ok;
}
