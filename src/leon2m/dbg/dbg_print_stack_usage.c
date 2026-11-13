/* dbg_print_stack_usage  (FUN_a00dd540)
 *
 * Print the highest, lowest and current stack position and whether it is in range.
 * Name basis: proven - prints '[MainStack]Max:0x%08X,Min:0x%08X,Curr:0x%08X,' and Pass / Fail; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dd540 @ 0xa00dd540-0xa00dd5b8 (30 words).
 * Source form: the three values are read into locals before the print; the comparison reads register 0x328 again.
 */
extern int dbg_printf(const char *fmt, ...);
extern unsigned int sys_core_read_reg_032c(void);
extern unsigned int sys_core_read_reg_0328(void);
extern unsigned int sys_get_stack_pointer(void);
extern unsigned int sys_core_read_reg_0324(void);

/*
 * Debug aid: print "[MainStack]Max:..,Min:..,Curr:.." with the core registers 0x9F02032C and 0x9F020328 and the
 * current stack pointer, then "Pass" when register 0x9F020328 is above register 0x9F020324 and "Fail" otherwise.
 * Only an argument of 0 does anything. Nothing in the image calls this routine.
 */
void dbg_print_stack_usage(int mode)
{
    if (mode == 0) {
        unsigned int max = sys_core_read_reg_032c();
        unsigned int min = sys_core_read_reg_0328();
        unsigned int current = sys_get_stack_pointer();

        dbg_printf("[MainStack]Max:0x%08X,Min:0x%08X,Curr:0x%08X,", max, min, current);
        if (sys_core_read_reg_0328() > sys_core_read_reg_0324())
            dbg_printf("Pass\r\n");
        else
            dbg_printf("Fail\r\n");
    }
}
