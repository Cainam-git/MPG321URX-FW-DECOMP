/* leon2m FUN_a00df384 @ 0xa00df384-0xa00df3d0 (19 words).
 * Polls bit 0 of func_0x4008c250(0xc00b0014) up to 1000 times; when it is set, returns the low byte of
 * func_0x4008c250(0xc00b0000). Returns 0 when the bit stays clear.
 */
extern unsigned int func_0x4008c250(unsigned int);

unsigned char FUN_a00df384(void)
{
    unsigned int c = 0;
    int i;

    for (i = 0; i < 1000; i++) {
        if (func_0x4008c250(0xc00b0014) & 1) {
            c = func_0x4008c250(0xc00b0000);
            break;
        }
    }
    return c;
}
