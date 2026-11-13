/* sys_task_start  (CONV2HDMITX_UpdateInterface_4)
 *
 * Start the task whose record carries the given descriptor address: fill period, count and routine.
 * Note: Prints "Can not find S/W timer!" when no record carries that address; it does not take a free slot.
 * Name basis: derived - 16 task records of 24 bytes at 0xA80793B8, matched by the id word (+0x10); used by the
 *   routines that start a timer
 *
 * Matching notes
 * --------------
 * CONV2HDMITX_UpdateInterface_4 (leon2s 0xa00b2194-0xa00b222c, 152 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the descriptor is a struct pointer and the stores run in the order period, periodic, count, fn,
 * active. The search loop is the one of sys_task_remove.
 */
/* One of the 16 records of sys_task_table, 24 bytes. */
struct Task {
    unsigned int periodic;      /* copied from the descriptor */
    unsigned char active;       /* set to 1 when the task is entered */
    unsigned char pending;      /* tested and cleared by sys_task_run_pending */
    unsigned char _6[2];
    unsigned int period;        /* copied from the descriptor */
    unsigned int count;         /* starts as the period */
    unsigned int id;            /* descriptor address that names the task; timer_tick_isr counts only tasks where it is non-zero,
                                   sys_task_remove sets it to 0 */
    void (*fn)(void);           /* called by sys_task_run_pending */
};
/* What the caller passes in. */
struct TimerDesc { unsigned int periodic; unsigned int period; void (*fn)(void); };
extern struct Task sys_task_table[16];
extern int dbg_printf(const char *, ...);

/* Fill the task record whose id is this descriptor's address with the descriptor's period, periodic flag and
 * function, and mark it active. The record has to be there already: when no record carries the address, the
 * routine prints "Can not find S/W timer!" and changes nothing.
 *   desc: timer descriptor; a null pointer does nothing
 */
void sys_task_start(struct TimerDesc *desc)
{
    int i;
    struct Task *task;

    if (desc == 0)
        return;
    for (i = 0; i < 16; i++) {
        task = &sys_task_table[i];
        if (task->id == (unsigned int)desc)
            break;
    }
    if (i == 16) {
        dbg_printf("\nCan not find S/W timer!");
        return;
    }
    task->period = desc->period;
    task->periodic = desc->periodic;
    task->count = desc->period;
    task->fn = desc->fn;
    task->active = 1;
}
