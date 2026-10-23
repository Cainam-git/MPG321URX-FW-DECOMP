/* FUN_a01079f4 (leon2m 0xa01079f4-0xa0107a08, 20 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores a to byte 3 and b to byte 4 of the byte array DAT_a8027a82 (0xa8027a85, 0xa8027a86). Nothing in the image
 * refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a01079c0 and FUN_a0107a08.
 * Source form: one array symbol (one sethi/or base, offsets 3 and 4).
 */
extern unsigned char DAT_a8027a82[];

void FUN_a01079f4(unsigned char a, unsigned char b)
{
    DAT_a8027a82[3] = a;
    DAT_a8027a82[4] = b;
}
