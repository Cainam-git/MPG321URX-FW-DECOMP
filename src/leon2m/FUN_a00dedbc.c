/* FUN_a00dedbc (leon2m 0xa00dedbc-0xa00dedc8, 12 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Clears the byte DAT_a802b0bd. Nothing in the image refers to it: no call, branch, sethi/or constant or address
 * word. It lies between FUN_a00dedb0 and FUN_a00dedc8. Source form: a direct store to the extern symbol (the store
 * sits in the retl delay slot).
 */
extern unsigned char DAT_a802b0bd;

void FUN_a00dedbc(void)
{
    DAT_a802b0bd = 0;
}
