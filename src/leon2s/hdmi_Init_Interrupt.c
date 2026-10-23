/* leon2s hdmi_Init_Interrupt @ 0xa00a2fd4 (-mcpu=v8 -Os -g)
 * Prints "[INIT]: %s" with "_hdmi_Init_Interrupt" when bit 0 of DAT_a8078634 is set (FUN_a0073044); FUN_a00a0514();
 * FUN_a00a2e48(0) and FUN_a00a2e48(1); FUN_a00b1980(); FUN_a00b1a4c(); returns 0. The function name is a separate
 * static const char[] (the firmware keeps it apart from the format string).
 */
/* hdmi_Init_Interrupt at 0xa00a2fd4 */

extern unsigned int DAT_a8078634; /* 0xa8078634 */
extern void FUN_a0073044(const char *, const char *); /* 0xa0073044 */
extern void FUN_a00a0514(void); /* 0xa00a0514 */
extern void FUN_a00a2e48(unsigned char); /* 0xa00a2e48 */
extern void FUN_a00b1980(void); /* 0xa00b1980 */
extern void FUN_a00b1a4c(void); /* 0xa00b1a4c */

static const char fn_[] = "_hdmi_Init_Interrupt";   /* the firmware keeps function names apart from the format strings (__FUNCTION__-style .rodata object) */

int hdmi_Init_Interrupt(void)
{
    if (DAT_a8078634 & 1) {
        FUN_a0073044("[INIT]: %s\n", fn_);
    }
    FUN_a00a0514();
    {
        unsigned int i = 0;
        do {
            FUN_a00a2e48((unsigned char)i);
            i++;
        } while ((unsigned char)i <= 1);
    }
    FUN_a00b1980();
    FUN_a00b1a4c();
    return 0;
}
