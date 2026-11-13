/* sys_task_init  (FUN_a00b1e70)
 *
 * Initialise the tick record and the task table.
 * Note: Clears active, pending and fn of the 16 task entries; the id word (+0x10), which marks a slot as used,
 *   is not cleared.
 * Name basis: derived - one-time set-up of the records at 0xA80793A4 and 0xA80793B8
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -Os -g.
 * Source form: int loop counters in plain for loops (the inner loop over the two hook words is counted down by
 * the compiler); struct records instead of pointer walks. The task table is a separate symbol with its own
 * address load. volatile only on the 0x9f1x / 0xc0xx hardware registers.
 */
#define REG_9F100090 (*(volatile unsigned int *)0x9f100090)
#define REG_9F120028 (*(volatile unsigned int *)0x9f120028)
#define REG_9F120030 (*(volatile unsigned int *)0x9f120030)
#define REG_9F120034 (*(volatile unsigned int *)0x9f120034)
#define REG_9F120038 (*(volatile unsigned int *)0x9f120038)
#define REG_9F120044 (*(volatile unsigned int *)0x9f120044)
#define REG_9F12007C (*(volatile unsigned int *)0x9f12007c)
#define REG_C0000000 (*(volatile unsigned int *)0xc0000000)

/* Start of timer_tick_record: init flag (+0), then the two tick hook words (+0xc) that sys_register_tick_hook
 * fills (one index, two slots). */
struct tick_record {
    unsigned char init;
    unsigned char _01[0xb];
    struct { unsigned int slot[2]; } hooks[1];
};
/* One 24-byte entry of sys_task_table; only the fields this routine clears. */
struct task_record {
    unsigned char _00[4];
    unsigned char active;       /* +4 */
    unsigned char pending;      /* +5 */
    unsigned char _06[0xe];
    unsigned int fn;            /* +0x14, the task function */
};
extern struct tick_record timer_tick_record;
extern struct task_record sys_task_table[16];
extern unsigned int sys_clock_hz;
extern unsigned int timer_tick_count_second;
extern void reg_write32(volatile unsigned int *, unsigned int);
extern void timer_delay_long_units(int);

/*
 * One-time set-up of the tick counter, the tick hooks and the 16-entry task table, and of the hardware
 * registers it uses. Runs only while the first byte of timer_tick_record is 0 and sets it to 1 at the end, so
 * a second call does nothing. In order:
 *  - clear the per-second tick count and the two tick hook words;
 *  - pick timer_value from the clock frequency sys_clock_hz: 12000 for 96 000 000, 10000 for 80 000 000,
 *    3000 for any other value;
 *  - clear active, pending and fn of every task table entry (the id word at +0x10 is not touched);
 *  - set bit 1 of 0xc0000000, wait one long delay unit, clear it again;
 *  - write timer_value, 0x83 and 0 to 0xc00a0010, 0xc00a0014 and 0xc00a0018;
 *  - change the registers 0x9f120030, 0x9f100090, 0x9f120028, 0x9f120044, 0x9f12007c, 0x9f120038 and
 *    0x9f120034 as listed in the code.
 * Caller: startup_init_system.
 */
void sys_task_init(void)
{
    int i, j;
    unsigned int timer_value;

    if (timer_tick_record.init == 0) {
        timer_tick_count_second = 0;
        for (i = 0; i < 1; i++)
            for (j = 0; j < 2; j++)
                timer_tick_record.hooks[i].slot[j] = 0;
        if (sys_clock_hz == 96000000)
            timer_value = 12000;
        else if (sys_clock_hz == 80000000)
            timer_value = 10000;
        else
            timer_value = 3000;
        for (i = 0; i < 16; i++) {
            sys_task_table[i].active = 0;
            sys_task_table[i].pending = 0;
            sys_task_table[i].fn = 0;
        }
        REG_C0000000 |= 2;
        timer_delay_long_units(1);
        REG_C0000000 &= ~2;
        reg_write32((volatile unsigned int *)0xc00a0010, timer_value);
        reg_write32((volatile unsigned int *)0xc00a0014, 0x83);
        reg_write32((volatile unsigned int *)0xc00a0018, 0);
        REG_9F120030 |= 0x10;
        REG_9F100090 |= 0x10;
        REG_9F120028 &= ~0x10;
        REG_9F120044 &= ~2;
        REG_9F12007C = 2;
        REG_9F120038 &= ~0xf;
        REG_9F120034 = 0x10;
        timer_tick_record.init = 1;
    }
}
