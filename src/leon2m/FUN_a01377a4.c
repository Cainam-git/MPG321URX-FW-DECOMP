/* leon2m FUN_a01377a4 @ 0xa01377a4 (-mcpu=v8 -O3 -g)
 * Clears a word w, reads into it through func_0x4008c4d0(1, 0xc, &w, 1) and returns 1 when p1 & (bits 8-15 of w)
 * is nonzero, otherwise 0. Same code as FUN_a01377e8 with other constants.
 */
extern void func_0x4008c4d0();

unsigned int FUN_a01377a4(unsigned short param_1, unsigned int param_2)
{
    unsigned int local_c;
    
    local_c = 0;
    func_0x4008c4d0(1, 0xc, &local_c, 1);
    return (param_1 & ((local_c & 0xff00) >> 8)) != 0;
}
