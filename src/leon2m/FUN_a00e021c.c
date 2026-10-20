/* leon2m FUN_a00e021c @ 0xa00e021c (-mcpu=v8 -O2 -g)
 * Twin of FUN_a002c250: same code, other constants.
 * See FUN_a002c250 for the explanation; this copy's constants differ, so its comments were removed.
 */
unsigned int FUN_a00e021c(unsigned int addr)
{
    return *(volatile unsigned int *)addr;
}
