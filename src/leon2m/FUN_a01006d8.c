/* FUN_a01006d8 (leon2m 0xa01006d8-0xa01006e4, 12 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Stores its argument to the byte DAT_a8027a74. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between switchdataD_a010062c and FUN_a01006e4. Source form: a direct store to
 * the extern symbol (the store sits in the retl delay slot).
 */
extern unsigned char DAT_a8027a74;

void FUN_a01006d8(unsigned char v)
{
    DAT_a8027a74 = v;
}
