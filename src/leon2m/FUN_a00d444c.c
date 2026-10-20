/* leon2m FUN_a00d444c @ 0xa00d444c-0xa00d44bc (28 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Reads register 0xf of the given port with FUN_a0145660, limits it to the value of register 0x12 (read again
 * with FUN_a0145660 when it is lower) and writes the result back to register 0xf with FUN_a0145808(port, 0xf,
 * value, 1).
 */
extern unsigned short FUN_a0145660(unsigned char, int);
extern void FUN_a0145808(unsigned char, int, unsigned short, int);

void FUN_a00d444c(unsigned char port)
{
    unsigned short v = FUN_a0145660(port, 0xf);

    if (v > FUN_a0145660(port, 0x12))
        v = FUN_a0145660(port, 0x12);
    FUN_a0145808(port, 0xf, v, 1);
}
