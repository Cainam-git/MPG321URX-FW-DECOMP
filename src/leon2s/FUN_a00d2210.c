/* leon2s FUN_a00d2210 @ 0xa00d2210  MATCH (-mcpu=v8 -Os -g, twin)
 * Twin of FUN_a00d2300: same code, constants swapped; byte-exact.
 * See FUN_a00d2300 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern int func_0xa0f71528(unsigned int);
extern void func_0xa0f714b8(unsigned int *, int, int, unsigned char);
extern int func_0xa0f71534(unsigned int, unsigned int);

int FUN_a00d2210(unsigned char param_1, unsigned char param_2)
{
    unsigned int local_c;
    unsigned int buf[1];
    
    buf[0] = 0;
    if ((param_1 & 0xff) == 0) {
        local_c = func_0xa0f71528(0xd0013fd0);
        buf[0] = local_c;
        func_0xa0f714b8(buf, 0x1f, 0x1f, param_2 & 0xff);
        func_0xa0f71534(0xd0013fd0, buf[0]);
    } else {
        local_c = func_0xa0f71528(0xd0013fd0);
        buf[0] = local_c;
        func_0xa0f714b8(buf, 0x1e, 0x1e, param_2 & 0xff);
        func_0xa0f71534(0xd0013fd0, buf[0]);
    }
    return 1;
}
