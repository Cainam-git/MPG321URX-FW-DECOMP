/* FUN_a006e990 (leon2s 0xa006e990-0xa006ed40, 944 bytes), flags -mcpu=v8 -Os -g.
 * Called by DP_GetClrSpace with a port record and a port number. Saves the record's halfwords
 * +2/+4/+6/+8/+0xa and byte +0xd in a local copy, reads the new values with FUN_a00acac0 (HrtlDE),
 * FUN_a00acb00 (VrtlDE), FUN_a00acb40 (Htotal), FUN_a00acb60 (Vtotal), FUN_a00acb94 (color depth) and
 * FUN_a00acc54 (Clk), then calls FUN_a006e820(rec, port). Returns 1 after printing the reason when bit 4 of
 * halfword +0x12 (bForceModeChange, then cleared) is set, when one of the HrtlDE / VrtlDE / Htotal / Vtotal
 * results is 9 or less, when Clk is outside 0x14..0xd48, or when FUN_a00af1e8(port) differs from
 * DAT_a8078898[port] (the table entry is updated).
 * Otherwise sets the result to 1 for a changed color depth byte +0x12 (printed and stored), for HrtlDE / VrtlDE /
 * Htotal differences above 2 / 1 / 4 (printed), and for a Clk difference above 0xf (old Clk > 0x32) or 5;
 * stores the five new values; compares bit 1 of byte +0xd with the saved byte (printed); when the result is 1
 * prints the six "DP(%d) ..." lines. Names follow the firmware's print strings.
 * Source form: the depth result is kept as unsigned int and copied into an unsigned char before the compare;
 * the comparisons read the saved values through a pointer to the local copy that is set after r = 0.
 */
struct PortRec {
    unsigned char b0, b1;
    unsigned short htotal, vtotal, hrtlde, vrtlde, clk;
    unsigned char bc, phy_status, be, bf, b10, b11;
    union {
        unsigned short h;
        unsigned char depth;
        struct { unsigned short hi : 11; unsigned short force_mode_change : 1; unsigned short lo : 4; } f;
    } u12;
};
struct Old { unsigned short hrtlde, vrtlde, htotal, vtotal, clk; unsigned char phy_status; };

extern unsigned char DAT_a8078898[];
extern char s_a0065fb8[], s_a0065fd0[], s_a0065fe8[], s_a0066000[], s_a0066018[], s_a0066030[], s_a0066048[],
    s_a0066078[], s_a00660a0[], s_a00660b8[], s_a00660d0[], s_a00660e8[], s_a0066110[], s_a0066138[],
    s_a0066158[], s_a0066178[], s_a0066198[], s_a00661b8[];
extern int FUN_a0073044(char *, ...);
extern unsigned short FUN_a00acac0(unsigned int);
extern unsigned short FUN_a00acb00(unsigned int);
extern unsigned short FUN_a00acb40(unsigned int);
extern unsigned short FUN_a00acb60(unsigned int);
extern unsigned int FUN_a00acb94(unsigned int);
extern unsigned short FUN_a00acc54(unsigned char);
extern void FUN_a006e820(struct PortRec *, unsigned char);
extern unsigned char FUN_a00af1e8(unsigned char);
extern int abs(int);

unsigned char FUN_a006e990(struct PortRec *rec, unsigned char port)
{
    unsigned char slice[2] = {0, 0};
    struct Old old;
    struct Old *o;
    unsigned short hrtlde, vrtlde, htotal, vtotal, clk;
    unsigned int depth;
    unsigned char r;
    unsigned char c;

    old.htotal = rec->htotal;
    old.vtotal = rec->vtotal;
    old.hrtlde = rec->hrtlde;
    old.vrtlde = rec->vrtlde;
    old.clk = rec->clk;
    old.phy_status = rec->phy_status;
    hrtlde = FUN_a00acac0(port);
    vrtlde = FUN_a00acb00(port);
    htotal = FUN_a00acb40(port);
    vtotal = FUN_a00acb60(port);
    depth = FUN_a00acb94(port);
    clk = FUN_a00acc54(port);
    FUN_a006e820(rec, port);
    r = 0;
    o = &old;
    if (rec->u12.f.force_mode_change) {
        FUN_a0073044(s_a0065fb8, rec->u12.f.force_mode_change);
        rec->u12.f.force_mode_change = 0;
        return 1;
    }
    if (hrtlde <= 9) {
        FUN_a0073044(s_a0065fd0, hrtlde);
        return 1;
    }
    if (vrtlde <= 9) {
        FUN_a0073044(s_a0065fe8, vrtlde);
        return 1;
    }
    if (htotal <= 9) {
        FUN_a0073044(s_a0066000, htotal);
        return 1;
    }
    if (vtotal <= 9) {
        FUN_a0073044(s_a0066018, vtotal);
        return 1;
    }
    if ((unsigned short)(clk - 0x14) > 0xd34) {
        FUN_a0073044(s_a0066030, clk, 0x14, 0xd48);
        return 1;
    }
    slice[port] = FUN_a00af1e8(port);
    if (slice[port] != DAT_a8078898[port]) {
        FUN_a0073044(s_a0066048, port, DAT_a8078898[port], slice[port]);
        DAT_a8078898[port] = slice[port];
        return 1;
    }
    c = depth;
    if (c != rec->u12.depth) {
        FUN_a0073044(s_a0066078, rec->u12.depth, c);
        rec->u12.depth = c;
        r = 1;
    }
    if (abs(hrtlde - o->hrtlde) > 2) {
        FUN_a0073044(s_a00660a0, hrtlde, o->hrtlde);
        r = 1;
    }
    if (abs(vrtlde - o->vrtlde) > 1) {
        FUN_a0073044(s_a00660b8, vrtlde, o->vrtlde);
        r = 1;
    }
    if (abs(htotal - o->htotal) > 4) {
        FUN_a0073044(s_a00660d0, htotal, o->htotal);
        r = 1;
    }
    if (o->clk > 0x32) {
        if (abs(clk - o->clk) > 0xf)
            r = 1;
    } else {
        if (abs(clk - o->clk) > 5)
            r = 1;
    }
    rec->hrtlde = hrtlde;
    rec->vrtlde = vrtlde;
    rec->htotal = htotal;
    rec->vtotal = vtotal;
    rec->clk = clk;
    if ((rec->phy_status & 2) != (o->phy_status & 2)) {
        FUN_a0073044(s_a00660e8, rec->phy_status, o->phy_status);
        r = 1;
    }
    if (r == 1) {
        FUN_a0073044(s_a0066110, port);
        FUN_a0073044(s_a0066138, port, rec->htotal);
        FUN_a0073044(s_a0066158, port, rec->vtotal);
        FUN_a0073044(s_a0066178, port, rec->hrtlde);
        FUN_a0073044(s_a0066198, port, rec->vrtlde);
        FUN_a0073044(s_a00661b8, port, rec->clk);
    }
    return r;
}
