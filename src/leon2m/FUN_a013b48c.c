/* FUN_a013b48c (leon2m 0xa013b48c-0xa013b4a4, 24 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores a, b and c to the halfwords 0, 1 and 2 of the array DAT_a802a46c. Nothing in the image refers to it: no
 * call, branch, sethi/or constant or address word. It lies between FUN_a013b46c and FUN_a013b4a4. Source form: one
 * array symbol; GCC orders the stores 0, 2, 1.
 */
extern unsigned short DAT_a802a46c[];

void FUN_a013b48c(unsigned short a, unsigned short b, unsigned short c)
{
    DAT_a802a46c[0] = a;
    DAT_a802a46c[1] = b;
    DAT_a802a46c[2] = c;
}
