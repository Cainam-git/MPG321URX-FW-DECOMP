/* DRV_HDMI_Config_BCH (leon2s 0xa009c5b4-0xa009c6e4, 304 bytes), flags -mcpu=v8 -Os -g.
 * h = halfword +8 of the 0x18-byte record ARR_a807cc64[port]. Under bit 1 of _DAT_a8078634 prints
 * "[EQ]: Port%c %s \n" with 'A' + port and the function name. When en != 0 and h > 100: prints the
 * "capture SCDC ERROR ==>Enable BCH" message under the same bit and, through the register-block pointer in
 * word 0 of the 0x34-byte record ARR_a807db00[port], sets the top byte of register +0xc0 to 5, clears the low
 * byte of +0xc4 and sets the low 5 bits of +0xbc. Otherwise sets the top byte of +0xc0 to 0x50, clears the
 * low byte of +0xc4 and sets the low 5 bits of +0xbc to 1. The register block is volatile (hardware).
 * Source form: h is an unsigned int; the register pointer is a block-local variable in each arm.
 */
struct sel_rec {
    unsigned char b[8];
    unsigned short h8;
    unsigned char _a[0x18 - 0xa];
};
struct Port34 { volatile unsigned int *regs; unsigned char rest[0x34 - 4]; };
extern struct sel_rec ARR_a807cc64[];
extern struct Port34 ARR_a807db00[];
extern unsigned int _DAT_a8078634;
extern int FUN_a0073044(const char *, ...);
static const char fn_[] = "DRV_HDMI_Config_BCH";

void DRV_HDMI_Config_BCH(unsigned char port, unsigned char en)
{
    unsigned int h = ARR_a807cc64[port].h8;

    if (_DAT_a8078634 & 2)
        FUN_a0073044("[EQ]: Port%c %s \n", (char)(port + 'A'), fn_);
    if (en != 0 && h > 100) {
        if (_DAT_a8078634 & 2)
            FUN_a0073044("[EQ]: \x1b[1mPort%c capture SCDC ERROR ==>Enable BCH \n\x1b[m", (char)(port + 'A'));
        volatile unsigned int *r = ARR_a807db00[port].regs;

        r[0xc0 / 4] = (r[0xc0 / 4] & ~0xff000000) | 0x05000000;
        r[0xc4 / 4] &= ~0xff;
        r[0xbc / 4] |= 0x1f;
    } else {
        volatile unsigned int *r = ARR_a807db00[port].regs;

        r[0xc0 / 4] = (r[0xc0 / 4] & ~0xff000000) | 0x50000000;
        r[0xc4 / 4] &= ~0xff;
        r[0xbc / 4] = (r[0xbc / 4] & ~0x1f) | 1;
    }
}
