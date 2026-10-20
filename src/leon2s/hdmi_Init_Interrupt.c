/* leon2s hdmi_Init_Interrupt @ 0xa00a2fd4  MATCH (-mcpu=v8 -Os -g, gcc 3.4.4, near)
 * near-miss repaired mechanically (tools/nearfix.py): name hdmi_status->DAT_a8078634; format string with \n; function name as a static const char[] (separate .rodata object)
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
