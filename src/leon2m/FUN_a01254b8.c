/* leon2m FUN_a01254b8 @ 0xa01254b8-0xa01254f8 (16 words).
 * Sets bit n of the byte at 0xa802c9fa when on is non-zero and clears it when on is zero. Called three times from
 * FUN_a014b750. Each arm writes its own 1 << n expression; GCC hoists the shift above the test and keeps two
 * copies of it (mov %o4, %o5). A mask variable shared by both arms gives one copy and other registers.
 */
extern unsigned char DAT_a802c9fa;

void FUN_a01254b8(unsigned char n, unsigned char on)
{
    if (on)
        DAT_a802c9fa |= 1 << n;
    else
        DAT_a802c9fa &= ~(1 << n);
}
