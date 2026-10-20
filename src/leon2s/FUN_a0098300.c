/* FUN_a0098300 (leon2s, 0xa0098300-0xa0098330, 48 bytes, 12 words, leaf).
 * Flags: -mcpu=v8 -Os -g.
 * Port record = DAT_a807db00 + (u8)param_1 * 0x34 (52-byte records); the word at +0x18 is a register-block
 * pointer; returns 1 when bits 24..27 of the register at that block + 0x90 are 0.
 * The record stride is 0x34 bytes. The register block is volatile (MMIO: the firmware reads the full word
 * with ld and shifts; the other words of this record are register bases too, e.g. +0 used with
 * FUN_a00a7408 and read-modify-write at +0x84 in FUN_a009c6e4); the RAM record itself is not volatile.
 */
struct Port { unsigned char pad[0x18]; volatile unsigned int *regs; unsigned char rest[0x34 - 0x1c]; };
extern struct Port DAT_a807db00[];

int FUN_a0098300(unsigned int param_1)
{
    unsigned int val = DAT_a807db00[param_1 & 0xff].regs[0x90 / 4];
    return ((val >> 0x18) & 0xf) == 0;
}
