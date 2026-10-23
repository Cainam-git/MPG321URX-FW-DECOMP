/* MODEDET_handler_2 (leon2s 0xa009d87c-0xa009dd40, 1220 bytes), flags -mcpu=v8 -Os -g.
 * Arguments: port (low byte p, 0 or 1; other values return at once) and mode. bits[4] = {8, 10, 12, 16} is a
 * local copy of the ROM table 0xa00b44fc (memcpy FUN_a00b15d8). sel = 2 / 3 and k = 0 / 1 for port 0 / 1.
 * DAT_a807db00 holds 0x34-byte port records whose words +0 and +4 point to register blocks r0 and r4.
 * Bits 5..6 of r4[0x11] both set: sets bit 6 (port 0) or 7 (port 1) of 0xcf011640, else clears it.
 * FUN_a00a7408(0xb, r0 + 2) != 0: FUN_a00b1d00(sel, 0x80, 0x50 / 0x60 / 0x80 for mode 5 / 6 / 7, else 0x40);
 * otherwise FUN_a00b1d00(sel, 0x80, 0x40).
 * FUN_a00a7408(0x14, r0 + 0x21) == 0: mode 5 / 6 / 7: FUN_a00a73d4(0xd, r0 + 0x10), print "Set PLL 10 / 12 /
 * 16 bits Mode" (bit 2 of _DAT_a8078634), then FUN_a008d800() > 0x81 gives FUN_a00a1f84(p, mode) and
 * FUN_a00a2010(p, 1), else FUN_a00b1d00(k, 0xc0, 0xf0 / 0x120 / 0x180). Other modes: when FUN_a00a03c8(p)
 * is 1, FUN_a00a73d4(2, r0 + 0x2d) and bits 8..11 of r0[0x11] = 4; FUN_a00a73ac(0xd, r0 + 0x10); the same
 * FUN_a008d800 test with code 4 / FUN_a00a2010(p, 0) or FUN_a00b1d00(k, 0xc0, 0xc0); print "Set PLL 8 bits
 * Mode".
 * Otherwise: FUN_a00a73d4(0xd, r0 + 0x10), FUN_a00a7488(sel, 0x1f08, 0xfffffff8, mode 5..7 or 4), print
 * "Use Internal PLL".
 * End: byte +0x19 of the 400-byte record ARR_a807d7e0[p] = bits[mode - 4] for mode 4..7, else 8.
 * Source forms: the two port tests on 0xcf011640 are switches; the defaults of the mode switches come first;
 * the final record index is a second unsigned char copy of the parameter (the firmware re-extends it there).
 * Compiler aid: the repeated 'sel2 = sel;' emits no instructions; with a single copy GCC replaces the copy
 * with the constant 2, the firmware keeps 'mov %l3, %l0'.
 */
#define R1640 (*(volatile unsigned int *)0xcf011640)

struct port_rec {
    volatile unsigned int *r0;
    volatile unsigned int *r4;
    unsigned char _08[0x34 - 8];
};
extern struct port_rec DAT_a807db00[];
extern unsigned char ARR_a807d7e0[];
extern unsigned int _DAT_a8078634;
extern void *memcpy(void *, const void *, unsigned int) __asm__("FUN_a00b15d8");
extern int FUN_a0073044(const char *, ...);
extern unsigned int FUN_a00a7408(unsigned int, volatile unsigned int *);
extern void FUN_a00b1d00(unsigned char sel, unsigned int a, unsigned int b);
extern unsigned char FUN_a00a03c8(unsigned char port);
extern void FUN_a00a73d4(unsigned int bit, volatile unsigned int *p);
extern void FUN_a00a73ac(unsigned int bit, volatile unsigned int *p);
extern unsigned char FUN_a008d800(void);
extern void FUN_a00a1f84(unsigned char sel, unsigned char code);
extern void FUN_a00a2010(unsigned char sel, unsigned char v);
extern void FUN_a00a7488(unsigned char port, unsigned short reg, unsigned int mask, unsigned int v);

void MODEDET_handler_2(unsigned int arg, unsigned int mode)
{
    unsigned int bits[4] = {8, 10, 12, 16};
    unsigned char p = arg;
    unsigned char sel = 2;
    unsigned char sel2;
    unsigned char k = 0;
    unsigned char q;

    sel2 = sel;
    sel2 = sel; /* compiler aid, see the header */
    if (p != 0) {
        if (p != 1)
            return;
        sel = 3;
        k = 1;
        sel2 = sel;
    }
    if ((DAT_a807db00[p].r4[0x11] & 0x60) == 0x60) {
        switch (p) {
        case 0:
            R1640 |= 0x40;
            break;
        case 1:
            R1640 |= 0x80;
            break;
        }
    } else {
        switch (p) {
        case 0:
            R1640 &= ~0x40;
            break;
        case 1:
            R1640 &= ~0x80;
            break;
        }
    }
    if (FUN_a00a7408(0xb, DAT_a807db00[p].r0 + 2) != 0) {
        switch (mode) {
        case 5:
            FUN_a00b1d00(sel2, 0x80, 0x50);
            break;
        case 6:
            FUN_a00b1d00(sel2, 0x80, 0x60);
            break;
        case 7:
            FUN_a00b1d00(sel2, 0x80, 0x80);
            break;
        default:
            FUN_a00b1d00(sel2, 0x80, 0x40);
            break;
        }
    } else {
        FUN_a00b1d00(sel2, 0x80, 0x40);
    }
    if (FUN_a00a7408(0x14, DAT_a807db00[p].r0 + 0x21) == 0) {
        switch (mode) {
        default:
            if (FUN_a00a03c8(p) == 1) {
                FUN_a00a73d4(2, DAT_a807db00[p].r0 + 0x2d);
                DAT_a807db00[p].r0[0x11] = (DAT_a807db00[p].r0[0x11] & ~0xf00) | 0x400;
            }
            FUN_a00a73ac(0xd, DAT_a807db00[p].r0 + 0x10);
            if (FUN_a008d800() > 0x81) {
                FUN_a00a1f84(p, 4);
                FUN_a00a2010(p, 0);
            } else {
                FUN_a00b1d00(k, 0xc0, 0xc0);
            }
            if ((_DAT_a8078634 & 4) != 0)
                FUN_a0073044("[MODEDET]: Port%c Set PLL 8 bits Mode\n", (char)(arg + 'A'));
            break;
        case 5:
            FUN_a00a73d4(0xd, DAT_a807db00[p].r0 + 0x10);
            if ((_DAT_a8078634 & 4) != 0)
                FUN_a0073044("[MODEDET]: Port%c Set PLL 10 bits Mode\n", (char)(arg + 'A'));
            if (FUN_a008d800() > 0x81) {
                FUN_a00a1f84(p, 5);
                FUN_a00a2010(p, 1);
            } else {
                FUN_a00b1d00(k, 0xc0, 0xf0);
            }
            break;
        case 6:
            FUN_a00a73d4(0xd, DAT_a807db00[p].r0 + 0x10);
            if ((_DAT_a8078634 & 4) != 0)
                FUN_a0073044("[MODEDET]: Port%c Set PLL 12 bits Mode\n", (char)(arg + 'A'));
            if (FUN_a008d800() > 0x81) {
                FUN_a00a1f84(p, 6);
                FUN_a00a2010(p, 1);
            } else {
                FUN_a00b1d00(k, 0xc0, 0x120);
            }
            break;
        case 7:
            FUN_a00a73d4(0xd, DAT_a807db00[p].r0 + 0x10);
            if ((_DAT_a8078634 & 4) != 0)
                FUN_a0073044("[MODEDET]: Port%c Set PLL 16 bits Mode\n", (char)(arg + 'A'));
            if (FUN_a008d800() > 0x81) {
                FUN_a00a1f84(p, 7);
                FUN_a00a2010(p, 1);
            } else {
                FUN_a00b1d00(k, 0xc0, 0x180);
            }
            break;
        }
    } else {
        FUN_a00a73d4(0xd, DAT_a807db00[p].r0 + 0x10);
        switch (mode) {
        default:
            FUN_a00a7488(sel, 0x1f08, 0xfffffff8, 4);
            break;
        case 5:
            FUN_a00a7488(sel, 0x1f08, 0xfffffff8, 5);
            break;
        case 6:
            FUN_a00a7488(sel, 0x1f08, 0xfffffff8, 6);
            break;
        case 7:
            FUN_a00a7488(sel, 0x1f08, 0xfffffff8, 7);
            break;
        }
        if ((_DAT_a8078634 & 4) != 0)
            FUN_a0073044("[MODEDET]: Port%c Use Internal PLL\n", (char)(arg + 'A'));
    }
    q = arg;
    if (mode >= 4 && mode <= 7)
        ARR_a807d7e0[q * 400 + 0x19] = bits[mode - 4];
    else
        ARR_a807d7e0[q * 400 + 0x19] = 8;
}
