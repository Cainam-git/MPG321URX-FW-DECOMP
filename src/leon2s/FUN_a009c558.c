/* leon2s FUN_a009c558 @ 0xa009c558-0xa009c58c (13 words), flags -mcpu=v8 -Os -g.
 * Code facts: leaf; r = register-block pointer at +4 of the 0x34-byte port record ARR_a807db00[port];
 * returns (r[2] & 0xff) << 16 | r[1] >> 16 (two full-word ld, +8 first). The record pointer is an
 * MMIO block (full-word loads with field extraction), so it is volatile.
 * Fixes vs the autoc draft (54.55): real base ARR_a807db00 (the draft used the mid-record a807db04),
 * u32 register words (the draft read shorts). Aids: none beyond the hw-register volatile.
 */
struct PortRec { unsigned int w00; volatile unsigned int *regs; unsigned char pad[0x34 - 8]; };
extern struct PortRec ARR_a807db00[];

unsigned int FUN_a009c558(unsigned char port)
{
    volatile unsigned int *r = ARR_a807db00[port].regs;
    unsigned int hi = r[2] & 0xff;

    return hi << 16 | r[1] >> 16;
}
