/* leon2m FUN_a012498c @ 0xa012498c  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, autoc)
 * Finished by hand from mechanical Ghidra C. Asks 0x4008cd38(7, 0x40) and returns 1 when the
 * low byte of the answer is 1, else 0. Twin of FUN_a01248c8 (which asks (9, 8)).
 * Still needs a real name and proper types.
 */
extern int func_0x4008cd38(int, int);

int FUN_a012498c(void)
{
    return (func_0x4008cd38(7, 0x40) & 0xff) == 1;
}
