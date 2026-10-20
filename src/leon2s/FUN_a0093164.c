/* FUN_a0093164 (leon2s 0xa0093164-0xa00931fc, 152 bytes), flags -mcpu=v8 -Os -g.
 * Copies two byte tables into page-0 registers of a port through FUN_a00a8054(port, 0, reg, value):
 * the 5 bytes DAT_a8078600[0..4] to regs 0x11e..0x122 and the 9 bytes DAT_a80785f0[0..8] to regs
 * 0x180..0x188. The raw parameter is passed to the unsigned char port parameter on every call.
 */
extern unsigned char DAT_a8078600[];
extern unsigned char DAT_a80785f0[];
extern void FUN_a00a8054(unsigned char, unsigned int, unsigned short, unsigned char);

void FUN_a0093164(unsigned int port)
{
    unsigned char i;

    for (i = 0; i < 5; i++)
        FUN_a00a8054(port, 0, i + 0x11e, DAT_a8078600[i]);
    for (i = 0; i < 9; i++)
        FUN_a00a8054(port, 0, i + 0x180, DAT_a80785f0[i]);
}
