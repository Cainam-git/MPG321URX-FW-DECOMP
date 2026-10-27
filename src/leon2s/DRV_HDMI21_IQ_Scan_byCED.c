/* DRV_HDMI21_IQ_Scan_byCED (leon2s 0xa007fa0c-0xa007fde0, 980 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port); only ports 2 and 3 (record p = 0 / 1 of ARR_a807d680, 0xb0 bytes, byte 0 = lane count n).
 * Prints the function name s_a00b3f80 through DAT_a0067868 when bit 11 of DAT_a8078634 is set. For k = 0x10 ..
 * 0x2f: FUN_a007aac4(port, 0xff, k, k, k, k), FUN_a007f9e8(port), then for each lane ch < n: ok =
 * FUN_a00a7468(0xf / 0x1f, port, 0x2e64 / 0x2e68) != 0 (lanes 0..3; other lanes keep the previous ok). With ok
 * the lane's 15-bit value (low / high half of FUN_a00a7314(port, 0x2e64 / 0x2e68)) goes to the halfword table
 * ced[ch * 0x20 + k - 0x10]; a value below 100 records k - 0x10 in lo[ch] and, the first time, (k - 0x10) | 0x80
 * in hi[ch]. Without ok the entry becomes 0x7fff and "1ms CED[%d] non valid" is printed. Afterwards res[ch] =
 * ((lo[ch] + (hi[ch] & 0x3f)) >> 1) + 0x10 is printed per lane and passed as FUN_a007aac4(port, 0xff, res[0..3]),
 * followed by FUN_a007f9d0(port).
 * Source forms the exact build depends on: K&R definition with an unsigned char parameter (zero-extended at every
 * use); ced as one flat 128-entry array indexed ch * 0x20 + k - 0x10 in every arm; one FUN_a00a7468 call per
 * lane arm (cross-jumped by GCC); hi cleared before lo.
 */
struct Lane176 {
    unsigned char n;
    unsigned char rest[0xaf];
};
extern struct Lane176 ARR_a807d680[];
extern unsigned int DAT_a8078634;
extern const char DAT_a0067868[], s_a00b3f80[];
extern void *FUN_a00b15ac(void *, int, unsigned int);
extern int FUN_a0073044(const char *, ...);
extern int FUN_a00734c4(const char *);
extern unsigned int FUN_a00a7468(unsigned int, unsigned char, unsigned short);
extern unsigned int FUN_a00a7314(unsigned int, unsigned short);
extern void FUN_a007aac4(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);
extern void FUN_a007f9e8(unsigned char);
extern void FUN_a007f9d0(unsigned char);

void DRV_HDMI21_IQ_Scan_byCED(port)
    unsigned char port;
{
    unsigned char res[4] = {0, 0, 0, 0};
    unsigned short ced[128];
    unsigned char hi[4];
    unsigned char lo[4];
    unsigned char ok = 0;
    unsigned char p;
    unsigned char ch, k;
    unsigned int reg;
    unsigned int m;

    FUN_a00b15ac(ced, 0, 0x100);
    if (port == 2)
        p = 0;
    else if (port == 3)
        p = 1;
    else
        return;
    if (DAT_a8078634 & 0x800)
        FUN_a0073044(DAT_a0067868, s_a00b3f80);
    for (ch = 0; ch < ARR_a807d680[p].n; ch++) {
        hi[ch] = 0;
        lo[ch] = 0;
    }
    for (k = 0x10; k < 0x30; k++) {
        FUN_a007aac4(port, 0xff, k, k, k, k);
        FUN_a007f9e8(port);
        for (ch = 0; ch < ARR_a807d680[p].n; ch++) {
            if (ch == 0) {
                reg = 0x2e64;
                m = 0xf;
                ok = FUN_a00a7468(m, port, reg) != 0;
            } else if (ch == 1) {
                reg = 0x2e64;
                m = 0x1f;
                ok = FUN_a00a7468(m, port, reg) != 0;
            } else if (ch == 2) {
                reg = 0x2e68;
                m = 0xf;
                ok = FUN_a00a7468(m, port, reg) != 0;
            } else if (ch == 3) {
                reg = 0x2e68;
                m = 0x1f;
                ok = FUN_a00a7468(m, port, reg) != 0;
            }
            if (ok) {
                if (ch == 0)
                    ced[ch * 0x20 + k - 0x10] = FUN_a00a7314(port, 0x2e64) & 0x7fff;
                else if (ch == 1)
                    ced[ch * 0x20 + k - 0x10] = (FUN_a00a7314(port, 0x2e64) >> 16) & 0x7fff;
                else if (ch == 2)
                    ced[ch * 0x20 + k - 0x10] = FUN_a00a7314(port, 0x2e68) & 0x7fff;
                else if (ch == 3)
                    ced[ch * 0x20 + k - 0x10] = (FUN_a00a7314(port, 0x2e68) >> 16) & 0x7fff;
                if (ced[ch * 0x20 + k - 0x10] < 100) {
                    if (!(hi[ch] & 0x80))
                        hi[ch] = (k - 0x10) | 0x80;
                    lo[ch] = k - 0x10;
                }
            } else {
                ced[ch * 0x20 + k - 0x10] = 0x7fff;
                FUN_a0073044("1ms CED[%d] non valid\n\n", ch);
            }
        }
    }
    for (ch = 0; ch < ARR_a807d680[p].n; ch++)
        res[ch] = ((lo[ch] + (hi[ch] & 0x3f)) >> 1) + 0x10;
    FUN_a0073044("u8IQ_Best_Idx = ");
    for (ch = 0; ch < ARR_a807d680[p].n; ch++)
        FUN_a0073044(" CH%d = 0x%02X \r\n", ch, res[ch]);
    FUN_a00734c4("\n========IQ scan end======\n");
    FUN_a007aac4(port, 0xff, res[0], res[1], res[2], res[3]);
    FUN_a007f9d0(port);
}
