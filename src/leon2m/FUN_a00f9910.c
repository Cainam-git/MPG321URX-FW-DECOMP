/* leon2m FUN_a00f9910 @ 0xa00f9910-0xa00f9940 (12 words).
 * Calls FUN_a00f1b5c(blk, 0x2f, 0x80, 1) and then FUN_a00f1b5c(blk, 0x2f, 0x80, 0): bit 7 of register 0x2f of block
 * blk is set and then cleared again. The function ends at 0xa00f9940; the word that follows is data.
 */
extern void FUN_a00f1b5c(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);

void FUN_a00f9910(unsigned int blk)
{
    FUN_a00f1b5c(blk & 0xff, 0x2f, 0x80, 1);
    FUN_a00f1b5c(blk & 0xff, 0x2f, 0x80, 0);
}
