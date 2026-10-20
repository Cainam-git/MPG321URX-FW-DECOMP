/* leon2m FUN_a00e021c @ 0xa00e021c  MATCH (-mcpu=v8 -O2 -g, twin)
 * Twin of FUN_a002c250: same code, constants swapped; byte-exact.
 * See FUN_a002c250 for the explanation; this copy's constants differ, so its comments were removed.
 */
unsigned int FUN_a00e021c(unsigned int addr)
{
    return *(volatile unsigned int *)addr;
}
