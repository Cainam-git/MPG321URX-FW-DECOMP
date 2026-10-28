/* leon2m FUN_a00f6340 @ 0xa00f6340 (7 words), flags -mcpu=v8 -O3 -g.
 * Returns FUN_a00f1a90(blk, 0x43): the low byte of register 0x43 of block blk, read through the
 * 0x19A31C block table. Caller: FUN_a012a774. One of three neighbouring getters (registers 0x43, 0x44, 0x45);
 * blk is the only parameter.
 */
extern unsigned char FUN_a00f1a90(unsigned char blk, unsigned char reg);

unsigned char FUN_a00f6340(unsigned char blk)
{
    return FUN_a00f1a90(blk, 0x43);
}
