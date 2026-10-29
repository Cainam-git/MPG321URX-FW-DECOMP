/* leon2m FUN_a00b9750 @ 0xa00b9750-0xa00b9c68 (1304 bytes), flags -mcpu=v8 -O3 -g. Caller: FUN_a00a5908.
 * FUN_a00b9750(x, y): r = FUN_a014448c(0); for i = 0..6, FUN_a0146a80(x + 4, i * 3 + y + 1, 0xe, 0x596, 0) and
 * FUN_a00a31a4(0, x + 4, i * 3 + y + 1, 0xe, FUN_a00a3844(DAT_00191b30, i * 29 + byte DAT_a802d290+8), 0); then
 * FUN_a00a31a4(0, x + 4, y + 2, 0xe, FUN_a00a3844(DAT_00196b24, FUN_a01445fc(byte +0x1e)), 0). Three rows formatted
 * with FUN_a01577f4 into buf ("n%4dX%4d" with FUN_a014837c(0) and 0x870, the same with FUN_a0145660(0, 7) and
 * FUN_a0145660(0, 8), "n%d HZ" with FUN_a00d8b38()), each followed by buf[0] = index of the first zero byte among
 * bytes 0..15 minus 1 and FUN_a00a31a4(0, x + 3, y + 5 / 8 / 0xb, 0x10, buf, 0). Row y + 0xe: when bit 11 of word
 * +0xa8 is clear, entry (byte +0x182) * 29 + byte +8 of DAT_00195f24, else entry u * 29 + byte +8 of DAT_001951dc with
 * u = 0 for byte +0x181 == 7, the byte itself above 6, else the byte + 1. Row y + 0x11 (x + 4, width 0xe): "nHDR"
 * when FUN_a00d7d48() != 0, else "nSDR". Row y + 0x14: m = FUN_a01447bc(0), replaced by byte DAT_a8025c57 when
 * FUN_a014d544(0) is non-zero and r - 5 (as a byte) <= 1; "n8 Bit", "n10 Bit", "n12 Bit", "n16 Bit" or "n6 Bit"
 * for m = 8, 10, 12, 16, 6 (buf unchanged otherwise). The strings are copied with strcpy (GCC stores them as words).
 * Source form: the bit 11 test is written with the clear-bit arm first; u is an int set to (unsigned char)(v + 1)
 * in the last arm and narrowed again at its use; the format strings are the symbols s_001981e0 / s_001981d8.
 */
struct R290 { unsigned char p000[8]; unsigned char b008; unsigned char p009[0x1e - 9]; unsigned char b01e;
              unsigned char p01f[0xa8 - 0x1f]; unsigned int w0a8; unsigned char p0ac[0x181 - 0xac];
              unsigned char b181; unsigned char b182; };
extern struct R290 DAT_a802d290;
extern unsigned char DAT_a8025c57;
extern unsigned int DAT_00191b30[], DAT_00196b24[], DAT_001951dc[], DAT_00195f24[];
extern unsigned char FUN_a014448c(unsigned char);
extern void FUN_a0146a80(unsigned short, unsigned short, unsigned char, unsigned short, unsigned char);
extern unsigned int FUN_a00a3844(unsigned int *, unsigned short);
extern void FUN_a00a31a4(int, unsigned short, unsigned short, int, unsigned char *, int);
extern unsigned char FUN_a01445fc(unsigned char);
extern unsigned short FUN_a014837c(int);
extern unsigned short FUN_a0145660(unsigned char, unsigned int);
extern unsigned short FUN_a00d8b38(void);
extern int FUN_a00d7d48(void);
extern int FUN_a01447bc(int);
extern unsigned char FUN_a014d544(int);
extern void FUN_a01577f4(unsigned char *, const char *, ...);
extern const char s_001981e0[], s_001981d8[];
extern char *strcpy(char *, const char *);

void FUN_a00b9750(unsigned short x, unsigned short y)
{
    unsigned char buf[16];
    unsigned char i, r, m, v;

    r = FUN_a014448c(0);
    for (i = 0; i <= 6; i++) {
        FUN_a0146a80(x + 4, i * 3 + y + 1, 0xe, 0x596, 0);
        FUN_a00a31a4(0, x + 4, i * 3 + y + 1, 0xe,
                     (unsigned char *)FUN_a00a3844(DAT_00191b30, i * 29 + DAT_a802d290.b008), 0);
    }
    FUN_a00a31a4(0, x + 4, y + 2, 0xe, (unsigned char *)FUN_a00a3844(DAT_00196b24, FUN_a01445fc(DAT_a802d290.b01e)), 0);
    FUN_a01577f4(buf, s_001981e0, FUN_a014837c(0), 0x870);
    for (i = 0; i < 16; i++)
        if (buf[i] == 0)
            break;
    buf[0] = i - 1;
    FUN_a00a31a4(0, x + 3, y + 5, 0x10, buf, 0);
    FUN_a01577f4(buf, s_001981e0, FUN_a0145660(0, 7), FUN_a0145660(0, 8));
    for (i = 0; i < 16; i++)
        if (buf[i] == 0)
            break;
    buf[0] = i - 1;
    FUN_a00a31a4(0, x + 3, y + 8, 0x10, buf, 0);
    FUN_a01577f4(buf, s_001981d8, FUN_a00d8b38());
    for (i = 0; i < 16; i++)
        if (buf[i] == 0)
            break;
    buf[0] = i - 1;
    FUN_a00a31a4(0, x + 3, y + 0xb, 0x10, buf, 0);
    if (!(DAT_a802d290.w0a8 & 0x800)) {
        FUN_a00a31a4(0, x + 3, y + 0xe, 0x10,
                     (unsigned char *)FUN_a00a3844(DAT_00195f24, DAT_a802d290.b182 * 29 + DAT_a802d290.b008), 0);
    } else {
        v = DAT_a802d290.b181;
        {
            int u;

            if (v == 7)
                u = 0;
            else if (v > 6)
                u = v;
            else
                u = (unsigned char)(v + 1);
            FUN_a00a31a4(0, x + 3, y + 0xe, 0x10, (unsigned char *)FUN_a00a3844(DAT_001951dc, (unsigned char)u * 29 + DAT_a802d290.b008), 0);
        }
    }
    if (FUN_a00d7d48() != 0)
        strcpy((char *)buf, "nHDR");
    else
        strcpy((char *)buf, "nSDR");
    for (i = 0; i < 16; i++)
        if (buf[i] == 0)
            break;
    buf[0] = i - 1;
    FUN_a00a31a4(0, x + 4, y + 0x11, 0xe, buf, 0);
    m = FUN_a01447bc(0);
    if (FUN_a014d544(0) && (unsigned char)(r - 5) <= 1)
        m = DAT_a8025c57;
    if (m == 8)
        strcpy((char *)buf, "n8 Bit");
    else if (m == 10)
        strcpy((char *)buf, "n10 Bit");
    else if (m == 12)
        strcpy((char *)buf, "n12 Bit");
    else if (m == 16)
        strcpy((char *)buf, "n16 Bit");
    else if (m == 6)
        strcpy((char *)buf, "n6 Bit");
    for (i = 0; i < 16; i++)
        if (buf[i] == 0)
            break;
    buf[0] = i - 1;
    FUN_a00a31a4(0, x + 3, y + 0x14, 0x10, buf, 0);
}
