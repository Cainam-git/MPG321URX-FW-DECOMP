/* leon2m FUN_a0099bb4 @ 0xa0099bb4  MATCH (-mcpu=v8 -O2 -g)
 * This function reads a byte from a global array at offset 0xac, passes it to a function, copies another global byte into that slot, performs two register writes and two function calls, then clears the source byte. The key corrections from Ghidra's version are: using the proven array declaration `DAT_a802d290[]` instead of the unrelated `DAT_a802d33c`, matching the call to `FUN_a00da754` with the byte argument, and omitting the fake 64-bit return value. The function is void since the assembly ends with `ret; restore` and no return value is set.
 */
extern unsigned char DAT_a8025c55;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a802d290[];
extern int FUN_a00a93bc();
extern void FUN_a00af44c(unsigned int, unsigned int);
extern void FUN_a00a9650(unsigned int, unsigned int);
extern void FUN_a00da754(unsigned char);

void FUN_a0099bb4(void)
{
    FUN_a00a93bc(DAT_a802d290[0xac]);
    DAT_a802d290[0xac] = DAT_a8025c55;
    FUN_a00af44c(0x2a, 3);
    _DAT_a802afec = 0xb3;
    FUN_a00a9650(2, 1);
    FUN_a00da754(DAT_a802d290[0xac]);
    DAT_a8025c55 = 0;
}
