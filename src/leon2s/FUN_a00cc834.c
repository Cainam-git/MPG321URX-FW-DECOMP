/* FUN_a00cc834 (leon2s 0xa00cc834-0xa00cc8d4, 160 bytes), flags -mcpu=v8 -Os -g.
 * For port 2: the register word selected by the index in 0xcf018d00 (address (index << 2) | 0xcf000000)
 * gets bit 1 set when on != 0, cleared otherwise. For every other port: FUN_a00c76c0(port, 4, 0x10, 1)
 * when on != 0, FUN_a00c76c0(port, 4, 0x10, 0) otherwise, as a leaf tail call.
 * Source forms: one call per arm (GCC keeps both argument sets and shares the call); the register address
 * is recomputed in each arm.
 */
#define _DAT_cf018d00 (*(volatile unsigned int *)0xcf018d00)
extern void FUN_a00c76c0(unsigned char port, unsigned short reg, unsigned char mask, unsigned char set);

void FUN_a00cc834(unsigned char port, unsigned char on)
{
    if (port == 2) {
        if (on)
            *(volatile unsigned int *)((_DAT_cf018d00 << 2) | 0xcf000000) |= 2;
        else
            *(volatile unsigned int *)((_DAT_cf018d00 << 2) | 0xcf000000) &= ~2;
    } else {
        if (on)
            FUN_a00c76c0(port, 4, 0x10, 1);
        else
            FUN_a00c76c0(port, 4, 0x10, 0);
    }
}
