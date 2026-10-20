/* leon2m FUN_a0149130 @ 0xa0149130-0xa014913c (3 words).
 * Stores v into byte 0xa802e3ed (sethi, then the store in the delay slot of retl). Leaf routine directly after
 * FUN_a0149064; the function table listed it as part of FUN_a0149064 until its range was corrected.
 */
extern unsigned char DAT_a802e3ed;

void FUN_a0149130(unsigned char v)
{
    DAT_a802e3ed = v;
}
