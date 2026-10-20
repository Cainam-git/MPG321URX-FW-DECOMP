/* FUN_a0088f90 (leon2s, 0xa0088f90-0xa0088fb0, 8 words, leaf). Flags -mcpu=v8 -Os -g.
 * void (u8 port, u16 bits): ARR_a8078a00[port] |= bits on the u16 array at 0xa8078a00 (lduh, or, sth; the
 * byte offset is port * 2, firmware 'add %o0,%o0'). Returns nothing.
 */
extern unsigned short ARR_a8078a00[];

void FUN_a0088f90(unsigned char port, unsigned short bits)
{
    ARR_a8078a00[port] |= bits;
}
