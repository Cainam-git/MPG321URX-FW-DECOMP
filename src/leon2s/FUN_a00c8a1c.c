/* leon2s FUN_a00c8a1c @ 0xa00c8a1c-0xa00c8a80 (25 words).
 * Read-modify-write of bit 0 through the ROM routines at 0xa0fb7fd8 (read) and 0xa0fb8054 (write): reads
 * func_0xa0fb7fd8(p, 0, 0x27), sets bit 0 when on is 1 and clears it otherwise, and writes the byte back with
 * func_0xa0fb8054(p, 0, 0x27, value).
 */
extern unsigned char func_0xa0fb7fd8(unsigned char, int, int);
extern void func_0xa0fb8054(unsigned char, int, int, unsigned char);

void FUN_a00c8a1c(unsigned char p, unsigned char on)
{
    if (on == 1)
        func_0xa0fb8054(p, 0, 0x27, func_0xa0fb7fd8(p, 0, 0x27) | 1);
    else
        func_0xa0fb8054(p, 0, 0x27, func_0xa0fb7fd8(p, 0, 0x27) & 0xfe);
}
