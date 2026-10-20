/* leon2m FUN_a0121b98 @ 0xa0121b98-0xa0121bcc (13 words), flags -mcpu=v8 -O3 -g.
 * Code facts: read-modify-write of bit-block register 0x40: v = FUN_a00f1f9c(blk, 0x40) (u8 read);
 * sibcall FUN_a00f1fe0(blk, 0x40, (v & 1) | (on << 1)) (u8 write). Both params are u8.
 * Fixes vs the autoc draft (53.85): the 'and 1' is on the READ value (%o0 after the first call), not
 * on blk; the write callee takes 3 args (src prototype void(u8,u8,u8)). void. Aids: none.
 */
extern unsigned char FUN_a00f1f9c(unsigned char, unsigned char);
extern void FUN_a00f1fe0(unsigned char, unsigned char, unsigned char);

void FUN_a0121b98(unsigned char blk, unsigned char on)
{
    unsigned char v;

    v = FUN_a00f1f9c(blk, 0x40);
    FUN_a00f1fe0(blk, 0x40, (v & 1) | (on << 1));
}
