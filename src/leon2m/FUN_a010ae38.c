/* leon2m FUN_a010ae38 @ 0xa010ae38 (-mcpu=v8 -O3 -g)
 * Returns 1 when bit 7 of register 0xCF00EAC8 is set, otherwise 0. Same code as FUN_a0108e54 with other constants.
 */
#define _DAT_cf00eac8 (*(volatile unsigned int *)0xcf00eac8)

unsigned int FUN_a010ae38(void)
{
    unsigned int val = _DAT_cf00eac8 & 0x80;
    return val != 0;
}
