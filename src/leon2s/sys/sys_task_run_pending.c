/* sys_task_run_pending  (FUN_a00b229c)
 *
 * Run every task whose time has come.
 * Name basis: derived - task runner over the 16 records: clear the flag, call the function
 *
 * Matching notes
 * --------------
 * FUN_a00b229c @ 0xa00b229c-0xa00b22fc (24 words), flags -mcpu=v8 -Os -g.
 * The firmware counts a down counter 15..0 next to the 0x18 stride; the plain for loop over i builds that.
 */
struct Task { unsigned char pad[5]; unsigned char pending; unsigned char pad2[0x14 - 6]; void (*fn)(void); };
extern struct Task sys_task_table[16];
extern unsigned char timer_task_pending_flag;

/* When timer_task_pending_flag is set (timer_tick_isr sets it on every tick), call the function of every task
 * record marked pending, clearing the mark first, then clear the flag. */
void sys_task_run_pending(void)
{
    int i;

    if (timer_task_pending_flag != 0) {
        for (i = 0; i < 16; i++) {
            if (sys_task_table[i].pending != 0) {
                sys_task_table[i].pending = 0;
                sys_task_table[i].fn();
            }
        }
        timer_task_pending_flag = 0;
    }
}
