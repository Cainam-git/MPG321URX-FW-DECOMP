/* DPTX_IsHPDAction_Off (leon2s 0xa0089428-0xa0089750, 808 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port). 16-byte stack buffer buf (cleared) and byte m = 1. When FUN_a0089420() == 1 and
 * FUN_a00866a4() is set: func_0x9f1cc0a8(). r = FUN_a008899c(port), or, when DAT_a80761b8[port] == 1, 1 or 2 by
 * FUN_a0088af0(port) == 1 (FUN_a008899c is still called, DAT_a80761b8[port] cleared). r == 1 prints
 * "DPTX_IsHPDAction_On" and sets flags f = 0x807 for port 0, else 8; r == 2 prints "DPTX_IsHPDAction_Off",
 * clears DAT_a8078a0a and sets f = 0x40. f |= 8 when FUN_a0088a80(port) and FUN_a0088af0(port) == 1;
 * f |= FUN_a0088fb0(port). With bit 3: FUN_a0088c5c(port, buf, &m) == 1 sets bits 0..1 (and calls
 * func_0x9f1cc034(1) when FUN_a00ab674(0) is set and port is 0); FUN_a0088fec(port) sets bit 0; bit 6 of buf[6]
 * and FUN_a0086678(port) set bit 2; buf[2] != 0 sets bit 4. With bit 4: FUN_a00883d0(port, buf) 1 sets bits 0..1,
 * 2 clears f. Then bit 2: FUN_a0088b60(port); bit 1: FUN_a008686c(port); bit 6: FUN_a00866b8(port),
 * FUN_a00aa930(port, 7) and, for FUN_a00ab674(0) set and port 0, func_0x9f1cc040(0), func_0x9f1cc034(1);
 * bit 0: func_0x9f1cc040(1) when FUN_a00866a4() and port 0, then when FUN_a0087824(port, &m) == 1:
 * func_0x9f1cc034(0) (same condition) and FUN_a008661c(port).
 * Source form: the two two-value choices as '== ? :' conditional expressions (their if-conversion order).
 */
extern unsigned char DAT_a80761b8[];
extern unsigned char DAT_a8078a0a;
extern unsigned char FUN_a0089420(void);
extern unsigned char FUN_a00866a4(void);
extern void func_0x9f1cc0a8(void);
extern unsigned char FUN_a0088af0(unsigned char);
extern unsigned char FUN_a008899c(unsigned char);
extern int FUN_a00734c4(const char *);
extern unsigned char FUN_a0088a80(unsigned char);
extern unsigned short FUN_a0088fb0(unsigned char);
extern unsigned char FUN_a0088c5c(unsigned char, unsigned char *, unsigned char *);
extern unsigned char FUN_a00ab674(unsigned char);
extern void func_0x9f1cc034(unsigned char);
extern void func_0x9f1cc040(unsigned char);
extern unsigned char FUN_a0088fec(unsigned char);
extern unsigned char FUN_a0086678(unsigned char);
extern unsigned char FUN_a00883d0(unsigned char, unsigned char *);
extern void FUN_a0088b60(unsigned char);
extern void FUN_a008686c(unsigned char);
extern void FUN_a00866b8(unsigned char);
extern void FUN_a00aa930(unsigned char, unsigned char);
extern unsigned char FUN_a0087824(unsigned char, unsigned char *);
extern unsigned char FUN_a008661c(unsigned char);

void DPTX_IsHPDAction_Off(unsigned char port)
{
    unsigned char buf[16] = {0};
    unsigned char m = 1;
    unsigned short f = 0;
    unsigned char r;

    if (FUN_a0089420() == 1) {
        if (FUN_a00866a4())
            func_0x9f1cc0a8();
    }
    if (DAT_a80761b8[port] == 1) {
        r = FUN_a0088af0(port) == 1 ? 1 : 2;
        FUN_a008899c(port);
        DAT_a80761b8[port] = 0;
    } else
        r = FUN_a008899c(port);
    if (r == 1) {
        FUN_a00734c4("DPTX_IsHPDAction_On\r");
        f = port == 0 ? 0x807 : 8;
    } else if (r == 2) {
        FUN_a00734c4("DPTX_IsHPDAction_Off\r");
        DAT_a8078a0a = 0;
        f = 0x40;
    }
    if (FUN_a0088a80(port) && FUN_a0088af0(port) == 1)
        f |= 8;
    f |= FUN_a0088fb0(port);
    if (f & 8) {
        if (FUN_a0088c5c(port, buf, &m) == 1) {
            if (FUN_a00ab674(0) && port == 0)
                func_0x9f1cc034(1);
            f |= 3;
        }
        if (FUN_a0088fec(port))
            f |= 1;
        if (buf[6] & 0x40) {
            if (FUN_a0086678(port))
                f |= 4;
        }
        if (buf[2] != 0)
            f |= 0x10;
    }
    if (f & 0x10) {
        switch (FUN_a00883d0(port, buf)) {
        case 1:
            f |= 3;
            break;
        case 2:
            f = 0;
            break;
        }
    }
    if (f & 4)
        FUN_a0088b60(port);
    if (f & 2)
        FUN_a008686c(port);
    if (f & 0x40) {
        FUN_a00866b8(port);
        FUN_a00aa930(port, 7);
        if (FUN_a00ab674(0) && port == 0) {
            func_0x9f1cc040(0);
            func_0x9f1cc034(1);
        }
    }
    if (f & 1) {
        if (FUN_a00866a4() && port == 0)
            func_0x9f1cc040(1);
        if (FUN_a0087824(port, &m) == 1) {
            if (FUN_a00866a4() && port == 0)
                func_0x9f1cc034(0);
            FUN_a008661c(port);
        }
    }
}
