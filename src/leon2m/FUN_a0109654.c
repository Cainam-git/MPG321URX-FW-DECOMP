/* leon2m FUN_a0109654 @ 0xa0109654-0xa010983c (122 words).
 * on 0: clears the registers 0xcf00f500 and 0xcf00f580. Otherwise for sel 0 the block at 0xcf00f500, else the
 * block at 0xcf00f580: after a 1 ms delay (func_0x4008d1a0) writes 0x40 then 0x80 to +0, 0x20 to +4, +8, +0xc,
 * 0 to +0x10, +0x14, 0xc6 / 0xc8 to +0x18, 0 to +0x1c..+0x24, 0xc8 / 0xca to +0x28, 0 to +0x2c, the four bytes of
 * v (low first) to +0x30..+0x3c, 0x80 to +0x60 and 1 to +0x64; after another 1 ms delay 0x40 then 0x80 to +0.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern void func_0x4008d1a0(int ms);

void FUN_a0109654(unsigned char sel, unsigned int v, unsigned char on)
{
    if (on) {
        if (sel != 0) {
            func_0x4008d1a0(1);
            R(0xcf00f580) = 0x40;
            R(0xcf00f580) = 0x80;
            R(0xcf00f584) = 0x20;
            R(0xcf00f588) = 0x20;
            R(0xcf00f58c) = 0x20;
            R(0xcf00f590) = 0;
            R(0xcf00f594) = 0;
            R(0xcf00f598) = 0xc8;
            R(0xcf00f59c) = 0;
            R(0xcf00f5a0) = 0;
            R(0xcf00f5a4) = 0;
            R(0xcf00f5a8) = 0xca;
            R(0xcf00f5ac) = 0;
            R(0xcf00f5b0) = v & 0xff;
            R(0xcf00f5b4) = (v >> 8) & 0xff;
            R(0xcf00f5b8) = (v >> 16) & 0xff;
            R(0xcf00f5bc) = v >> 24;
            R(0xcf00f5e0) = 0x80;
            R(0xcf00f5e4) = 1;
            func_0x4008d1a0(1);
            R(0xcf00f580) = 0x40;
            R(0xcf00f580) = 0x80;
        } else {
            func_0x4008d1a0(1);
            R(0xcf00f500) = 0x40;
            R(0xcf00f500) = 0x80;
            R(0xcf00f504) = 0x20;
            R(0xcf00f508) = 0x20;
            R(0xcf00f50c) = 0x20;
            R(0xcf00f510) = 0;
            R(0xcf00f514) = 0;
            R(0xcf00f518) = 0xc6;
            R(0xcf00f51c) = 0;
            R(0xcf00f520) = 0;
            R(0xcf00f524) = 0;
            R(0xcf00f528) = 0xc8;
            R(0xcf00f52c) = 0;
            R(0xcf00f530) = v & 0xff;
            R(0xcf00f534) = (v >> 8) & 0xff;
            R(0xcf00f538) = (v >> 16) & 0xff;
            R(0xcf00f53c) = v >> 24;
            R(0xcf00f560) = 0x80;
            R(0xcf00f564) = 1;
            func_0x4008d1a0(1);
            R(0xcf00f500) = 0x40;
            R(0xcf00f500) = 0x80;
        }
    } else {
        R(0xcf00f500) = 0;
        R(0xcf00f580) = 0;
    }
}
