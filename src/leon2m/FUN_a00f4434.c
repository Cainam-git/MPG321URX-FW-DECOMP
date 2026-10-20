/* leon2m FUN_a00f4434 @ 0xa00f4434  MATCH (-mcpu=v8 -O3 -g)
 * Returns 1 when FUN_a0120a18(port) * n, compared unsigned, is greater than 2050000, else 0.
 * No direct callers found (reached through a pointer).
 */
extern unsigned short FUN_a0120a18(unsigned char port);

int FUN_a00f4434(unsigned char port, unsigned short n)
{
    return (unsigned int)(FUN_a0120a18(port) * n) > 2050000;
}
