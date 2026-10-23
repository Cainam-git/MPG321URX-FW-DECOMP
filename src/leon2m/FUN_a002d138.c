/* FUN_a002d138 (leon2m 0xa002d138-0xa002d148, 16 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores 1 to the byte DAT_a802b0bd. Nothing in the image refers to it: no call, branch, sethi/or constant or
 * address word. It lies between FUN_a002d10c and FUN_a002d148. Source form: a direct store of a constant to the
 * extern symbol (the store sits in the retl delay slot).
 */
extern unsigned char DAT_a802b0bd;

void FUN_a002d138(void)
{
    DAT_a802b0bd = 1;
}
