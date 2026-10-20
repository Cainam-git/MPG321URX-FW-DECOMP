/* FUN_a0087db4 (leon2s 0xa0087db4-0xa0087e60, 172 bytes), flags -mcpu=v8 -Os -g.
 * Switches a port between two register setups with FUN_a00a7940 (port, reg, mask, set): en == 1 clears bit 1
 * of reg 0x76 and sets bits 0 and 1 of reg 0xa0 and bit 6 of reg 0x67; any other en does the opposite.
 * Source form: each arm ends with its own reg 0x67 call (GCC sets the shared sibling-call arguments once).
 */
extern void FUN_a00a7940(unsigned int port, short reg, unsigned int mask, unsigned int mode);

void FUN_a0087db4(unsigned int port, unsigned char en)
{
    port &= 0xff;
    if (en == 1) {
        FUN_a00a7940(port, 0x76, 2, 0);
        FUN_a00a7940(port, 0xa0, 1, 1);
        FUN_a00a7940(port, 0xa0, 2, 1);
        FUN_a00a7940(port, 0x67, 0x40, 1);
    } else {
        FUN_a00a7940(port, 0x76, 2, 1);
        FUN_a00a7940(port, 0xa0, 1, 0);
        FUN_a00a7940(port, 0xa0, 2, 0);
        FUN_a00a7940(port, 0x67, 0x40, 0);
    }
}
