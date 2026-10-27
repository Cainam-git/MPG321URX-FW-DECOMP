/* FUN_a0085b80 (leon2s 0xa0085b80-0xa0085dcc, 588 bytes), flags -mcpu=v8 -Os -g. Called by FUN_a0085ea8.
 * void (unsigned char port). For port 0 and for any other port the same register sequence through
 * FUN_a00a7940 / FUN_a00a78fc: mask 0x20 of 0x72 and 0x80 of 0x75 set, 0x1e to register 2, register 3 = bit 6 of
 * its old value | 0x84, the two written values 0x1e / 0x84 kept in DAT_a807cd68[0..1] (port 0) or
 * DAT_a807cd00[0..1] (other ports), 0xfe to 0x71, masks of 1 / 0x76 / 0x18 / 0x6d set. Port 0 also writes the
 * registers 0xcf018e80..0xcf018ed4 (0x84 to ea8, 0x13 to e80, bit 0 of eb0 set, bits 4..6 of e84 cleared then
 * bit 2 set, 5 to e8c, 0x38 to eac, 0x30 to ed0, 0xaa to ed4) and sets mask 0x10 of 0x7d. Ends with
 * FUN_a0085914(port).
 * DAT_a807cd00 and DAT_a807cd68 are declared volatile as in their other matched users (FUN_a0085830,
 * FUN_a0085888, FUN_a00866e0, FUN_a00883d0, FUN_a0086c48).
 */
#define R8E80 (*(volatile unsigned int *)0xcf018e80)
#define R8E84 (*(volatile unsigned int *)0xcf018e84)
#define R8E8C (*(volatile unsigned int *)0xcf018e8c)
#define R8EA8 (*(volatile unsigned int *)0xcf018ea8)
#define R8EAC (*(volatile unsigned int *)0xcf018eac)
#define R8EB0 (*(volatile unsigned int *)0xcf018eb0)
#define R8ED0 (*(volatile unsigned int *)0xcf018ed0)
#define R8ED4 (*(volatile unsigned int *)0xcf018ed4)

extern volatile unsigned char DAT_a807cd68[];
extern volatile unsigned char DAT_a807cd00[];
extern void FUN_a00a7940(unsigned int port, short reg, unsigned int mask, unsigned int mode);
extern void FUN_a00a78fc(unsigned int, unsigned short, unsigned int);
extern unsigned int FUN_a00a78b4(unsigned int, unsigned short);
extern void FUN_a0085914(unsigned char);

void FUN_a0085b80(unsigned char port)
{
    if (port == 0) {
        FUN_a00a7940(0, 0x72, 0x20, 1);
        FUN_a00a7940(0, 0x75, 0x80, 1);
        FUN_a00a78fc(0, 2, 0x1e);
        FUN_a00a78fc(0, 3, (unsigned char)((FUN_a00a78b4(0, 3) & 0x40) | 0x84));
        DAT_a807cd68[0] = 0x1e;
        DAT_a807cd68[1] = 0x84;
        FUN_a00a78fc(0, 0x71, 0xfe);
        FUN_a00a7940(0, 1, 0x20, 1);
        FUN_a00a7940(0, 0x76, 4, 1);
        FUN_a00a7940(0, 0x18, 0x11, 1);
        FUN_a00a7940(0, 0x6d, 0x80, 1);
        R8EA8 = 0x84;
        R8E80 = 0x13;
        R8EB0 |= 1;
        R8E84 &= ~0x70;
        R8E84 |= 4;
        R8E8C = 5;
        R8EAC = 0x38;
        R8ED0 = 0x30;
        R8ED4 = 0xaa;
        FUN_a00a7940(0, 0x7d, 0x10, 1);
    } else {
        FUN_a00a7940(port, 0x72, 0x20, 1);
        FUN_a00a7940(port, 0x75, 0x80, 1);
        FUN_a00a78fc(port, 2, 0x1e);
        FUN_a00a78fc(port, 3, (unsigned char)((FUN_a00a78b4(port, 3) & 0x40) | 0x84));
        DAT_a807cd00[0] = 0x1e;
        DAT_a807cd00[1] = 0x84;
        FUN_a00a78fc(port, 0x71, 0xfe);
        FUN_a00a7940(port, 1, 0x20, 1);
        FUN_a00a7940(port, 0x76, 4, 1);
        FUN_a00a7940(port, 0x18, 0x11, 1);
        FUN_a00a7940(port, 0x6d, 0x80, 1);
    }
    FUN_a0085914(port);
}
