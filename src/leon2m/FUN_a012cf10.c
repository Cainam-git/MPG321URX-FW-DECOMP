/* FUN_a012cf10 (leon2m 0xa012cf10-0xa012cf1c, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores its argument to the byte DAT_a802e1d7. Called by gap. It lies between FUN_a012cee4 and FUN_a012cf1c.
 * Source form: a direct store to the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned char DAT_a802e1d7;

void FUN_a012cf10(unsigned char v)
{
    DAT_a802e1d7 = v;
}
