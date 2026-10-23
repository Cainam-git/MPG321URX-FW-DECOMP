/*
 * FUN_a00aaf94 (leon2s, 0xa00aaf94-0xa00ab4a8, 1300 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port, u8 lvl, u8 mode). Picks idx from mode and lvl (mode 0: lvl if lvl <= 3; mode 1: lvl + 4
 * if lvl <= 2; mode 2: lvl + 7 if lvl <= 1; other modes: 9; otherwise 0) and reads the halfword
 * e = DAT_a00b4dcc[port != 0][idx] (two rows of 10). For k = 0..3 on the 16-byte record DAT_a80792b4[port]:
 * v[k] = a[k] + ((e & 0xff00) >> 8), limited to 0x1f, and w[k] = b[k] + (e & 0xf), limited to 0xf.
 * Then, per port (0, 1, 2, 3, other), writes FUN_a00a7d88(page, reg) with the low or high nibble forced
 * (lvl != 0: | 0xf or | 0xf0, else & 0xf0 or & 0xf) back with FUN_a00a7cc0(page, reg, value), the four
 * v bytes, and the w bytes (port 0: one register each; other ports: pairs w[1] << 4 | w[0] and
 * w[3] << 4 | w[2]); register numbers 0x49/0x4b..0x4e/0x45..0x48 (port 0, page 0), 0x66/0x6f..0x72/0x62/0x63
 * (port 1), 0x66/0x73..0x76/0x64/0x65 (port 2), 0x89/0x92..0x95/0x85/0x86 (port 3), 0x89/0x96..0x99/0x87/0x88
 * (other ports), page 1 for every port but 0. The last FUN_a00a7cc0 call is a tail call.
 * Source forms: every arm indexes the record with the variable port (the firmware materialises the record
 * address of the constant port the compare established); FUN_a00a7d88 is called inside each lvl arm and
 * its result passed straight to FUN_a00a7cc0 (u8 value parameter); hi is an int local, lo a u8 local,
 * v is loaded first and then increased by hi.
 * Compiler aid: the 'if (w) X; else X;' with identical arms in the port 0 arm emits no instructions (the
 * arms are merged after register allocation); it keeps w live past the loop, which gives the firmware's
 * register choice for the v and w computations.
 */
struct Rec16 { unsigned char v[4]; unsigned char a[4]; unsigned char w[4]; unsigned char b[4]; };
extern struct Rec16 DAT_a80792b4[];
extern const unsigned short DAT_a00b4dcc[2][10];
extern unsigned int FUN_a00a7d88(unsigned int, unsigned short);
extern void FUN_a00a7cc0(unsigned char, unsigned short, unsigned char);

void FUN_a00aaf94(unsigned char port, unsigned char lvl, unsigned char mode)
{
    unsigned char row = port != 0;
    unsigned char idx = 0;
    unsigned char k;
    unsigned char v, w;
    int hi;
    unsigned char lo;

    if (mode == 0) {
        if (lvl <= 3)
            idx = lvl;
    } else if (mode == 1) {
        if (lvl <= 2)
            idx = lvl + 4;
    } else if (mode == 2) {
        if (lvl <= 1)
            idx = lvl + 7;
    } else
        idx = 9;
    hi = (DAT_a00b4dcc[row][idx] & 0xff00) >> 8;
    lo = DAT_a00b4dcc[row][idx] & 0xf;
    for (k = 0; k < 4; k++) {
        v = DAT_a80792b4[port].a[k];
        v += hi;
        if (v > 0x1f)
            v = 0x1f;
        DAT_a80792b4[port].v[k] = v;
        w = lo + DAT_a80792b4[port].b[k];
        if (w > 0xf)
            w = 0xf;
        DAT_a80792b4[port].w[k] = w;
    }
    if (port == 0) {
        if (lvl) {
            if (w)
                FUN_a00a7cc0(0, 0x49, FUN_a00a7d88(0, 0x49) | 0xf);
            else
                FUN_a00a7cc0(0, 0x49, FUN_a00a7d88(0, 0x49) | 0xf);
        } else
            FUN_a00a7cc0(0, 0x49, FUN_a00a7d88(0, 0x49) & 0xf0);
        FUN_a00a7cc0(0, 0x4b, DAT_a80792b4[port].v[0]);
        FUN_a00a7cc0(0, 0x4c, DAT_a80792b4[port].v[1]);
        FUN_a00a7cc0(0, 0x4d, DAT_a80792b4[port].v[2]);
        FUN_a00a7cc0(0, 0x4e, DAT_a80792b4[port].v[3]);
        FUN_a00a7cc0(0, 0x45, DAT_a80792b4[port].w[0]);
        FUN_a00a7cc0(0, 0x46, DAT_a80792b4[port].w[1]);
        FUN_a00a7cc0(0, 0x47, DAT_a80792b4[port].w[2]);
        FUN_a00a7cc0(0, 0x48, DAT_a80792b4[port].w[3]);
    } else if (port == 1) {
        if (lvl)
            FUN_a00a7cc0(1, 0x66, FUN_a00a7d88(1, 0x66) | 0xf);
        else
            FUN_a00a7cc0(1, 0x66, FUN_a00a7d88(1, 0x66) & 0xf0);
        FUN_a00a7cc0(1, 0x6f, DAT_a80792b4[port].v[0]);
        FUN_a00a7cc0(1, 0x70, DAT_a80792b4[port].v[1]);
        FUN_a00a7cc0(1, 0x71, DAT_a80792b4[port].v[2]);
        FUN_a00a7cc0(1, 0x72, DAT_a80792b4[port].v[3]);
        FUN_a00a7cc0(1, 0x62, (unsigned char)((DAT_a80792b4[port].w[1] << 4) + DAT_a80792b4[port].w[0]));
        FUN_a00a7cc0(1, 0x63, (unsigned char)((DAT_a80792b4[port].w[3] << 4) + DAT_a80792b4[port].w[2]));
    } else if (port == 2) {
        if (lvl)
            FUN_a00a7cc0(1, 0x66, FUN_a00a7d88(1, 0x66) | 0xf0);
        else
            FUN_a00a7cc0(1, 0x66, FUN_a00a7d88(1, 0x66) & 0xf);
        FUN_a00a7cc0(1, 0x73, DAT_a80792b4[port].v[0]);
        FUN_a00a7cc0(1, 0x74, DAT_a80792b4[port].v[1]);
        FUN_a00a7cc0(1, 0x75, DAT_a80792b4[port].v[2]);
        FUN_a00a7cc0(1, 0x76, DAT_a80792b4[port].v[3]);
        FUN_a00a7cc0(1, 0x64, (unsigned char)((DAT_a80792b4[port].w[1] << 4) + DAT_a80792b4[port].w[0]));
        FUN_a00a7cc0(1, 0x65, (unsigned char)((DAT_a80792b4[port].w[3] << 4) + DAT_a80792b4[port].w[2]));
    } else if (port == 3) {
        if (lvl)
            FUN_a00a7cc0(1, 0x89, FUN_a00a7d88(1, 0x89) | 0xf);
        else
            FUN_a00a7cc0(1, 0x89, FUN_a00a7d88(1, 0x89) & 0xf0);
        FUN_a00a7cc0(1, 0x92, DAT_a80792b4[port].v[0]);
        FUN_a00a7cc0(1, 0x93, DAT_a80792b4[port].v[1]);
        FUN_a00a7cc0(1, 0x94, DAT_a80792b4[port].v[2]);
        FUN_a00a7cc0(1, 0x95, DAT_a80792b4[port].v[3]);
        FUN_a00a7cc0(1, 0x85, (unsigned char)((DAT_a80792b4[port].w[1] << 4) + DAT_a80792b4[port].w[0]));
        FUN_a00a7cc0(1, 0x86, (unsigned char)((DAT_a80792b4[port].w[3] << 4) + DAT_a80792b4[port].w[2]));
    } else {
        if (lvl)
            FUN_a00a7cc0(1, 0x89, FUN_a00a7d88(1, 0x89) | 0xf0);
        else
            FUN_a00a7cc0(1, 0x89, FUN_a00a7d88(1, 0x89) & 0xf);
        FUN_a00a7cc0(1, 0x96, DAT_a80792b4[port].v[0]);
        FUN_a00a7cc0(1, 0x97, DAT_a80792b4[port].v[1]);
        FUN_a00a7cc0(1, 0x98, DAT_a80792b4[port].v[2]);
        FUN_a00a7cc0(1, 0x99, DAT_a80792b4[port].v[3]);
        FUN_a00a7cc0(1, 0x87, (unsigned char)((DAT_a80792b4[port].w[1] << 4) + DAT_a80792b4[port].w[0]));
        FUN_a00a7cc0(1, 0x88, (unsigned char)((DAT_a80792b4[port].w[3] << 4) + DAT_a80792b4[port].w[2]));
    }
}
