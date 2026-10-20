/* leon2m FUN_a0104a34 @ 0xa0104a34-0xa0104b2c (62 words). -mcpu=v8 -O3 -g.
 * What it does: dc6c state 8 step (FRC set-up of the channel's input port), called as
 * FUN_a0104a34(port, f8, h06, f4); only port (u8) and h06 (u16) are used:
 *   1. if (block-register read FUN_a00f1a90(port, 4) & 0xf) <= 1 and bit 5 of reg 3 is clear and
 *      (reg 0x54 & 3) == 1: set bit 6 of the hardware register 0xcf012804;
 *   2. FUN_a012127c(port, h06, 1);
 *   3. set bit 7 of the hardware register 0xcf011658;
 *   4. FUN_a00f92d4(port) (= bit 7 of reg 0x8c of block port): 1 -> reg 1 of the 0x19a2fc-table block
 *      (FUN_a00f1f9c read, FUN_a00f1fe0 write) gets its low nibble set (| 0xf), 0 -> its low nibble
 *      cleared (& 0xf0);
 *   5. clear the hardware register 0xcf01136c.
 * Nothing here depends on the refresh rate; it runs for every channel in state 8.
 * Facts used: FUN_a00f92d4 is called with ONE argument (fw leaves %o1 unset) and its result is tested
 * as a byte (btst 0xff); FUN_a012127c takes (u8, u16, u8) (its asm: and %i0,0xff / sll %i1,16 / btst 0xff,%i2);
 * the 'if' arm is the '| 0xf' one (fw fall-through). volatile only on real hardware registers. Aids: none.
 */
extern unsigned char FUN_a00f1a90(unsigned char blk, unsigned char reg);
extern unsigned char FUN_a00f92d4(unsigned char port);
extern unsigned char FUN_a00f1f9c(unsigned char blk, unsigned char reg);
extern void FUN_a00f1fe0(unsigned char blk, unsigned char reg, unsigned char val);
extern void FUN_a012127c(unsigned char port, unsigned short h, unsigned char on);
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a0104a34(unsigned char port, int f8, unsigned short h, int f4)
{
    if ((FUN_a00f1a90(port, 4) & 0xf) <= 1) {
        if (!(FUN_a00f1a90(port, 3) & 0x20)) {
            if ((FUN_a00f1a90(port, 0x54) & 3) == 1)
                R(0xcf012804) |= 0x40;
        }
    }
    FUN_a012127c(port, h, 1);
    R(0xcf011658) |= 0x80;
    if (FUN_a00f92d4(port))
        FUN_a00f1fe0(port, 1, FUN_a00f1f9c(port, 1) | 0xf);
    else
        FUN_a00f1fe0(port, 1, FUN_a00f1f9c(port, 1) & 0xf0);
    R(0xcf01136c) = 0;
}
