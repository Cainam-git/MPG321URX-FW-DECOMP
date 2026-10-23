/* leon2m FUN_a0129c10 @ 0xa0129c10-0xa0129c64 (21 words).
 * Sets byte 0xa802ca04 to 1 when on is nonzero. Then, when that byte is nonzero, stores FUN_a0101bb0(on) in it and,
 * when the result is 0, calls FUN_a0101c64(1) (tail call). No return value.
 */
extern unsigned char DAT_a802ca04;
extern int FUN_a0101bb0(unsigned char init);
extern void FUN_a0101c64(unsigned char);

void FUN_a0129c10(unsigned char on)
{
    if (on)
        DAT_a802ca04 = 1;
    if (DAT_a802ca04) {
        DAT_a802ca04 = FUN_a0101bb0(on);
        if (DAT_a802ca04 == 0)
            FUN_a0101c64(1);
    }
}
