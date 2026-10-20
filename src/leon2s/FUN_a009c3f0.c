/* FUN_a009c3f0 (leon2s 0xa009c3f0-0xa009c434, 68 bytes, leaf), flags -mcpu=v8 -Os -g.
 * r = register-block pointer at +4 of the 0x34-byte port record ARR_a807db00[port] (volatile MMIO block, as in
 * FUN_a009c558). Reads bit 17 of r[10] (offset 0x28) 50 times and returns 1 when the last read was clear, else 0.
 */
struct PortRec { unsigned int w00; volatile unsigned int *regs; unsigned char pad[0x34 - 8]; };
extern struct PortRec ARR_a807db00[];

unsigned int FUN_a009c3f0(unsigned char port)
{
    volatile unsigned int *r = ARR_a807db00[port].regs;
    unsigned char i;
    unsigned int v;

    for (i = 0; i < 50; i++)
        v = r[10] & 0x20000;
    return v == 0;
}
