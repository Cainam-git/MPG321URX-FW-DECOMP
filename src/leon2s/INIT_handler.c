/* INIT_handler (leon2s 0xa00a17c4-0xa00a1a80, 700 bytes), flags -mcpu=v8 -Os -g.
 * Called by hdmi21_Initialize once per input port. Port 0 or 1 only (any other port returns at once);
 * sel = 2 for port 0, 3 for port 1. Sets and clears bits in the register blocks of the port through
 * FUN_a00a73ac (set bit n of the word array) and FUN_a00a73d4 (clear bit n), rewrites register fields
 * at r0[0x30]/r0[0x31], r4[0xd], r20[0x20] and r8[0x27], clears/sets bytes of the 400-byte record
 * ARR_a807d7e0[port] and the 0xb0-byte record ARR_a807d680[port], prints "[INIT]: Port%c ..." when bit 0
 * of _DAT_a8078634 is set, then calls DRV_HDMI21_LTS_STS_InitialSettings(port), FUN_a00a7424(1, 0x1e, sel,
 * 0x2e60), FUN_a00a2f70(port, 0x12, 1) and FUN_a00a8694(port).
 * Data: DAT_a807db00 is an array of 0x34-byte port records holding pointers to the register blocks.
 * Source forms the exact build depends on: the debug word is read into a local before the record byte
 * stores; the record stores are written in the order shown; the r20 field is accessed through the record
 * each time, while the r0 block uses a local pointer.
 */
struct port_rec {
    volatile unsigned int *r0;
    volatile unsigned int *r4;
    volatile unsigned int *r8;
    volatile unsigned int *rc;
    volatile unsigned int *r10;
    volatile unsigned int *r14;
    volatile unsigned int *r18;
    volatile unsigned int *r1c;
    volatile unsigned int *r20;
    unsigned char _24[0x34 - 0x24];
};
extern struct port_rec DAT_a807db00[];
extern unsigned char ARR_a807d7e0[];
extern unsigned char ARR_a807d680[];
extern unsigned int _DAT_a8078634;
extern int FUN_a0073044(const char *, ...);
extern void FUN_a00a73ac(unsigned int, volatile unsigned int *);
extern void FUN_a00a73d4(unsigned int, volatile unsigned int *);
extern void FUN_a00a7424(int mode, unsigned int bit, unsigned char reg, unsigned short val);
extern void FUN_a00a2f70(unsigned char, unsigned char, unsigned char);
extern void FUN_a00a8694(unsigned char);
extern void DRV_HDMI21_LTS_STS_InitialSettings(unsigned char);

void INIT_handler(unsigned int param_1)
{
    unsigned char port;
    unsigned char sel;
    unsigned char *rec;
    unsigned int dbg;
    volatile unsigned int *p;

    port = param_1;
    if (port == 0)
        sel = 2;
    else if (port == 1)
        sel = 3;
    else
        return;
    FUN_a00a73ac(0x17, DAT_a807db00[port].r4 + 15);
    FUN_a00a73ac(0x16, DAT_a807db00[port].r4 + 15);
    FUN_a00a73ac(0x15, DAT_a807db00[port].r4 + 15);
    dbg = _DAT_a8078634;
    rec = ARR_a807d7e0 + port * 0x190;
    rec[2] = 0;
    rec[0xba] = 1;
    rec[0x183] = 1;
    if (dbg & 1)
        FUN_a0073044("[INIT]: Port%c , 5V Ident = %d ##\n", (char)(param_1 + 0x41), 1);
    p = DAT_a807db00[port].r0;
    p[0x30] = (p[0x30] & 0xffffff) | 0x50000000;
    p[0x31] = p[0x31] & 0xffffff00;
    p[0x31] = (p[0x31] & 0xffff00ff) | 0x100;
    p[0x31] = p[0x31] & 0xff00ffff;
    FUN_a00a73ac(0x14, p + 0x21);
    FUN_a00a73d4(port + 0x14, DAT_a807db00[port].r0 + 0x35);
    FUN_a00a73ac(0x1b, DAT_a807db00[port].r4 + 9);
    FUN_a00a73ac(0x1c, DAT_a807db00[port].r4 + 9);
    FUN_a00a73ac(0x1d, DAT_a807db00[port].r4 + 9);
    FUN_a00a73ac(0x1e, DAT_a807db00[port].r4 + 9);
    FUN_a00a73ac(0x1f, DAT_a807db00[port].r4 + 9);
    FUN_a00a73ac(0xd, DAT_a807db00[port].r4 + 10);
    FUN_a00a73ac(8, DAT_a807db00[port].r4 + 10);
    FUN_a00a73ac(9, DAT_a807db00[port].r4 + 10);
    FUN_a00a73ac(10, DAT_a807db00[port].r4 + 10);
    FUN_a00a73d4(0xb, DAT_a807db00[port].r4 + 10);
    DAT_a807db00[port].r4[0xd] = (DAT_a807db00[port].r4[0xd] & 0xffff00ff) | 0x600;
    FUN_a00a73d4(0xf, DAT_a807db00[port].r0 + 0x10);
    rec = ARR_a807d680 + port * 0xb0;
    rec[0x3a] = 1;
    *(unsigned int *)(rec + 0x30) = 0;
    rec[0x3b] = 0;
    rec[0x3c] = 0;
    DRV_HDMI21_LTS_STS_InitialSettings(port);
    FUN_a00a73d4(0x11, DAT_a807db00[port].r18 + 0x24);
    FUN_a00a73ac(8, DAT_a807db00[port].r18 + 2);
    FUN_a00a7424(1, 0x1e, sel, 0x2e60);
    FUN_a00a73ac(0xc, DAT_a807db00[port].rc + 0x1f);
    FUN_a00a73ac(0x15, DAT_a807db00[port].r0 + 1);
    DAT_a807db00[port].r20[0x20] = (DAT_a807db00[port].r20[0x20] & 0xff) | 0x4000000;
    DAT_a807db00[port].r20[0x20] = DAT_a807db00[port].r20[0x20] | 7;
    FUN_a00a2f70(port, 0x12, 1);
    FUN_a00a8694(port);
    DAT_a807db00[port].r8[0x27] = (DAT_a807db00[port].r8[0x27] & 0xffffff) | 0x2000000;
}
