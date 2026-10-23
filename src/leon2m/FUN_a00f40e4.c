/* leon2m FUN_a00f40e4 @ 0xa00f40e4-0xa00f42b8 (117 words).
 * Returns 0 when bit 7 of register 0x54 of block blk is clear. Otherwise clears byte 0xa802b7ac, calls
 * FUN_a0121e3c(blk), writes 0x40 to register 0x37 and 0 then 0x11 to register 0x36, waits 20 ms and polls
 * register 0x36 until bit 0 clears (FUN_a0121374(blk) == 1 stores 1 to the byte and stops; more than 99 ticks
 * of func_0x4008d594 stop without success). Without success the byte is set to 1; when the byte is 1 the result is
 * 0. Otherwise copies 16-bit register 0x3e (12 bits) to 0x12, 0x38 (11 bits) to 0xe and 0xc
 * (FUN_a00f1ce4 / FUN_a00f1d48), calls FUN_a00f8e2c(blk, 1) when 0x38 is below 0x3a, (blk, 0xffff) when above,
 * (blk, 0) when equal, and returns 1. Source form: register 0x3a is read first in both compares.
 */
extern unsigned char DAT_a802b7ac;
extern unsigned char FUN_a00f1a90(unsigned char blk, unsigned char reg);
extern void FUN_a00f1ad4(unsigned char blk, unsigned char reg, unsigned char val);
extern unsigned short FUN_a00f1ce4(unsigned char blk, unsigned char reg);
extern void FUN_a00f1d48(unsigned char blk, unsigned char reg, unsigned short val);
extern unsigned char FUN_a0121374(unsigned char blk);
extern void FUN_a0121e3c(unsigned char blk);
extern void FUN_a00f8e2c(unsigned char blk, unsigned short v);
extern void func_0x4008d1a0(int ms);
extern unsigned short func_0x4008d588(void);
extern unsigned short func_0x4008d594(unsigned short start);

unsigned char FUN_a00f40e4(unsigned char blk)
{
    unsigned short t0;
    unsigned char ok;

    if (!(FUN_a00f1a90(blk, 0x54) & 0x80))
        return 0;
    DAT_a802b7ac = 0;
    FUN_a0121e3c(blk);
    FUN_a00f1ad4(blk, 0x37, 0x40);
    FUN_a00f1ad4(blk, 0x36, 0);
    FUN_a00f1ad4(blk, 0x36, 0x11);
    func_0x4008d1a0(20);
    ok = 0;
    t0 = func_0x4008d588();
    for (;;) {
        if (FUN_a0121374(blk) == 1) {
            DAT_a802b7ac = 1;
            break;
        }
        if (!(FUN_a00f1a90(blk, 0x36) & 1)) {
            ok = 1;
            break;
        }
        if (func_0x4008d594(t0) > 0x63)
            break;
    }
    if (ok == 0)
        DAT_a802b7ac = 1;
    if (DAT_a802b7ac == 1)
        return 0;
    FUN_a00f1d48(blk, 0x12, FUN_a00f1ce4(blk, 0x3e) & 0xfff);
    FUN_a00f1d48(blk, 0xe, FUN_a00f1ce4(blk, 0x38) & 0x7ff);
    FUN_a00f1d48(blk, 0xc, FUN_a00f1ce4(blk, 0x38) & 0x7ff);
    if (FUN_a00f1ce4(blk, 0x3a) > FUN_a00f1ce4(blk, 0x38))
        FUN_a00f8e2c(blk, 1);
    else if (FUN_a00f1ce4(blk, 0x3a) < FUN_a00f1ce4(blk, 0x38))
        FUN_a00f8e2c(blk, 0xffff);
    else
        FUN_a00f8e2c(blk, 0);
    return 1;
}
