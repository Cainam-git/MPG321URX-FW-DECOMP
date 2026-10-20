/* leon2m FUN_a0099c64 @ 0xa0099c64-0xa0099cfc (38 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Clears bit 31 of the word 0xa802d46c (0xa802d290 + 0x1dc) and bit 15 of the halfword 0xa802d002 (0xa802cff4 +
 * 0xe), clears byte 0xa8025c56, runs the body of FUN_a0090fd8 (inlined: when bit 15 of the halfword 0xa802cff8 is
 * set, sets its bit 10 and calls FUN_a00808ac(4, 0); clears word 0xa802afec; calls FUN_a00b5080), clears bytes
 * 0xa802d033 (0xa802cff4 + 0x3f) and 0xa802d474 (0xa802d290 + 0x1e4), calls FUN_a00b1ba4(byte 0xa8025c56, 4) and
 * sets word 0xa802afec to 0x10a. The single bits are 1-bit bit-fields.
 */
union H { unsigned short h; struct { unsigned short b15 : 1, rest : 15; } f; };
struct Rcff4 { unsigned char pad[4]; union H w4; unsigned char pad6[8]; union H we; unsigned char pad10[0x2f];
               unsigned char b3f; };
struct R290 { unsigned char pad[0x1dc]; unsigned int b31 : 1, rest : 31; unsigned char pad1e0[4]; unsigned char b1e4; };
extern struct Rcff4 DAT_a802cff4;
extern struct R290 DAT_a802d290;
extern unsigned int DAT_a802afec;
extern unsigned char DAT_a8025c56;
extern void FUN_a00808ac(int, int);
extern void FUN_a00b5080(void);
extern void FUN_a00b1ba4(unsigned char, int);

static void FUN_a0090fd8(void)
{
    if (DAT_a802cff4.w4.f.b15) {
        DAT_a802cff4.w4.h |= 0x400;
        FUN_a00808ac(4, 0);
    }
    DAT_a802afec = 0;
    FUN_a00b5080();
}

void FUN_a0099c64(void)
{
    DAT_a802d290.b31 = 0;
    DAT_a802cff4.we.f.b15 = 0;
    DAT_a8025c56 = 0;
    FUN_a0090fd8();
    DAT_a802cff4.b3f = 0;
    DAT_a802d290.b1e4 = 0;
    FUN_a00b1ba4(DAT_a8025c56, 4);
    DAT_a802afec = 0x10a;
}
