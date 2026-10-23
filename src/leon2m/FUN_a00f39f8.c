/* FUN_a00f39f8 (leon2m 0xa00f39f8-0xa00f3a04, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores its argument to the word DAT_a802b7a8. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a00f39ec and FUN_a00f3a04. Source form: a direct store to the
 * extern symbol (the store sits in the retl delay slot).
 */
extern unsigned int DAT_a802b7a8;

void FUN_a00f39f8(unsigned int v)
{
    DAT_a802b7a8 = v;
}
