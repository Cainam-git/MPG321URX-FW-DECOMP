/* FUN_a010b444 (leon2m 0xa010b444-0xa010b450, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores its argument to the byte DAT_a8027a88. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between switchdataD_a010b430 and FUN_a010b450. Source form: a direct store to
 * the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned char DAT_a8027a88;

void FUN_a010b444(unsigned char v)
{
    DAT_a8027a88 = v;
}
