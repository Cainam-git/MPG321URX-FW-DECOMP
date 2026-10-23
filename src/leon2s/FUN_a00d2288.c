/* leon2s FUN_a00d2288 @ 0xa00d2288 (-mcpu=v8 -Os -g)
 * Reads w = func_0xa0f71528(0xD0013FE0), calls func_0xa0f714b8(&w, b, b, p2 & 0xff) with b = 0x1f when p1 == 0 and
 * 0x1e otherwise, and writes w back through func_0xa0f71534(0xD0013FE0, w). Returns 1. Same code as FUN_a00d2300
 * with other constants.
 * See FUN_a00d2300 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern int func_0xa0f71528(unsigned int);
extern void func_0xa0f714b8(unsigned int *, int, int, unsigned char);
extern int func_0xa0f71534(unsigned int, unsigned int);

int FUN_a00d2288(unsigned char param_1, unsigned char param_2)
{
    unsigned int local_c;
    unsigned int buf[1];
    
    buf[0] = 0;
    if ((param_1 & 0xff) == 0) {
        local_c = func_0xa0f71528(0xd0013fe0);
        buf[0] = local_c;
        func_0xa0f714b8(buf, 0x1f, 0x1f, param_2 & 0xff);
        func_0xa0f71534(0xd0013fe0, buf[0]);
    } else {
        local_c = func_0xa0f71528(0xd0013fe0);
        buf[0] = local_c;
        func_0xa0f714b8(buf, 0x1e, 0x1e, param_2 & 0xff);
        func_0xa0f71534(0xd0013fe0, buf[0]);
    }
    return 1;
}
