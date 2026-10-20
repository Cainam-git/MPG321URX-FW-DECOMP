/* leon2m FUN_a013c910 @ 0xa013c910  byte copy (hand)
 * memcpy-like: copies n bytes from src to dst, one byte at a time, counting n down to -1 (leaf function; returns dst like memcpy). Called by the display set-up FUN_a01038c0 (copies 0x3C bytes of the input timing record to the stack)
 * and by FUN_a0082b00, FUN_a0088724, FUN_a00ba184 and others.
 */
void *FUN_a013c910(void *dst, const void *src, int n)
{
    unsigned char *d = dst;
    const unsigned char *s = src;
    while (n-- != 0)
        *d++ = *s++;
    return dst;
}
