/* leon2m FUN_a01411f8 @ 0xa01411f8-0xa014122c (13 words), flags -mcpu=v8 -O3 -g.
 * Twin of src FUN_a01411c8.
 * Code facts: p &= 0xff in place (and %i0 in the call delay slot); r = FUN_a011909c() (no args,
 * returns the low nibble of 0xcf012fdc, re-extended with and 0xff here); returns the SECOND byte
 * [((p << 4) + r) * 2 + 1] of the ROM table at 0x1a3648 (16 two-byte entries per p).
 * Fixes vs the autoc draft (38.46): the FUN_a01411c8 twin form (separate 'p &= 0xff;', u8 callee, u32 r,
 * one index expression with + 1 inside the subscript; the draft passed a stray 2nd param and used
 * the mid-entry address 0x1a3649). Aids: none.
 */
extern unsigned char DAT_001a3648[];
extern unsigned char FUN_a011909c(void);

unsigned char FUN_a01411f8(unsigned int p)
{
    unsigned int r;

    p &= 0xff;
    r = FUN_a011909c();
    return DAT_001a3648[((p << 4) + r) * 2 + 1];
}
