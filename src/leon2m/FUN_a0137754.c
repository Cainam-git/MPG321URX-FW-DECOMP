/* leon2m FUN_a0137754 @ 0xa0137754  MATCH (-mcpu=v8 -O2 -g)
 * Calls func_0x4008c4d0(1, 0xC, &local_c, 1) with local_c = 0 and returns byte 3 of local_c (ldub [%fp-9]), the
 * low byte on this big-endian target.
 */
extern int func_0x4008c4d0();

int FUN_a0137754(void)
{
    unsigned int local_c;
    
    local_c = 0;
    func_0x4008c4d0(1, 0xc, &local_c, 1);
    return *((unsigned char *)&local_c + 3);
}
