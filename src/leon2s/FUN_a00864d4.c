/* leon2s FUN_a00864d4 @ 0xa00864d4 (-mcpu=v8 -Os -g)
 * Maps the low byte of param_2 (0, 1, 2, 3) to 0x21, 0x22, 0x23, 0x27 (other values 0), passes the address of that
 * byte to FUN_a00863d4(param_1 & 0xFF, 0x80, 0x102, 0, &byte) and returns 1 when the result is non-zero (cmp %g0,
 * %o0; addx %g0, 0, %i0).
 */
extern unsigned char FUN_a00863d4(unsigned int, unsigned int, unsigned int, char, unsigned int);

int FUN_a00864d4(unsigned int param_1, unsigned int param_2)
{
    unsigned char local_9;
    unsigned char uVar1;
    
    uVar1 = (unsigned char)param_2;
    if (uVar1 == 0)
        local_9 = 0x21;
    else if (uVar1 == 1)
        local_9 = 0x22;
    else if (uVar1 == 2)
        local_9 = 0x23;
    else if (uVar1 == 3)
        local_9 = 0x27;
    else
        local_9 = 0;
    
    return FUN_a00863d4((unsigned char)param_1, 0x80, 0x102, 0, (unsigned int)&local_9) != 0;
}
