/* leon2m FUN_a010b160 @ 0xa010b160 (-mcpu=v8 -O3 -g)
 * Twin of FUN_a0108e54: same code, other constants.
 */
#define _DAT_cf00eac8 (*(volatile unsigned int *)0xcf00eac8)

unsigned int FUN_a010b160(void)
{
    unsigned int val = _DAT_cf00eac8 & 0x4;
    return val != 0;
}
