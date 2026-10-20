/* leon2s FUN_a009c558 @ 0xa009c558-0xa009c58c (13 words), flags -mcpu=v8 -Os -g.
 * Leaf; r = register-block pointer at +4 of the 0x34-byte port record ARR_a807db00[port]; returns
 * (r[2] & 0xff) << 16 | r[1] >> 16 (two full-word ld, +8 first). The record pointer is an MMIO block
 * (full-word loads with field extraction), so it is volatile.
 * The base is ARR_a807db00; the register words are u32.
 * Compiler aid: only the hardware-register volatile.
 */
struct PortRec { unsigned int w00; volatile unsigned int *regs; unsigned char pad[0x34 - 8]; };
extern struct PortRec ARR_a807db00[];

unsigned int FUN_a009c558(unsigned char port)
{
    volatile unsigned int *r = ARR_a807db00[port].regs;
    unsigned int hi = r[2] & 0xff;

    return hi << 16 | r[1] >> 16;
}
