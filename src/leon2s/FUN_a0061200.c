/* FUN_a0061200 (leon2s 0xa0061200-0xa0061224, 36 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Writes 0x8000 to the registers 0x9f120034 and 0x9f10009c. Address word at 0xa00b6078.
 * The table at 0xa00b6070 holds FUN_a0061138, FUN_a006119c and this routine in consecutive words. Hardware
 * registers: volatile; each store keeps its own address constant.
 */
#define R9C (*(volatile unsigned int *)0x9f10009c)
#define S34 (*(volatile unsigned int *)0x9f120034)

void FUN_a0061200(void)
{
    S34 = 0x8000;
    R9C = 0x8000;
}
