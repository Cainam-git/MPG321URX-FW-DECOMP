/* leon2m FUN_a01248c8 @ 0xa01248c8  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, autoc)
 * Finished by hand from mechanical Ghidra C. Asks 0x4008cd38(9, 8) and returns 1 when the
 * low byte of the answer is 1, else 0 (a yes/no status check). Ghidra's fake 64-bit return
 * removed.
 * Still needs a real name and proper types.
 */
extern int func_0x4008cd38(int, int);

int FUN_a01248c8(void)
{
    return (func_0x4008cd38(9, 8) & 0xff) == 1;
}
