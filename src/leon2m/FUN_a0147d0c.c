/* leon2m FUN_a0147d0c @ 0xa0147d0c-0xa0147d70 (25 words).
 * Converts the four characters s[n - 8] .. s[n - 5] with FUN_a0123c4c ('0'-'9' and 'A'-'F' to their digit value)
 * and returns them combined as a 16-bit value, s[n - 8] in bits 12-15 down to s[n - 5] in bits 0-3.
 * No direct callers were found.
 */
extern unsigned char FUN_a0123c4c(int ch);

unsigned short FUN_a0147d0c(unsigned char *s, unsigned char n)
{
    return (FUN_a0123c4c(s[n - 8]) << 12) | (FUN_a0123c4c(s[n - 7]) << 8) |
           (FUN_a0123c4c(s[n - 6]) << 4) | FUN_a0123c4c(s[n - 5]);
}
