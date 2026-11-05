/* leon2m FUN_a012d554 @ 0xa012d554-0xa012e004 (2736 bytes), flags -mcpu=v8 -O3 -g. Caller: FUN_a0088724.
 * p points to a byte record; p[4] selects the action through a 31-entry jump table (p[4] - 17; values 17, 18, 19,
 * 20, 23, 28, 36, 39, 40, 41, 43, 46, 47 have code, the others do nothing). FGA location = the settings record at
 * 0xA802E1A0 (dev = byte +0x34, addr = 16-bit field +0x35..0x36, sel = byte +0x37) and fga_off(sub) =
 * ((sel <= 1 ? 0x120 : 0x240) & 0x360) + sub, the static helpers of FUN_a012d4f8 / FUN_a012cfac.
 *   17: FUN_a0140e74(dev, addr + u16 0xA802CB78, 0x20, p + 5, 0); 0xA802CB78 += 0x20; byte 0xA802CB10 += p[5 + k]
 *       for k < p[1] - 131; when 0xA802CB78 then equals fga_off(0), one byte 0x78 is written at addr + 0xA802CB78
 *       (FUN_a0140e74 length 1, flag 1) and 0xA802CB78 = 0.
 *   18: 0xA802CB10 += p[6] + p[7] + p[8]; u16 0xA802CB1A = key_index(table 0x1A5198, rows 0..10, key p[9], mask
 *       0x508), u16 0xA802CB18 = key_index(table 0x1A5168, rows 0..11, key p[5], mask 0x92); u16 0xA802CB16 =
 *       CB1A * 9 + CB18 * 3; bytes 0xA802CB20[CB16 + 0..2] = p[6..8]; if p[9] == 0x16, p[6..8] also go to
 *       0xA802E1F0 + 6 / 9 / 0xc / 0xf / 0x12 / 0x15 / 0x21 for p[5] = 0x32 / 0x41 / 0x4b / 0x52 / 0x5d / 0x73 / 0x82.
 *       key_index: the tables are u16 pairs (key, flag bit); the first row whose key equals the key (row last + 1
 *       when none does) gives the flag f; the result is 0xff when f & mask is 0, else the number of mask bits
 *       below the bit of f.
 *   19: FUN_a0105d04(2); FUN_a0103808(0, p[5], p[6], p[7]); print "NVT_FGA_SET_PATTERN ,%d %d %d" of p[5..7].
 *   20: 0xA802CB14 = FUN_a01266b0(), 0xA802CB12 = FUN_a01264e8(), FUN_a012653c(1), FUN_a0143804(0x3ff),
 *       0xA802CB1C = FUN_a00fe47c(), five calls without arguments, byte 0xA802E220 |= 0x40, 0xA802CB10 = 0,
 *       0xA802CB78 = 0xA802CB7A = 0, FUN_a00f6cdc(2), FUN_a00fe44c(CB1C | 0x126), bit 0 of 0xD0013F10 and bit 31 of
 *       0xD0013F50 / F60 / FD0 / FE0 cleared, the FUN_a00f66a4 .. FUN_a00f6d00 call sequence of the listing,
 *       FUN_a0140500(dev), 0xA802E220 &= ~0x20.
 *   23: for k < 18: 0xA802CB10 += p[5 + k] and byte 0xA802CB40[u16 0xA802CB7A + k] = p[5 + k]; then CB7A += 18.
 *   28: 27 bytes of 0xA802CB20 to addr + fga_off(0x10) and 54 bytes of 0xA802CB40 to addr + fga_off(0x30)
 *       (FUN_a0140e74 flag 0), CB78 = CB7A = 0, FUN_a00f67d0(1), FUN_a00f6898(0), FUN_a00f63bc(0),
 *       FUN_a00f6d00(0x540, 0x2f4, 0x480, 0x288).
 *   36: FUN_a0105d04(0), FUN_a00fe44c(CB1C); if (FUN_a01438dc(0) == 1 and FUN_a014ba68()) or FUN_a014bd70(0):
 *       bit 0 of 0xD0013F10 and bit 31 of 0xD0013F50 / F60 / FD0 / FE0 set; then FUN_a00f67d0(2), FUN_a00f63bc(0),
 *       FUN_a00f6d00(0, 0, 0xf00, 0x870), FUN_a012653c(byte 0xA802CB15), FUN_a0126360(CB12), 0xA802E220 bit 0x20
 *       set and bit 0x40 cleared.
 *   39: by p[5]: 0 -> FUN_a0143848((p[8] << 8) + p[7]); 1 -> that value stored low byte first at 0xA802CB78 +
 *       2 * p[6]; 0xfe -> FUN_a01438c8(p[6] != 0); 0xff -> FUN_a0140e74(dev, addr + fga_off(0x70), 0, 0xA802CB78, 0).
 *   40: dev = p[5]. 41: addr = p[5] | p[6] << 8. 43: one byte p[5] to addr + fga_off(0) (FUN_a012d4f8's code).
 *   46 / 47: fixed call sequences (FUN_a012653c(0) / (2) first).
 * Data: 0xA802CB78 is read and written as a u16 (DAT_a802cb78) and, in action 39, as byte pairs indexed by p[6]
 * (ARR_a802cb78); byte 0xA802CB15 is the low byte of the u16 at 0xA802CB14.
 * Source form: the case bodies are written in the order 17, 23, 39, 18, 19, 28, 20, 40, 43, 41, 46, 36, 47 (the jump
 * table fixes the block layout; the source order decides the register names); key_index reads the tables as a
 * flat u16 array (t[i * 2], t[i * 2 + 1]: index-first address sum) and passes the flag to a bit-count helper with an
 * unsigned short value and a short mask (the firmware's copy of the flag and its in-loop mask load); the count is a byte
 * set to 0xff on the no-bit path; action 39 is an if-chain with one call per arm of p[6] == 0 (merged by
 * cross-jumping). Compiler aids: none.
 */
struct FgaLoc { unsigned char dev; unsigned int addr : 16; unsigned char sel; };
struct Rec1a0 { unsigned char a[0x34]; struct FgaLoc fga; unsigned char rest[0x18]; };
extern struct Rec1a0 DAT_a802e1a0;
extern unsigned char DAT_a802e1f0[];
extern unsigned char DAT_a802e220;
extern unsigned char DAT_a802cb10;
extern unsigned short DAT_a802cb12;
extern unsigned short DAT_a802cb14;
extern unsigned char DAT_a802cb15;
extern unsigned short DAT_a802cb16;
extern unsigned short DAT_a802cb18;
extern unsigned short DAT_a802cb1a;
extern unsigned short DAT_a802cb1c;
extern unsigned char DAT_a802cb20[];
extern unsigned char DAT_a802cb40[];
union U16b { unsigned short h; struct { unsigned char lo, hi; } b; };
extern unsigned short DAT_a802cb78;
extern union U16b ARR_a802cb78[];
extern unsigned short DAT_a802cb7a;
extern const unsigned short DAT_001a5168[];
extern const unsigned short DAT_001a5198[];
extern void FUN_a012653c(unsigned char);
extern void FUN_a0126360(unsigned short);
extern void FUN_a0143804(unsigned short);
extern void FUN_a00f67d0(int);
extern void FUN_a00f6898(unsigned int);
extern void FUN_a00f63bc(unsigned int);
extern void FUN_a00f6d00(unsigned short, unsigned short, unsigned short, unsigned short);
extern void FUN_a00f6b34(unsigned int);
extern void FUN_a00f6e88(unsigned char);
extern void FUN_a00f6ecc(unsigned char);
extern void FUN_a00f6f10(unsigned char);
extern void FUN_a0105d04(unsigned char);
extern void FUN_a00fe44c(unsigned short);
extern unsigned short FUN_a00fe47c(void);
extern unsigned char FUN_a01438dc(int);
extern unsigned char FUN_a014bd70(int);
extern unsigned char FUN_a014ba68(void);
extern unsigned short FUN_a01266b0(void);
extern unsigned short FUN_a01264e8(void);
extern void FUN_a010ae70(void);
extern void FUN_a010af50(void);
extern void FUN_a010afc8(void);
extern void FUN_a010b198(void);
extern void FUN_a00f6c6c(void);
extern void FUN_a00f6ca4(void);
extern void FUN_a00f6cdc(unsigned char);
extern void FUN_a00f66a4(unsigned int);
extern void FUN_a0140500(unsigned char);
extern void FUN_a0103808(int, int, int, int);
extern void FUN_a01438c8(unsigned char);
extern void FUN_a0143848(unsigned short);
extern int FUN_a00df170(const char *, ...);
extern void FUN_a0140e74(unsigned char, unsigned short, unsigned short, void *, unsigned char);

#define REG(a) (*(volatile unsigned int *)(a))

static unsigned short fga_off(unsigned short sub)
{
    unsigned short o;
    if (DAT_a802e1a0.fga.sel <= 1)
        o = 0x120;
    else
        o = 0x240;
    return (o & 0x360) + sub;
}

static void fga_wr1(unsigned char v)
{
    FUN_a0140e74(DAT_a802e1a0.fga.dev, DAT_a802e1a0.fga.addr + fga_off(0), 1, &v, 1);
}

static unsigned char bitpos(unsigned short f, short mask)
{
    unsigned char b, c;

    c = 0;
    if (!(f & mask))
        c = 0xff;
    else
        for (b = 0; (f >> b) != 1; b++)
            if ((mask >> b) & 1)
                c++;
    return c;
}

static unsigned char key_index(const unsigned short *t, unsigned char last, unsigned char key, unsigned short mask)
{
    unsigned char i;

    for (i = 0; i <= last; i++)
        if (key == t[i * 2])
            break;
    return bitpos(t[i * 2 + 1], mask);
}

void FUN_a012d554(unsigned char *p)
{
    unsigned short k;

    switch (p[4]) {
    case 17:
        FUN_a0140e74(DAT_a802e1a0.fga.dev, DAT_a802e1a0.fga.addr + DAT_a802cb78, 0x20, p + 5, 0);
        DAT_a802cb78 += 0x20;
        for (k = 0; k < p[1] - 131; k++)
            DAT_a802cb10 += p[5 + k];
        if (DAT_a802cb78 == fga_off(0)) {
            unsigned char v = 0x78;
            FUN_a0140e74(DAT_a802e1a0.fga.dev, DAT_a802e1a0.fga.addr + DAT_a802cb78, 1, &v, 1);
            DAT_a802cb78 = 0;
        }
        break;
    case 23:
        for (k = 0; k < 18; k++) {
            DAT_a802cb10 += p[5 + k];
            DAT_a802cb40[DAT_a802cb7a + k] = p[5 + k];
        }
        DAT_a802cb7a += 18;
        break;
    case 39:
        if (p[5] == 0)
            FUN_a0143848((p[8] << 8) + p[7]);
        else if (p[5] == 1) {
            k = (p[8] << 8) + p[7];
            ARR_a802cb78[p[6]].b.lo = k;
            ARR_a802cb78[p[6]].b.hi = k >> 8;
        } else if (p[5] == 0xfe) {
            if (p[6] == 0)
                FUN_a01438c8(0);
            else
                FUN_a01438c8(1);
        } else if (p[5] == 0xff)
            FUN_a0140e74(DAT_a802e1a0.fga.dev, DAT_a802e1a0.fga.addr + fga_off(0x70), 0, &DAT_a802cb78, 0);
        break;
    case 18:
        DAT_a802cb10 += p[6] + p[7] + p[8];
        DAT_a802cb1a = key_index(DAT_001a5198, 10, p[9], 0x508);
        DAT_a802cb18 = key_index(DAT_001a5168, 11, p[5], 0x92);
        DAT_a802cb16 = DAT_a802cb1a * 9 + DAT_a802cb18 * 3;
        for (k = 0; k < 3; k++)
            DAT_a802cb20[DAT_a802cb16 + k] = p[6 + k];
        if (p[9] == 0x16) {
            switch (p[5]) {
            case 0x32: DAT_a802e1f0[6] = p[6]; DAT_a802e1f0[7] = p[7]; DAT_a802e1f0[8] = p[8]; break;
            case 0x41: DAT_a802e1f0[9] = p[6]; DAT_a802e1f0[0xa] = p[7]; DAT_a802e1f0[0xb] = p[8]; break;
            case 0x4b: DAT_a802e1f0[0xc] = p[6]; DAT_a802e1f0[0xd] = p[7]; DAT_a802e1f0[0xe] = p[8]; break;
            case 0x52: DAT_a802e1f0[0xf] = p[6]; DAT_a802e1f0[0x10] = p[7]; DAT_a802e1f0[0x11] = p[8]; break;
            case 0x5d: DAT_a802e1f0[0x12] = p[6]; DAT_a802e1f0[0x13] = p[7]; DAT_a802e1f0[0x14] = p[8]; break;
            case 0x73: DAT_a802e1f0[0x15] = p[6]; DAT_a802e1f0[0x16] = p[7]; DAT_a802e1f0[0x17] = p[8]; break;
            case 0x82: DAT_a802e1f0[0x21] = p[6]; DAT_a802e1f0[0x22] = p[7]; DAT_a802e1f0[0x23] = p[8]; break;
            }
        }
        break;
    case 19:
        FUN_a0105d04(2);
        FUN_a0103808(0, p[5], p[6], p[7]);
        FUN_a00df170("NVT_FGA_SET_PATTERN ,%d %d %d\r\n", p[5], p[6], p[7]);
        break;
    case 28:
        FUN_a0140e74(DAT_a802e1a0.fga.dev, DAT_a802e1a0.fga.addr + fga_off(0x10), 0x1b, DAT_a802cb20, 0);
        FUN_a0140e74(DAT_a802e1a0.fga.dev, DAT_a802e1a0.fga.addr + fga_off(0x30), 0x36, DAT_a802cb40, 0);
        DAT_a802cb78 = 0;
        DAT_a802cb7a = 0;
        FUN_a00f67d0(1);
        FUN_a00f6898(0);
        FUN_a00f63bc(0);
        FUN_a00f6d00(0x540, 0x2f4, 0x480, 0x288);
        break;
    case 20:
        DAT_a802cb14 = FUN_a01266b0();
        DAT_a802cb12 = FUN_a01264e8();
        FUN_a012653c(1);
        FUN_a0143804(0x3ff);
        DAT_a802cb1c = FUN_a00fe47c();
        FUN_a010ae70();
        FUN_a010af50();
        FUN_a010afc8();
        FUN_a010b198();
        FUN_a00f6c6c();
        FUN_a00f6ca4();
        DAT_a802e220 |= 0x40;
        DAT_a802cb10 = 0;
        DAT_a802cb78 = 0;
        DAT_a802cb7a = 0;
        FUN_a00f6cdc(2);
        FUN_a00fe44c(DAT_a802cb1c | 0x126);
        REG(0xd0013f10) &= ~1;
        REG(0xd0013f50) &= 0x7fffffff;
        REG(0xd0013f60) &= 0x7fffffff;
        REG(0xd0013fd0) &= 0x7fffffff;
        REG(0xd0013fe0) &= 0x7fffffff;
        FUN_a00f66a4(0xff);
        FUN_a00f67d0(0);
        FUN_a00f6898(2);
        FUN_a00f63bc(2);
        FUN_a00f6d00(0, 0, 0xf00, 0x870);
        FUN_a00f6b34(2);
        FUN_a00f6e88(0);
        FUN_a00f6ecc(0);
        FUN_a00f6f10(0);
        FUN_a00f6898(1);
        FUN_a00f63bc(1);
        FUN_a00f6d00(0x540, 0x2f4, 0x480, 0x288);
        FUN_a0143804(0x3ff);
        FUN_a0140500(DAT_a802e1a0.fga.dev);
        DAT_a802e220 &= ~0x20;
        break;
    case 40:
        DAT_a802e1a0.fga.dev = p[5];
        break;
    case 43:
        fga_wr1(p[5]);
        break;
    case 41:
        DAT_a802e1a0.fga.addr = p[5] | p[6] << 8;
        break;
    case 46:
        FUN_a012653c(0);
        FUN_a0143804(0x3ff);
        FUN_a00f67d0(0);
        FUN_a00f6898(2);
        FUN_a00f63bc(2);
        FUN_a00f6d00(0, 0, 0xf00, 0x870);
        FUN_a00f6b34(2);
        FUN_a00f6e88(0);
        FUN_a00f6ecc(0);
        FUN_a00f6f10(0);
        FUN_a00f6898(1);
        FUN_a00f63bc(1);
        FUN_a00f6d00(0x63a, 0x380, 0x28d, 0x16f);
        break;
    case 36:
        FUN_a0105d04(0);
        FUN_a00fe44c(DAT_a802cb1c);
        if ((FUN_a01438dc(0) == 1 && FUN_a014ba68()) || FUN_a014bd70(0)) {
            REG(0xd0013f10) |= 1;
            REG(0xd0013f50) |= 0x80000000;
            REG(0xd0013f60) |= 0x80000000;
            REG(0xd0013fd0) |= 0x80000000;
            REG(0xd0013fe0) |= 0x80000000;
        }
        FUN_a00f67d0(2);
        FUN_a00f63bc(0);
        FUN_a00f6d00(0, 0, 0xf00, 0x870);
        FUN_a012653c(DAT_a802cb15);
        FUN_a0126360(DAT_a802cb12);
        DAT_a802e220 = (DAT_a802e220 | 0x20) & ~0x40;
        break;
    case 47:
        FUN_a012653c(2);
        FUN_a0126360(DAT_a802cb12);
        break;
    }
}
