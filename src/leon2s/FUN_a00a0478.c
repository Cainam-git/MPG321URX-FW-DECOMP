/*
 * FUN_a00a0478 (leon2s 0xa00a0478-0xa00a0514, 156 bytes), flags -mcpu=v8 -Os -g. Called by
 * DRV_HDMI_ModeDetect_FSM_Complete with a 5-byte block.
 * u8 (u8 port, u8 *out). When FUN_a00a03c8(port) returns 0: clears out[0..4] with FUN_a00b15ac(out, 0, 5) and
 * returns 1. Otherwise, with w = word 2 of the register block ARR_a807db00[port].regs (0x34-byte records,
 * pointer at +0x2c): out[0] = bits 20..23 of w when they are non-zero, else 0x10; out[1] = bit 27 of w; returns 0.
 * w is read again for each use (volatile: the record pointers address hardware registers, as in the other users of
 * ARR_a807db00).
 * Source form: the FUN_a00b15ac block stands between the out[0] value selection and the stores, reached by goto
 * from the FUN_a00a03c8 test (its place in the source gives the firmware's layout and the recomputed record
 * address after the join).
 */
struct Port34 {
    unsigned char pad[0x2c];
    volatile unsigned int *regs;
    unsigned char rest[0x34 - 0x30];
};
extern struct Port34 ARR_a807db00[];
extern unsigned char FUN_a00a03c8(unsigned char);
extern void *FUN_a00b15ac(unsigned char *, unsigned char, int);

unsigned char FUN_a00a0478(unsigned char port, unsigned char *out)
{
    unsigned char n = 0x10;

    if (FUN_a00a03c8(port) == 0)
        goto fail;
    if ((ARR_a807db00[port].regs[2] >> 16) & 0xf0)
        n = (ARR_a807db00[port].regs[2] >> 20) & 0xf;
    goto store;
fail:
    FUN_a00b15ac(out, 0, 5);
    return 1;
store:
    out[0] = n;
    out[1] = (ARR_a807db00[port].regs[2] >> 27) & 1;
    return 0;
}
