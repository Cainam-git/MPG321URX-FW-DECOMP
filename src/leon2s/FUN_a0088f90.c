/* FUN_a0088f90 (leon2s, 0xa0088f90-0xa0088fb0, 8 words, leaf). Flags -mcpu=v8 -Os -g.
 Code facts: void (u8 port, u16 bits): ARR_a8078a00[port] |= bits on the u16 array at 0xa8078a00 (lduh, or, sth; index = port * 2 bytes).
 Fixes vs draft: BEHAVIOUR the draft indexed the u16 array with port * 2 elements (byte offset port * 4, fw 'add %o0,%o0' = 2 bytes)
 and returned a value from a void function. Aids: none.
 */
extern unsigned short ARR_a8078a00[];

void FUN_a0088f90(unsigned char port, unsigned short bits)
{
    ARR_a8078a00[port] |= bits;
}
