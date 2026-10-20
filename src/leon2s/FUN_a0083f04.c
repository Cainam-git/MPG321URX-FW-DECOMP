/* FUN_a0083f04 (leon2s 0xa0083f04-0xa0083fb8, 180 bytes), flags -mcpu=v8 -Os -g.
 * Passes port = FUN_a0083ed0(p) as the first argument of four FUN_a00a7718 calls. With en set the other
 * arguments are (0x490, 1, 1), (0x434, 1, 0), (0x433, 0x10, 0), (0x490, 2, 0); with en clear the same calls
 * with the last argument inverted. The last call is a tail call.
 * Source form: each arm of the en test makes all four calls.
 */
extern unsigned char FUN_a0083ed0(unsigned char a);
extern void FUN_a00a7718(unsigned char, unsigned short, unsigned char, unsigned char);

void FUN_a0083f04(unsigned char p, unsigned char en)
{
    unsigned char port = FUN_a0083ed0(p);

    if (en) {
        FUN_a00a7718(port, 0x490, 1, 1);
        FUN_a00a7718(port, 0x434, 1, 0);
        FUN_a00a7718(port, 0x433, 0x10, 0);
        FUN_a00a7718(port, 0x490, 2, 0);
    } else {
        FUN_a00a7718(port, 0x490, 1, 0);
        FUN_a00a7718(port, 0x434, 1, 1);
        FUN_a00a7718(port, 0x433, 0x10, 1);
        FUN_a00a7718(port, 0x490, 2, 1);
    }
}
