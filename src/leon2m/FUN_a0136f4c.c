/* leon2m FUN_a0136f4c @ 0xa0136f4c (-mcpu=v8 -O2 -g)
 * Builds a word with DAT_a802a457 in bits 16..23 and param_1 bits 0..3 mapped to 0x04, 0x08, 0x10, 0x20 in the top
 * byte, and passes its address to func_0x4008c5f8(1, 8, &local, 1).
 */
extern unsigned char DAT_a802a457;
extern int func_0x4008c5f8();

void FUN_a0136f4c(unsigned short param_1)
{
    unsigned int flags = 0;
    unsigned int local;
    
    if (param_1 & 1)  flags = 4;
    if (param_1 & 2)  flags |= 8;
    if (param_1 & 4)  flags |= 0x10;
    if (param_1 & 8)  flags |= 0x20;
    
    local = ((unsigned int)DAT_a802a457 << 16) | (flags << 24);
    func_0x4008c5f8(1, 8, &local, 1);
}
