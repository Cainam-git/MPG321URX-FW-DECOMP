/* FUN_a013adf4 (leon2m 0xa013adf4-0xa013ae00, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores its argument to the byte DAT_a802a460. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a013adcc and FUN_a013ae00. Source form: a direct store to the
 * extern symbol (the store sits in the retl delay slot).
 */
extern unsigned char DAT_a802a460;

void FUN_a013adf4(unsigned char v)
{
    DAT_a802a460 = v;
}
