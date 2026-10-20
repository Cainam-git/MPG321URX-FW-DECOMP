/* leon2m FUN_a01216f8 @ 0xa01216f8-0xa0121714 (7 words).
 * Sets bit ch of the word at 0xa802c9e4 (read-modify-write: load, or with 1 << ch, store). FUN_a0121714 clears
 * and sets the same bit of this word for its first argument. Called twice from FUN_a012f43c.
 * The shift uses only the low five bits of ch, so the byte parameter goes to the sll without a zero-extension.
 */
extern unsigned int DAT_a802c9e4;

void FUN_a01216f8(unsigned char ch)
{
    DAT_a802c9e4 |= 1 << ch;
}
