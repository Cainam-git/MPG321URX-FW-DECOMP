/* leon2m FUN_a0099b60 @ 0xa0099b60 (-mcpu=v8 -O2 -g)
 * The function reads a byte from a configuration register, calls a function with it, sets a word register to 0xb3, calls another function, ORs a flag byte with 2, clears another byte, and returns its first parameter unchanged. The second parameter `param_2` is unused in the assembly — no instruction moves `%i1` to an output register.
 */
extern unsigned char DAT_a8025c55;
extern unsigned char DAT_a802b08e;
extern unsigned char DAT_a802d33c;
extern unsigned int _DAT_a802afec;

extern int FUN_a00a93bc();
extern int FUN_a00a9650();
extern void FUN_a00af44c();

unsigned int FUN_a0099b60(unsigned int param_1, char param_2)
{
    FUN_a00a93bc(DAT_a802d33c);
    FUN_a00af44c(0x2a, 3);
    _DAT_a802afec = 0xb3;
    FUN_a00a9650(2, 1);
    DAT_a802b08e = DAT_a802b08e | 2;
    DAT_a8025c55 = 0;
    return param_1;
}
