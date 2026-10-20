/* leon2s FUN_a00d2300 @ 0xa00d2300 (-mcpu=v8 -Os -g)
 * Reads func_0xa0f71528(0xD0013F50) into a one-word buffer, calls func_0xa0f714b8(buf, n, n, param_2 & 0xFF) with
 * n = 0x1F when the low byte of param_1 is 0, else n = 0x1E, and writes the buffer back with
 * func_0xa0f71534(0xD0013F50, buf[0]). Both branches use 0xD0013F50 ('or %l0, 0x350, %o0'). Always returns 1.
 */
extern int func_0xa0f71528(unsigned int);
extern void func_0xa0f714b8(unsigned int *, int, int, unsigned char);
extern int func_0xa0f71534(unsigned int, unsigned int);

int FUN_a00d2300(unsigned char param_1, unsigned char param_2)
{
    unsigned int local_c;
    unsigned int buf[1];
    
    buf[0] = 0;
    if ((param_1 & 0xff) == 0) {
        local_c = func_0xa0f71528(0xd0013f50);
        buf[0] = local_c;
        func_0xa0f714b8(buf, 0x1f, 0x1f, param_2 & 0xff);
        func_0xa0f71534(0xd0013f50, buf[0]);
    } else {
        local_c = func_0xa0f71528(0xd0013f50);
        buf[0] = local_c;
        func_0xa0f714b8(buf, 0x1e, 0x1e, param_2 & 0xff);
        func_0xa0f71534(0xd0013f50, buf[0]);
    }
    return 1;
}
