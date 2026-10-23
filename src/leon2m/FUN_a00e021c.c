/* leon2m FUN_a00e021c @ 0xa00e021c (-mcpu=v8 -O2 -g)
 * Returns the word at address p1. Same code as FUN_a002c250.
 * See FUN_a002c250 for the explanation; this copy's constants differ, so its comments were removed.
 */
unsigned int FUN_a00e021c(unsigned int addr)
{
    return *(volatile unsigned int *)addr;
}
