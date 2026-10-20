/* leon2m FUN_a00fc1a0 @ 0xa00fc1a0 (-mcpu=v8 -O2 -g)
 * 
 */
extern int FUN_4008d1a0(int, ...);

void FUN_a00fc1a0(void)
{
    unsigned int l1;
    volatile unsigned int *reg = (volatile unsigned int *)0xd0040000;
    
    l1 = *reg;
    *reg = l1 | 0x20000000;
    FUN_4008d1a0(5);
    *reg = l1;
}
