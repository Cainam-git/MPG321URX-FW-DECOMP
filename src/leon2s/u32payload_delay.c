/* u32payload_delay (leon2s 0xa00967ec-0xa0096a6c, 640 bytes), flags -mcpu=v8 -Os -g.
 * unsigned int (u8 port). rec = DAT_a807db00[port] (0x34-byte records; words +0 and +0x18 point to register
 * blocks r0 and r18). Clears bits 0x19 and 0x1a of the word array at r18 + 0x48 (FUN_a00a73d4), clears
 * DAT_a80790a8[port], clears bit 0xc at r0 + 8, sets bit 8 at r0 + 4 (FUN_a00a73ac), FUN_a00b1794(1), clears
 * bit 8 at r0 + 4 and sets bit 0 at r18 + 0x64. Then repeats FUN_a00b1794(1) while FUN_a00a7408(1, r18 + 0x64)
 * is 0, leaving when the pass counter (post-increment) was above 10. Counter above 10: when bit 2 of
 * _DAT_a8078634 is set, FUN_a00734c4 prints "[MODEDET]: u32payload_delay abnormal\n"; returns 0.
 * Otherwise copies the six words of DAT_a00b427c (166, 333, 333, 444, 555, 666) to tab on the stack
 * (FUN_a00b15d8), prints "Port%c Payload Cnt 0x%08x" with port + 'A' and r18[0x1a] >> 8 when bit 2 is set,
 * takes idx = byte 1 of the 0xb0-byte row ARR_a807d680[port] and v = ((r18[0x1a] >> 10) * tab[idx - 1]) / 511
 * >> 6 when idx > 2, else ... / 681 >> 6. v <= 100 clears bit 0x19 at r18 + 0x48, else sets it; sets bit 0x1a;
 * returns v. The register-block pointers are volatile, as in the prototypes of the bit helpers.
 * Source form: K&R parameter definition (the byte parameter is copied raw and masked at each use); the
 * divisions are written as '/ 511 >> 6' and '/ 681 >> 6' (a single divisor 32704 is pre-shifted by GCC).
 */
struct port_rec {
    volatile unsigned int *r0;
    unsigned int _04[5];
    volatile unsigned int *r18;
    unsigned char _1c[0x34 - 0x1c];
};
extern struct port_rec DAT_a807db00[];
extern unsigned char DAT_a80790a8[];
extern unsigned char ARR_a807d680[];
extern unsigned int _DAT_a8078634;
extern const int DAT_a00b427c[6];
extern void FUN_a00a73ac(unsigned int, volatile unsigned int *);
extern void FUN_a00a73d4(unsigned int, volatile unsigned int *);
extern unsigned int FUN_a00a7408(unsigned int, volatile unsigned int *);
extern void FUN_a00b1794(int);
extern void *FUN_a00b15d8(void *, const void *, unsigned int);
extern int FUN_a0073044(const char *, ...);
extern int FUN_a00734c4(const char *);

unsigned int u32payload_delay(port)
    unsigned char port;
{
    unsigned int cnt;
    unsigned int v;
    unsigned int idx;
    int tab[6];

    FUN_a00a73d4(0x19, DAT_a807db00[port].r18 + 0x12);
    FUN_a00a73d4(0x1a, DAT_a807db00[port].r18 + 0x12);
    DAT_a80790a8[port] = 0;
    FUN_a00a73d4(0xc, DAT_a807db00[port].r0 + 2);
    FUN_a00a73ac(8, DAT_a807db00[port].r0 + 1);
    FUN_a00b1794(1);
    FUN_a00a73d4(8, DAT_a807db00[port].r0 + 1);
    cnt = 0;
    FUN_a00a73ac(0, DAT_a807db00[port].r18 + 0x19);
    do {
        FUN_a00b1794(1);
        if (cnt++ > 10)
            break;
    } while (FUN_a00a7408(1, DAT_a807db00[port].r18 + 0x19) == 0);
    if (cnt > 10) {
        if (_DAT_a8078634 & 4)
            FUN_a00734c4("[MODEDET]: u32payload_delay abnormal\n");
        return 0;
    }
    FUN_a00b15d8(tab, DAT_a00b427c, sizeof(tab));
    if (_DAT_a8078634 & 4)
        FUN_a0073044("[MODEDET]: Port%c Payload Cnt 0x%08x\n", (char)(port + 0x41),
                     DAT_a807db00[port].r18[0x1a] >> 8);
    idx = ARR_a807d680[port * 0xb0 + 1];
    if (idx > 2)
        v = ((DAT_a807db00[port].r18[0x1a] >> 10) * tab[idx - 1]) / 511 >> 6;
    else
        v = ((DAT_a807db00[port].r18[0x1a] >> 10) * tab[idx - 1]) / 681 >> 6;
    if (v <= 100)
        FUN_a00a73d4(0x19, DAT_a807db00[port].r18 + 0x12);
    else
        FUN_a00a73ac(0x19, DAT_a807db00[port].r18 + 0x12);
    FUN_a00a73ac(0x1a, DAT_a807db00[port].r18 + 0x12);
    return v;
}
