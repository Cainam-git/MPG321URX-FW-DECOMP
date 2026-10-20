/* leon2m FUN_a00fca40 @ 0xa00fca40-0xa00fca4c (3 words).
 * Returns byte 0xa802c97f. A three-word leaf routine without a register window (sethi, retl, ldub in the delay
 * slot); the neighbouring FUN_a00fca34 returns byte 0xa802c97e the same way.
 */
extern unsigned char DAT_a802c97f;

unsigned char FUN_a00fca40(void)
{
    return DAT_a802c97f;
}
