/* leon2s FUN_a00d23bc @ 0xa00d23bc (-mcpu=v8 -Os -g)
 * A = 0xD0013F60 when p1 == 0, otherwise 0xD0013F70. Reads w = func_0xa0f71528(A), calls func_0xa0f714b8(&w, 0x1f,
 * 0x1f, p2 & 0xff) and writes w back through func_0xa0f71534(A, w). Returns 1.
 * Source form: Ghidra's type and symbol names are kept.
 */
extern int func_0xa0f71528(unsigned int);
extern void func_0xa0f714b8(unsigned int *, int, int, unsigned char);
extern int func_0xa0f71534(unsigned int, unsigned int);

int FUN_a00d23bc(unsigned char param_1, unsigned char param_2)
{
    unsigned int local_c;
    unsigned int buf[1];
    
    buf[0] = 0;
    if ((param_1 & 0xff) == 0) {
        local_c = func_0xa0f71528(0xd0013f60);
        buf[0] = local_c;
        func_0xa0f714b8(buf, 0x1f, 0x1f, param_2 & 0xff);
        func_0xa0f71534(0xd0013f60, buf[0]);
    } else {
        local_c = func_0xa0f71528(0xd0013f70);
        buf[0] = local_c;
        func_0xa0f714b8(buf, 0x1f, 0x1f, param_2 & 0xff);
        func_0xa0f71534(0xd0013f70, buf[0]);
    }
    return 1;
}
