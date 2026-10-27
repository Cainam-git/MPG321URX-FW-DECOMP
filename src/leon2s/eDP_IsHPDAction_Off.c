/* eDP_IsHPDAction_Off (leon2s 0xa0089090-0xa0089420, 912 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 all). Ports lo..hi are 0..0, or DAT_a80761c0..DAT_a80761bf when all != 0; 16-byte stack buffer buf
 * (cleared), byte m = FUN_a0089058(lo, hi), halfword flags f = 0. For each port while DAT_a8078a0c != 0:
 * r = FUN_a008899c(port), or, when DAT_a80761b8[port] == 1, 1 (with the "...GOGO %d!!" print) or 2 by
 * FUN_a0088af0(port) == 1 (FUN_a008899c is still called, DAT_a80761b8[port] cleared). r == 1 prints
 * "eDP_IsHPDAction_On %d" and sets f |= 9; r == 2 prints "eDP_IsHPDAction_Off %d" and sets f |= 0x40. When
 * FUN_a0088a80(port) is set: prints "eDP_IsIRQAction" and FUN_a0088af0(port) == 1 sets f |= 8. Second pass over
 * the ports: f |= FUN_a0088fb0(port); FUN_a0088af0(port) == 1 clears bit 6, otherwise the port's bit in m;
 * bit 14 calls FUN_a00aa88c(port, 0). f != 0 prints "action = %d". Bit 3: FUN_a0088c5c(lo, buf, &m) == 1 sets
 * bit 0, buf[2] != 0 sets bit 4 (each with a print). Bit 4: for the ports set in m, FUN_a00883d0(port, buf)
 * 1 sets bits 0..1, 2 clears f. Bit 2: FUN_a0088b60(lo); bit 6: print only; bit 0: FUN_a00866e0(lo, &m) and
 * FUN_a0087824(lo, &m) == 1 prints "training finish %d".
 * Source forms the exact build depends on: hi initialised to 0 at its declaration and assigned again in the
 * '!all' arm as 'lo = 0; hi = 0;' (the firmware's 'mov %l5,%l7' copy of lo's zero register); the r = 2 of the
 * GOGO test written as the else arm (not before the test); the second dispatch on FUN_a00883d0 as a switch.
 */
extern unsigned char DAT_a80761b8[];
extern unsigned char DAT_a80761bf;
extern unsigned char DAT_a80761c0;
extern unsigned char DAT_a8078a0c;
extern int FUN_a0073044(const char *, ...);
extern int FUN_a00734c4(const char *);
extern unsigned char FUN_a0089058(unsigned char, unsigned char);
extern unsigned char FUN_a0088af0(unsigned char);
extern unsigned char FUN_a008899c(unsigned char);
extern unsigned char FUN_a0088a80(unsigned char);
extern unsigned short FUN_a0088fb0(unsigned char);
extern void FUN_a00aa88c(unsigned int, unsigned int);
extern unsigned char FUN_a0088c5c(unsigned char, unsigned char *, unsigned char *);
extern unsigned char FUN_a00883d0(unsigned char, unsigned char *);
extern void FUN_a0088b60(unsigned char);
extern void FUN_a00866e0(unsigned char, unsigned char *);
extern unsigned char FUN_a0087824(unsigned char, unsigned char *);

void eDP_IsHPDAction_Off(unsigned char all)
{
    unsigned char buf[16] = {0};
    unsigned char m = 0;
    unsigned short f = 0;
    unsigned char lo;
    unsigned char hi = 0;
    unsigned char port;
    unsigned char r;

    if (!all) {
        lo = 0;
        hi = 0;
    } else {
        lo = DAT_a80761c0;
        hi = DAT_a80761bf;
    }
    m = FUN_a0089058(lo, hi);
    for (port = lo; port <= hi; port++) {
        if (DAT_a8078a0c == 0)
            continue;
        if (DAT_a80761b8[port] == 1) {
            if (FUN_a0088af0(port) == 1) {
                r = 1;
                FUN_a0073044("=========================================GOGO %d!!\r\n", port);
            } else
                r = 2;
            FUN_a008899c(port);
            DAT_a80761b8[port] = 0;
        } else
            r = FUN_a008899c(port);
        if (r == 1) {
            FUN_a0073044("eDP_IsHPDAction_On %d\r\n", port);
            f |= 9;
        } else if (r == 2) {
            FUN_a0073044("eDP_IsHPDAction_Off %d\r\n", port);
            f |= 0x40;
        }
        if (FUN_a0088a80(port)) {
            FUN_a00734c4("eDP_IsIRQAction\r");
            if (FUN_a0088af0(port) == 1)
                f |= 8;
        }
    }
    for (port = lo; port <= hi; port++) {
        f = FUN_a0088fb0(port) | f;
        if (FUN_a0088af0(port) == 1)
            f &= ~0x40;
        else
            m &= ~(1 << port);
        if (f & 0x4000)
            FUN_a00aa88c(port, 0);
    }
    if (f != 0)
        FUN_a0073044("action = %d\r\n", f);
    if (f & 8) {
        FUN_a0073044("eDPAction CheckSinkStatus %d\r\n", lo);
        if (FUN_a0088c5c(lo, buf, &m) == 1)
            f |= 1;
        if (buf[2] != 0) {
            FUN_a0073044("eDPAction IRQVectorHandle %d\r\n", lo);
            f |= 0x10;
        }
    }
    if (f & 0x10) {
        for (port = lo; port <= hi; port++) {
            if ((m >> port) & 1) {
                switch (FUN_a00883d0(port, buf)) {
                case 1:
                    f |= 3;
                    break;
                case 2:
                    f = 0;
                    break;
                }
            }
        }
    }
    if (f & 4) {
        FUN_a0073044("eDPAction ReadEDID %d\r\n", lo);
        FUN_a0088b60(lo);
    }
    if (f & 0x40)
        FUN_a0073044("eDPAction HPDDisConnect %d\r\n", lo);
    if (f & 1) {
        FUN_a0073044("eDPAction Training %d\r\n", lo);
        FUN_a00866e0(lo, &m);
        if (FUN_a0087824(lo, &m) == 1)
            FUN_a0073044("training finish %d\r\n", lo);
    }
}
