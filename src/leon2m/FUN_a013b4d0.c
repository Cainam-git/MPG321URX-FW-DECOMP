/* FUN_a013b4d0 (leon2m 0xa013b4d0-0xa013b4e8, 24 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores a, b and c to the bytes 0, 1 and 2 of the array DAT_a802a468. Nothing in the image refers to it: no call,
 * branch, sethi/or constant or address word. It lies between FUN_a013b4a4 and FUN_a013b4e8. Source form: one array
 * symbol; GCC orders the stores 0, 2, 1.
 */
extern unsigned char DAT_a802a468[];

void FUN_a013b4d0(unsigned char a, unsigned char b, unsigned char c)
{
    DAT_a802a468[0] = a;
    DAT_a802a468[1] = b;
    DAT_a802a468[2] = c;
}
