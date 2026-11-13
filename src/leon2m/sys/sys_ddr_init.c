/* sys_ddr_init  (FUN_a00e1fc8)
 *
 * Choose the old or the new memory script by a pin and run it.
 * Name basis: proven - prints 'Old DDR' or 'New DDR'; called from the start-up clock set-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e1fc8 @ 0xa00e1fc8-0xa00e2040 (30 words), flags -mcpu=v8 -O3 -g.
 * Source form: the '== 0' arm ("Old DDR") is first in the source (the firmware falls through into it). The script
 * addresses are symbol addresses (each its own sethi). sys_ddr_run_script is called as a tail call with one
 * argument, 0.
 */
extern void *DAT_a802d654_DDRScript;            /* address of the script to run */
extern unsigned int DAT_a802d658_DDRScriptLen;  /* its length in bytes */
extern unsigned char sys_ddr_script_new[], sys_ddr_script_old[];
extern int dbg_printf();
extern void sys_ddr_run_script(int);
extern unsigned int sys_get_const_0x1429(void);
extern unsigned int sys_get_const_0x1429_copy(void);
extern unsigned char gpio_is_port13_bit4_high(void);

/*
 * Set up the memory interfaces. Pick the setup script by the level of pin 4 of GPIO port 13: low prints
 * "Old DDR" and selects sys_ddr_script_old, high prints "New DDR" and selects sys_ddr_script_new. The script
 * length is 0x1429 in both cases. Then run the script from its start (sys_ddr_run_script). Called from
 * startup_init_display_clocks.
 */
void sys_ddr_init(void)
{
    if (gpio_is_port13_bit4_high() == 0) {
        dbg_printf("Old DDR\r\n");
        DAT_a802d654_DDRScript = sys_ddr_script_old;
        DAT_a802d658_DDRScriptLen = sys_get_const_0x1429();
    } else {
        dbg_printf("New DDR\r\n");
        DAT_a802d654_DDRScript = sys_ddr_script_new;
        DAT_a802d658_DDRScriptLen = sys_get_const_0x1429_copy();
    }
    sys_ddr_run_script(0);
}
