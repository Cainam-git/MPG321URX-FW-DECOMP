/* sys_task_create  (CONV2HDMITX_UpdateInterface_3)
 *
 * Fill the first free record of the task table from a descriptor.
 * Name basis: derived - 16 task records at 0xA80793B8; used by the routines that initialise a timer; prints
 *   when the table is full
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -Os -g.
 * Source form: three separate early-return tests (tick record flag, descriptor, function pointer). The
 * stores run in the order period, periodic, fn, count, id, active; the record is reached through the pointer
 * 'task' left over from the search loop.
 */
struct Task {
    unsigned int periodic;      /* copied from the descriptor */
    unsigned char active;       /* set to 1 when the task is entered */
    unsigned char pending;      /* tested and cleared by sys_task_run_pending */
    unsigned char _6[2];
    unsigned int period;        /* copied from the descriptor */
    unsigned int count;         /* starts as the period */
    unsigned int id;            /* address of the descriptor that created the task; 0 = slot unused */
    void (*fn)(void);           /* called by sys_task_run_pending */
};
/* Descriptor supplied by the caller; its address is the task's id (see sys_task_remove). */
struct TimerDesc { unsigned int periodic; unsigned int period; void (*fn)(void); };
extern struct Task sys_task_table[16];
extern unsigned char timer_tick_record;
extern int dbg_printf(const char *, ...);

/*
 * Enter a new task into the first unused slot of the 16-entry task table.
 * Nothing happens until sys_task_init has run (timer_tick_record's first byte is still 0), or when the
 * descriptor or its function is null. A slot is unused when its id is 0. The task gets the descriptor's
 * period and periodic flag; its countdown starts at the full period, and its id is the descriptor's address,
 * which sys_task_remove and sys_task_start use to find it again. When all 16 slots are taken the routine
 * only prints "No S/W timer available".
 *   d: descriptor {periodic, period, fn}
 */
void sys_task_create(struct TimerDesc *d)
{
    int i;
    struct Task *task;

    if (timer_tick_record == 0)
        return;
    if (d == 0)
        return;
    if (d->fn == 0)
        return;
    for (i = 0; i < 16; i++) {
        task = &sys_task_table[i];
        if (task->id == 0)
            break;
    }
    if (i == 16) {
        dbg_printf("\nNo S/W timer available");
        return;
    }
    task->period = d->period;
    task->periodic = d->periodic;
    task->fn = d->fn;
    task->count = d->period;
    task->id = (unsigned int)d; /* the id */
    task->active = 1;
}
