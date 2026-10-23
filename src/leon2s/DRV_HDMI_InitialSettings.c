/* leon2s DRV_HDMI_InitialSettings @ 0xa0073c44-0xa0074bf8 (4020 bytes), flags -mcpu=v8 -Os -g.
 * No parameters, no return value. With bit 0 of _DAT_a8078634 set it prints DAT_a0066838 with the function
 * name, then s_a0066848 ("[INIT] EQ V2.2") when DAT_a807619f is non-zero, else s_a0066860 ("[INIT] EQ V1.0").
 * Sets bits 0..1 of the register 0xcf011514 and bit 0 of PHY register 0x3534 on pages 2 and 3, writes the low
 * bytes of 0x1000 (0xf9) and 0x1f04 (0x5f) on pages 0..3, then runs one loop over the ports i = 0..3:
 * r = FUN_a0073520(i) (non-zero for ports 2 and 3) selects the extra writes to the 0x2c.. / 0x36.. registers.
 * Each port has a byte record (port 0 DAT_a807d299, 1 DAT_a807d2a9, 2 DAT_a807d2b9, 3 DAT_a807d2e9); byte 0
 * == 0xa0 marks a loaded record (debug prints "EFUSE Load" s_a0066878 / s_a00668d8, else "Manual Load"
 * s_a00668a8 / s_a0066908). Ports 0 and 1 take byte 3 into 0x1c08 bits 0..7 and bytes 0xd..0xf into bits
 * 16..23 of 0x103c/0x143c/0x183c (defaults 9 and 0x10). Ports 2 and 3 copy bytes 0x10..0x12 and 0x10..0x23 of
 * the record (or 0x10 each) into six zero-initialised local byte arrays and write them to the 0x1c08/0x2c08,
 * 0x103c..0x303c, 0x2054.., 0x2068.. and 0x2070.. registers (5-bit fields at bit 11 or bit 3).
 * The Z50 step reads bits 28..30 of 0x1100 when FUN_a00a7468(0x18, i, 0x1100) returns 0 (else uses 4) and
 * writes them to bits 4..6 of 0x1c04 (and 0x2c04 when r). Then the 0x1f44/0x1c00/0x1000/0x3608 settings,
 * page-0 settings, FUN_a00b15ac clears of ARR_a807ccc4[i] (12 bytes), ARR_a807a9f0[i] (0x898 bytes) and
 * DAT_a807cc64[i] (0x18 bytes), the 0x2c20..0x2c38 settings when r, and FUN_a0073c24(i, 1). After the loop
 * it prints s_a00669f0 with 0x378.
 * Source form: u8 loop counter (the firmware re-extends it at several joins), the port-3 record chosen in an
 * if/else chain followed by 'i < 2' (jump threading gives the firmware's compare chain), byte arrays declared
 * with '= {0}' inside the ports 2/3 branch, and byte 3 of the record read before byte 0x10 there.
 */
#define REG_CF011514 (*(volatile unsigned int *)0xcf011514)
struct Rec12 { unsigned int w0; unsigned int w4; unsigned char b8; unsigned char pad[3]; };
struct Rec24 { unsigned char b[0x18]; };
extern struct Rec12 ARR_a807ccc4[];
extern struct Rec24 DAT_a807cc64[];
extern unsigned char ARR_a807a9f0[][0x898];
extern unsigned int _DAT_a8078634;
extern unsigned char DAT_a807619f;
extern unsigned char DAT_a807d299[], DAT_a807d2a9[], DAT_a807d2b9[], DAT_a807d2e9[];
extern char DAT_a0066838[], s_a0066848[], s_a0066860[], s_a0066878[], s_a00668a8[], s_a00668d8[],
    s_a0066908[], s_a0066938[], s_a0066968[], s_a0066998[], s_a00669c8[], s_a00669f0[];
extern int FUN_a0073044(const void *, ...);
extern int FUN_a00734c4(const char *);
extern unsigned char FUN_a0073520(unsigned char);
extern void FUN_a0073738(unsigned char);
extern void FUN_a0073c24(unsigned int, unsigned char);
extern unsigned int FUN_a00a7314(unsigned int, unsigned short);
extern void FUN_a00a7424(int, unsigned int, unsigned char, unsigned short);
extern unsigned int FUN_a00a7468(unsigned int, unsigned char, unsigned short);
extern void FUN_a00a7488(unsigned int, unsigned short, unsigned int, unsigned int);
extern void FUN_a00b1794(unsigned short);
extern void *FUN_a00b15ac(void *, int, unsigned int);

void DRV_HDMI_InitialSettings(void)
{
    unsigned char i;
    unsigned char r;
    unsigned char *p;
    unsigned char v;
    unsigned char z;

    if ((_DAT_a8078634 & 1) != 0)
        FUN_a0073044(DAT_a0066838, "DRV_HDMI_InitialSettings");
    if (DAT_a807619f != 0) {
        if ((_DAT_a8078634 & 1) != 0)
            FUN_a00734c4(s_a0066848);
    } else {
        if ((_DAT_a8078634 & 1) != 0)
            FUN_a00734c4(s_a0066860);
    }
    REG_CF011514 |= 3;
    FUN_a00a7424(1, 0, 2, 0x3534);
    FUN_a00a7424(1, 0, 3, 0x3534);
    for (i = 0; i < 4; i++) {
        FUN_a00a7488(i, 0x1000, 0xffffff00, 0xf9);
        FUN_a00a7488(i, 0x1f04, 0xffffff00, 0x5f);
    }
    for (i = 0; i < 4; i++) {
        r = FUN_a0073520(i);
        if (r) {
            FUN_a00a7424(1, 0x10, i, 0x361c);
            FUN_a00a7424(1, 0x11, i, 0x361c);
            FUN_a00a7424(1, 0x12, i, 0x361c);
            FUN_a00a7488(i, 0x361c, 0xff8fffff, 0x600000);
        }
        FUN_a00a7488(0, 0x1104, 0xfcffffff, 0x3000000);
        if (i == 0)
            p = DAT_a807d299;
        else if (i == 1)
            p = DAT_a807d2a9;
        else if (i == 2)
            p = DAT_a807d2b9;
        else
            p = DAT_a807d2e9;
        if (i < 2) {
            if (p[0] == 0xa0) {
                if ((_DAT_a8078634 & 1) != 0)
                    FUN_a0073044(s_a0066878, (char)(i + 'A'));
                v = p[3];
                FUN_a00a7488(i, 0x1c08, 0xffffff, 0x60000000);
                FUN_a00a7488(i, 0x1c08, 0xffffff00, v);
                FUN_a00a7488(i, 0x103c, 0xffff, p[0xd] << 16 | 0x1f000000);
                FUN_a00a7488(i, 0x143c, 0xffff, p[0xe] << 16 | 0x1f000000);
                FUN_a00a7488(i, 0x183c, 0xffff, p[0xf] << 16 | 0x1f000000);
            } else {
                if ((_DAT_a8078634 & 1) != 0)
                    FUN_a0073044(s_a00668a8, (char)(i + 'A'));
                FUN_a00a7488(i, 0x1c08, 0xffffff, 0x60000000);
                FUN_a00a7488(i, 0x1c08, 0xffffff00, 9);
                FUN_a00a7488(i, 0x103c, 0xffff, 0x1f100000);
                FUN_a00a7488(i, 0x143c, 0xffff, 0x1f100000);
                FUN_a00a7488(i, 0x183c, 0xffff, 0x1f100000);
            }
        } else {
            unsigned char a[3] = {0};
            unsigned char b0[4] = {0};
            unsigned char b1[4] = {0};
            unsigned char b2[4] = {0};
            unsigned char b3[4] = {0};
            unsigned char b4[4] = {0};

            if (p[0] == 0xa0) {
                if ((_DAT_a8078634 & 1) != 0)
                    FUN_a0073044(s_a00668d8, (char)(i + 'A'));
                v = p[3];
                a[0] = p[0x10];
                a[1] = p[0x11];
                a[2] = p[0x12];
                b0[0] = p[0x10];
                b0[1] = p[0x11];
                b0[2] = p[0x12];
                b0[3] = p[0x13];
                b1[0] = p[0x14];
                b1[1] = p[0x15];
                b1[2] = p[0x16];
                b1[3] = p[0x17];
                b2[0] = p[0x18];
                b2[1] = p[0x19];
                b2[2] = p[0x1a];
                b2[3] = p[0x1b];
                b3[0] = p[0x1c];
                b3[1] = p[0x1d];
                b3[2] = p[0x1e];
                b3[3] = p[0x1f];
                b4[0] = p[0x20];
                b4[1] = p[0x21];
                b4[2] = p[0x22];
                b4[3] = p[0x23];
            } else {
                if ((_DAT_a8078634 & 1) != 0)
                    FUN_a0073044(s_a0066908, (char)(i + 'A'));
                a[0] = 0x10;
                a[1] = 0x10;
                a[2] = 0x10;
                b0[0] = 0x10;
                b0[1] = 0x10;
                b0[2] = 0x10;
                b0[3] = 0x10;
                b1[0] = 0x10;
                b1[1] = 0x10;
                b1[2] = 0x10;
                b1[3] = 0x10;
                b2[0] = 0x10;
                b2[1] = 0x10;
                b2[2] = 0x10;
                b2[3] = 0x10;
                b3[0] = 0x10;
                b3[1] = 0x10;
                b3[2] = 0x10;
                b3[3] = 0x10;
                b4[0] = 0x10;
                b4[1] = 0x10;
                b4[2] = 0x10;
                b4[3] = 0x10;
                v = 9;
            }
            FUN_a00a7488(i, 0x1c08, 0xffffff, 0x60000000);
            FUN_a00a7488(i, 0x2c08, 0xffffff, 0x60000000);
            FUN_a00a7488(i, 0x1c08, 0xffffff00, v);
            FUN_a00a7488(i, 0x2c08, 0xffffff00, v);
            FUN_a00a7488(i, 0x103c, 0xffff, a[0] << 16 | 0x1f000000);
            FUN_a00a7488(i, 0x143c, 0xffff, a[1] << 16 | 0x1f000000);
            FUN_a00a7488(i, 0x183c, 0xffff, a[2] << 16 | 0x1f000000);
            FUN_a00a7488(i, 0x203c, 0xffff, b0[0] << 16 | 0x1f000000);
            FUN_a00a7488(i, 0x243c, 0xffff, b0[1] << 16 | 0x1f000000);
            FUN_a00a7488(i, 0x283c, 0xffff, b0[2] << 16 | 0x1f000000);
            FUN_a00a7488(i, 0x303c, 0xffff, b0[3] << 16 | 0x1f000000);
            FUN_a00a7488(i, 0x2034, 0xffffffff, 0xf0000000);
            FUN_a00a7488(i, 0x2434, 0xffffffff, 0xf0000000);
            FUN_a00a7488(i, 0x2834, 0xffffffff, 0xf0000000);
            FUN_a00a7488(i, 0x3034, 0xffffffff, 0xf0000000);
            FUN_a00a7488(i, 0x2054, 0xffff07ff, (b1[0] & 0x1f) << 11);
            FUN_a00a7488(i, 0x2454, 0xffff07ff, (b1[1] & 0x1f) << 11);
            FUN_a00a7488(i, 0x2854, 0xffff07ff, (b1[2] & 0x1f) << 11);
            FUN_a00a7488(i, 0x3054, 0xffff07ff, (b1[3] & 0x1f) << 11);
            FUN_a00a7488(i, 0x2068, 0xffffff07, (b2[0] & 0x1f) << 3);
            FUN_a00a7488(i, 0x2468, 0xffffff07, (b2[1] & 0x1f) << 3);
            FUN_a00a7488(i, 0x2868, 0xffffff07, (b2[2] & 0x1f) << 3);
            FUN_a00a7488(i, 0x3068, 0xffffff07, (b2[3] & 0x1f) << 3);
            FUN_a00a7488(i, 0x2068, 0xffff07ff, (b3[0] & 0x1f) << 11);
            FUN_a00a7488(i, 0x2468, 0xffff07ff, (b3[1] & 0x1f) << 11);
            FUN_a00a7488(i, 0x2868, 0xffff07ff, (b3[2] & 0x1f) << 11);
            FUN_a00a7488(i, 0x3068, 0xffff07ff, (b3[3] & 0x1f) << 11);
            FUN_a00a7488(i, 0x2070, 0xffff07ff, (b4[0] & 0x1f) << 11);
            FUN_a00a7488(i, 0x2470, 0xffff07ff, (b4[1] & 0x1f) << 11);
            FUN_a00a7488(i, 0x2870, 0xffff07ff, (b4[2] & 0x1f) << 11);
            FUN_a00a7488(i, 0x3070, 0xffff07ff, (b4[3] & 0x1f) << 11);
        }
        FUN_a00a7424(1, 0x11, i, 0x1c04);
        if (r) {
            FUN_a00a7424(1, 0x11, i, 0x2c04);
            FUN_a0073738(i);
            FUN_a00a7488(i, 0x361c, 0xffffff00, 0xb0);
            FUN_a00a7488(i, 0x361c, 0xffffff00, 0xb3);
            FUN_a00b1794(1);
            FUN_a00a7488(i, 0x361c, 0xffffff00, 0x33);
            FUN_a00a7488(i, 0x361c, 0xffff00ff, 0x3300);
            FUN_a00a7488(i, 0x361c, 0xff00ffff, 0x670000);
            FUN_a00a7488(i, 0x3618, 0xffffff, 0x13000000);
        }
        FUN_a00a7488(i, 0x1028, 0xfffffcff, 0x300);
        FUN_a00a7488(i, 0x1008, 0xffff00ff, 0xf00);
        FUN_a00a7424(1, 7, i, 0x1c04);
        FUN_a00a7424(1, 7, i, 0x2c04);
        FUN_a00a7488(i, 0x1100, 0xffffff, 0x2000000);
        FUN_a00a7488(i, 0x1100, 0xffffff, 0x3000000);
        FUN_a00b1794(1);
        if (FUN_a00a7468(0x18, i, 0x1100) == 0) {
            z = (FUN_a00a7314(i, 0x1100) >> 28) & 7;
            if ((_DAT_a8078634 & 1) != 0)
                FUN_a0073044(s_a0066938, (char)(i + 'A'), z & 7);
            FUN_a00a7488(i, 0x1c04, 0xffffff8f, (z & 7) << 4);
            if (r)
                FUN_a00a7488(i, 0x2c04, 0xffffff8f, (z & 7) << 4);
        } else {
            if ((_DAT_a8078634 & 1) != 0)
                FUN_a0073044(s_a0066968, (char)(i + 'A'));
            FUN_a00a7488(i, 0x1c04, 0xffffff8f, 0x40);
            if (r)
                FUN_a00a7488(i, 0x2c04, 0xffffff8f, 0x40);
        }
        if (!r) {
            FUN_a00a7424(1, 8, i, 0x1014);
            FUN_a00a7424(1, 8, i, 0x1034);
            FUN_a00a7424(1, 8, i, 0x1414);
            FUN_a00a7424(1, 8, i, 0x1434);
            FUN_a00a7424(1, 8, i, 0x1814);
            FUN_a00a7424(1, 8, i, 0x1834);
        }
        FUN_a00a7488(i, 0x1f44, 0xffffffc0, 0x1f);
        FUN_a00a7424(1, 0x15, i, 0x1c00);
        if (r) {
            FUN_a00a7424(1, 0x15, i, 0x2c00);
            FUN_a00a7488(i, 0x2c00, 0xfff0ffff, 0x80000);
        }
        FUN_a00a7488(i, 0x1c00, 0xfff0ffff, 0x80000);
        FUN_a00a7424(1, 0x1b, i, 0x1c00);
        if (r)
            FUN_a00a7424(1, 0x1b, i, 0x2c00);
        FUN_a00a7488(i, 0x1000, 0xff00ffff, 0x6e0000);
        FUN_a00a7424(1, 0x18, i, 0x1f40);
        FUN_a00a7424(1, 8, i, 0x3608);
        if (r) {
            FUN_a00a7424(1, 9, i, 0x3608);
            FUN_a00a7488(i, 0x3608, 0xffffc7ff, 0x3700);
        }
        FUN_a00b1794(1);
        FUN_a00a7424(1, 0x10, i, 0x1c04);
        FUN_a00a7424(0, 0x15, 0, 0x1c04);
        FUN_a00a7424(0, 7, 0, 0x1e80);
        FUN_a00a7488(0, 0x1c04, 0xffff00ff, 0x4d00);
        FUN_a00a7424(0, 0xf, 0, 0x1c04);
        FUN_a00a7424(0, 0x19, 0, 0x1160);
        FUN_a00a7424(0, 0x16, 0, 0x1c00);
        FUN_a00a7424(0, 0x17, 0, 0x1c00);
        FUN_a00a7424(1, 0x18, 0, 0x1c0c);
        FUN_a00a7424(1, 2, i, 0x1c04);
        FUN_a00b15ac(&ARR_a807ccc4[i], 0, 0xc);
        FUN_a00b15ac(ARR_a807a9f0[i], 0, 0x898);
        FUN_a00b15ac(&DAT_a807cc64[i], 0, 0x18);
        if ((_DAT_a8078634 & 1) != 0)
            FUN_a0073044(s_a0066998, (char)(i + 'A'), i);
        if (r) {
            if ((_DAT_a8078634 & 1) != 0)
                FUN_a0073044(s_a00669c8, (char)(i + 'A'), i);
            FUN_a00a7424(0, 0x13, i, 0x2c34);
            FUN_a00a7424(1, 0x19, i, 0x2c34);
            FUN_a00a7424(0, 0x10, i, 0x2c34);
            FUN_a00a7424(0, 0x11, i, 0x2c34);
            FUN_a00a7424(0, 0x12, i, 0x2c34);
            FUN_a00a7488(i, 0x2c30, 0xfff0ffff, 0xb0000);
            FUN_a00a7488(i, 0x2c30, 0xff0fffff, 0x400000);
            FUN_a00a7488(i, 0x2c30, 0xf0ffffff, 0xd000000);
            FUN_a00a7488(i, 0x2c30, 0xfffffff, 0x20000000);
            FUN_a00a7424(0, 0, i, 0x2c30);
            FUN_a00a7488(i, 0x2c34, 0xff1fffff, 0xc00000);
            FUN_a00a7488(i, 0x2c38, 0xfffff1ff, 0);
            FUN_a00a7488(i, 0x2c34, 0xfffff3ff, 0);
            FUN_a00a7424(0, 0x14, i, 0x2c34);
            FUN_a00a7488(i, 0x2c24, 0xfcffffff, 0);
            FUN_a00a7424(0, 5, i, 0x2c20);
            FUN_a00a7424(0, 4, i, 0x2c20);
        }
        FUN_a0073c24(i, 1);
    }
    if ((_DAT_a8078634 & 1) != 0)
        FUN_a0073044(s_a00669f0, 0x378);
}
