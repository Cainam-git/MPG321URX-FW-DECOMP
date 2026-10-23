/* FUN_a00a03c8 (leon2s 0xa00a03c8-0xa00a0478, 176 bytes, leaf), flags -mcpu=v8 -Os -g.
 * r = word pointer at +0x2c of entry port of ARR_a807db00 (0x34-byte entries). Returns 0 when bits 4-5 of r[0] are
 * set, when byte 2 of r[0] is not 1, when (byte 3 of r[0]) * 0x100 + byte 0 of r[1] is not 2, when
 * (byte 1 of r[1]) * 0x100 + byte 2 of r[1] is 0, or when byte 3 of r[1] is 0; otherwise returns 1.
 * r points to registers: every test reads r[0] / r[1] again, so the pointer target is volatile.
 * Source form: all five tests are one '||' condition with a single 'return 0'.
 */
struct Port34 { unsigned char pad[0x2c]; volatile unsigned int *regs; unsigned char rest[0x34 - 0x30]; };
extern struct Port34 ARR_a807db00[];

unsigned char FUN_a00a03c8(unsigned char port)
{
    volatile unsigned int *r = ARR_a807db00[port].regs;

    if ((r[0] & 0x30) || ((r[0] >> 16) & 0xff) != 1 || (r[0] >> 24) * 0x100 + (r[1] & 0xff) != 2 ||
        ((r[1] >> 8) & 0xff) * 0x100 + ((r[1] >> 16) & 0xff) == 0 || (r[1] >> 24) == 0)
        return 0;
    return 1;
}
