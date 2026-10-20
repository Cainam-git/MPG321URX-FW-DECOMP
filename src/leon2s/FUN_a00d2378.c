/* leon2s FUN_a00d2378 @ 0xa00d2378  MATCH (-mcpu=v8 -Os -g)
 * Read-modify-write of register 0xD0013F50: func_0xa0f71528 reads it into a one-word buffer, func_0xa0f714b8(buf,
 * 0xb, 0, param_1) writes param_1 into bits 11..0 of the buffered value, and func_0xa0f71534 writes it back.
 * Returns 1. Same field-write pattern as FUN_a00d2300 and FUN_a00d2678.
 */
extern int func_0xa0f71528(unsigned int);
extern void func_0xa0f714b8(unsigned int *, int, int, unsigned short);
extern int func_0xa0f71534(unsigned int, unsigned int);

int FUN_a00d2378(unsigned short param_1)
{
    unsigned int local_c;
    unsigned int buf[1];
    
    buf[0] = 0;
    local_c = func_0xa0f71528(0xd0013f50);
    buf[0] = local_c;
    func_0xa0f714b8(buf, 0xb, 0, param_1 & 0xffff);
    func_0xa0f71534(0xd0013f50, buf[0]);
    return 1;
}
