/* leon2m FUN_a0150da4 @ 0xa0150da4-0xa0150df8 (21 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0 mismatches.
 * Code facts: FUN_a00f793c(); FUN_a00f87b0(0xd3da0); FUN_a00f63bc(0); FUN_a013b6e4(0);
 * FUN_a013b710(0); then the high nibble of byte 0xa802a4b8 |= 3 (fw: ldub; and 0xf0; or 0x30;
 * and 0xf; or; stb = gcc's bit-field insert of the high 4-bit field).
 * Fix vs the autoc draft (95.24, 'and -16' vs fw 'and 0xf0'): the byte is a struct of two 4-bit
 * fields (big-endian: hi = bits 7..4) and the source is 'DAT_a802a4b8.hi |= 3;' - the bit-field
 * lever from tools/lessons.txt; the mask form gives QImode -16 or other register order. Aids: none.
 */
extern void FUN_a00f793c(void);          /* 0xa00f793c */
extern void FUN_a00f87b0(unsigned int);  /* 0xa00f87b0 */
extern void FUN_a00f63bc(unsigned int);  /* 0xa00f63bc */
extern void FUN_a013b6e4(unsigned int);  /* 0xa013b6e4 */
extern void FUN_a013b710(unsigned char); /* 0xa013b710 */
struct B { unsigned char hi:4, lo:4; };
extern struct B DAT_a802a4b8;       /* 0xa802a4b8 */

void FUN_a0150da4(void)
{

    FUN_a00f793c();
    FUN_a00f87b0(0xd3da0);
    FUN_a00f63bc(0);
    FUN_a013b6e4(0);
    FUN_a013b710(0);
    DAT_a802a4b8.hi |= 3;
}
