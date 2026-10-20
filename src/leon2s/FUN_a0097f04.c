/* FUN_a0097f04 (leon2s 0xa0097f04-0xa0097ff4, 240 bytes), flags -mcpu=v8 -Os -g. Returns 1.
 * Counts byte +6 of the 0x18-byte record DAT_a807d650[port] down while the low byte of word 0x10
 * of the port register block r4 (0x34-byte record DAT_a807db00[port]) is not 0x82, else clears it. Then
 * FUN_a00a07b8(port, 0x16); when FUN_a008d800() returns more than 0x82 also FUN_a00a07b8 with 8, 0xb and
 * 0xc. Finally sets the record state word to 7; the source tests FUN_a0097ed0(port) and stores 7 in both
 * arms (GCC keeps the test and both stores).
 * Source forms: the hold step is a static helper taking the raw parameter as unsigned char (the firmware
 * converts the port twice); the record is indexed directly in every access.
 */
struct port_rec {
    unsigned int _00;
    volatile unsigned int *r4;
    unsigned char _08[0x34 - 8];
};
struct eq_state {
    unsigned int st;
    unsigned char cnt;
    unsigned char _5;
    unsigned char hold;
    unsigned char _7[0x18 - 7];
};
extern struct port_rec DAT_a807db00[];
extern struct eq_state DAT_a807d650[];
extern void FUN_a00a07b8(unsigned char, unsigned int);
extern unsigned char FUN_a008d800(void);
extern unsigned char FUN_a0097ed0(unsigned char);

static void hold_step(unsigned char port)
{
    if (DAT_a807d650[port].hold != 0 && (DAT_a807db00[port].r4[0x10] & 0xff) != 0x82)
        DAT_a807d650[port].hold--;
    else
        DAT_a807d650[port].hold = 0;
}

int FUN_a0097f04(unsigned int param_1)
{
    unsigned char port;

    hold_step(param_1);
    port = param_1;
    FUN_a00a07b8(port, 0x16);
    if (FUN_a008d800() > 0x82) {
        FUN_a00a07b8(port, 8);
        FUN_a00a07b8(port, 0xb);
        FUN_a00a07b8(port, 0xc);
    }
    if (FUN_a0097ed0(port) == 0)
        DAT_a807d650[port].st = 7;
    else
        DAT_a807d650[port].st = 7;
    return 1;
}
