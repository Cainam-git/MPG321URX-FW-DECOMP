/* leon2m FUN_a00bab80 @ 0xa00bab80-0xa00babe0 (24 words).
 * Sends the first len bytes of a port's transmit buffer with FUN_a01487e8(port, len, buffer): port 2 uses the
 * buffer at 0xa802d128, port 3 the buffer at 0xa802d108, any other port the buffer at 0xa802d078. All three calls
 * are tail calls.
 */
extern unsigned char DAT_a802d078[], DAT_a802d108[], DAT_a802d128[];
extern void FUN_a01487e8(unsigned char, unsigned short, unsigned char *);

void FUN_a00bab80(unsigned char port, unsigned char len)
{
    if (port == 2)
        FUN_a01487e8(2, len, DAT_a802d128);
    else if (port == 3)
        FUN_a01487e8(3, len, DAT_a802d108);
    else
        FUN_a01487e8(port, len, DAT_a802d078);
}
