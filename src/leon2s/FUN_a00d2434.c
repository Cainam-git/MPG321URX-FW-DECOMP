/* leon2s FUN_a00d2434 @ 0xa00d2434 (-mcpu=v8 -Os -g)
 * This function reads a value from a register at 0xd0013f10, passes it through a transformation function with different parameters depending on the input flag, then writes back the result. The structure matches the similar functions exactly, with the only differences being the constant address (0xd0013f10 instead of 0xd0013f60/0xd0013f50) and the parameter values passed to func_0xa0f714b8 (0,0 in one branch and 1,1 in the other, matching the mov 1, %o1 and mov 1, %o2 in the target).
 */
extern int func_0xa0f71528(unsigned int);
extern void func_0xa0f714b8(unsigned int *, int, int, unsigned char);
extern int func_0xa0f71534(unsigned int, unsigned int);

int FUN_a00d2434(unsigned char param_1, unsigned char param_2)
{
    unsigned int local_c;
    unsigned int buf[1];
    
    buf[0] = 0;
    if ((param_1 & 0xff) == 0) {
        local_c = func_0xa0f71528(0xd0013f10);
        buf[0] = local_c;
        func_0xa0f714b8(buf, 0, 0, param_2 & 0xff);
        func_0xa0f71534(0xd0013f10, buf[0]);
    } else {
        local_c = func_0xa0f71528(0xd0013f10);
        buf[0] = local_c;
        func_0xa0f714b8(buf, 1, 1, param_2 & 0xff);
        func_0xa0f71534(0xd0013f10, buf[0]);
    }
    return 1;
}
