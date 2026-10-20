/* leon2m FUN_a0080bc0 @ 0xa0080bc0-0xa0080bd8 (6 words).
 * Returns 1 when bit 3 of byte 0xa802af41 is set and 0 otherwise (the comparison result is formed with
 * cmp/addx, without a branch). A leaf routine without a register window.
 */
extern unsigned char DAT_a802af41;

int FUN_a0080bc0(void)
{
    if (DAT_a802af41 & 8)
        return 1;
    return 0;
}
