/* leon2m FUN_a00f92d4 @ 0xa00f92d4  MATCH (-mcpu=v8 -O2 -g)
 * Returns bit 7 of FUN_a00f1a90(param_1 & 0xff, 0x8c) as 0 or 1. The bit is extracted with a left shift by 24
 * followed by a logical right shift by 31; the unsigned int local makes the compiler emit srl rather than sra, and
 * the two separate assignments keep the shifts as two instructions.
 */
/* FUN_a00f1a90 at 0xa00f1a90 – called with (masked_byte, 0x8c) */
extern int FUN_a00f1a90(int, int);

int FUN_a00f92d4(int param_1, int param_2)
{
    unsigned int r;
    r = (unsigned int)FUN_a00f1a90(param_1 & 0xff, 0x8c);
    r = r << 24;
    return (int)(r >> 31);
}
