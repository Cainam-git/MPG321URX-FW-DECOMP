/* sys_task_remove  (FUN_a00b222c)
 *
 * Remove the task with a given id from the task table.
 * Name basis: derived - 16 task records; the record whose id word matches is found and its id word is cleared;
 *   used by the routines that delete a timer; prints when it is not found
 *
 * Matching notes
 * --------------
 * FUN_a00b222c (leon2s 0xa00b222c-0xa00b229c, 112 bytes, leaf), flags -mcpu=v8 -Os -g.
 * The record pointer is taken inside the loop and used for the clear (the firmware walks a record pointer).
 */
/* One of the 16 records of sys_task_table, 24 bytes (see sys_task_start). */
struct Task {
    unsigned int periodic;
    unsigned char active;
    unsigned char pending;
    unsigned char _6[2];
    unsigned int period;
    unsigned int count;
    unsigned int id;
    void (*fn)(void);
};
extern struct Task sys_task_table[16];
extern int dbg_printf(const char *, ...);

/* Stop a task: find the record whose id word equals the given id and clear that word, which takes the task out
 * of the count of timer_tick_isr. When no record has the id, print "Can not find S/W timer!".
 *   id: task id (the address of its descriptor); 0 does nothing
 */
void sys_task_remove(unsigned int id)
{
    int i;
    struct Task *task;

    if (id == 0)
        return;
    for (i = 0; i < 16; i++) {
        task = &sys_task_table[i];
        if (task->id == id)
            break;
    }
    if (i == 16) {
        dbg_printf("\nCan not find S/W timer!");
        return;
    }
    task->id = 0;
}
