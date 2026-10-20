/* hdmi21_Initialize (leon2s 0xa00a303c-0xa00a317c, 320 bytes), flags -mcpu=v8 -Os -g. Returns 0.
 * Start-up sequence: optional "[INIT]: %s" trace with the function-name string; when bit 8 of
 * register 0x1f0c reads 0 (FUN_a00a7468) calls FUN_a00a2a80(1), then FUN_a00a2b98, FUN_a00a2b08(1),
 * FUN_a00a2ecc, the same bit test with FUN_a00a2a80(0), FUN_a00a2c18(1), FUN_a00a2a28 and
 * hdmi_Init_Interrupt. For ports 0 and 1: clears bit 1 of r0[2], sets the low byte of rc[0x14] to 1, sets
 * bit 0xc of r0[1], runs INIT_handler(port) and writes 0x10000 to r20[0xf] (0x34-byte records DAT_a807db00).
 * Finally registers FUN_a009f654 through FUN_a00b2070(0, ...) when FUN_a008d800() is at most 0x82.
 * Source form: the loop counter is initialised at its declaration.
 */
struct port_rec {
    volatile unsigned int *r0;
    volatile unsigned int *r4;
    volatile unsigned int *r8;
    volatile unsigned int *rc;
    unsigned int _10[4];
    volatile unsigned int *r20;
    unsigned char _24[0x34 - 0x24];
};
extern struct port_rec DAT_a807db00[];
extern unsigned int _DAT_a8078634;
extern int FUN_a0073044(const char *, ...);
extern unsigned int FUN_a00a7468(unsigned int, unsigned char, unsigned short);
extern int FUN_a00a2a80(unsigned char);
extern void FUN_a00a2b98(void);
extern int FUN_a00a2b08(unsigned char);
extern int FUN_a00a2ecc(void);
extern int FUN_a00a2c18(unsigned char);
extern int FUN_a00a2a28(void);
extern int hdmi_Init_Interrupt(void);
extern void FUN_a00a73ac(unsigned int, volatile unsigned int *);
extern void FUN_a00a73d4(unsigned int, volatile unsigned int *);
extern void INIT_handler(unsigned int);
extern unsigned char FUN_a008d800(void);
extern void FUN_a00b2070(unsigned int, void (*)(void));
extern void FUN_a009f654(void);
static const char fn_[] = "_hdmi21_Initialize";

int hdmi21_Initialize(void)
{
    unsigned char i = 0;
    unsigned char port;

    if (_DAT_a8078634 & 1)
        FUN_a0073044("[INIT]: %s\n", fn_);
    if (FUN_a00a7468(8, 0, 0x1f0c) == 0)
        FUN_a00a2a80(1);
    FUN_a00a2b98();
    FUN_a00a2b08(1);
    FUN_a00a2ecc();
    if (FUN_a00a7468(8, 0, 0x1f0c) == 0)
        FUN_a00a2a80(0);
    FUN_a00a2c18(1);
    FUN_a00a2a28();
    hdmi_Init_Interrupt();
    for (; i < 2; i++) {
        port = i;
        FUN_a00a73d4(1, DAT_a807db00[port].r0 + 2);
        DAT_a807db00[port].rc[0x14] = (DAT_a807db00[port].rc[0x14] & ~0xff) | 1;
        FUN_a00a73ac(0xc, DAT_a807db00[port].r0 + 1);
        INIT_handler(port);
        DAT_a807db00[port].r20[0xf] = 0x10000;
    }
    if (FUN_a008d800() <= 0x82)
        FUN_a00b2070(0, FUN_a009f654);
    return 0;
}
