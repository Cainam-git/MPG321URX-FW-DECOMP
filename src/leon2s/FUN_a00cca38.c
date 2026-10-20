/* leon2s FUN_a00cca38 @ 0xa00cca38 (-mcpu=v8 -Os -g)
 * 
 */
extern int func_0xa0fb7acc();

void FUN_a00cca38(unsigned int param_1)
{
    unsigned int uVar1;
    
    if ((param_1 & 0xff) == 1)
    {
        uVar1 = func_0xa0fb7acc(0, 6);
        if (uVar1 & 1)
        {
            *(volatile unsigned int *)0xcf018d54 |= 2;
            *(volatile unsigned int *)0xcf018ddc |= 1;
        }
        *(volatile unsigned int *)0xcf018d00 |= 2;
    }
    else
    {
        uVar1 = func_0xa0fb7acc(0, 6);
        if (uVar1 & 1)
        {
            *(volatile unsigned int *)0xcf018ddc &= 0xfffffffe;
        }
        *(volatile unsigned int *)0xcf018d00 &= 0xfffffffd;
    }
}
