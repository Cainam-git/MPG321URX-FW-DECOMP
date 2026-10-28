/* leon2m FUN_a011d670 @ 0xa011d670-0xa011d740 (52 words, leaf), flags -mcpu=v8 -O3 -g. No direct callers.
 * Parameters (c, a, b): a and b are limited to 3. The register is chosen by c: 1..6 -> 0xcf016134, 0xcf01614c,
 * 0xcf016164, 0xcf01617c, 0xcf016194, 0xcf0161ac; 16..19 -> 0xcf01640c; any other c writes nothing. The register
 * keeps its bits 4..7 (& 0xf0), then the byte (a << 2) | b is ORed in.
 * Source form: every arm of the if/else-if chain holds its own copy of the two read-modify-writes with its own
 * register address; GCC merges the identical tails into one block and computes each address before its test,
 * so each arm keeps its own sethi of 0xcf016000 as in the firmware. One shared pointer variable lets the
 * compiler share that high part.
 */
#define R(a) ((volatile unsigned int *)(a))

void FUN_a011d670(unsigned char c, unsigned char a, unsigned char b)
{
    if (a > 3)
        a = 3;
    if (b > 3)
        b = 3;
    if (c == 1) {
        *R(0xcf016134) &= 0xf0;
        *R(0xcf016134) |= (unsigned char)((a << 2) | b);
    } else if (c == 2) {
        *R(0xcf01614c) &= 0xf0;
        *R(0xcf01614c) |= (unsigned char)((a << 2) | b);
    } else if (c == 3) {
        *R(0xcf016164) &= 0xf0;
        *R(0xcf016164) |= (unsigned char)((a << 2) | b);
    } else if (c == 4) {
        *R(0xcf01617c) &= 0xf0;
        *R(0xcf01617c) |= (unsigned char)((a << 2) | b);
    } else if (c == 5) {
        *R(0xcf016194) &= 0xf0;
        *R(0xcf016194) |= (unsigned char)((a << 2) | b);
    } else if (c == 6) {
        *R(0xcf0161ac) &= 0xf0;
        *R(0xcf0161ac) |= (unsigned char)((a << 2) | b);
    } else if ((unsigned char)(c - 16) < 4) {
        *R(0xcf01640c) &= 0xf0;
        *R(0xcf01640c) |= (unsigned char)((a << 2) | b);
    }
}
