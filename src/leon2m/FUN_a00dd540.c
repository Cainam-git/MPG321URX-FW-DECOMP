/* leon2m FUN_a00dd540 @ 0xa00dd540-0xa00dd5b8 (30 words).
 * When the argument is 0: prints "[MainStack]Max:0x%08X,Min:0x%08X,Curr:0x%08X," with FUN_a00de9c0(),
 * FUN_a00de9a8() and the current stack pointer (FUN_a00de9d8()), then "Pass" when FUN_a00de9a8() is above
 * FUN_a00de9e0() and "Fail" otherwise. Other arguments do nothing.
 */
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned int FUN_a00de9c0(void);
extern unsigned int FUN_a00de9a8(void);
extern unsigned int FUN_a00de9d8(void);
extern unsigned int FUN_a00de9e0(void);

void FUN_a00dd540(int arg)
{
    if (arg == 0) {
        unsigned int max = FUN_a00de9c0();
        unsigned int min = FUN_a00de9a8();
        unsigned int cur = FUN_a00de9d8();

        FUN_a00df170("[MainStack]Max:0x%08X,Min:0x%08X,Curr:0x%08X,", max, min, cur);
        if (FUN_a00de9a8() > FUN_a00de9e0())
            FUN_a00df170("Pass\r\n");
        else
            FUN_a00df170("Fail\r\n");
    }
}
