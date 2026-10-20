/* leon2m FUN_a0136ff0 @ 0xa0136ff0 (-mcpu=v8 -O2 -g)
 * Calls func_0x4008c4d0(1, 0x0C, &local, 1) with a zero-initialised 4-byte local and returns bit 0 of the local's
 * first byte (big-endian: bits 24..31 of the word): ((unsigned char *)&local_c)[0] & 1.
 */
extern int func_0x4008c4d0();

int FUN_a0136ff0(void)
{
    unsigned int local_c;
    
    local_c = 0;
    func_0x4008c4d0(1, 0xc, &local_c, 1);
    return *((unsigned char *)&local_c) & 1;
}
